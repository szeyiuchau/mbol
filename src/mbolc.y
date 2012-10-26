%{
    #include<sstream>
    #include<iostream>
    #include<fstream>
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<map>
    #include<set>
    #include<list>
    using namespace std;
%}
%token SM IN CO GE LE EQ US SI SU VA MA MI ST PL SB DI MU LC RC LP RP AA BB CC DD EL AN UN SR RR LR LI ZC SE CT SS FR PR GT LT NE LJ CN
%union {
    int ival;
    char* sval;
}
%token <sval> NU
%token <sval> VA
%type <ival> objective objective_type constraints constraint equation inequality qualifiers qualifier operator indices sum sum_product_qualifiers number_variable sum_product expression primary_expression
%%
program:
AA objective constraints BB {
    // going to figure out the types of element variables and store them here
    map<string,string> typeMap;
    
    // take care of simple variables
    for(map<string,string>::iterator i=varType.begin();i!=varType.end();i++) {
        if(i->second=="number") {
            if(declType[i->first]=="variable") {
                if(intConstraints.count(i->first)) {
                    typeMap[i->first]="MyIloIntVar";
                    typeMap["RET_"+i->first.substr(0,i->first.size()-4)]="int";
                } else {
                    typeMap[i->first]="MyIloNumVar";
                    typeMap["RET_"+i->first.substr(0,i->first.size()-4)]="double";
                }
            } else {
                typeMap[i->first]="double";
            }
        }
    }
    
    // start with basic elements which will be integers
    set<string> startNodes;
    for(map<string,map<string,int> >::iterator i=setGraph.begin();i!=setGraph.end();i++) {
        startNodes.insert(i->first);
    }
    for(map<string,map<string,int> >::iterator i=setGraph.begin();i!=setGraph.end();i++) {
        for(map<string,int>::iterator j=i->second.begin();j!=i->second.end();j++) {
            startNodes.erase(j->first);
        }
    }
    
    // BFS search to figure out distance to each node which reveals its element type
    map<int,list<string> > toVisit;
    set<string> visited;
    for(set<string>::iterator i=startNodes.begin();i!=startNodes.end();i++) {
        toVisit[0].push_back(*i);
    }
    while(!toVisit.empty()) {
        string x=toVisit.begin()->second.front();
        int length=toVisit.begin()->first;
        toVisit.begin()->second.pop_front();
        while(!toVisit.empty()&&toVisit.begin()->second.empty()) {
            toVisit.erase(toVisit.begin());
        }
        if(visited.count(x)) {
            continue;
        }
        visited.insert(x);
        string type="";
        for(int i=0;i<length;i++) {
            type+="set<";
        }
        type+="int";
        for(int i=0;i<length;i++) {
            if(i==0) {
                type+=">";
            } else {
                type+=",set"+convert(i)+"comp>";
            }
        }
        typeMap[x]=type;
        for(map<string,int>::iterator i=setGraph[x].begin(); i!=setGraph[x].end(); i++) {
            if(visited.count(i->first)==0) {
                toVisit[length+i->second].push_back(i->first);
            }
        }
    }
    
    // get types of the map objects (real/integer variables in mathematical program)
    for(map<string,list<list<string> > >::iterator i=mapTypes.begin();i!=mapTypes.end();i++) {
        list<string> example=i->second.front();
        string type="";
        for(list<string>::iterator j=example.begin();j!=example.end();j++) {
            if(typeMap[*j]=="int") {
                type+="map<int,";
            }
            if(typeMap[*j]=="set<int>") {
                type+="map<set<int>,";
            }
        }
        if(declType[i->first]=="variable") {
            if(intConstraints.count(i->first)) {
                type+="MyIloIntVar";
            } else {
                type+="MyIloNumVar";
            }
        } else {
            type+="double";
        }
        for(list<string>::reverse_iterator j=example.rbegin();j!=example.rend();j++) {
            if(typeMap[*j]=="int") {
                if(type[type.size()-1]=='>') {
                    type+=" ";
                }
                type+=">";
            }
            if(typeMap[*j]=="set<int>") {
                type+=",set1comp>";
            }
        }
        typeMap[i->first]=type;
        if(declType[i->first]=="variable") {
            if(intConstraints.count(i->first)) {
                type=replaceAll(type,"MyIloIntVar","int");
            } else {
                type=replaceAll(type,"MyIloNumVar","double");
            }
            typeMap["RET_"+i->first.substr(0,i->first.size()-4)]=type;
        }
    }
    
    // if a variable had the cardinality operator applied to it, then it is a set even if labeled an int
    for(set<string>::iterator i=weakSet.begin();i!=weakSet.end();i++) {
        if(typeMap[*i]=="int") {
            typeMap[*i]="set<int>";
        }
    }
    
    // start making all the cppCode
    hppCode="#include<set>\n#include<map>\n#include<ilcplex/ilocplex.h>\nusing namespace std;\n#ifndef CPLEX_SETUP_STUFF\n#define CPLEX_SETUP_STUFF\nIloEnv g_env;\nclass MyIloIntVar : public IloIntVar {\npublic:\nMyIloIntVar() : IloIntVar(g_env) {}\n};\nclass MyIloNumVar : public IloNumVar {\npublic:\nMyIloNumVar() : IloNumVar(g_env) {}\n};\nstruct set1comp {\nbool operator() (const set<int>& lhs,const set<int>& rhs) const {\nif(lhs.size()!=rhs.size()) {\nreturn lhs.size()<rhs.size();\n}\nset<int>::iterator i,j;\ni=lhs.begin();\nj=rhs.begin();\nwhile(i!=lhs.end()) {\nif(*i!=*j) {\nreturn *i<*j;\n}\ni++;\nj++;\n}\nreturn 0;\n}\n};\nset<set<int>,set1comp> powerset(set<int> x) {\nset<set<int>,set1comp> pset;\nfor(int i=0; i<pow(2,x.size()); i++) {\nset<int> s;\nset<int>::iterator k=x.begin();\nfor(int j=0; j<x.size(); j++) {\nif(((i >> j)&1)==1) {\ns.insert(*k);\n}\nk++;\n}\npset.insert(s);\n}\nreturn pset;\n}\n#endif\n#ifndef CPLEX_FUNC_"+functionName+"\n#define CPLEX_FUNC_"+functionName+"\nclass "+functionName+" {\npublic:\nbool init();\nbool solve();\n"+functionName+"();\n~"+functionName+"();\nbool hasInitialized;\nIloCplex cplex;\nIloEnv env;\ndouble objValue;\nIloExpr objExp;\n";
    
    // create struct for returning variables 
    for(map<string,string>::iterator i=varType.begin();i!=varType.end();i++) {
        if(declType[i->first]=="variable") {
            string retName=i->first.substr(0,i->first.size()-4);
            hppCode+="TYPE_RET_"+retName+"_ "+retName+";\n";
        }
    }
    
    
    // making arguments which are constants in the program
    for(map<string,string>::iterator i=varType.begin();i!=varType.end();i++) {
        if(i->second!="constant"&&declType[i->first]=="") {
            hppCode+="TYPE_"+i->first+"_ "+i->first+";\n";
        }
    }
    
    // declare CPLEX variables (actual variables in program)
    for(map<string,string>::iterator i=varType.begin();i!=varType.end();i++) {
        if(declType[i->first]=="variable") {
            hppCode+="TYPE_"+i->first+"_ "+i->first+";\n";
        }
    }
    hppCode+="};\n#endif\n";
    cppCode=functionName+"::"+functionName+"() {\nhasInitialized=false;\n}\nbool "+functionName+"::init() {\n";
    cppCode+="IloModel model(env);\ng_env=env;\ntry {\n";
    
    
    // take care of simple variables
    for(map<string,string>::iterator i=varType.begin();i!=varType.end();i++) {
        if(i->second=="number"&&declType[i->first]=="variable") {
            if(intConstraints.count(i->first)) {
                cppCode+="MyIloIntVar";
            } else {
                cppCode+="MyIloNumVar";
            }
            cppCode+=" temp"+i->first+";\n"+i->first+"=temp"+i->first+";\n";
        }
    }
    
    // this contains most of the logic of the program
    cppCode+=declarations+strs[$2]+"\n"+strs[$3]+"\n";
    cppCode+="IloCplex tempCplex(model);\ncplex=tempCplex;\n";
    if(quiet) {
        cppCode+="cplex.setOut(env.getNullStream());\n";
    }
    if(paramFile!="") {
        FILE* f=fopen(paramFile.c_str(),"r");
        int num;
        char buf[1024];
        do {
            bzero(buf,1024);
            num=fread(buf,1000,1,f);
            cppCode+=string(buf);
        } while(num==1000);
        fclose(f);
    }
    cppCode+="}\ncatch(IloException& ex) {\ncout << ex << endl;\nreturn false;\n}\nhasInitialized=true;\nreturn true;\n}\nbool "+functionName+"::solve() {\nif(!hasInitialized) {\ninit();\n}\nif(!hasInitialized) {\nreturn false;\n}\ncplex.solve();\nobjValue=cplex.getValue(objExp);\n";
    
    
    
    // fill in simple variable values
    for(map<string,string>::iterator i=varType.begin();i!=varType.end();i++) {
        if(i->second=="number") {
            if(declType.count(i->first)&&declType[i->first]=="variable") {
                cppCode+=i->first.substr(0,i->first.size()-4)+"=cplex.getValue("+i->first+");\n";
            }
        }
    }
    
    // fill in map variable values
    for(map<string,list<list<string> > >::iterator i=mapTypes.begin();i!=mapTypes.end();i++) {
        if(declType[i->first]!="variable") {
            continue;
        }
        string retName=i->first.substr(0,i->first.size()-4);
        list<string> example=i->second.front();
        int tVal=0;
        string prev=i->first;
        string indices="";
        for(int j=0;j<example.size();j++) {
            cppCode+="for(";
            int temp;
            temp=0;
            for(list<string>::iterator k=example.begin();k!=example.end();k++) {
                temp++;
                if(temp>j) {
                    if(typeMap[*k]=="int") {
                        cppCode+="map<int,";
                    }
                    if(typeMap[*k]=="set<int>") {
                        cppCode+="map<set<int>,";
                    }
                }
            }
            if(intConstraints.count(i->first)) {
                cppCode+="MyIloIntVar";
            } else {
                cppCode+="MyIloNumVar";
            }
            temp=example.size()-j;
            for(list<string>::reverse_iterator j=example.rbegin();j!=example.rend();j++) {
                temp--;
                if(temp>=0) {
                    if(typeMap[*j]=="int") {
                        if(cppCode[cppCode.size()-1]=='>') {
                            cppCode+=" ";
                        }
                        cppCode+=">";
                    }
                    if(typeMap[*j]=="set<int>") {
                        cppCode+=",set1comp>";
                    }
                }
            }
            cppCode+="::iterator iter"+convert(tVal)+"="+prev+".begin();iter"+convert(tVal)+"!="+prev+".end();iter"+convert(tVal)+"++) {\n";
            indices+="[iter"+convert(tVal)+"->first]";
            prev="iter"+convert(tVal)+"->second";
            tVal++;
        }
        cppCode+=retName+indices+"=cplex.getValue("+prev+");\n";
        for(list<string>::iterator j=example.begin();j!=example.end();j++) {
            cppCode+="}\n";
        }
    }
    cppCode+="return true;\n}\n"+functionName+"::~"+functionName+"() {\nenv.end();\n}\n";
    
    // real types put in the cppCode
    for(map<string,string>::iterator i=typeMap.begin();i!=typeMap.end();i++) {
        hppCode=replaceAll(hppCode,"TYPE_"+i->first+"_",i->second);
        cppCode=replaceAll(cppCode,"TYPE_"+i->first+"_",i->second);
    }
};
objective:
objective_type LC program_variables RC LC primary_expression RC {
    int n=strs.size();
    strs[n]=scopeStuff[$6]+"IloExpr tempObjExp(env);\nobjExp=tempObjExp;\nobjExp=objExp+"+strs[$6]+";\n"+strs[$1];
    $$=n;
};
program_variables:
VA {
    declType[string($1)]="variable";
    declType[string($1)+"_var"]="variable";
}|
program_variables CO VA {
    declType[string($3)]="variable";
    declType[string($3)+"_var"]="variable";
};
objective_type:
MA {
    int n=strs.size();
    strs[n]="IloObjective obj=IloMaximize(env,objExp);\nmodel.add(obj);";
    $$=n;
}|
MI {
    int n=strs.size();
    strs[n]="IloObjective obj=IloMinimize(env,objExp);\nmodel.add(obj);";
    $$=n;
};
constraints:
CN LC constraint RC {
    int n=strs.size();
    strs[n]=strs[$3];
    $$=n;
}|
constraints CN LC constraint RC {
    int n=strs.size();
    strs[n]=strs[$1]+"\n{\n"+strs[$4]+"\n}";
    $$=n;
};
constraint:
equation {
    int n=strs.size();
    strs[n]=strs[$1];
    $$=n;
}|
VA IN ZC {
    intConstraints.insert(string($1)+"_var");
}|
equation CO qualifiers {
    int n=strs.size();
    strs[n]=scopeStuff[$3]+strs[$3]+"\n"+strs[$1];
    int numbrackets=0;
    for(int i=0;i<strs[$3].size();i++) {
        if(strs[$3][i]=='}') {
            numbrackets--;
        }
        if(strs[$3][i]=='{') { 
            numbrackets++;
        }
    }
    for(int i=0;i<numbrackets;i++) {
        strs[n]=strs[n]+"\n}";
    }
    $$=n;
};
equation:
primary_expression inequality primary_expression {
    int n=strs.size();
    strs[n]="{\n"+scopeStuff[$1]+"IloExpr exp1(env);\nexp1=exp1+"+strs[$1]+";\n"+scopeStuff[$3]+"IloExpr exp2(env);\nexp2=exp2+"+strs[$3]+";\nmodel.add(exp1"+strs[$2]+"exp2);\n}";
    $$=n; 
}|
primary_expression EQ primary_expression {
    int n=strs.size();
    strs[n]="{\n"+scopeStuff[$1]+"IloExpr exp1(env);\nexp1=exp1+"+strs[$1]+";\n"+scopeStuff[$3]+"IloExpr exp2(env);\nexp2=exp2+"+strs[$3]+";\nmodel.add(exp1 == exp2);\n}";
    $$=n; 
};
inequality:
GT {
    int n=strs.size();
    strs[n]=">";
    $$=n;
}|
LT {
    int n=strs.size();
    strs[n]="<";
    $$=n;
}|
NE {
    int n=strs.size();
    strs[n]="!=";
    $$=n;
}|
LE{
    int n=strs.size();
    strs[n]="<=";
    $$=n;
}|
GE{
    int n=strs.size();
    strs[n]=">=";
    $$=n;
};
qualifiers:
qualifier {
    int n=strs.size();
    strs[n]=scopeStuff[$1]+strs[$1];
    $$=n;
}|
qualifiers CO qualifier {
    int n=strs.size();
    strs[n]=strs[$1]+"\n"+scopeStuff[$3]+strs[$3];
    $$=n;
};
qualifier:
VA inequality VA {
    int n=strs.size();
    strs[n]="if("+string($1)+strs[$2]+string($3)+") {";
    $$=n;
}|
VA SS primary_expression {
    string tv1="t"+convert(tempVar++);
    string tv2="t"+convert(tempVar++);
    int n=strs.size();
    declType[string($1)]="temporary";
    scopeStuff[n]=scopeStuff[$3]+"TYPE_"+tv1+"_ "+tv1+"=powerset("+strs[$3]+");\n"+tv1+".erase("+strs[$3]+");\n";
    setGraph[string($1)][strs[$3]]=0;
    setGraph[strs[$3]][string($1)]=0;
    setGraph[strs[$3]][tv2]=0;
    setGraph[tv2][strs[$3]]=0;
    setGraph[string($1)][tv2]=0;
    setGraph[tv2][string($1)]=0;
    setGraph[string($1)][tv1]=1;
    setGraph[strs[$3]][tv1]=1;
    setGraph[tv2][tv1]=1;
    strs[n]="for(TYPE_"+tv1+"_::iterator "+tv2+"="+tv1+".begin();"+tv2+"!="+tv1+".end();"+tv2+"++) {\nTYPE_"+string($1)+"_ "+string($1)+"=*"+tv2+";";
    $$=n;
}|
VA SE primary_expression {
    string tv1="t"+convert(tempVar++);
    string tv2="t"+convert(tempVar++);
    int n=strs.size();
    declType[string($1)]="temporary";
    scopeStuff[n]=scopeStuff[$3]+"TYPE_"+tv1+"_ "+tv1+"=powerset("+strs[$3]+");\n";
    setGraph[string($1)][strs[$3]]=0;
    setGraph[strs[$3]][string($1)]=0;
    setGraph[strs[$3]][tv2]=0;
    setGraph[tv2][strs[$3]]=0;
    setGraph[string($1)][tv2]=0;
    setGraph[tv2][string($1)]=0;
    setGraph[string($1)][tv1]=1;
    setGraph[strs[$3]][tv1]=1;
    setGraph[tv2][tv1]=1;
    strs[n]="for(TYPE_"+tv1+"_::iterator "+tv2+"="+tv1+".begin();"+tv2+"!="+tv1+".end();"+tv2+"++) {\nTYPE_"+string($1)+"_ "+string($1)+"=*"+tv2+";";
    $$=n;
}|
NU LE VA LE number_variable {
    declType[string($3)]="temporary";
    string tv="t"+convert(tempVar++);
    int n=strs.size();
    strs[n]="for(int "+string($3)+"="+string($1)+";"+string($3)+"<="+strs[$5]+";"+string($3)+"++) {";
    $$=n;
}|
VA IN primary_expression {
    declType[string($1)]="temporary";
    string tv="t"+convert(tempVar++);
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$3];
    setGraph[string($1)][strs[$3]]=1;
    strs[n]="for(TYPE_"+strs[$3]+"_::iterator "+tv+"="+strs[$3]+".begin();"+tv+"!="+strs[$3]+".end();"+tv+"++) {\nTYPE_"+string($1)+"_ "+string($1)+"=*"+tv+";";
    $$=n; 
};
number_variable:
VA {
    int n=strs.size();
    strs[n]=string($1);
    $$=n;
}|
NU {
    int n=strs.size();
    strs[n]=string($1);
    $$=n;
};
primary_expression:
expression {
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$1];
    strs[n]=strs[$1];
    $$=n;
}|
primary_expression SR expression {
    int n=strs.size();
    string tv="t"+convert(tempVar++);
    setGraph[tv][strs[$1]]=0;
    setGraph[strs[$1]][tv]=0;
    setGraph[strs[$3]][tv]=0;
    setGraph[tv][strs[$3]]=0;
    setGraph[strs[$1]][strs[$3]]=0;
    setGraph[strs[$3]][strs[$1]]=0;
    scopeStuff[n]=scopeStuff[$1]+scopeStuff[$3]+"TYPE_"+tv+"_ "+tv+"="+strs[$1]+";\nfor(TYPE_"+strs[$3]+"_::iterator iter="+strs[$3]+".begin();iter!="+strs[$3]+".end();iter++) {\n"+tv+".erase(*iter);\n}\n";
    strs[n]=tv;
    $$=n;
}|
primary_expression SU expression {
    int n=strs.size();
    string tv="t"+convert(tempVar++);
    setGraph[tv][strs[$1]]=0;
    setGraph[strs[$1]][tv]=0;
    setGraph[strs[$3]][tv]=0;
    setGraph[tv][strs[$3]]=0;
    setGraph[strs[$1]][strs[$3]]=0;
    setGraph[strs[$3]][strs[$1]]=0;
    scopeStuff[n]=scopeStuff[$1]+scopeStuff[$3]+"TYPE_"+tv+"_ "+tv+"="+strs[$1]+";\n"+tv+".insert("+strs[$3]+".begin(),"+strs[$3]+".end());\n";
    strs[n]=tv;
    $$=n;
}|
primary_expression SI expression {
    int n=strs.size();
    string tv="t"+convert(tempVar++);
    setGraph[tv][strs[$1]]=0;
    setGraph[strs[$1]][tv]=0;
    setGraph[strs[$3]][tv]=0;
    setGraph[tv][strs[$3]]=0;
    setGraph[strs[$1]][strs[$3]]=0;
    setGraph[strs[$3]][strs[$1]]=0;
    scopeStuff[n]=scopeStuff[$1]+scopeStuff[$3]+"TYPE_"+tv+"_ "+tv+";\nfor(TYPE_"+strs[$3]+"_::iterator iter="+strs[$3]+".begin();iter!="+strs[$3]+".end();iter++) {\nif("+strs[$1]+".count(*iter)) {\n"+tv+".insert(*iter);\n}\n}\n";
    strs[n]=tv;
    $$=n;
}|
primary_expression expression {
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$1]+scopeStuff[$2];
    strs[n]=strs[$1]+"*"+strs[$2];
    //type(strs[$2],"number");
    $$=n;
}|
primary_expression operator expression {
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$1]+scopeStuff[$3];
    strs[n]=strs[$1]+strs[$2]+strs[$3];
    $$=n;
};
expression:
sum {
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$1];
    strs[n]=strs[$1];
    $$=n;
}|
LI primary_expression LJ {
    int n=strs.size();
    weakSet.insert(strs[$2]);
    scopeStuff[n]=scopeStuff[$2];
    strs[n]=strs[$2]+".size()";
    setGraph[strs[$2]][strs[n]]=1;
    $$=n;
}|
FR LC primary_expression RC LC primary_expression RC {
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$3]+scopeStuff[$6];
    strs[n]="("+strs[$3]+"/"+strs[$6]+")";
    $$=n;
}|
LP primary_expression RP {
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$2];
    strs[n]="("+strs[$2]+")";
    $$=n;
}|
NU {
    int n=strs.size();
    strs[n]=string($1);
    $$=n;
}|
VA {
    int n=strs.size();
    strs[n]=string($1);
    if(declType[strs[n]]=="variable") {
        strs[n]+="_var";
    }
    varType[strs[n]]="number";
    $$=n;
}|
LR primary_expression RR {
    int n=strs.size();
    string tv="t"+convert(tempVar++);
    scopeStuff[n]=scopeStuff[$2];
    setGraph[strs[$2]][tv]=1;
    //varType[strs[$2]]="constant";
    scopeStuff[n]+="TYPE_"+tv+"_ "+tv+";\n"+tv+".insert("+strs[$2]+");\n";
    strs[n]=tv;
    $$=n;
}|
VA US LC indices RC {
    int n=strs.size();
    strs[n]=string($1);
    if(declType[strs[n]]=="variable") {
        strs[n]+="_var";
    }
    varType[strs[n]]="map";
    scopeStuff[n]=scopeStuff[$4];
    int i=0;
    list<string> vars;
    while(strs[$4].find("[",i)!=string::npos) {
        vars.push_back(strs[$4].substr(strs[$4].find("[",i)+1,strs[$4].find("]",i)-strs[$4].find("[",i)-1));
        i=strs[$4].find("[",i+1);
    }
    mapTypes[strs[n]].push_back(vars);
    strs[n]+=strs[$4];
    $$=n;
};
operator:
PL {
    int n=strs.size();
    strs[n]="+";
    $$=n;
}|
SB {
    int n=strs.size();
    strs[n]="-";
    $$=n;
}|
DI {
    int n=strs.size();
    strs[n]="/";
    $$=n;
}|
MU {
    int n=strs.size();
    strs[n]="*";
    $$=n;
};
indices:
expression {
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$1];
    strs[n]="["+strs[$1]+"]";
    $$=n;
}|
indices CO expression {
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$1]+scopeStuff[$3];
    strs[n]=strs[$1]+"["+strs[$3]+"]";
    $$=n;
};
sum:
sum_product sum_product_qualifiers LP primary_expression RP {
    int n=strs.size();
    string tv1="t"+convert(tempVar++);
    string tv2="t"+convert(tempVar++);
    scopeStuff[n]=scopeStuff[$2]+"IloExpr "+tv1+"(env);\n";
    if(strs[$1]=="*") {
        scopeStuff[n]+=tv1+"="+tv1+"+1;\n";
    }
    scopeStuff[n]+=strs[$2]+"\n"+scopeStuff[$4]+"IloExpr "+tv2+"(env);\n"+tv2+"="+tv2+"+"+strs[$4]+";\n"+tv1+"="+tv1+strs[$1]+tv2+";\n";
    int numbrackets=0;
    for(int i=0;i<strs[$2].size();i++) {
        if(strs[$2][i]=='}') {
            numbrackets--;
        }
        if(strs[$2][i]=='{') { 
            numbrackets++;
        }
    }
    for(int i=0;i<numbrackets;i++) {
        scopeStuff[n]=scopeStuff[n]+"}\n";
    }
    strs[n]=tv1;
    $$=n;
};
sum_product:
SM {
    int n=strs.size();
    strs[n]="+";
    $$=n;
}|
PR {
    int n=strs.size();
    strs[n]="*";
    $$=n;
};
sum_product_qualifiers:
US LC expression EQ expression RC CT LC expression RC {
    int n=strs.size();
    strs[n]="for(int "+strs[$3]+"="+strs[$5]+";"+strs[$3]+"<="+strs[$9]+";"+strs[$3]+"++) {";
    declType[strs[$3]]="temporary";
    $$=n;
}|
US LC qualifiers RC {
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$3];
    strs[n]=strs[$3];
    $$=n;
};

