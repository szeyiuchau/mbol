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
#define NU 301
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
    4,    7,    1,    3,    1,    1,    4,    5,    1,    3,
    3,    3,    3,    1,    1,    1,    1,    1,    1,    3,
    1,    3,    5,    3,    3,    3,    3,    3,    3,    5,
    5,    3,    1,    3,    3,    3,    1,    2,    3,    5,
    3,    3,    1,    1,    3,    7,    7,    3,    1,    1,
    5,    3,    1,    1,    1,    1,    1,    3,    5,   10,
   10,    4,
};
static const short yydefred[] = {                         0,
    0,    0,    5,    6,    0,    0,    0,    0,    0,    0,
    1,    0,    3,    0,    0,    0,    0,    0,    0,   49,
    0,    0,   44,    0,   37,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   43,    0,    0,    0,   33,    0,
    7,    0,   18,   17,    0,   53,   54,   55,   56,   14,
   15,   16,    0,    0,   38,    0,    4,    0,    0,    0,
   10,   52,    0,    0,    0,    0,    0,    0,    0,    0,
   45,    0,    0,    0,    0,    0,    0,   19,    0,    0,
   39,    8,    0,    0,    0,    0,    0,    0,    0,   42,
    0,   41,   36,   35,   34,    0,    0,    0,    0,    0,
    0,   21,    0,    0,    0,    0,    0,    2,    0,   62,
   59,    0,   51,    0,    0,    0,    0,   26,    0,    0,
   27,    0,    0,    0,    0,    0,   20,    0,    0,    0,
   40,    0,   22,    0,    0,    0,   46,   47,    0,   31,
    0,    0,    0,    0,    0,   61,   60,
};
static const short yydgoto[] = {                          2,
    5,    8,   21,   14,   22,  101,   77,   78,   54,   87,
   23,   30,   24,   38,   25,   39,  103,    6,
};
static const short yysindex[] = {                      -271,
 -200,    0,    0,    0, -285, -227, -202, -218, -189, -248,
    0, -183,    0, -232, -159, -246,  -94, -137, -160,    0,
 -141, -139,    0,  -93,    0, -248, -123, -127, -126, -125,
 -132, -250, -101, -251,    0, -137,    5, -152,    0,  -94,
    0, -262,    0,    0,  -94,    0,    0,    0,    0,    0,
    0,    0,  -94,  -94,    0, -105,    0,  -94, -243,  -94,
    0,    0, -137, -117,   39, -118,  -26, -137, -137, -137,
    0,  -40, -106,  -81, -261,  -69,  -66,    0,   90,   90,
    0,    0,   -8,  110, -185,   18, -173,   36,  -70,    0,
 -262,    0,    0,    0,    0,  -60, -137,  -61, -137, -137,
  -50,    0, -225, -137, -137,  -25, -262,    0, -255,    0,
    0, -137,    0,  -94, -254,  -94,   36,    0,   36,   36,
    0,  -20,  -11,   36,   36,   -7,    0,   -6,   36,   42,
    0,   66,    0, -137, -212,  -36,    0,    0,   36,    0,
   36,  -17, -155,   -5,   12,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -51,    0,    0,    0,    0,
    0,   -1,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -178,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -135,    0,  -13,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    3,    0, -131,  -84,
    0,    0,    0,    0,    0,    0,    0,  -41,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -199,    0, -190, -156,
    0,    0,    0, -110,  -88,    0,    0,    0,  -19,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -63,    0,
  -62,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  240,    0,    0,  255,  -18,  175,    0,    0,
    0,    0,   -9,  -34,  -24,  159,    0,    0,
};
#define YYTABLESIZE 406
static const short yytable[] = {                         55,
  104,   65,   67,   73,  107,   15,    1,   34,   15,   55,
  118,   31,    7,   74,   33,   62,   32,   16,   46,   47,
   48,   49,   84,   63,   17,   64,   27,   17,   88,   81,
   72,  131,   74,  122,  105,   79,   18,   75,   76,   18,
   85,   19,   28,   80,   19,  128,    9,   55,   83,   20,
   86,  123,   20,   35,   55,   55,   75,   76,   55,   32,
   11,   55,  117,   36,  119,  120,    3,    4,   29,  124,
  125,   10,  115,  107,   37,   32,   13,  129,   50,   12,
   50,   50,   50,   50,   29,  112,   32,   50,  140,  110,
   26,   50,   50,   50,   50,   29,   50,   50,   50,  139,
  141,  113,   28,   29,  130,   55,  132,   55,  145,   50,
   35,   68,   69,   40,   50,   50,   50,   50,   28,   42,
   36,   48,   50,   48,   48,   48,   48,   13,   35,   28,
   48,   37,   70,   41,   48,   48,   48,   48,   36,   48,
   48,   48,   57,   13,   71,  144,   58,   59,   24,   37,
   60,   97,   48,   43,   44,   98,   61,   48,   48,   48,
   48,   32,   15,   15,   24,   48,   43,   44,   45,   82,
   25,   33,   33,   89,   12,   24,   46,   47,   48,   49,
   91,   17,   17,   99,  102,  100,   25,   50,   51,   52,
   12,  106,  107,   18,   18,   23,   30,   25,   19,   19,
   50,   51,   52,  114,  118,   50,   20,   20,   50,   50,
   50,   23,   30,  116,   50,  121,   15,   57,   50,   50,
   50,   50,   23,   30,   50,   33,   93,   94,   95,   46,
   47,   48,   49,   57,   96,   17,   50,   68,   69,   58,
  126,   50,   50,   50,   50,  133,  134,   18,   15,   50,
   43,   43,   19,  135,  142,   58,  143,   33,   70,   92,
   20,   46,   47,   48,   49,   56,  108,   17,  136,  146,
   66,   43,   43,    9,   15,   68,   69,   11,   53,   18,
   36,  127,    0,   33,   19,    0,  147,   46,   47,   48,
   49,   37,   20,   17,  111,    0,   70,    0,   15,   68,
   69,    0,   68,   69,    0,   18,    0,   33,    0,    0,
   19,   46,   47,   48,   49,   90,  137,   17,   20,    0,
   70,    0,   15,   70,    0,    0,    0,    0,    0,   18,
    0,   33,    0,    0,   19,   46,   47,   48,   49,    0,
  138,   17,   20,    0,    0,    0,   15,    0,    0,    0,
    0,    0,    0,   18,    0,   33,    0,    0,   19,   46,
   47,   48,   49,    0,    0,   17,   20,   97,    0,   43,
   44,  109,    0,    0,    0,    0,    0,   18,    0,    0,
    0,    0,   19,    0,    0,    0,    0,    0,    0,    0,
   20,    0,    0,    0,    0,    0,    0,    0,    0,   99,
    0,  100,    0,   50,   51,   52,
};
static const short yycheck[] = {                         24,
  262,   36,   37,  266,  259,  257,  278,   17,  257,   34,
  266,  258,  298,  276,  266,  266,  263,  266,  270,  271,
  272,  273,  266,  274,  276,  277,  259,  276,   63,   54,
   40,  286,  276,  259,  296,   45,  288,  300,  301,  288,
   59,  293,  275,   53,  293,  301,  274,   72,   58,  301,
   60,  277,  301,  266,   79,   80,  300,  301,   83,  259,
  279,   86,   97,  276,   99,  100,  267,  268,  259,  104,
  105,  274,   91,  259,  287,  275,  266,  112,  257,  298,
  259,  260,  261,  262,  275,  259,  286,  266,  301,  275,
  274,  270,  271,  272,  273,  286,  275,  276,  277,  134,
  135,  275,  259,  263,  114,  130,  116,  132,  143,  288,
  266,  264,  265,  274,  293,  294,  295,  296,  275,  259,
  276,  257,  301,  259,  260,  261,  262,  259,  266,  286,
  266,  287,  285,  275,  270,  271,  272,  273,  276,  275,
  276,  277,  266,  275,  297,  301,  274,  274,  259,  287,
  276,  258,  288,  260,  261,  262,  289,  293,  294,  295,
  296,  263,  257,  257,  275,  301,  260,  261,  262,  275,
  259,  266,  266,  291,  259,  286,  270,  271,  272,  273,
  299,  276,  276,  290,  266,  292,  275,  294,  295,  296,
  275,  261,  259,  288,  288,  259,  259,  286,  293,  293,
  294,  295,  296,  274,  266,  257,  301,  301,  260,  261,
  262,  275,  275,  274,  266,  266,  257,  259,  270,  271,
  272,  273,  286,  286,  276,  266,   68,   69,   70,  270,
  271,  272,  273,  275,  275,  276,  288,  264,  265,  259,
  266,  293,  294,  295,  296,  266,  258,  288,  257,  301,
  264,  265,  293,  261,  291,  275,  274,  266,  285,  286,
  301,  270,  271,  272,  273,   26,  275,  276,  275,  275,
  266,  285,  286,  275,  257,  264,  265,  275,   24,  288,
  276,  107,   -1,  266,  293,   -1,  275,  270,  271,  272,
  273,  287,  301,  276,  277,   -1,  285,   -1,  257,  264,
  265,   -1,  264,  265,   -1,  288,   -1,  266,   -1,   -1,
  293,  270,  271,  272,  273,  277,  275,  276,  301,   -1,
  285,   -1,  257,  285,   -1,   -1,   -1,   -1,   -1,  288,
   -1,  266,   -1,   -1,  293,  270,  271,  272,  273,   -1,
  275,  276,  301,   -1,   -1,   -1,  257,   -1,   -1,   -1,
   -1,   -1,   -1,  288,   -1,  266,   -1,   -1,  293,  270,
  271,  272,  273,   -1,   -1,  276,  301,  258,   -1,  260,
  261,  262,   -1,   -1,   -1,   -1,   -1,  288,   -1,   -1,
   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  301,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  290,
   -1,  292,   -1,  294,  295,  296,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 301
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
"LT","NE","LJ","CN","CL","ES","NU",
};
static const char *yyrule[] = {
"$accept : program",
"program : AA objective constraints BB",
"objective : objective_type LC program_variables RC LC number_expression RC",
"program_variables : VA",
"program_variables : program_variables CO VA",
"objective_type : MA",
"objective_type : MI",
"constraints : CN LC constraint RC",
"constraints : constraints CN LC constraint RC",
"constraint : equation",
"constraint : VA IN ZC",
"constraint : equation CO qualifiers",
"equation : number_expression inequality number_expression",
"equation : number_expression EQ number_expression",
"inequality : GT",
"inequality : LT",
"inequality : NE",
"inequality : LE",
"inequality : GE",
"qualifiers : qualifier",
"qualifiers : qualifiers CO qualifier",
"tuple_indices : VA",
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
#line 291 "mbolc.y"
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
#line 573 "y.tab.c"

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
    yyval.constraintsVal=new Constraints(yystack.l_mark[-1].constraintVal);
}
break;
case 8:
#line 90 "mbolc.y"
	{
    yystack.l_mark[-4].constraintsVal->constraints.push_back(yystack.l_mark[-1].constraintVal);
}
break;
case 9:
#line 94 "mbolc.y"
	{
    yyval.constraintVal=new Constraint(yystack.l_mark[0].equationVal);
}
break;
case 10:
#line 97 "mbolc.y"
	{
    yyval.constraintVal=new Constraint(string(yystack.l_mark[-2].sval));
}
break;
case 11:
#line 100 "mbolc.y"
	{
    yyval.constraintVal=new Constraint(yystack.l_mark[-2].equationVal,yystack.l_mark[0].qualifiersVal);
}
break;
case 12:
#line 104 "mbolc.y"
	{
    yyval.equationVal=new Equation(yystack.l_mark[-2].numberExpressionVal,yystack.l_mark[-1].inequalityVal,yystack.l_mark[0].numberExpressionVal);
}
break;
case 13:
#line 107 "mbolc.y"
	{
    yyval.equationVal=new Equation(yystack.l_mark[-2].numberExpressionVal,new Inequality("=="),yystack.l_mark[0].numberExpressionVal);
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
    /*    int n=strs.size();
    tupleHolder[n].push_back(string($1));
    $$=n;*/
}
break;
case 22:
#line 139 "mbolc.y"
	{
    /*    int n=strs.size();
    tupleHolder[n]=tupleHolder[$1];
    tupleHolder[n].push_back(string($3));
    $$=n;*/
}
break;
case 23:
#line 146 "mbolc.y"
	{
    /*    int n=strs.size();
    string tv=tempElement();
    scopeStuff[n]=scopeStuff[$5];
    setGraphEdge(tv,strs[$5],1);
    strs[n]="for(TYPE_"+strs[$5]+"_::iterator "+tv+"="+strs[$5]+".begin();"+tv+"!="+strs[$5]+".end();"+tv+"++) {";
    for(int i=0;i<tupleHolder[$2].size();i++) {
        strs[n]+="\nTYPE_"+tupleHolder[$2][i]+"_ "+tupleHolder[$2][i]+"="+tv+"->e"+convert(i)+";";
        setDeclType(tupleHolder[$2][i],"temporary");
    }
    tupleType[tv]=tupleHolder[$2];
    $$=n;*/
}
break;
case 24:
#line 159 "mbolc.y"
	{
}
break;
case 25:
#line 161 "mbolc.y"
	{
}
break;
case 26:
#line 163 "mbolc.y"
	{
}
break;
case 27:
#line 165 "mbolc.y"
	{
}
break;
case 28:
#line 167 "mbolc.y"
	{
    yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),"subset",yystack.l_mark[0].elementExpressionVal);
}
break;
case 29:
#line 170 "mbolc.y"
	{
    yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),"subsetequal",yystack.l_mark[0].elementExpressionVal);
}
break;
case 30:
#line 173 "mbolc.y"
	{
    yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),"in",new ElementExpression(new ElementSubexpression(new ElementNumbers(string(yystack.l_mark[-4].sval),yystack.l_mark[0].elementExpressionVal))));
}
break;
case 31:
#line 176 "mbolc.y"
	{
    yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),"in",new ElementExpression(new ElementSubexpression(new ElementNumbers(string(yystack.l_mark[-4].sval),string(yystack.l_mark[0].sval)))));
}
break;
case 32:
#line 179 "mbolc.y"
	{
    yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),"in",yystack.l_mark[0].elementExpressionVal);
}
break;
case 33:
#line 183 "mbolc.y"
	{
    yyval.elementExpressionVal=new ElementExpression(yystack.l_mark[0].elementSubexpressionVal);
}
break;
case 34:
#line 186 "mbolc.y"
	{
    yyval.elementExpressionVal=new ElementExpression(yystack.l_mark[-2].elementExpressionVal,new ElementOperator("reduce"),yystack.l_mark[0].elementSubexpressionVal);
}
break;
case 35:
#line 189 "mbolc.y"
	{
    yyval.elementExpressionVal=new ElementExpression(yystack.l_mark[-2].elementExpressionVal,new ElementOperator("union"),yystack.l_mark[0].elementSubexpressionVal);
}
break;
case 36:
#line 192 "mbolc.y"
	{
    yyval.elementExpressionVal=new ElementExpression(yystack.l_mark[-2].elementExpressionVal,new ElementOperator("intersect"),yystack.l_mark[0].elementSubexpressionVal);
}
break;
case 37:
#line 196 "mbolc.y"
	{
    yyval.numberExpressionVal=new NumberExpression(yystack.l_mark[0].numberSubexpressionVal);
}
break;
case 38:
#line 199 "mbolc.y"
	{
    yystack.l_mark[-1].numberExpressionVal->numberSubexpressions.push_back(yystack.l_mark[0].numberSubexpressionVal);
    yystack.l_mark[-1].numberExpressionVal->numberOperators.push_back(new NumberOperator("*"));
}
break;
case 39:
#line 203 "mbolc.y"
	{
    yystack.l_mark[-2].numberExpressionVal->numberSubexpressions.push_back(yystack.l_mark[0].numberSubexpressionVal);
    yystack.l_mark[-2].numberExpressionVal->numberOperators.push_back(yystack.l_mark[-1].numberOperatorVal);
}
break;
case 40:
#line 208 "mbolc.y"
	{
    yyval.elementSubexpressionVal=new ElementSubexpression(new SetCreator(string(yystack.l_mark[-3].sval),yystack.l_mark[-1].qualifiersVal));
}
break;
case 41:
#line 211 "mbolc.y"
	{
    yyval.elementSubexpressionVal=new ElementSubexpression(new ElementSet(yystack.l_mark[-1].elementExpressionVal));
}
break;
case 42:
#line 214 "mbolc.y"
	{
    yyval.elementSubexpressionVal=new ElementSubexpression(new ElementParantheses(yystack.l_mark[-1].elementExpressionVal));
}
break;
case 43:
#line 217 "mbolc.y"
	{
    yyval.elementSubexpressionVal=new ElementSubexpression(new ElementVariable(string(yystack.l_mark[0].sval)));
}
break;
case 44:
#line 221 "mbolc.y"
	{
    yyval.numberSubexpressionVal=new NumberSubexpression(yystack.l_mark[0].sumVal);
}
break;
case 45:
#line 224 "mbolc.y"
	{
    yyval.numberSubexpressionVal=new NumberSubexpression(new SetSize(yystack.l_mark[-1].elementExpressionVal));
}
break;
case 46:
#line 227 "mbolc.y"
	{
    /*    
    int n=strs.size();
    string tv1=tempExp();
    string tv2=tempExp();
    string tv3=tempExp();
    scopeStuff[n]=scopeStuff[$2]+scopeStuff[$6]+"double "+tv1+"="+strs[$2]+";\ndouble "+tv2+"="+strs[$6]+";\ndouble "+tv3+"=pow("+tv1+","+tv2+");\n";
    strs[n]=tv3;
    $$=n;*/
}
break;
case 47:
#line 237 "mbolc.y"
	{
    yyval.numberSubexpressionVal=new NumberSubexpression(new Fraction(yystack.l_mark[-4].numberExpressionVal,yystack.l_mark[-1].numberExpressionVal));
}
break;
case 48:
#line 240 "mbolc.y"
	{
    yyval.numberSubexpressionVal=new NumberSubexpression(new NumberParantheses(yystack.l_mark[-1].numberExpressionVal));
}
break;
case 49:
#line 243 "mbolc.y"
	{
    yyval.numberSubexpressionVal=new NumberSubexpression(new NumberLiteral(string(yystack.l_mark[0].sval)));
}
break;
case 50:
#line 246 "mbolc.y"
	{
    yyval.numberSubexpressionVal=new NumberSubexpression(new NumberVariable(string(yystack.l_mark[0].sval)));
}
break;
case 51:
#line 249 "mbolc.y"
	{
    yyval.numberSubexpressionVal=new NumberSubexpression(new VariableMap(string(yystack.l_mark[-4].sval),yystack.l_mark[-1].indicesVal));
}
break;
case 52:
#line 252 "mbolc.y"
	{
    yyval.numberSubexpressionVal=new NumberSubexpression(new VariableMap(string(yystack.l_mark[-2].sval),string(yystack.l_mark[0].sval)));
}
break;
case 53:
#line 256 "mbolc.y"
	{
    yyval.numberOperatorVal=new NumberOperator("+");
}
break;
case 54:
#line 259 "mbolc.y"
	{
    yyval.numberOperatorVal=new NumberOperator("-");
}
break;
case 55:
#line 262 "mbolc.y"
	{
    yyval.numberOperatorVal=new NumberOperator("/");
}
break;
case 56:
#line 265 "mbolc.y"
	{
    yyval.numberOperatorVal=new NumberOperator("*");
}
break;
case 57:
#line 269 "mbolc.y"
	{
    yyval.indicesVal=new Indices(yystack.l_mark[0].elementExpressionVal);
}
break;
case 58:
#line 272 "mbolc.y"
	{
    yystack.l_mark[-2].indicesVal->elementExpressions.push_back(yystack.l_mark[0].elementExpressionVal);
}
break;
case 59:
#line 276 "mbolc.y"
	{
    yyval.sumVal=new Sum(string(yystack.l_mark[-4].sval),yystack.l_mark[-3].sumQualifiersVal,yystack.l_mark[-1].numberExpressionVal);
}
break;
case 60:
#line 280 "mbolc.y"
	{
    yyval.sumQualifiersVal=new SumQualifiers(string(yystack.l_mark[-7].sval),string(yystack.l_mark[-5].sval),yystack.l_mark[-1].elementExpressionVal);
}
break;
case 61:
#line 283 "mbolc.y"
	{
    yyval.sumQualifiersVal=new SumQualifiers(string(yystack.l_mark[-7].sval),string(yystack.l_mark[-5].sval),string(yystack.l_mark[-1].sval));
}
break;
case 62:
#line 286 "mbolc.y"
	{
    yyval.sumQualifiersVal=new SumQualifiers(yystack.l_mark[-1].qualifiersVal);
}
break;
#line 1172 "y.tab.c"
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
