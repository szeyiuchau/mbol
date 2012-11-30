%{
    #include<visitors.hpp>
    #include<utilities.hpp>
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
    #include<classes.hpp>
    using namespace std;
%}
%token SM IN CO GE LE EQ US SI SU VA MA MI ST PL SB DI MU LC RC LP RP AA BB CC DD EL AN UN SR RR LR LI ZC SE CT SS FR GT LT NE LJ CN CL ES
%union {
    int ival;
    char* sval;
    Objective* objectiveVal;
    ObjectiveType* objectiveTypeVal;
    Constraints* constraintsVal;
    Constraint* constraintVal;
    Equation* equationVal;
    Inequality* inequalityVal;
    Qualifiers* qualifiersVal;
    Qualifier* qualifierVal;
    NumberOperator* numberOperatorVal;
    Indices* indicesVal;
    Sum* sumVal;
    SumQualifiers* sumQualifiersVal;
    NumberExpression* numberExpressionVal;
    ElementExpression* elementExpressionVal;
    NumberSubexpression* numberSubexpressionVal;
    ProgramVariables* programVariablesVal;
    ElementSubexpression* elementSubexpressionVal;
    TupleIndices* tupleIndicesVal;
    Program* programVal;
}
%token <sval> NU SM
%token <sval> VA
%type <objectiveVal> objective
%type <constraintsVal> constraints
%type <programVal> program
%type <constraintVal> constraint
%type <programVariablesVal> program_variables
%type <equationVal> equation
%type <inequalityVal> inequality
%type <qualifiersVal> qualifiers
%type <qualifierVal> qualifier
%type <numberOperatorVal> number_operator
%type <indicesVal> indices
%type <sumVal> sum
%type <sumQualifiersVal> sum_qualifiers
%type <numberExpressionVal> number_expression
%type <elementExpressionVal> element_expression
%type <numberSubexpressionVal> number_subexpression
%type <elementSubexpressionVal> element_subexpression
%type <tupleIndicesVal> tuple_indices
%type <objectiveTypeVal> objective_type
%%
program:
AA objective constraints BB {
    program=new Program($2,$3);
    $$=program;
};
objective:
objective_type LC program_variables RC LC number_expression RC {
    $$=new Objective($1,$3,$6);
};
program_variables:
VA {
    $$=new ProgramVariables(string($1));
}|
program_variables CO VA {
    $1->variables.push_back(string($3));
};
objective_type:
MA {
    $$=new ObjectiveType("max");
}|
MI {
    $$=new ObjectiveType("min");
};
constraints:
CN LC constraint RC {
    $$=new Constraints($3);
}|
constraints CN LC constraint RC {
    $1->constraints.push_back($4);
};
constraint:
equation {
    $$=new Constraint($1);
}|
VA IN ZC {
    $$=new Constraint(string($1));
}|
equation CO qualifiers {
    $$=new Constraint($1,$3);
};
equation:
number_expression inequality number_expression {
    $$=new Equation($1,$2,$3);
}|
number_expression EQ number_expression {
    $$=new Equation($1,new Inequality("=="),$3);
};
inequality:
GT {
    $$=new Inequality(">");
}|
LT {
    $$=new Inequality("<");
}|
NE {
    $$=new Inequality("!=");
}|
LE{
    $$=new Inequality("<=");
}|
GE{
    $$=new Inequality(">=");
};
qualifiers:
qualifier {
    $$=new Qualifiers($1);
}|
qualifiers CO qualifier {
    $1->qualifiers.push_back($3);
};
tuple_indices:
VA CO VA {
    $$=new TupleIndices($1,$3);
}|
tuple_indices CO VA {
    $1->indices.push_back(string($3));
};
qualifier:
LP tuple_indices RP IN element_expression {
    $$=new Qualifier($2,$5);
}|
ES EQ element_expression {
    $$=new Qualifier(new Equation(new NumberExpression(new NumberSubexpression(new NumberLiteral("0"))),new Inequality("=="),new NumberExpression(new NumberSubexpression(new SetSize($3)))));
}|
ES NE element_expression {
    $$=new Qualifier(new Equation(new NumberExpression(new NumberSubexpression(new NumberLiteral("0"))),new Inequality("!="),new NumberExpression(new NumberSubexpression(new SetSize($3)))));
}|
VA EQ VA {
    $$=new Qualifier(new Equation(new NumberExpression(new NumberSubexpression(new NumberVariable($1))),new Inequality("=="),new NumberExpression(new NumberSubexpression(new NumberVariable($3)))));
}|
VA inequality VA {
    $$=new Qualifier(new Equation(new NumberExpression(new NumberSubexpression(new NumberVariable($1))),$2,new NumberExpression(new NumberSubexpression(new NumberVariable($3)))));
}|
VA SS element_expression {
    $$=new Qualifier(string($1),"subset",$3);
}|
VA SE element_expression {
    $$=new Qualifier(string($1),"subsetequal",$3);
}|
NU LE VA LE element_expression {
    $$=new Qualifier(string($3),"in",new ElementExpression(new ElementSubexpression(new ElementNumbers(string($1),$5))));
}|
NU LE VA LE NU {
    $$=new Qualifier(string($3),"in",new ElementExpression(new ElementSubexpression(new ElementNumbers(string($1),string($5)))));
}|
VA IN element_expression {
    $$=new Qualifier(string($1),"in",$3);
};
element_expression:
element_subexpression {
    $$=new ElementExpression($1);
}|
element_expression SR element_subexpression {
    $$=new ElementExpression($1,new ElementOperator("reduce"),$3);
}|
element_expression SU element_subexpression {
    $$=new ElementExpression($1,new ElementOperator("union"),$3);
}|
element_expression SI element_subexpression {
    $$=new ElementExpression($1,new ElementOperator("intersect"),$3);
};
number_expression:
number_subexpression {
    $$=new NumberExpression($1);
}|
number_expression number_subexpression {
    $1->numberSubexpressions.push_back($2);
    $1->numberOperators.push_back(new NumberOperator("*"));
}|
number_expression number_operator number_subexpression {
    $1->numberSubexpressions.push_back($3);
    $1->numberOperators.push_back($2);
};
element_subexpression:
LR VA CL qualifiers RR {
    $$=new ElementSubexpression(new SetCreator(string($2),$4));
}|
LR element_expression RR {
    $$=new ElementSubexpression(new ElementSet($2));
}|
LP element_expression RP {
    $$=new ElementSubexpression(new ElementParantheses($2));
}|
VA {
    $$=new ElementSubexpression(new ElementVariable(string($1)));
};
number_subexpression:
sum {
    $$=new NumberSubexpression($1);
}|
LI element_expression LJ {
    $$=new NumberSubexpression(new SetSize($2));
}|
LP number_expression RP CT LC number_expression RC {
    /*    
    int n=strs.size();
    string tv1=tempExp();
    string tv2=tempExp();
    string tv3=tempExp();
    scopeStuff[n]=scopeStuff[$2]+scopeStuff[$6]+"double "+tv1+"="+strs[$2]+";\ndouble "+tv2+"="+strs[$6]+";\ndouble "+tv3+"=pow("+tv1+","+tv2+");\n";
    strs[n]=tv3;
    $$=n;*/
}|
FR LC number_expression RC LC number_expression RC {
    $$=new NumberSubexpression(new Fraction($3,$6));
}|
LP number_expression RP {
    $$=new NumberSubexpression(new NumberParantheses($2));
}|
NU {
    $$=new NumberSubexpression(new NumberLiteral(string($1)));
}|
VA {
    $$=new NumberSubexpression(new NumberVariable(string($1)));
}|
VA US LC indices RC {
    $$=new NumberSubexpression(new VariableMap(string($1),$4));
}|
VA US VA {
    $$=new NumberSubexpression(new VariableMap(string($1),string($3)));
};
number_operator:
PL {
    $$=new NumberOperator("+");
}|
SB {
    $$=new NumberOperator("-");
}|
DI {
    $$=new NumberOperator("/");
}|
MU {
    $$=new NumberOperator("*");
};
indices:
element_expression {
    $$=new Indices($1);
}|
indices CO element_expression {
    $1->elementExpressions.push_back($3);
};
sum:
SM sum_qualifiers LP number_expression RP {
    $$=new Sum(string($1),$2,$4);
};
sum_qualifiers:
US LC VA EQ NU RC CT LC element_expression RC {
    $$=new SumQualifiers(string($3),string($5),$9);
}|
US LC VA EQ NU RC CT LC NU RC {
    $$=new SumQualifiers(string($3),string($5),string($9));
}|
US LC qualifiers RC {
    $$=new SumQualifiers($3);
};

