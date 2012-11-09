%{
    #include<sstream>
    #include<iostream>
    #include<fstream>
    #include<vector>
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<map>
    #include<set>
    #include<list>
    using namespace std;
%}
%token SM IN CO GE LE EQ US SI SU VA MA MI ST PL SB DI MU LC RC LP RP AA BB CC DD EL AN UN SR RR LR LI ZC SE CT SS FR PR GT LT NE LJ CN CL ES
%union {
    int ival;
    char* sval;
}
%token <sval> NU
%token <sval> VA
%type <ival> objective objective_type constraints constraint equation inequality qualifiers qualifier operator indices sum sum_product_qualifiers sum_product number_expression element_expression number_subexpression element_subexpression tuple_indices
%%
program:
AA objective constraints BB {
    
    // if a variable has no declare type, then it is a constant that must be provided by the user
    for(map<string,string>::iterator i=varType.begin();i!=varType.end();i++) {
        if(declType[i->first]=="") {
            setDeclType(i->first,"constant");
        }
    }
    
    // find basic elements which will be integers
    set<string> startNodes;
    for(map<string,string>::iterator i=varType.begin();i!=varType.end();i++) {
        if(i->second=="an element") {
            startNodes.insert(i->first);
        }
    }
    for(map<string,map<string,int> >::iterator i=setGraph.begin();i!=setGraph.end();i++) {
        for(map<string,int>::iterator j=i->second.begin();j!=i->second.end();j++) {
            startNodes.erase(j->first);
        }
    }
    
    // BFS search to figure out distance to each node which reveals its element type
    map<int,list<list<string> > > toVisit;
    set<string> visited;
    map<string,list<string> > foundPaths;
    for(set<string>::iterator i=startNodes.begin();i!=startNodes.end();i++) {
        list<string> temp;
        temp.push_back(*i);
        toVisit[0].push_back(temp);
    }
    while(!toVisit.empty()) {
        list<string> x=toVisit.begin()->second.front();
        int length=toVisit.begin()->first;
        toVisit.begin()->second.pop_front();
        while(!toVisit.empty()&&toVisit.begin()->second.empty()) {
            toVisit.erase(toVisit.begin());
        }
        string type="";
        if(tupleType.count(x.front())) {
            for(int i=0;i<length;i++) {
                type+="set<";
            }
            type+="TYPE_"+x.front()+"_";
            for(int i=0;i<length;i++) {
                type+=",set"+convert(i)+"comp_TYPE_"+x.front()+"_>";
            }
        } else {
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
        }
        if(visited.count(x.back())) {
            if(tupleType.count(x.front())==0&&type!=typeMap[x.back()]) {
                set<int> lines;
                string prev;
                prev="";
                for(list<string>::iterator i=x.begin();i!=x.end();i++) {
                    if(prev!="") {
                        lines.insert(setGraphReasoning[prev][*i]);
                    }
                    prev=*i;
                }
                prev="";
                for(list<string>::iterator i=foundPaths[x.back()].begin();i!=foundPaths[x.back()].end();i++) {
                    if(prev!="") {
                        lines.insert(setGraphReasoning[prev][*i]);
                    }
                    prev=*i;
                }
                cout << "ERROR: inconsistent types for element " << stripVar(x.back()) << " on line";
                if(lines.size()>1) {
                    cout << "s";
                }
                for(set<int>::iterator i=lines.begin();i!=lines.end();i++) {
                    cout << " " << *i;
                }
                cout << endl;
                exit(1);
            }
            continue;
        }
        foundPaths[x.back()]=x;
        typeMap[x.back()]=type;
        visited.insert(x.back());
        for(map<string,int>::iterator i=setGraph[x.back()].begin(); i!=setGraph[x.back()].end(); i++) {
            list<string> y=x;
            y.push_back(i->first);
            toVisit[length+i->second].push_back(y);
        }
    }
    
    for(map<string,vector<string> >::iterator i=tupleType.begin();i!=tupleType.end();i++) {
        string type="tuple";
        for(vector<string>::iterator j=i->second.begin();j!=i->second.end();j++) {
            if(typeMap[*j]=="int") {
                type+="_int";
            } else {
                type+="_set"+convert(countStr(typeMap[*j],"set<"));
            }
        }
        typeMap[i->first]=type;
    }
    
    // take care of simple variables
    for(map<string,string>::iterator i=varType.begin();i!=varType.end();i++) {
        if(i->second=="a number"&&!typeMap.count(i->first)) {
            if(declType[i->first]=="variable") {
                if(intConstraints.count(i->first)) {
                    typeMap[i->first]="MyIloIntVar";
                    typeMap["RET_"+i->first.substr(0,i->first.size()-4)]="int";
                } else {
                    //cout << i->first << endl;
                    typeMap[i->first]="MyIloNumVar";
                    typeMap["RET_"+i->first.substr(0,i->first.size()-4)]="double";
                }
            } else {
                typeMap[i->first]="double";
            }
        }
    }
    
    // setup constant ints with types
    /*for(map<string,string>::iterator i=varType.begin();i!=varType.end();i++) {
        if(i->second=="constant") {
            typeMap[i->first]="int";
        }
    }*/
    
    // get types of the map objects (real/integer variables in mathematical program)
    for(map<string,list<list<string> > >::iterator i=mapTypes.begin();i!=mapTypes.end();i++) {
        list<string> example=i->second.front();
        list<int>::iterator rs=mapTypeReasons[i->first].begin();
        for(list<list<string> >::iterator j=i->second.begin();j!=i->second.end();j++) {
            bool different=false;
            if(j->size()!=example.size()) {
                different=true;
            } else {
                list<string>::iterator kk=example.begin(); 
                for(list<string>::iterator k=j->begin();k!=j->end();k++) {
                    if(typeMap[*kk]!=typeMap[*k]) {
                        different=true;
                    }
                    kk++;
                }
            }
            if(different) {
                set<int> lines;
                lines.insert(mapTypeReasons[i->first].front());
                cout << "ERROR: inconsistent use of indices for "+stripVar(i->first)+" on line";
                int first=mapTypeReasons[i->first].front();
                if(*rs!=first) {
                    cout << "s " << first;
                }
                cout << " " << *rs << endl;
                exit(1);
            }
            rs++;
        }
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
    hppCode="#include<set>\n#include<map>\n#include<ilcplex/ilocplex.h>\n#include<mbol.hpp>\nusing namespace std;\n#ifndef MBOL_"+className+"\n#define MBOL_"+className+"\nclass "+className+" {\npublic:\nbool init();\nbool solve();\n"+className+"();\n~"+className+"();\nbool hasInitialized;\nIloCplex cplex;\nIloEnv env;\ndouble objValue;\nIloExpr objExp;\n";
    
    // create struct for returning variables 
    hppCode+="// Variable results\n";
    for(map<string,string>::iterator i=declType.begin();i!=declType.end();i++) {
        if(i->second=="variable") {
            string retName=i->first.substr(0,i->first.size()-4);
            hppCode+="TYPE_RET_"+retName+"_ "+retName+";\n";
        }
    }
    
    
    // making arguments which are constants in the program
    hppCode+="// Constants in the program that you must initialize\n";
    for(map<string,string>::iterator i=declType.begin();i!=declType.end();i++) {
        if(i->second=="constant") {
            hppCode+="TYPE_"+i->first+"_ "+i->first+";\n";
        }
    }
    
    // declare CPLEX variables (actual variables in program)
    hppCode+="// Variables used by the CPLEX program\n";
    for(map<string,string>::iterator i=declType.begin();i!=declType.end();i++) {
        if(i->second=="variable") {
            hppCode+="TYPE_"+i->first+"_ "+i->first+";\n";
        }
    }
    hppCode+="};\n#endif\n";
    cppCode=className+"::"+className+"() {\nhasInitialized=false;\n}\nbool "+className+"::init() {\n";
    cppCode+="IloModel model(env);\ng_env=env;\ntry {\n";
    
    
    // take care of simple variables
    for(map<string,string>::iterator i=declType.begin();i!=declType.end();i++) {
        if(varType[i->first]=="a number"&&i->second=="variable"&&mapTypes.count(i->first)==0) {
            if(intConstraints.count(i->first)) {
                cppCode+="MyIloIntVar";
            } else {
                cppCode+="MyIloNumVar";
            }
            cppCode+=" temp"+i->first+";\n"+i->first+"=temp"+i->first+";\n";
        }
    }
    
    // this contains most of the logic of the program
    cppCode+=declarations+strs[$2]+strs[$3];
    cppCode+="IloCplex tempCplex(model);\ncplex=tempCplex;\n";
    if(quiet) {
        cppCode+="cplex.setOut(env.getNullStream());\n";
    }
    cppCode+="}\ncatch(IloException& ex) {\ncout << ex << endl;\nreturn false;\n}\nhasInitialized=true;\nreturn true;\n}\nbool "+className+"::solve() {\nif(!hasInitialized) {\ninit();\n}\nif(!hasInitialized) {\nreturn false;\n}\ntry{\ncplex.solve();\nobjValue=cplex.getValue(objExp);\n";
    
    
    
    // fill in simple variable values
    for(map<string,string>::iterator i=declType.begin();i!=declType.end();i++) {
        if(i->second=="variable"&&varType[i->first]=="a number"&&mapTypes.count(i->first)==0) {
            cppCode+=i->first.substr(0,i->first.size()-4)+"=cplex.getValue("+i->first+");\n";
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
    cppCode+="} catch(IloException& ex) {\ncout << ex << endl;\nreturn false;\n}\nreturn true;\n}\n"+className+"::~"+className+"() {\nenv.end();\n}\n";
    
    // real types put in the cppCode
    for(map<string,string>::iterator i=typeMap.begin();i!=typeMap.end();i++) {
        hppCode=replaceAll(hppCode,"TYPE_"+i->first+"_",i->second);
        cppCode=replaceAll(cppCode,"TYPE_"+i->first+"_",i->second);
    }
};
objective:
objective_type LC program_variables RC LC number_expression RC {
    int n=strs.size();
    strs[n]="{\n"+scopeStuff[$6]+"IloExpr tempObjExp(env);\nobjExp=tempObjExp;\nobjExp=objExp+"+strs[$6]+";\n"+strs[$1]+"\n}\n";
    $$=n;
};
program_variables:
VA {
    setDeclType(string($1),"variable (return)");
    setDeclType(string($1)+"_var","variable");
}|
program_variables CO VA {
    setDeclType(string($3),"variable (return)");
    setDeclType(string($3)+"_var","variable");
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
    strs[n]=strs[$1]+strs[$4];
    $$=n;
};
constraint:
equation {
    int n=strs.size();
    strs[n]="// Line "+convert(yylineno)+" of optimization program\n{\n"+strs[$1]+"\n}\n";
    $$=n;
}|
VA IN ZC {
    intConstraints.insert(string($1)+"_var");
}|
equation CO qualifiers {
    int n=strs.size();
    strs[n]="// Line "+convert(yylineno)+" of optimization program\n"+scopeStuff[$3]+strs[$3]+"\n"+strs[$1];
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
    strs[n]+="\n";
    $$=n;
};
equation:
number_expression inequality number_expression {
    int n=strs.size();
    strs[n]=scopeStuff[$1]+"IloExpr expLHS(env);\nexpLHS=expLHS+"+strs[$1]+";\n"+scopeStuff[$3]+"IloExpr expRHS(env);\nexpRHS=expRHS+"+strs[$3]+";\nmodel.add(expLHS"+strs[$2]+"expRHS);";
    $$=n; 
}|
number_expression EQ number_expression {
    int n=strs.size();
    strs[n]=scopeStuff[$1]+"IloExpr expLHS(env);\nexpLHS=expLHS+"+strs[$1]+";\n"+scopeStuff[$3]+"IloExpr expRHS(env);\nexpRHS=expRHS+"+strs[$3]+";\nmodel.add(expLHS == expRHS);";
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
tuple_indices:
VA {
    int n=strs.size();
    tupleHolder[n].push_back(string($1));
    $$=n;
}|
tuple_indices CO VA {
    int n=strs.size();
    tupleHolder[n]=tupleHolder[$1];
    tupleHolder[n].push_back(string($3));
    $$=n;
};
qualifier:
LP tuple_indices RP IN element_expression {
    int n=strs.size();
    string tv=tempElement();
    scopeStuff[n]=scopeStuff[$5];
    setGraphEdge(tv,strs[$5],1);
    strs[n]="for(TYPE_"+strs[$5]+"_::iterator "+tv+"="+strs[$5]+".begin();"+tv+"!="+strs[$5]+".end();"+tv+"++) {";
    for(int i=0;i<tupleHolder[$2].size();i++) {
        strs[n]+="\nTYPE_"+tupleHolder[$2][i]+"_ "+tupleHolder[$2][i]+"="+tv+"->e"+convert(i)+";";
        setDeclType(tupleHolder[$2][i],"temporary");
    }
    tupleType[tv]=tupleHolder[$2];
    $$=n;
}|
ES EQ element_expression {
    int n=strs.size();
    strs[n]="if("+strs[$3]+".empty()) {";
    $$=n;
}|
ES NE element_expression {
    int n=strs.size();
    strs[n]="if(!"+strs[$3]+".empty()) {";
    $$=n;
}|
VA EQ VA {
    int n=strs.size();
    strs[n]="if("+string($1)+"=="+string($3)+") {";
    $$=n;
}|
VA inequality VA {
    int n=strs.size();
    strs[n]="if("+string($1)+strs[$2]+string($3)+") {";
    $$=n;
}|
VA SS element_expression {
    string tv1=tempElement();
    string tv2=tempElement();
    int n=strs.size();
    setVarType(string($1),"an element");
    setDeclType(string($1),"temporary");
    scopeStuff[n]=scopeStuff[$3]+"TYPE_"+tv1+"_ "+tv1+"=powerset("+strs[$3]+");\n"+tv1+".erase("+strs[$3]+");\n";
    setGraphTriple(strs[$3],tv2,string($1));
    setGraphEdge(string($1),tv1,1);
    setGraphEdge(strs[$3],tv1,1);
    setGraphEdge(tv2,tv1,1);
    strs[n]="for(TYPE_"+tv1+"_::iterator "+tv2+"="+tv1+".begin();"+tv2+"!="+tv1+".end();"+tv2+"++) {\nTYPE_"+string($1)+"_ "+string($1)+"=*"+tv2+";";
    $$=n;
}|
VA SE element_expression {
    string tv1=tempElement();
    string tv2=tempElement();
    int n=strs.size();
    setVarType(string($1),"an element");
    setDeclType(string($1),"temporary");
    scopeStuff[n]=scopeStuff[$3]+"TYPE_"+tv1+"_ "+tv1+"=powerset("+strs[$3]+");\n";
    setGraphTriple(strs[$3],tv2,string($1));
    setGraphEdge(string($1),tv1,1);
    setGraphEdge(strs[$3],tv1,1);
    setGraphEdge(tv2,tv1,1);
    strs[n]="for(TYPE_"+tv1+"_::iterator "+tv2+"="+tv1+".begin();"+tv2+"!="+tv1+".end();"+tv2+"++) {\nTYPE_"+string($1)+"_ "+string($1)+"=*"+tv2+";";
    $$=n;
}|
NU LE VA LE number_expression {
    //    setDeclType(string($3),"temporary");
    //    setVarType(string($3),"an element");
    setGraph[string($3)];
    int n=strs.size();
    strs[n]="for(int "+string($3)+"="+string($1)+";"+string($3)+"<="+strs[$5]+";"+string($3)+"++) {";
    $$=n;
}|
VA IN element_expression {
    setDeclType(string($1),"temporary");
    setVarType(string($1),"an element");
    string tv=tempExp();
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$3];
    setGraphEdge(string($1),strs[$3],1);
    strs[n]="for(TYPE_"+strs[$3]+"_::iterator "+tv+"="+strs[$3]+".begin();"+tv+"!="+strs[$3]+".end();"+tv+"++) {\nTYPE_"+string($1)+"_ "+string($1)+"=*"+tv+";";
    $$=n; 
};
element_expression:
element_subexpression {
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$1];
    strs[n]=strs[$1];
    $$=n;
}|
element_expression SR element_subexpression {
    int n=strs.size();
    string tv=tempElement();
    setGraphTriple(tv,strs[$1],strs[$3]);
    scopeStuff[n]=scopeStuff[$1]+scopeStuff[$3]+"TYPE_"+tv+"_ "+tv+"="+strs[$1]+";\nfor(TYPE_"+strs[$3]+"_::iterator iter="+strs[$3]+".begin();iter!="+strs[$3]+".end();iter++) {\n"+tv+".erase(*iter);\n}\n";
    strs[n]=tv;
    $$=n;
}|
element_expression SU element_subexpression {
    int n=strs.size();
    string tv=tempElement();;
    setGraphTriple(tv,strs[$1],strs[$3]);
    scopeStuff[n]=scopeStuff[$1]+scopeStuff[$3]+"TYPE_"+tv+"_ "+tv+"="+strs[$1]+";\n"+tv+".insert("+strs[$3]+".begin(),"+strs[$3]+".end());\n";
    strs[n]=tv;
    $$=n;
}|
element_expression SI element_subexpression {
    int n=strs.size();
    string tv=tempElement();
    setGraphTriple(tv,strs[$1],strs[$3]);
    scopeStuff[n]=scopeStuff[$1]+scopeStuff[$3]+"TYPE_"+tv+"_ "+tv+";\nfor(TYPE_"+strs[$3]+"_::iterator iter="+strs[$3]+".begin();iter!="+strs[$3]+".end();iter++) {\nif("+strs[$1]+".count(*iter)) {\n"+tv+".insert(*iter);\n}\n}\n";
    strs[n]=tv;
    $$=n;
};
number_expression:
number_subexpression {
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$1];
    strs[n]=strs[$1];
    $$=n;
}|
number_expression number_subexpression {
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$1]+scopeStuff[$2];
    strs[n]=strs[$1]+"*"+strs[$2];
    //type(strs[$2],"number");
    $$=n;
}|
number_expression operator number_subexpression {
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$1]+scopeStuff[$3];
    strs[n]=strs[$1]+strs[$2]+strs[$3];
    $$=n;
};
element_subexpression:
LR VA CL qualifiers RR {
    int n=strs.size();
    string tv=tempElement();
    scopeStuff[n]="TYPE_"+tv+"_ "+tv+";\n"+strs[$4]+"\n"+tv+".insert("+string($2)+");";
    setDeclType(string($2),"temporary");
    setVarType(string($2),"an element");
    setGraphEdge(string($2),tv,1);
    int numbrackets=0;
    for(int i=0;i<scopeStuff[n].size();i++) {
        if(scopeStuff[n][i]=='}') {
            numbrackets--;
        }
        if(scopeStuff[n][i]=='{') { 
            numbrackets++;
        }
    }
    for(int i=0;i<numbrackets;i++) {
        scopeStuff[n]=scopeStuff[n]+"\n}";
    }
    scopeStuff[n]+="\n";
    strs[n]=tv;
    $$=n;
}|
LR element_expression RR {
    int n=strs.size();
    string tv=tempElement();
    scopeStuff[n]=scopeStuff[$2];
    setGraphEdge(strs[$2],tv,1);
    scopeStuff[n]+="TYPE_"+tv+"_ "+tv+";\n"+tv+".insert("+strs[$2]+");\n";
    strs[n]=tv;
    $$=n;
}|
LP element_expression RP {
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$2];
    strs[n]="("+strs[$2]+")";
    $$=n;
}|
VA {
    int n=strs.size();
    strs[n]=string($1);
    setVarType(strs[n],"an element");
    setGraph[string($1)]; 
    $$=n;
};
number_subexpression:
sum {
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$1];
    strs[n]=strs[$1];
    $$=n;
}|
LI element_expression LJ {
    int n=strs.size();
    weakSet.insert(strs[$2]);
    scopeStuff[n]=scopeStuff[$2];
    strs[n]=strs[$2]+".size()";
    setGraphEdge(strs[$2],strs[n],1);
    $$=n;
}|
LP number_expression RP CT LC number_expression RC {
    int n=strs.size();
    string tv1=tempExp();
    string tv2=tempExp();
    string tv3=tempExp();
    scopeStuff[n]=scopeStuff[$2]+scopeStuff[$6]+"double "+tv1+"="+strs[$2]+";\ndouble "+tv2+"="+strs[$6]+";\ndouble "+tv3+"=pow("+tv1+","+tv2+");\n";
    strs[n]=tv3;
    $$=n;
}|
FR LC number_expression RC LC number_expression RC {
    int n=strs.size();
    string tv1=tempExp();
    string tv2=tempExp();
    string tv3=tempExp();
    scopeStuff[n]=scopeStuff[$3]+scopeStuff[$6]+"IloExpr "+tv1+"(env);\n"+tv1+"="+tv1+"+"+strs[$3]+";\nIloExpr "+tv2+"(env);\n"+tv2+"="+tv2+"+"+strs[$6]+";\nIloExpr "+tv3+"(env);\n"+tv3+"="+tv3+"+"+tv1+"/"+tv2+";\n";
    strs[n]=tv3;
    $$=n;
}|
LP number_expression RP {
    int n=strs.size();
    string tv=tempExp();
    scopeStuff[n]=scopeStuff[$2];
    scopeStuff[n]+="IloExpr "+tv+"(env);\n"+tv+"="+tv+"+"+strs[$2]+";\n";
    strs[n]=tv;
    $$=n;
}|
NU {
    int n=strs.size();
    strs[n]=string($1);
    //    setVarType(strs[n],"a number");
    $$=n;
}|
VA {
    int n=strs.size();
    strs[n]=string($1);
    if(declType[strs[n]]=="variable (return)") {
        strs[n]+="_var";
    }
    setVarType(strs[n],"a number");
    $$=n;
}|
VA US LC indices RC {
    int n=strs.size();
    strs[n]=string($1);
    if(declType[strs[n]]=="variable (return)") {
        strs[n]+="_var";
    }
    setVarType(strs[n],"a number");
    scopeStuff[n]=scopeStuff[$4];
    int i=0;
    list<string> vars;
    while(strs[$4].find("[",i)!=string::npos) {
        vars.push_back(strs[$4].substr(strs[$4].find("[",i)+1,strs[$4].find("]",i)-strs[$4].find("[",i)-1));
        i=strs[$4].find("[",i+1);
    }
    mapTypes[strs[n]].push_back(vars);
    mapTypeReasons[strs[n]].push_back(yylineno);
    strs[n]+=strs[$4];
    $$=n;
}|
VA US element_expression {
    int n=strs.size();
    strs[n]=string($1);
    if(declType[strs[n]]=="variable (return)") {
        strs[n]+="_var";
    }
    setVarType(strs[n],"a number");
    scopeStuff[n]=scopeStuff[$3];
    int i=0;
    list<string> vars;
    vars.push_back(strs[$3]);
    mapTypes[strs[n]].push_back(vars);
    mapTypeReasons[strs[n]].push_back(yylineno);
    strs[n]+="["+strs[$3]+"]";
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
element_expression {
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$1];
    strs[n]="["+strs[$1]+"]";
    $$=n;
}|
indices CO element_expression {
    int n=strs.size();
    scopeStuff[n]=scopeStuff[$1]+scopeStuff[$3];
    strs[n]=strs[$1]+"["+strs[$3]+"]";
    $$=n;
};
sum:
sum_product sum_product_qualifiers LP number_expression RP {
    int n=strs.size();
    string tv1=tempExp();
    string tv2=tempExp();
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
US LC VA EQ NU RC CT LC number_subexpression RC {
    int n=strs.size();
    typeMap[string($3)]="int";
    strs[n]="for(int "+string($3)+"="+string($5)+";"+string($3)+"<="+strs[$9]+";"+string($3)+"++) {";
    setDeclType(string($3),"temporary");
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
string className;
map<string,int> declareMap;
void yyerror(const char *str) {
    cout << "ERROR: " << str << " for token " << string(yytext) << " on line " << yylineno << endl;
    exit(1);
}
int yywrap() {
    return 1;
}
map<string,list<int> > mapTypeReasons;
map<string,list<list<string> > > mapTypes;
map<int,string> scopeStuff;
map<string,int> varReason;
map<string,int> declReason;
map<string,string> declType;
map<string,string> varType;
map<int,vector<string> > tupleHolder;
string tempExp() {
    string tv="t"+convert(tempVar++);
    return tv;
}
map<string,vector<string> > tupleType;
map<string,map<string,int> > setGraphReasoning;
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
int countStr(string a,string b) {
    int x=0;
    while(a.find(b)!=string::npos) {
        x++;
        a=a.substr(0,a.find(b))+a.substr(a.find(b)+b.size());
    }
    return x;
}
map<string,string> typeMap;
bool quiet;
map<string,string> options;
void usage() {
    cout << "Usage: mbolc [options] input_file" << endl;
    cout << "Options:" << endl;
    int msize=0;
    for(map<string,string>::iterator i=options.begin();i!=options.end();i++) {
        if(i->first.size()>msize) {
            msize=i->first.size();
        }
    }
    for(map<string,string>::iterator i=options.begin();i!=options.end();i++) {
        cout << "  " << i->first;
        for(int j=0;j<msize+2-i->first.size();j++) {
            cout << " ";
        }
        cout << i->second << endl;
    }
}
void version() {
    cout << "MBOLC Version 0.2.0" << endl;
    exit(0);
}
void help() {
    usage();
    exit(0);
}
void badArgs() {
    cout << "Invalid arguments, correct usage:" << endl;
    usage();
    exit(1);
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
string stripVar(string a) {
    return replaceAll(a,"_var","");
}
void setVarType(string name,string type) {
    if(varType[name]=="") {
        varType[name]=type;
        varReason[name]=yylineno;
    } else if(varType[name]!=type) {
        cout << "ERROR: inconsistent type for " << stripVar(name) << " as it is " << varType[name] << " on line " << varReason[name] << " and " << type << " on line " << yylineno << endl;
        exit(1);
    }
}
void setDeclType(string name,string type) {
    if(declType[name]=="") {
        declType[name]=type;
        declReason[name]=yylineno;
    } else if(declType[name]!=type) {
        cout << "ERROR: inconsistent usage for " << stripVar(name) << " as it is " << declType[name] << " on line " << declReason[name] << " and " << type << " on line " << yylineno << endl;
        exit(1);
    }
}
void setGraphEdge(string a,string b,int c) {
    if(setGraph[a].count(b)) {
        if(setGraph[a][b]!=c) {
            cout << "ERROR: contradicting relationships between elements "+stripVar(a)+" and "+stripVar(b)+" on line";
            if(setGraphReasoning[a][b]!=yylineno) {
                cout << "s " << setGraphReasoning[a][b];
            }
            cout << " " << yylineno << endl;
            exit(1);
        }
    } else {
        setGraph[a][b]=c;
        setGraphReasoning[a][b]=yylineno;
    }
}
void setGraphTriple(string a,string b,string c) {
    setGraphEdge(a,b,0);
    setGraphEdge(b,a,0);
    setGraphEdge(b,c,0);
    setGraphEdge(c,b,0);
    setGraphEdge(a,c,0);
    setGraphEdge(c,a,0);
}
string tempElement() {
    string tv="t"+convert(tempVar++);
    setDeclType(tv,"temporary");
    setVarType(tv,"an element");
    return tv;
}
int main(int argc,char* argv[]) {
    bool inputRead=false;
    quiet=false;
    string outputName;
    bool customClassName=false;
    options["-v"]="Print version information and exit";
    options["-h"]="Print help information and exit";
    options["-q"]="Put CPLEX in quiet mode";
    options["-o <arg>"]="Use <arg> as output class which makes output file <arg>.hpp";
    for(int i=1;i<argc;i++) {
        if(string(argv[i])=="-q") {
            quiet=true;
        } else if(string(argv[i])=="-v") {
            version();
        } else if(string(argv[i])=="-h") {
            help();
        } else if(string(argv[i])=="-o") {
            i++;
            if(i<argc) {
                customClassName=true;
                className=string(argv[i]);
            } else {
                badArgs();
            }
        } else if(!inputRead) {
            yyin=fopen(argv[i],"r");
            inputRead=true;
            string inputName=string(argv[i]);
            if(!customClassName) {
                if(inputName.find(".")!=string::npos) {
                    className=inputName.substr(0,inputName.find("."));
                } else {
                    className=inputName;
                }
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
    
    out.open((className+".hpp").c_str());
    out << indentCode(hppCode);
    out << indentCode(cppCode);
    out.close();
}
