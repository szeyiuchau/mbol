#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20110908

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "mbolc.y"
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
#line 18 "mbolc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
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
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 65 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#define YYERROR_DECL() yyerror(const char *s)
#define YYERROR_CALL(msg) yyerror(msg)

extern int YYPARSE_DECL();

#define SM 257
#define IN 258
#define CO 259
#define GE 260
#define LE 261
#define EQ 262
#define US 263
#define SI 264
#define SU 265
#define VA 266
#define MA 267
#define MI 268
#define ST 269
#define PL 270
#define SB 271
#define DI 272
#define MU 273
#define LC 274
#define RC 275
#define LP 276
#define RP 277
#define AA 278
#define BB 279
#define CC 280
#define DD 281
#define EL 282
#define AN 283
#define UN 284
#define SR 285
#define RR 286
#define LR 287
#define LI 288
#define ZC 289
#define SE 290
#define CT 291
#define SS 292
#define FR 293
#define GT 294
#define LT 295
#define NE 296
#define LJ 297
#define CN 298
#define CL 299
#define ES 300
#define IC 301
#define MC 302
#define NU 303
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    4,    4,   18,   18,    2,    2,    3,    3,
    3,    5,    5,    6,    6,    6,    6,    6,    7,    7,
   17,   17,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,   14,   14,   14,   14,   13,   13,   13,   16,
   16,   16,   16,   15,   15,   15,   15,   15,   15,   15,
   15,   15,    9,    9,    9,    9,   10,   10,   11,   12,
   12,   12,
};
static const short yylen[] = {                            2,
    4,    7,    1,    3,    1,    1,    1,    2,    4,    4,
    7,    7,    7,    1,    1,    1,    1,    1,    1,    3,
    3,    3,    5,    3,    3,    3,    3,    3,    3,    5,
    5,    3,    1,    3,    3,    3,    1,    2,    3,    5,
    3,    3,    1,    1,    3,    7,    7,    3,    1,    1,
    5,    3,    1,    1,    1,    1,    1,    3,    5,   10,
   10,    4,
};
static const short yydefred[] = {                         0,
    0,    0,    5,    6,    0,    0,    0,    0,    0,    0,
    7,    0,    0,    0,    0,    1,    8,    3,    0,    0,
    0,    0,    0,    0,   49,    0,   44,    0,   37,    0,
    0,    0,    0,    0,    0,    0,    0,   43,    0,    0,
    0,   33,    0,    9,   53,   54,   55,   56,    0,    0,
   38,   10,    0,    4,    0,    0,    0,   52,    0,    0,
    0,    0,    0,    0,    0,    0,   45,    0,    0,   39,
    0,    0,    0,    0,    0,    0,    0,   19,    0,    0,
    0,    0,   42,    0,   41,   36,   35,   34,    0,   18,
   17,    0,   14,   15,   16,    0,    0,    0,    2,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   62,   59,    0,   51,    0,    0,    0,    0,    0,    0,
   11,    0,   26,    0,    0,    0,   27,    0,    0,    0,
    0,    0,    0,   20,    0,    0,   40,    0,    0,    0,
    0,   21,   22,    0,    0,   46,   47,    0,    0,    0,
    0,   31,    0,    0,    0,    0,   61,   60,
};
static const short yydgoto[] = {                          2,
    5,   10,   11,   19,   26,  104,   77,   78,   50,   80,
   27,   35,   28,   41,   29,   42,  106,    6,
};
static const short yysindex[] = {                      -273,
 -212,    0,    0,    0, -215, -260, -259, -228, -208, -241,
    0, -178,   -3, -171,   -3,    0,    0,    0, -216, -151,
 -148,   -3, -176, -177,    0, -145,    0, -144,    0, -137,
 -134, -121,  -90,  -81,  -82, -255, -120,    0, -176, -133,
 -180,    0,   -3,    0,    0,    0,    0,    0,  -79,   -3,
    0,    0,  -76,    0,   -3, -258,   -3,    0, -176,  -89,
   38,  -86, -261, -176, -176, -176,    0,  -96,  -95,    0,
 -253,  -85,   18,  -62, -242,  -44, -179,    0,  -61, -166,
 -125,  -51,    0, -253,    0,    0,    0,    0,  -50,    0,
    0,  -56,    0,    0,    0,  -54,   34, -112,    0, -176,
 -254, -176, -176,  -41,  -33, -249, -176, -176,  -29, -253,
    0,    0, -176,    0,   -3, -252,   -3,  -46,  -31,  -18,
    0, -125,    0,  -23, -125, -125,    0,  -13,   -9,    1,
 -125, -125,    4,    0, -125,  -37,    0,  -26,   -3,   -3,
   -8,    0,    0, -176, -185,    0,    0,   -2,   -2,   10,
 -125,    0, -125, -184,  -17,   42,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -240,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -199,
    0,   -4,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -111,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -207,    0,    0, -161, -117,    0,    0,    0,    0,
 -104,  -97,    0,    0,  -53,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   12,   14,    0,
  -45,    0,   13,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  265,    0,  278,  228,  -55,  188,    0,    0,
    0,    0,  -16,  -38,  -28,   70,    0,    0,
};
#define YYTABLESIZE 330
static const short yytable[] = {                         51,
   61,   63,   64,   65,    1,   37,  110,   73,   51,  129,
   58,  123,   97,   12,   13,   98,   50,   74,   59,  107,
   81,   70,   74,   66,   85,   50,   68,  130,  116,   50,
   50,   50,   50,  137,   50,   50,   50,   16,   72,   51,
   79,   75,   32,   51,   76,   14,   75,   50,  124,   76,
   51,   32,   50,  108,    3,    4,    7,   48,   33,    8,
    9,  122,   50,  125,  126,   15,   48,   32,  131,  132,
   48,   48,   48,   48,  135,   48,   48,   48,   32,  110,
   38,   38,    7,   64,   65,    8,    9,   18,   48,   38,
   39,   39,  113,   48,   30,  111,   43,   29,  136,   39,
  138,   40,   40,   48,   66,  151,  153,   51,  114,   51,
   40,   34,   20,   29,   36,  156,   67,  152,  155,   51,
   51,   21,  148,  149,   29,   45,   46,   47,   48,   44,
   49,   22,   62,   86,   87,   88,   20,   52,   64,   65,
   53,   28,   39,   23,   54,   21,  110,   57,   24,   45,
   46,   47,   48,   40,   24,   22,   60,   28,   25,   66,
   20,   25,  121,   57,   90,   91,   92,   23,   28,   21,
   24,   20,   24,   45,   46,   47,   48,   25,   89,   22,
   21,   24,   25,   55,   45,   46,   47,   48,   25,   99,
   22,   23,   56,   57,   69,   20,   24,   71,   93,   94,
   95,   82,   23,  105,   21,   58,   25,   24,   45,   46,
   47,   48,   84,   23,   22,  112,  109,   25,  118,   20,
  119,   58,  115,  117,  127,  128,   23,  139,   21,   23,
   20,   24,   45,   46,   47,   48,  133,  146,   22,   21,
   23,   25,  140,   45,   46,   47,   48,  123,  147,   22,
   23,  141,  142,   20,   20,   24,  143,  157,  144,   43,
   43,   23,   21,   21,  145,   25,   24,   45,   46,   47,
   48,   30,   22,   22,   17,  100,   25,   90,   91,  101,
   43,   43,  150,  154,   23,   23,   13,   30,   12,   24,
   24,  100,   31,   90,   91,  120,   96,  134,   30,   25,
   25,   64,   65,    0,    0,   64,   65,  102,    0,  103,
    0,   93,   94,   95,   83,    0,  158,    0,    0,    0,
    0,    0,   66,  102,    0,  103,   66,   93,   94,   95,
};
static const short yycheck[] = {                         28,
   39,   40,  264,  265,  278,   22,  259,  266,   37,  259,
  266,  266,  266,  274,  274,   71,  257,  276,  274,  262,
   59,   50,  276,  285,  286,  266,   43,  277,   84,  270,
  271,  272,  273,  286,  275,  276,  277,  279,   55,   68,
   57,  300,  259,   72,  303,  274,  300,  288,  303,  303,
   79,  259,  293,  296,  267,  268,  298,  257,  275,  301,
  302,  100,  303,  102,  103,  274,  266,  275,  107,  108,
  270,  271,  272,  273,  113,  275,  276,  277,  286,  259,
  266,  266,  298,  264,  265,  301,  302,  266,  288,  266,
  276,  276,  259,  293,  266,  275,  274,  259,  115,  276,
  117,  287,  287,  303,  285,  144,  145,  136,  275,  138,
  287,  263,  257,  275,  263,  154,  297,  303,  303,  148,
  149,  266,  139,  140,  286,  270,  271,  272,  273,  275,
  275,  276,  266,   64,   65,   66,  257,  275,  264,  265,
  275,  259,  276,  288,  266,  266,  259,  259,  293,  270,
  271,  272,  273,  287,  259,  276,  277,  275,  303,  285,
  257,  259,  275,  275,  260,  261,  262,  288,  286,  266,
  275,  257,  293,  270,  271,  272,  273,  275,  275,  276,
  266,  286,  303,  274,  270,  271,  272,  273,  286,  275,
  276,  288,  274,  276,  274,  257,  293,  274,  294,  295,
  296,  291,  288,  266,  266,  259,  303,  293,  270,  271,
  272,  273,  299,  259,  276,  277,  261,  303,  275,  257,
  275,  275,  274,  274,  266,  259,  288,  274,  266,  275,
  257,  293,  270,  271,  272,  273,  266,  275,  276,  266,
  286,  303,  274,  270,  271,  272,  273,  266,  275,  276,
  288,  275,  266,  257,  257,  293,  266,  275,  258,  264,
  265,  288,  266,  266,  261,  303,  293,  270,  271,  272,
  273,  259,  276,  276,   10,  258,  303,  260,  261,  262,
  285,  286,  291,  274,  288,  288,  275,  275,  275,  293,
  293,  258,   15,  260,  261,  262,   69,  110,  286,  303,
  303,  264,  265,   -1,   -1,  264,  265,  290,   -1,  292,
   -1,  294,  295,  296,  277,   -1,  275,   -1,   -1,   -1,
   -1,   -1,  285,  290,   -1,  292,  285,  294,  295,  296,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 303
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"SM","IN","CO","GE","LE","EQ",
"US","SI","SU","VA","MA","MI","ST","PL","SB","DI","MU","LC","RC","LP","RP","AA",
"BB","CC","DD","EL","AN","UN","SR","RR","LR","LI","ZC","SE","CT","SS","FR","GT",
"LT","NE","LJ","CN","CL","ES","IC","MC","NU",
};
static const char *yyrule[] = {
"$accept : program",
"program : AA objective constraints BB",
"objective : objective_type LC program_variables RC LC number_expression RC",
"program_variables : VA",
"program_variables : program_variables CO VA",
"objective_type : MA",
"objective_type : MI",
"constraints : constraint",
"constraints : constraints constraint",
"constraint : CN LC equation RC",
"constraint : IC LC VA RC",
"constraint : MC LC equation RC LC qualifiers RC",
"equation : number_expression RC LC inequality RC LC number_expression",
"equation : number_expression RC LC EQ RC LC number_expression",
"inequality : GT",
"inequality : LT",
"inequality : NE",
"inequality : LE",
"inequality : GE",
"qualifiers : qualifier",
"qualifiers : qualifiers CO qualifier",
"tuple_indices : VA CO VA",
"tuple_indices : tuple_indices CO VA",
"qualifier : LP tuple_indices RP IN element_expression",
"qualifier : ES EQ element_expression",
"qualifier : ES NE element_expression",
"qualifier : VA EQ VA",
"qualifier : VA inequality VA",
"qualifier : VA SS element_expression",
"qualifier : VA SE element_expression",
"qualifier : NU LE VA LE element_expression",
"qualifier : NU LE VA LE NU",
"qualifier : VA IN element_expression",
"element_expression : element_subexpression",
"element_expression : element_expression SR element_subexpression",
"element_expression : element_expression SU element_subexpression",
"element_expression : element_expression SI element_subexpression",
"number_expression : number_subexpression",
"number_expression : number_expression number_subexpression",
"number_expression : number_expression number_operator number_subexpression",
"element_subexpression : LR VA CL qualifiers RR",
"element_subexpression : LR element_expression RR",
"element_subexpression : LP element_expression RP",
"element_subexpression : VA",
"number_subexpression : sum",
"number_subexpression : LI element_expression LJ",
"number_subexpression : LP number_expression RP CT LC number_expression RC",
"number_subexpression : FR LC number_expression RC LC number_expression RC",
"number_subexpression : LP number_expression RP",
"number_subexpression : NU",
"number_subexpression : VA",
"number_subexpression : VA US LC indices RC",
"number_subexpression : VA US VA",
"number_operator : PL",
"number_operator : SB",
"number_operator : DI",
"number_operator : MU",
"indices : element_expression",
"indices : indices CO element_expression",
"sum : SM sum_qualifiers LP number_expression RP",
"sum_qualifiers : US LC VA EQ NU RC CT LC element_expression RC",
"sum_qualifiers : US LC VA EQ NU RC CT LC NU RC",
"sum_qualifiers : US LC qualifiers RC",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 273 "mbolc.y"
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
    string inputName;
    string outputDirectory="./";
    string className;
    bool hpp=false;
    bool bin=false;
    bool pdf=false;
    bool typ=false;
    options["-v"]="Print version information and exit";
    options["-h"]="Print help information and exit";
    options["-q"]="Put CPLEX in quiet mode";
    options["-d <arg>"]="Use <arg> as output directory";
    options["-typ"]="Print types inferred by mbolc";
    options["-bin"]="Compile a binary for default file I/O";
    options["-pdf"]="Compile a pdf of the program";
    options["-hpp"]="Compile a hpp header of the program";
    for(int i=1;i<argc;i++) {
        if(string(argv[i])=="-q") {
            quiet=true;
        } else if(string(argv[i])=="-v") {
            version();
        } else if(string(argv[i])=="-h") {
            help();
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
        code=indentCode(((MbolElementVisitorCPLEX*)vCplex)->code);
        
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
#line 666 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 64 "mbolc.y"
	{
    program=new Program(yystack.l_mark[-2].objectiveVal,yystack.l_mark[-1].constraintsVal);
    yyval.programVal=program;
}
break;
case 2:
#line 69 "mbolc.y"
	{
    yyval.objectiveVal=new Objective(yystack.l_mark[-6].objectiveTypeVal,yystack.l_mark[-4].programVariablesVal,yystack.l_mark[-1].numberExpressionVal);
}
break;
case 3:
#line 73 "mbolc.y"
	{
    yyval.programVariablesVal=new ProgramVariables(string(yystack.l_mark[0].sval));
}
break;
case 4:
#line 76 "mbolc.y"
	{
    yystack.l_mark[-2].programVariablesVal->variables.push_back(string(yystack.l_mark[0].sval));
}
break;
case 5:
#line 80 "mbolc.y"
	{
    yyval.objectiveTypeVal=new ObjectiveType("max");
}
break;
case 6:
#line 83 "mbolc.y"
	{
    yyval.objectiveTypeVal=new ObjectiveType("min");
}
break;
case 7:
#line 87 "mbolc.y"
	{
    yyval.constraintsVal=new Constraints(yystack.l_mark[0].constraintVal);
}
break;
case 8:
#line 90 "mbolc.y"
	{
    yystack.l_mark[-1].constraintsVal->constraints.push_back(yystack.l_mark[0].constraintVal);
}
break;
case 9:
#line 94 "mbolc.y"
	{
    yyval.constraintVal=new Constraint(yystack.l_mark[-1].equationVal);
}
break;
case 10:
#line 97 "mbolc.y"
	{
    yyval.constraintVal=new Constraint(string(yystack.l_mark[-1].sval));
}
break;
case 11:
#line 100 "mbolc.y"
	{
    yyval.constraintVal=new Constraint(yystack.l_mark[-4].equationVal,yystack.l_mark[-1].qualifiersVal);
}
break;
case 12:
#line 104 "mbolc.y"
	{
    yyval.equationVal=new Equation(yystack.l_mark[-6].numberExpressionVal,yystack.l_mark[-3].inequalityVal,yystack.l_mark[0].numberExpressionVal);
}
break;
case 13:
#line 107 "mbolc.y"
	{
    yyval.equationVal=new Equation(yystack.l_mark[-6].numberExpressionVal,new Inequality("=="),yystack.l_mark[0].numberExpressionVal);
}
break;
case 14:
#line 111 "mbolc.y"
	{
    yyval.inequalityVal=new Inequality(">");
}
break;
case 15:
#line 114 "mbolc.y"
	{
    yyval.inequalityVal=new Inequality("<");
}
break;
case 16:
#line 117 "mbolc.y"
	{
    yyval.inequalityVal=new Inequality("!=");
}
break;
case 17:
#line 120 "mbolc.y"
	{
    yyval.inequalityVal=new Inequality("<=");
}
break;
case 18:
#line 123 "mbolc.y"
	{
    yyval.inequalityVal=new Inequality(">=");
}
break;
case 19:
#line 127 "mbolc.y"
	{
    yyval.qualifiersVal=new Qualifiers(yystack.l_mark[0].qualifierVal);
}
break;
case 20:
#line 130 "mbolc.y"
	{
    yystack.l_mark[-2].qualifiersVal->qualifiers.push_back(yystack.l_mark[0].qualifierVal);
}
break;
case 21:
#line 134 "mbolc.y"
	{
    yyval.tupleIndicesVal=new TupleIndices(yystack.l_mark[-2].sval,yystack.l_mark[0].sval);
}
break;
case 22:
#line 137 "mbolc.y"
	{
    yystack.l_mark[-2].tupleIndicesVal->indices.push_back(string(yystack.l_mark[0].sval));
}
break;
case 23:
#line 141 "mbolc.y"
	{
    yyval.qualifierVal=new Qualifier(yystack.l_mark[-3].tupleIndicesVal,yystack.l_mark[0].elementExpressionVal);
}
break;
case 24:
#line 144 "mbolc.y"
	{
    yyval.qualifierVal=new Qualifier("0",new Inequality("=="),new SetSize(yystack.l_mark[0].elementExpressionVal));
}
break;
case 25:
#line 147 "mbolc.y"
	{
    yyval.qualifierVal=new Qualifier("0",new Inequality("!="),new SetSize(yystack.l_mark[0].elementExpressionVal));
}
break;
case 26:
#line 150 "mbolc.y"
	{
    yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),new Inequality("=="),string(yystack.l_mark[0].sval));
}
break;
case 27:
#line 153 "mbolc.y"
	{
    yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),yystack.l_mark[-1].inequalityVal,string(yystack.l_mark[0].sval));
}
break;
case 28:
#line 156 "mbolc.y"
	{
    yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),"subset",yystack.l_mark[0].elementExpressionVal);
}
break;
case 29:
#line 159 "mbolc.y"
	{
    yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),"subsetequal",yystack.l_mark[0].elementExpressionVal);
}
break;
case 30:
#line 162 "mbolc.y"
	{
    yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),"in",new ElementExpression(new ElementSubexpression(new ElementNumbers(string(yystack.l_mark[-4].sval),yystack.l_mark[0].elementExpressionVal))));
}
break;
case 31:
#line 165 "mbolc.y"
	{
    yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),"in",new ElementExpression(new ElementSubexpression(new ElementNumbers(string(yystack.l_mark[-4].sval),string(yystack.l_mark[0].sval)))));
}
break;
case 32:
#line 168 "mbolc.y"
	{
    yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),"in",yystack.l_mark[0].elementExpressionVal);
}
break;
case 33:
#line 172 "mbolc.y"
	{
    yyval.elementExpressionVal=new ElementExpression(yystack.l_mark[0].elementSubexpressionVal);
}
break;
case 34:
#line 175 "mbolc.y"
	{
    yyval.elementExpressionVal=new ElementExpression(yystack.l_mark[-2].elementExpressionVal,new ElementOperator("reduce"),yystack.l_mark[0].elementSubexpressionVal);
}
break;
case 35:
#line 178 "mbolc.y"
	{
    yyval.elementExpressionVal=new ElementExpression(yystack.l_mark[-2].elementExpressionVal,new ElementOperator("union"),yystack.l_mark[0].elementSubexpressionVal);
}
break;
case 36:
#line 181 "mbolc.y"
	{
    yyval.elementExpressionVal=new ElementExpression(yystack.l_mark[-2].elementExpressionVal,new ElementOperator("intersect"),yystack.l_mark[0].elementSubexpressionVal);
}
break;
case 37:
#line 185 "mbolc.y"
	{
    yyval.numberExpressionVal=new NumberExpression(yystack.l_mark[0].numberSubexpressionVal);
}
break;
case 38:
#line 188 "mbolc.y"
	{
    yystack.l_mark[-1].numberExpressionVal->numberSubexpressions.push_back(yystack.l_mark[0].numberSubexpressionVal);
    yystack.l_mark[-1].numberExpressionVal->numberOperators.push_back(new NumberOperator("*"));
}
break;
case 39:
#line 192 "mbolc.y"
	{
    yystack.l_mark[-2].numberExpressionVal->numberSubexpressions.push_back(yystack.l_mark[0].numberSubexpressionVal);
    yystack.l_mark[-2].numberExpressionVal->numberOperators.push_back(yystack.l_mark[-1].numberOperatorVal);
}
break;
case 40:
#line 197 "mbolc.y"
	{
    yyval.elementSubexpressionVal=new ElementSubexpression(new SetCreator(string(yystack.l_mark[-3].sval),yystack.l_mark[-1].qualifiersVal));
}
break;
case 41:
#line 200 "mbolc.y"
	{
    yyval.elementSubexpressionVal=new ElementSubexpression(new ElementSet(yystack.l_mark[-1].elementExpressionVal));
}
break;
case 42:
#line 203 "mbolc.y"
	{
    yyval.elementSubexpressionVal=new ElementSubexpression(new ElementParantheses(yystack.l_mark[-1].elementExpressionVal));
}
break;
case 43:
#line 206 "mbolc.y"
	{
    yyval.elementSubexpressionVal=new ElementSubexpression(new ElementVariable(string(yystack.l_mark[0].sval)));
}
break;
case 44:
#line 210 "mbolc.y"
	{
    yyval.numberSubexpressionVal=new NumberSubexpression(yystack.l_mark[0].sumVal);
}
break;
case 45:
#line 213 "mbolc.y"
	{
    yyval.numberSubexpressionVal=new NumberSubexpression(new SetSize(yystack.l_mark[-1].elementExpressionVal));
}
break;
case 46:
#line 216 "mbolc.y"
	{
    yyval.numberSubexpressionVal=new NumberSubexpression(new NumberPower(yystack.l_mark[-5].numberExpressionVal,yystack.l_mark[-1].numberExpressionVal));    
}
break;
case 47:
#line 219 "mbolc.y"
	{
    yyval.numberSubexpressionVal=new NumberSubexpression(new Fraction(yystack.l_mark[-4].numberExpressionVal,yystack.l_mark[-1].numberExpressionVal));
}
break;
case 48:
#line 222 "mbolc.y"
	{
    yyval.numberSubexpressionVal=new NumberSubexpression(new NumberParantheses(yystack.l_mark[-1].numberExpressionVal));
}
break;
case 49:
#line 225 "mbolc.y"
	{
    yyval.numberSubexpressionVal=new NumberSubexpression(new NumberLiteral(string(yystack.l_mark[0].sval)));
}
break;
case 50:
#line 228 "mbolc.y"
	{
    yyval.numberSubexpressionVal=new NumberSubexpression(new NumberVariable(string(yystack.l_mark[0].sval)));
}
break;
case 51:
#line 231 "mbolc.y"
	{
    yyval.numberSubexpressionVal=new NumberSubexpression(new VariableMap(string(yystack.l_mark[-4].sval),yystack.l_mark[-1].indicesVal));
}
break;
case 52:
#line 234 "mbolc.y"
	{
    yyval.numberSubexpressionVal=new NumberSubexpression(new VariableMap(string(yystack.l_mark[-2].sval),string(yystack.l_mark[0].sval)));
}
break;
case 53:
#line 238 "mbolc.y"
	{
    yyval.numberOperatorVal=new NumberOperator("+");
}
break;
case 54:
#line 241 "mbolc.y"
	{
    yyval.numberOperatorVal=new NumberOperator("-");
}
break;
case 55:
#line 244 "mbolc.y"
	{
    yyval.numberOperatorVal=new NumberOperator("/");
}
break;
case 56:
#line 247 "mbolc.y"
	{
    yyval.numberOperatorVal=new NumberOperator("*");
}
break;
case 57:
#line 251 "mbolc.y"
	{
    yyval.indicesVal=new Indices(yystack.l_mark[0].elementExpressionVal);
}
break;
case 58:
#line 254 "mbolc.y"
	{
    yystack.l_mark[-2].indicesVal->elementExpressions.push_back(yystack.l_mark[0].elementExpressionVal);
}
break;
case 59:
#line 258 "mbolc.y"
	{
    yyval.sumVal=new Sum(string(yystack.l_mark[-4].sval),yystack.l_mark[-3].sumQualifiersVal,yystack.l_mark[-1].numberExpressionVal);
}
break;
case 60:
#line 262 "mbolc.y"
	{
    yyval.sumQualifiersVal=new SumQualifiers(string(yystack.l_mark[-7].sval),string(yystack.l_mark[-5].sval),yystack.l_mark[-1].elementExpressionVal);
}
break;
case 61:
#line 265 "mbolc.y"
	{
    yyval.sumQualifiersVal=new SumQualifiers(string(yystack.l_mark[-7].sval),string(yystack.l_mark[-5].sval),string(yystack.l_mark[-1].sval));
}
break;
case 62:
#line 268 "mbolc.y"
	{
    yyval.sumQualifiersVal=new SumQualifiers(yystack.l_mark[-1].qualifiersVal);
}
break;
#line 1247 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