%%
Program* program;
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
extern int yyparse();
extern "C" int yywrap();
void yyerror(const char *str) {
    cout << "ERROR: " << str << " for token " << string(yytext) << " on line " << yylineno << endl;
    exit(1);
}
int yywrap() {
    return 1;
}
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
    cout << "MBOLC Version 0.3.0" << endl;
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
int main(int argc,char* argv[]) {
    bool inputRead=false;
    quiet=false;
    string outputName,inputName;
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
                outputName=string(argv[i]);
            } else {
                badArgs();
            }
        } else if(!inputRead) {
            inputRead=true;
            inputName=string(argv[i]);
            if(!customClassName) {
                if(inputName.find(".")!=string::npos) {
                    outputName=inputName.substr(0,inputName.find("."))+".hpp";
                } else {
                    outputName=inputName+".hpp";
                }
            }
        } else {
            badArgs();
        }
    }
    
    string className=outputName.substr(0,outputName.find("."));
    if(className.find("/")!=string::npos) {
        className=className.substr(className.rfind("/")+1);
    }
    yyin=fopen(inputName.c_str(),"r");
    string code;    
    yyparse();
    map<string,Type*> types;
    {
        MbolElementVisitor* v=new MbolElementVisitorTypeHelper();
        program->accept(*v);
        types=((MbolElementVisitorTypeHelper*)v)->types;
    }
    {
        MbolElementVisitor* v=new MbolElementVisitorCPLEX(types,quiet,className);
        program->accept(*v);
        code=indentCode(((MbolElementVisitorCPLEX*)v)->code);
    }
    
    if(!inputRead) {
        badArgs();
    }
    
    fclose(yyin);
    
    ofstream out((outputName).c_str());
    out << code;
    out.close();
}
