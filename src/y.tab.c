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
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 67 "y.tab.c"

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
#define LS 303
#define RS 304
#define BI 305
#define NU 306
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    6,    6,   20,   20,    4,    4,    4,    4,
    2,    5,    5,    5,    5,    7,    7,    8,    8,    8,
    8,    8,    9,    9,   19,   19,   10,   10,   10,   10,
   10,   10,   10,   10,   10,   10,   10,   10,   16,   16,
   16,   16,   15,   15,   15,   18,   18,   18,   18,   17,
   17,   17,   17,   17,   17,   17,    3,    3,    3,   11,
   11,   11,   11,   12,   12,   13,   14,   14,   14,
};
static const short yylen[] = {                            2,
    4,    7,    1,    3,    1,    1,    1,    1,    2,    2,
    9,    4,    6,    7,    9,    3,    3,    1,    1,    1,
    1,    1,    1,    3,    3,    3,    5,    3,    3,    3,
    3,    3,    3,    5,    5,    5,    5,    3,    1,    3,
    3,    3,    1,    2,    3,    5,    3,    3,    1,    1,
    3,    7,    7,    3,    1,    1,    1,    5,    3,    1,
    1,    1,    1,    1,    3,    3,   10,   10,    4,
};
static const short yydefred[] = {                         0,
    0,    0,    5,    6,    0,    0,    0,    7,    0,    8,
    0,    0,    0,    1,   10,    9,    3,    0,    0,    0,
    0,    0,    0,   55,    0,    0,   50,    0,   43,    0,
    0,    0,    0,    0,   23,    0,    0,    0,    0,    0,
   56,    0,   49,    0,    0,    0,   39,    0,    0,   12,
   22,   21,    0,   60,   61,   62,   63,   18,   19,   20,
    0,    0,   44,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    4,    0,    0,    0,   59,
    0,    0,    0,    0,    0,    0,    0,    0,   51,    0,
    0,    0,    0,   45,    0,   30,    0,    0,    0,   31,
    0,    0,    0,    0,    0,    0,   24,    0,    0,    0,
    0,    0,    0,    0,   48,    0,   47,   42,   41,   40,
    0,   13,    0,   25,   26,    0,    0,    0,    0,    2,
    0,   69,    0,   58,    0,    0,    0,   37,    0,    0,
   36,    0,    0,   14,    0,    0,    0,   46,    0,    0,
    0,    0,   52,   53,   15,   11,    0,    0,    0,    0,
   68,   67,
};
static const short yydgoto[] = {                          2,
    5,    8,   41,    9,   10,   18,   26,   68,   34,   35,
   62,  112,   27,   39,   28,   46,   29,   47,   70,    6,
};
static const short yysindex[] = {                      -265,
 -158,    0,    0,    0, -282, -252, -268,    0, -134,    0,
 -249, -135, -258,    0,    0,    0,    0, -248, -243, -189,
 -135,   29, -170,    0, -174, -169,    0,  -92,    0,  -31,
 -153, -224, -112, -257,    0, -114, -120, -118, -135, -259,
    0,  -19,    0,   29,   84,  -73,    0, -135, -113,    0,
    0,    0, -135,    0,    0,    0,    0,    0,    0,    0,
 -135, -135,    0,   29, -254,   29,   29,  -83,  -74, -159,
   29,   29,  -76, -258,  -56,    0, -135, -203,   69,    0,
   29,  -91,  -29,  -71, -260,   29,   29,   29,    0,    5,
  -52,   69,   69,    0, -178,    0,  -55, -178, -178,    0,
  -34,    1,  -17, -178, -178,  -15,    0, -135,   13,   86,
 -125, -108, -178,   -6,    0, -258,    0,    0,    0,    0,
   -2,    0, -186,    0,    0,   29, -171,    8,    7,    0,
 -245,    0,   29,    0, -135, -184, -135,    0, -178, -178,
    0, -178, -107,    0, -251, -178,   37,    0,   61,   15,
   16,  -18,    0,    0,    0,    0,   18, -140,   21,  -25,
    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -133,
    0,    0,    0,    0,  -51,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   91,    0,
    0, -217,    0,  -78,    0,    0,    0,    0,    0,    0,
    0,   22,   24,    0, -236,    0,    0, -193, -192,    0,
    0,    0,    0, -190, -129,    0,    0,    0,    0,    0,
    0,    0,  -62,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -51,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -127,  -87,
    0,  -70,    0,    0,    0,  -26,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const short yygindex[] = {                         0,
    0,  291,   -9,    0,  293,    0,  196,  286,   -8,  241,
    0,    0,    0,    0,  -20,  -35,  -28,  107,    0,    0,
};
#define YYTABLESIZE 387
static const short yytable[] = {                         63,
   42,   74,   25,   86,   87,   12,   80,   30,   83,   85,
   36,   96,    1,   63,   81,    7,   17,   31,   79,   38,
   96,   11,   38,  152,   88,  117,   37,   90,   95,  123,
   98,   99,   92,   94,   13,  104,  105,   71,   38,   54,
   93,   32,   54,   54,   54,  113,   75,   33,   54,   38,
   63,   97,   54,   54,   54,   54,  109,   54,   54,   54,
  145,   63,  110,   63,   63,   33,   32,   38,   28,  111,
   54,   72,   31,   40,   74,   54,   54,   54,   54,   43,
   63,   33,   32,   49,   28,   86,   87,  139,   54,   44,
  140,  142,   33,   32,   43,   28,   32,  146,  128,  102,
   45,  148,   33,   48,   44,   50,   88,  136,    3,    4,
   33,   32,   69,   28,  147,   45,  149,  103,   63,  138,
   63,   19,  160,   57,   57,   43,   57,   57,   57,   29,
   20,   35,   57,   74,  141,   44,   57,   57,   57,   57,
   21,   57,   57,   57,   14,   29,   45,   35,   73,  132,
  133,   76,   22,   77,   57,   78,   29,   23,   35,   57,
   57,   57,   57,    7,   19,  159,  134,   51,   52,   53,
   24,   27,   57,   20,   29,   91,   35,   54,   55,   56,
   57,  150,  100,   21,  101,   49,   49,   27,   34,  106,
   86,   87,  118,  119,  120,   22,   64,  151,   27,  114,
   23,   58,   59,   60,   34,   56,   49,   49,   56,   56,
   56,   88,   64,   24,   56,   34,   27,  108,   56,   56,
   56,   56,  122,   89,   56,  123,   64,  116,   51,   52,
   65,  124,   65,   34,   86,   87,   56,   19,   86,   87,
  126,   56,   56,   56,   56,  127,   20,  115,   65,  162,
   54,   55,   56,   57,   56,   88,   21,   82,   66,   88,
   67,   19,   58,   59,   60,  143,  125,  135,   22,   19,
   20,  137,  157,   23,   54,   55,   56,   57,   20,  121,
   21,  144,   54,   55,   56,   57,   24,  130,   21,  155,
  156,  158,   22,   19,   43,  161,   17,   23,   16,   15,
   22,   16,   20,  129,   44,   23,   54,   55,   56,   57,
   24,  153,   21,   61,  107,   45,    0,   19,   24,    0,
    0,    0,    0,    0,   22,   19,   20,    0,    0,   23,
   54,   55,   56,   57,   20,  154,   21,    0,   54,   55,
   56,   57,   24,   64,   21,   51,   52,  131,   22,   84,
   66,   66,   66,   23,    0,    0,   22,    0,    0,   44,
    0,   23,    0,    0,    0,   66,   24,   66,    0,    0,
   45,    0,    0,    0,   24,   66,    0,   67,    0,   58,
   59,   60,    0,    0,   66,   66,   66,
};
static const short yycheck[] = {                         28,
   21,  259,   12,  264,  265,  274,  266,  266,   44,   45,
  259,  266,  278,   42,  274,  298,  266,  276,   39,  263,
  266,  274,  259,  275,  285,  286,  275,   48,   64,  281,
   66,   67,   53,   62,  303,   71,   72,  262,  275,  257,
   61,  300,  260,  261,  262,   81,  304,  306,  266,  286,
   79,  306,  270,  271,  272,  273,   77,  275,  276,  277,
  306,   90,  266,   92,   93,  259,  259,  304,  259,   78,
  288,  296,  276,  263,  259,  293,  294,  295,  296,  266,
  109,  275,  275,  258,  275,  264,  265,  123,  306,  276,
  126,  127,  286,  286,  266,  286,  300,  133,  108,  259,
  287,  286,  306,  274,  276,  275,  285,  116,  267,  268,
  304,  304,  266,  304,  135,  287,  137,  277,  147,  306,
  149,  257,  158,  257,  258,  266,  260,  261,  262,  259,
  266,  259,  266,  259,  306,  276,  270,  271,  272,  273,
  276,  275,  276,  277,  279,  275,  287,  275,  261,  275,
  259,  266,  288,  274,  288,  274,  286,  293,  286,  293,
  294,  295,  296,  298,  257,  306,  275,  260,  261,  262,
  306,  259,  306,  266,  304,  289,  304,  270,  271,  272,
  273,  289,  266,  276,  259,  264,  265,  275,  259,  266,
  264,  265,   86,   87,   88,  288,  259,  305,  286,  291,
  293,  294,  295,  296,  275,  257,  285,  286,  260,  261,
  262,  285,  275,  306,  266,  286,  304,  274,  270,  271,
  272,  273,  275,  297,  276,  281,  258,  299,  260,  261,
  262,  266,  259,  304,  264,  265,  288,  257,  264,  265,
  258,  293,  294,  295,  296,  261,  266,  277,  275,  275,
  270,  271,  272,  273,  306,  285,  276,  277,  290,  285,
  292,  257,  294,  295,  296,  258,  266,  274,  288,  257,
  266,  274,  291,  293,  270,  271,  272,  273,  266,  275,
  276,  275,  270,  271,  272,  273,  306,  275,  276,  275,
  275,  274,  288,  257,  266,  275,  275,  293,  275,    9,
  288,    9,  266,  108,  276,  293,  270,  271,  272,  273,
  306,  275,  276,   28,   74,  287,   -1,  257,  306,   -1,
   -1,   -1,   -1,   -1,  288,  257,  266,   -1,   -1,  293,
  270,  271,  272,  273,  266,  275,  276,   -1,  270,  271,
  272,  273,  306,  258,  276,  260,  261,  262,  288,  266,
  260,  261,  262,  293,   -1,   -1,  288,   -1,   -1,  276,
   -1,  293,   -1,   -1,   -1,  275,  306,  277,   -1,   -1,
  287,   -1,   -1,   -1,  306,  290,   -1,  292,   -1,  294,
  295,  296,   -1,   -1,  294,  295,  296,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 306
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
"LT","NE","LJ","CN","CL","ES","IC","MC","LS","RS","BI","NU",
};
static const char *yyrule[] = {
"$accept : program",
"program : AA objective constraints BB",
"objective : objective_type LC program_variables RC LC number_expression RC",
"program_variables : VA",
"program_variables : program_variables CO VA",
"objective_type : MA",
"objective_type : MI",
"constraints : binary_constraint",
"constraints : constraint",
"constraints : constraints constraint",
"constraints : constraints binary_constraint",
"binary_constraint : CN LS qualifiers RS LC variable_map IN BI RC",
"constraint : CN LC equation RC",
"constraint : CN LC variable_map IN ZC RC",
"constraint : CN LS qualifiers RS LC equation RC",
"constraint : CN LS qualifiers RS LC variable_map IN ZC RC",
"equation : number_expression inequality number_expression",
"equation : number_expression EQ number_expression",
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
"qualifier : VA EQ NU DD element_expression",
"qualifier : NU LE VA LE NU",
"qualifier : VA EQ NU DD NU",
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
"number_subexpression : variable_map",
"variable_map : VA",
"variable_map : VA US LC indices RC",
"variable_map : VA US VA",
"number_operator : PL",
"number_operator : SB",
"number_operator : DI",
"number_operator : MU",
"indices : element_expression",
"indices : indices CO element_expression",
"sum : SM sum_qualifiers number_expression",
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
#line 303 "mbolc.y"
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
#line 698 "y.tab.c"

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
#line 68 "mbolc.y"
	{
  program=new Program(yystack.l_mark[-2].objectiveVal,yystack.l_mark[-1].constraintsVal);
  yyval.programVal=program;
}
break;
case 2:
#line 73 "mbolc.y"
	{
  yyval.objectiveVal=new Objective(yystack.l_mark[-6].objectiveTypeVal,yystack.l_mark[-4].programVariablesVal,yystack.l_mark[-1].numberExpressionVal);
}
break;
case 3:
#line 77 "mbolc.y"
	{
  yyval.programVariablesVal=new ProgramVariables(string(yystack.l_mark[0].sval));
}
break;
case 4:
#line 80 "mbolc.y"
	{
  yystack.l_mark[-2].programVariablesVal->variables.push_back(string(yystack.l_mark[0].sval));
}
break;
case 5:
#line 84 "mbolc.y"
	{
  yyval.objectiveTypeVal=new ObjectiveType("max");
}
break;
case 6:
#line 87 "mbolc.y"
	{
  yyval.objectiveTypeVal=new ObjectiveType("min");
}
break;
case 7:
#line 91 "mbolc.y"
	{
  yyval.constraintsVal=yystack.l_mark[0].binaryConstraintVal;
}
break;
case 8:
#line 94 "mbolc.y"
	{
  yyval.constraintsVal=new Constraints(yystack.l_mark[0].constraintVal);
}
break;
case 9:
#line 97 "mbolc.y"
	{
  yystack.l_mark[-1].constraintsVal->constraints.push_back(yystack.l_mark[0].constraintVal);
}
break;
case 10:
#line 100 "mbolc.y"
	{
  for(list<Constraint*>::iterator i=yystack.l_mark[0].binaryConstraintVal->constraints.begin();i!=yystack.l_mark[0].binaryConstraintVal->constraints.end();i++) {
    yystack.l_mark[-1].constraintsVal->constraints.push_back(*i);
  }
}
break;
case 11:
#line 106 "mbolc.y"
	{
  yyval.binaryConstraintVal=new Constraints(new Constraint(yystack.l_mark[-3].variableMap->variableName));
  yyval.binaryConstraintVal->constraints.push_back(new Constraint(new Equation(new NumberExpression(yystack.l_mark[-3].variableMap),new Inequality("<="),new NumberExpression(new NumberLiteral("1"))),new Equation(new NumberExpression(yystack.l_mark[-3].variableMap),new Inequality(">="),new NumberExpression(new NumberLiteral("0"))),yystack.l_mark[-6].qualifiersVal));
}
break;
case 12:
#line 111 "mbolc.y"
	{
  yyval.constraintVal=new Constraint(yystack.l_mark[-1].equationVal);
}
break;
case 13:
#line 114 "mbolc.y"
	{
  yyval.constraintVal=new Constraint(yystack.l_mark[-3].variableMap->variableName);
}
break;
case 14:
#line 117 "mbolc.y"
	{
  yyval.constraintVal=new Constraint(yystack.l_mark[-1].equationVal,yystack.l_mark[-4].qualifiersVal);
}
break;
case 15:
#line 120 "mbolc.y"
	{
  yyval.constraintVal=new Constraint(yystack.l_mark[-3].variableMap->variableName);
}
break;
case 16:
#line 124 "mbolc.y"
	{
  yyval.equationVal=new Equation(yystack.l_mark[-2].numberExpressionVal,yystack.l_mark[-1].inequalityVal,yystack.l_mark[0].numberExpressionVal);
}
break;
case 17:
#line 127 "mbolc.y"
	{
  yyval.equationVal=new Equation(yystack.l_mark[-2].numberExpressionVal,new Inequality("=="),yystack.l_mark[0].numberExpressionVal);
}
break;
case 18:
#line 131 "mbolc.y"
	{
  yyval.inequalityVal=new Inequality(">");
}
break;
case 19:
#line 134 "mbolc.y"
	{
  yyval.inequalityVal=new Inequality("<");
}
break;
case 20:
#line 137 "mbolc.y"
	{
  yyval.inequalityVal=new Inequality("!=");
}
break;
case 21:
#line 140 "mbolc.y"
	{
  yyval.inequalityVal=new Inequality("<=");
}
break;
case 22:
#line 143 "mbolc.y"
	{
  yyval.inequalityVal=new Inequality(">=");
}
break;
case 23:
#line 147 "mbolc.y"
	{
  yyval.qualifiersVal=new Qualifiers(yystack.l_mark[0].qualifierVal);
}
break;
case 24:
#line 150 "mbolc.y"
	{
  yystack.l_mark[-2].qualifiersVal->qualifiers.push_back(yystack.l_mark[0].qualifierVal);
}
break;
case 25:
#line 154 "mbolc.y"
	{
  yyval.tupleIndicesVal=new TupleIndices(yystack.l_mark[-2].sval,yystack.l_mark[0].sval);
}
break;
case 26:
#line 157 "mbolc.y"
	{
  yystack.l_mark[-2].tupleIndicesVal->indices.push_back(string(yystack.l_mark[0].sval));
}
break;
case 27:
#line 161 "mbolc.y"
	{
  yyval.qualifierVal=new Qualifier(yystack.l_mark[-3].tupleIndicesVal,yystack.l_mark[0].elementExpressionVal);
}
break;
case 28:
#line 164 "mbolc.y"
	{
  yyval.qualifierVal=new Qualifier("0",new Inequality("=="),new SetSize(yystack.l_mark[0].elementExpressionVal));
}
break;
case 29:
#line 167 "mbolc.y"
	{
  yyval.qualifierVal=new Qualifier("0",new Inequality("!="),new SetSize(yystack.l_mark[0].elementExpressionVal));
}
break;
case 30:
#line 170 "mbolc.y"
	{
  yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),new Inequality("=="),string(yystack.l_mark[0].sval));
}
break;
case 31:
#line 173 "mbolc.y"
	{
  yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),yystack.l_mark[-1].inequalityVal,string(yystack.l_mark[0].sval));
}
break;
case 32:
#line 176 "mbolc.y"
	{
  yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),"subset",yystack.l_mark[0].elementExpressionVal);
}
break;
case 33:
#line 179 "mbolc.y"
	{
  yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),"subsetequal",yystack.l_mark[0].elementExpressionVal);
}
break;
case 34:
#line 182 "mbolc.y"
	{
  yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),"in",new ElementExpression(new ElementSubexpression(new ElementNumbers(string(yystack.l_mark[-4].sval),yystack.l_mark[0].elementExpressionVal))));
}
break;
case 35:
#line 185 "mbolc.y"
	{
  yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-4].sval),"in",new ElementExpression(new ElementSubexpression(new ElementNumbers(string(yystack.l_mark[-2].sval),yystack.l_mark[0].elementExpressionVal))));
}
break;
case 36:
#line 188 "mbolc.y"
	{
  yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),"in",new ElementExpression(new ElementSubexpression(new ElementNumbers(string(yystack.l_mark[-4].sval),string(yystack.l_mark[0].sval)))));
}
break;
case 37:
#line 191 "mbolc.y"
	{
  yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-4].sval),"in",new ElementExpression(new ElementSubexpression(new ElementNumbers(string(yystack.l_mark[-2].sval),string(yystack.l_mark[0].sval)))));
}
break;
case 38:
#line 194 "mbolc.y"
	{
  yyval.qualifierVal=new Qualifier(string(yystack.l_mark[-2].sval),"in",yystack.l_mark[0].elementExpressionVal);
}
break;
case 39:
#line 198 "mbolc.y"
	{
  yyval.elementExpressionVal=new ElementExpression(yystack.l_mark[0].elementSubexpressionVal);
}
break;
case 40:
#line 201 "mbolc.y"
	{
  yyval.elementExpressionVal=new ElementExpression(yystack.l_mark[-2].elementExpressionVal,new ElementOperator("reduce"),yystack.l_mark[0].elementSubexpressionVal);
}
break;
case 41:
#line 204 "mbolc.y"
	{
  yyval.elementExpressionVal=new ElementExpression(yystack.l_mark[-2].elementExpressionVal,new ElementOperator("union"),yystack.l_mark[0].elementSubexpressionVal);
}
break;
case 42:
#line 207 "mbolc.y"
	{
  yyval.elementExpressionVal=new ElementExpression(yystack.l_mark[-2].elementExpressionVal,new ElementOperator("intersect"),yystack.l_mark[0].elementSubexpressionVal);
}
break;
case 43:
#line 211 "mbolc.y"
	{
  yyval.numberExpressionVal=new NumberExpression(yystack.l_mark[0].numberSubexpressionVal);
}
break;
case 44:
#line 214 "mbolc.y"
	{
  yystack.l_mark[-1].numberExpressionVal->numberSubexpressions.push_back(yystack.l_mark[0].numberSubexpressionVal);
  yystack.l_mark[-1].numberExpressionVal->numberOperators.push_back(new NumberOperator("*"));
}
break;
case 45:
#line 218 "mbolc.y"
	{
  yystack.l_mark[-2].numberExpressionVal->numberSubexpressions.push_back(yystack.l_mark[0].numberSubexpressionVal);
  yystack.l_mark[-2].numberExpressionVal->numberOperators.push_back(yystack.l_mark[-1].numberOperatorVal);
}
break;
case 46:
#line 223 "mbolc.y"
	{
  yyval.elementSubexpressionVal=new ElementSubexpression(new SetCreator(string(yystack.l_mark[-3].sval),yystack.l_mark[-1].qualifiersVal));
}
break;
case 47:
#line 226 "mbolc.y"
	{
  yyval.elementSubexpressionVal=new ElementSubexpression(new ElementSet(yystack.l_mark[-1].elementExpressionVal));
}
break;
case 48:
#line 229 "mbolc.y"
	{
  yyval.elementSubexpressionVal=new ElementSubexpression(new ElementParantheses(yystack.l_mark[-1].elementExpressionVal));
}
break;
case 49:
#line 232 "mbolc.y"
	{
  yyval.elementSubexpressionVal=new ElementSubexpression(new ElementVariable(string(yystack.l_mark[0].sval)));
}
break;
case 50:
#line 236 "mbolc.y"
	{
  yyval.numberSubexpressionVal=yystack.l_mark[0].sumVal;
}
break;
case 51:
#line 239 "mbolc.y"
	{
  yyval.numberSubexpressionVal=new SetSize(yystack.l_mark[-1].elementExpressionVal);
}
break;
case 52:
#line 242 "mbolc.y"
	{
  yyval.numberSubexpressionVal=new NumberPower(yystack.l_mark[-5].numberExpressionVal,yystack.l_mark[-1].numberExpressionVal);
}
break;
case 53:
#line 245 "mbolc.y"
	{
  yyval.numberSubexpressionVal=new Fraction(yystack.l_mark[-4].numberExpressionVal,yystack.l_mark[-1].numberExpressionVal);
}
break;
case 54:
#line 248 "mbolc.y"
	{
  yyval.numberSubexpressionVal=new NumberParantheses(yystack.l_mark[-1].numberExpressionVal);
}
break;
case 55:
#line 251 "mbolc.y"
	{
  yyval.numberSubexpressionVal=new NumberLiteral(string(yystack.l_mark[0].sval));
}
break;
case 56:
#line 254 "mbolc.y"
	{
  yyval.numberSubexpressionVal=yystack.l_mark[0].variableMap;
}
break;
case 57:
#line 258 "mbolc.y"
	{
  yyval.variableMap=new VariableMap(string(yystack.l_mark[0].sval));
}
break;
case 58:
#line 261 "mbolc.y"
	{
  yyval.variableMap=new VariableMap(string(yystack.l_mark[-4].sval),yystack.l_mark[-1].indicesVal);
}
break;
case 59:
#line 264 "mbolc.y"
	{
  yyval.variableMap=new VariableMap(string(yystack.l_mark[-2].sval),string(yystack.l_mark[0].sval));
}
break;
case 60:
#line 268 "mbolc.y"
	{
  yyval.numberOperatorVal=new NumberOperator("+");
}
break;
case 61:
#line 271 "mbolc.y"
	{
  yyval.numberOperatorVal=new NumberOperator("-");
}
break;
case 62:
#line 274 "mbolc.y"
	{
  yyval.numberOperatorVal=new NumberOperator("/");
}
break;
case 63:
#line 277 "mbolc.y"
	{
  yyval.numberOperatorVal=new NumberOperator("*");
}
break;
case 64:
#line 281 "mbolc.y"
	{
  yyval.indicesVal=new Indices(yystack.l_mark[0].elementExpressionVal);
}
break;
case 65:
#line 284 "mbolc.y"
	{
  yystack.l_mark[-2].indicesVal->elementExpressions.push_back(yystack.l_mark[0].elementExpressionVal);
}
break;
case 66:
#line 288 "mbolc.y"
	{
  yyval.sumVal=new Sum(string(yystack.l_mark[-2].sval),yystack.l_mark[-1].sumQualifiersVal,yystack.l_mark[0].numberExpressionVal);
}
break;
case 67:
#line 292 "mbolc.y"
	{
  yyval.sumQualifiersVal=new SumQualifiers(string(yystack.l_mark[-7].sval),string(yystack.l_mark[-5].sval),yystack.l_mark[-1].elementExpressionVal);
}
break;
case 68:
#line 295 "mbolc.y"
	{
  yyval.sumQualifiersVal=new SumQualifiers(string(yystack.l_mark[-7].sval),string(yystack.l_mark[-5].sval),string(yystack.l_mark[-1].sval));
}
break;
case 69:
#line 298 "mbolc.y"
	{
  yyval.sumQualifiersVal=new SumQualifiers(yystack.l_mark[-1].qualifiersVal);
}
break;
#line 1324 "y.tab.c"
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