%%
string convert(int x) {
    stringstream ss;
    ss << x;
    return ss.str();
}
int tempVar=0;
string arguments="";
string declarations="";
set<string> intConstraints;
string expressionVar;
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
extern int yyparse();
extern "C" int yywrap();
map<int,string> strs;
string functionName;
map<string,int> declareMap;
void yyerror(const char *str) {
    cout << yylineno << ": " << str << " " << string(yytext) << endl;
    exit(1);
}
int yywrap() {
    return 1;
}
map<string,list<list<string> > > mapTypes;
map<int,string> scopeStuff;
map<string,string> declType;
map<string,string> varType;
map<string,map<string,int> > setGraph;
set<string> weakSet;
ofstream out;
string cppCode;
string hppCode;
string replaceAll(string a,string b,string c) {
    while(a.find(b)!=string::npos) {
        a=a.substr(0,a.find(b))+c+a.substr(a.find(b)+b.size());
    }
    return a;
}
bool quiet;
void badArgs() {
    cout << "Invalid arguments, correct usage:" << endl;
    cout << "mbolc [-v] [-p PARAM_FILE] INPUT_FILE OUTPUT_FILE" << endl;
    exit(1);
}
string paramFile;
void typeCheck(string var,string type,string decl) {
}
string indentCode(string code) {
    string indentedCode="";
    int depth=0;
    while(!code.empty()) {
        string line;
        line=code.substr(0,code.find("\n")+1);
        code=code.substr(code.find("\n")+1);
        if(line.find("}")!=string::npos) {
            depth--;
        }
        for(int j=0;j<depth;j++) {
            indentedCode+="    ";
        }
        indentedCode+=line;
        if(line.find("{")!=string::npos) {
            depth++;
        }
    }
    return indentedCode;
}
int main(int argc,char* argv[]) {
    bool inputRead=false;
    bool compile=false;
    quiet=false;
    string outputName;
    paramFile="";
    for(int i=1;i<argc;i++) {
        if(string(argv[i])=="-q") {
            quiet=true;
        } else if(string(argv[i])=="-c") {
            compile=true;
        } else if(string(argv[i])=="-p") {
            i++;
            if(i>=argc) {
                badArgs();
            }
            paramFile=string(argv[i]);
        } else if(!inputRead) {
            yyin=fopen(argv[i],"r");
            inputRead=true;
            string inputName=string(argv[i]);
            if(inputName.find(".")!=string::npos) {
                functionName=inputName.substr(0,inputName.find("."));
            } else {
                functionName=inputName;
            }
        } else {
            badArgs();
        }
    }
    
    if(!inputRead) {
        badArgs();
    }
    
    yyparse();
    fclose(yyin);
    
    out.open((functionName+".hpp").c_str());
    out << indentCode(hppCode);
    out << indentCode(cppCode);
    out.close();
    
    if(compile) {
    }    
}
