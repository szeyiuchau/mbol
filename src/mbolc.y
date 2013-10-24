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
%token SM IN CO GE LE EQ US SI SU VA MA MI ST PL SB DI MU LC RC LP RP AA BB CC DD EL AN UN SR RR LR LI ZC SE CT SS FR GT LT NE LJ CN CL ES IC MC LS RS BI
%union {
  int ival;
  char* sval;
  Objective* objectiveVal;
  ObjectiveType* objectiveTypeVal;
  Constraints* constraintsVal;
  Constraints* binaryConstraintVal;
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
  VariableMap* variableMap;
  ProgramVariables* programVariablesVal;
  NumberSubexpression* numberSubexpressionVal;
  ElementSubexpression* elementSubexpressionVal;
  TupleIndices* tupleIndicesVal;
  Program* programVal;
}
%token <sval> NU SM
%token <sval> VA
%type <objectiveVal> objective
%type <binaryConstraintVal> binary_constraint
%type <variableMap> variable_map;
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
binary_constraint {
  $$=$1;
}|
constraint {
  $$=new Constraints($1);
}|
constraints constraint {
  $1->constraints.push_back($2);
}|
constraints binary_constraint {
  for(list<Constraint*>::iterator i=$2->constraints.begin();i!=$2->constraints.end();i++) {
    $1->constraints.push_back(*i);
  }
};
binary_constraint:
CN LS qualifiers RS LC variable_map IN BI RC {
  $$=new Constraints(new Constraint($6->variableName));
  $$->constraints.push_back(new Constraint(new Equation(new NumberExpression($6),new Inequality("<="),new NumberExpression(new NumberLiteral("1"))),new Equation(new NumberExpression($6),new Inequality(">="),new NumberExpression(new NumberLiteral("0"))),$3));
};
constraint:
CN LC equation RC {
  $$=new Constraint($3);
}|
CN LC variable_map IN ZC RC {
  $$=new Constraint($3->variableName);
}|
CN LS qualifiers RS LC equation RC {
  $$=new Constraint($6,$3);
}|
CN LS qualifiers RS LC variable_map IN ZC RC {
  $$=new Constraint($6->variableName);
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
  $$=new Qualifier("0",new Inequality("=="),new SetSize($3));
}|
ES NE element_expression {
  $$=new Qualifier("0",new Inequality("!="),new SetSize($3));
}|
VA EQ VA {
  $$=new Qualifier(string($1),new Inequality("=="),string($3));
}|
VA inequality VA {
  $$=new Qualifier(string($1),$2,string($3));
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
VA EQ NU DD element_expression {
  $$=new Qualifier(string($1),"in",new ElementExpression(new ElementSubexpression(new ElementNumbers(string($3),$5))));
}|
NU LE VA LE NU {
  $$=new Qualifier(string($3),"in",new ElementExpression(new ElementSubexpression(new ElementNumbers(string($1),string($5)))));
}|
VA EQ NU DD NU {
  $$=new Qualifier(string($1),"in",new ElementExpression(new ElementSubexpression(new ElementNumbers(string($3),string($5)))));
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
  $$=$1;
}|
LI element_expression LJ {
  $$=new SetSize($2);
}|
LP number_expression RP CT LC number_expression RC {
  $$=new NumberPower($2,$6);
}|
FR LC number_expression RC LC number_expression RC {
  $$=new Fraction($3,$6);
}|
LP number_expression RP {
  $$=new NumberParantheses($2);
}|
NU {
  $$=new NumberLiteral(string($1));
}|
variable_map {
  $$=$1;
};
variable_map:
VA {
  $$=new VariableMap(string($1));
}|
VA US LC indices RC {
  $$=new VariableMap(string($1),$4);
}|
VA US VA {
  $$=new VariableMap(string($1),string($3));
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
SM sum_qualifiers number_expression {
  $$=new Sum(string($1),$2,$3);
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
      indentedCode+="  ";
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
  string inputName;
  string outputDirectory="./";
  string className;
  bool hpp=false;
  bool bin=false;
  bool pdf=false;
  bool typ=false;
  bool cpx=false;
  options["-v"]="Print version information and exit";
  options["-h"]="Print help information and exit";
  options["-q"]="Put CPLEX in quiet mode";
  options["-d <arg>"]="Use <arg> as output directory";
  options["-typ"]="Print types inferred by mbolc";
  options["-bin"]="Compile a binary for default file I/O";
  options["-pdf"]="Compile a pdf of the program";
  options["-hpp"]="Compile a hpp header of the program";
  options["-cpx"]="User CPLEX as solver (COIN-OR symphony is deafult)";
  for(int i=1;i<argc;i++) {
    if(string(argv[i])=="-q") {
      quiet=true;
    } else if(string(argv[i])=="-v") {
      version();
    } else if(string(argv[i])=="-h") {
      help();
    } else if(string(argv[i])=="-cpx") {
      cpx=true;
    } else if(string(argv[i])=="-typ") {
      typ=true;
    } else if(string(argv[i])=="-pdf") {
      pdf=true;
    } else if(string(argv[i])=="-bin") {
      bin=true;
    } else if(string(argv[i])=="-hpp") {
      hpp=true;
    } else if(string(argv[i])=="-d") {
      i++;
      if(i<argc) {
        outputDirectory=string(argv[i]);
        if(outputDirectory[outputDirectory.size()-1]!='/') {
          outputDirectory+="/";
        }
      } else {
        badArgs();
      }
    } else if(!inputRead) {
      inputRead=true;
      inputName=string(argv[i]);
      if(inputName.find(".tex")!=inputName.size()-4) {
        cout << "Input file must be of the form *.tex" << endl;
        exit(1);
      }
      className=inputName.substr(0,inputName.size()-4);
      if(className.find("/")!=string::npos) {
        className=className.substr(className.rfind("/")+1);
      }
    } else {
      badArgs();
    }
  }
  
  if(!inputRead) {
    badArgs();
  }
  
  map<string,Type*> types;
  if(hpp||bin||typ) {
    yyin=fopen(inputName.c_str(),"r");
    yyparse();
    fclose(yyin);
    MbolElementVisitor* vTypes=new MbolElementVisitorTypeHelper();
    program->accept(*vTypes);
    types=((MbolElementVisitorTypeHelper*)vTypes)->types;
  }
  
  if(typ) {
    cout << "Program variables:" << endl;
    for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
      if(!getTemporaries().count(i->first)) {
        if(i->second->isVariable) {
          cout << "  " << i->first << ": " << i->second->print() << endl;
        }
      }
    }
    cout << endl;
    cout << "Program constants:" << endl;
    for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
      if(!getTemporaries().count(i->first)) {
        if(i->second->isConstant) {
          cout << "  " << i->first << ": " << i->second->print() << endl;
        }
      }
    }
    cout << endl;
    cout << "Program constant temporaries:" << endl;
    for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
      if(!getTemporaries().count(i->first)) {
        if(i->second->isTemporary) {
          cout << "  " << i->first << ": " << i->second->print() << endl;
        }
      }
    }
  }
  
  if(hpp||bin) {   
    string code;    
    MbolElementVisitor* vCplex=new MbolElementVisitorCPLEX(types,quiet,className);
    program->accept(*vCplex);
    code=((MbolElementVisitorCPLEX*)vCplex)->code;
    if(cpx) {
      code="#define CPLEX\n"+code;
    }
    code=indentCode(code);
    ofstream out((outputDirectory+className+".hpp").c_str());
    out << code;
    out.close();
  }
  
  if(bin) {
    char* mbolHomeC=getenv("MBOL_HOME");
    if(mbolHomeC==NULL) {
      cout << "ERROR: must set environment variable \"MBOL_HOME\" to create binary for default file I/O" << endl;
      exit(1);
    }
    string mbolHome(mbolHomeC);
    if(mbolHome[mbolHome.size()-1]!='/') {
      mbolHome+="/";
    }
    char* cplexHomeC=getenv("CPLEX_HOME");
    if(cplexHomeC==NULL) {
      cout << "ERROR: must set environment variable \"CPLEX_HOME\" to create binary for default file I/O" << endl;
      exit(1);
    }
    string cplexHome(cplexHomeC);
    if(cplexHome[cplexHome.size()-1]!='/') {
      cplexHome+="/";
    }
    string cppName=outputDirectory+className+".cpp";
    string cppCode="#include<"+className+".hpp>\nusing namespace std;\nint main(int argc,char* argv[]) {\n"+className+" x;\nstring input,output;\nif(argc>=2) {\ninput=string(argv[1]);\n} else {\ninput=\"input.txt\";\n}\nif(argc>=3) {\noutput=string(argv[2]);\n} else {\noutput=\"output.txt\";\n}\nx.readAll(input);\nx.solve();\nx.writeAll(output);\n}\n";
    ofstream cpp(cppName.c_str());
    cpp << indentCode(cppCode);
    cpp.close();
    
    string compileCmd="g++ -O3 -fopenmp -m64 -fPIC -fno-strict-aliasing -fexceptions -DNDEBUG -DIL_STD -I"+mbolHome+"include -I"+cplexHome+"cplex/include -I"+cplexHome+"concert/include -I"+outputDirectory+" "+cppName+" -o "+outputDirectory+className+" -L"+cplexHome+"cplex/lib/x86-64_sles10_4.1/static_pic -lilocplex -lcplex -L"+cplexHome+"concert/lib/x86-64_sles10_4.1/static_pic -lconcert -lm -pthread";
    //       cout << compileCmd << endl; 
    system(compileCmd.c_str());
  }
  
  if(pdf) {
    char* mbolHomeC=getenv("MBOL_HOME");
    if(mbolHomeC==NULL) {
      cout << "ERROR: must set environment variable \"MBOL_HOME\" to create pdf" << endl;
      exit(1);
    }
    string mbolHome(mbolHomeC);
    if(mbolHome[mbolHome.size()-1]!='/') {
      mbolHome+="/";
    }
    string texMainName=outputDirectory+className+"_main";
    ofstream texMain((texMainName+".tex").c_str());
    texMain << "\\documentclass{article}" << endl;
    texMain << "\\usepackage{fullpage}" << endl;
    texMain << "\\input{" << mbolHome << "include/mbol.tex}" << endl;
    texMain << "\\begin{document}" << endl;
    texMain << "\\input{"+inputName+"}" << endl;
    texMain << "\\end{document}" << endl;
    texMain.close();
    system(("pdflatex -output-directory "+outputDirectory+" "+texMainName+".tex > /dev/null").c_str());
    system(("rm -rf "+texMainName+".log").c_str());
    system(("rm -rf "+texMainName+".aux").c_str());
    system(("rm -rf "+texMainName+".tex").c_str());
    system(("mv "+texMainName+".pdf "+texMainName.substr(0,texMainName.size()-5)+".pdf").c_str());
  }    
  return 0;
}
