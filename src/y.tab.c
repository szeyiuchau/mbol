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
#define EX 306
#define NU 307
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    6,    6,   20,   20,    4,    4,    4,    4,
    2,    5,    5,    5,    5,    7,    7,    8,    8,    8,
    8,    8,    9,    9,   19,   19,   10,   10,   10,   10,
   10,   10,   10,   10,   10,   10,   10,   16,   16,   16,
   16,   16,   15,   15,   15,   18,   18,   18,   18,   18,
   17,   17,   17,   17,   17,   17,   17,    3,    3,    3,
   11,   11,   11,   11,   12,   12,   13,   14,   14,
};
static const short yylen[] = {                            2,
    4,    7,    1,    3,    1,    1,    1,    1,    2,    2,
    9,    4,    6,    7,    9,    3,    3,    1,    1,    1,
    1,    1,    1,    3,    3,    3,    4,    5,    3,    3,
    3,    3,    3,    3,    5,    5,    3,    1,    3,    3,
    3,    3,    1,    2,    3,    5,    3,    3,    1,    1,
    1,    3,    7,    7,    3,    1,    1,    1,    5,    3,
    1,    1,    1,    1,    1,    3,    3,   10,    4,
};
static const short yydefred[] = {                         0,
    0,    0,    5,    6,    0,    0,    0,    7,    0,    8,
    0,    0,    0,    1,   10,    9,    3,    0,    0,    0,
    0,    0,    0,   56,    0,    0,   51,    0,   43,    0,
    0,    0,    0,    0,    0,   23,    0,    0,    0,    0,
    0,   57,    0,   49,    0,    0,   50,    0,   38,    0,
    0,   12,   22,   21,    0,   61,   62,   63,   64,   18,
   19,   20,    0,    0,   44,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    4,    0,
    0,   67,   60,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   52,    0,    0,    0,    0,   45,    0,   31,
    0,    0,    0,   32,    0,    0,    0,    0,    0,    0,
    0,   24,    0,    0,    0,    0,    0,    0,    0,   48,
    0,   47,   42,   41,   39,   40,    0,   13,    0,   25,
   26,    0,    0,    0,    0,    0,    2,    0,   69,    0,
   59,    0,    0,    0,    0,    0,    0,    0,   14,    0,
    0,    0,   46,    0,    0,    0,    0,   53,   54,   15,
   11,    0,    0,    0,   68,
};
static const short yydgoto[] = {                          2,
    5,    8,   42,    9,   10,   18,   26,   70,   35,   36,
   64,  117,   27,   40,   28,   48,   29,   49,   72,    6,
};
static const short yysindex[] = {                      -257,
  -67,    0,    0,    0, -288, -260, -268,    0, -270,    0,
 -204, -216, -146,    0,    0,    0,    0, -202, -205, -187,
 -216, -258, -165,    0, -171, -186,    0,  -89,    0,   59,
 -145, -240, -128, -148, -256,    0, -127, -117, -111, -216,
 -162,    0, -246,    0, -258,   39,    0,   27,    0, -216,
 -144,    0,    0,    0, -216,    0,    0,    0,    0,    0,
    0,    0, -216, -216,    0, -258, -264, -258, -258,  -90,
  -73, -206, -258, -258,  -69,  -76, -146,  -60,    0, -216,
    4,    0,    0, -258,  -95,   71,  -83,   80, -258, -258,
 -258, -258,    0,  -78,  -45,   30,   30,    0, -115,    0,
  -41, -115, -115,    0,  -35,  -25,  -15, -115, -115, -258,
   -5,    0, -216,  -38,   67, -153, -152, -115,  -23,    0,
 -146,    0,    0,    0,    0,    0,  -22,    0, -258,    0,
    0, -258, -115, -258,   23,    7,    0, -253,    0, -258,
    0, -216, -254, -216, -115, -115, -115, -149,    0, -167,
 -115,   -9,    0,    2,    8,   10,  -31,    0,    0,    0,
    0,   12, -258, -200,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -178,
    0,    0,    0,    0,  -49,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -129,    0,  103,    0,    0,    0,
    0,    0,    0,    0,    0,   13,   14,    0, -252,    0,
    0, -208, -185,    0,    0,    0,    0, -124, -101,    0,
    0,    0,    0,    0,    0,    0,    0, -123,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -84,    0,  -49,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -50,  -33,  -10,    0,    0,    0,
 -106,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,  284,  -11,    0,  290,    0,  194,  280,  -62,  236,
    0,    0,    0,    0,  -17,  -29,  -28,  241,    0,    0,
};
#define YYTABLESIZE 389
static const short yytable[] = {                         65,
   25,  100,   77,   43,   77,   12,   37,   44,   14,    7,
   19,   82,  100,   11,   65,   86,   88,   45,  116,   20,
    1,   73,   37,   56,   57,   58,   59,    7,   46,   21,
   85,  153,   94,   37,   13,   98,   99,   96,  102,  103,
   19,   22,  101,  108,  109,   97,   23,   78,   47,   20,
   34,   37,  106,  150,  118,   74,   37,   39,  143,   21,
   24,   17,  114,   89,   90,   65,   34,   65,   65,   91,
  107,   22,   38,   33,  165,   41,   23,   34,   58,   58,
  133,   58,   58,   58,   92,   65,   51,   58,   52,   33,
   24,   58,   58,   58,   58,   34,   58,   58,   58,  145,
   33,  135,  146,   83,  147,   77,  140,  157,   50,   58,
  151,   84,   76,  129,   58,   58,   58,   58,   33,   30,
   71,  139,  141,   65,  152,   65,  154,   55,   58,   31,
   55,   55,   55,  164,   29,   65,   55,   75,   79,  155,
   55,   55,   55,   55,   95,   55,   55,   55,   89,   90,
   29,   65,   66,   32,   91,  156,   80,   30,   55,   33,
   34,   29,   81,   55,   55,   55,   55,   19,   66,   92,
   53,   54,   55,   30,   27,  104,   20,   55,   19,   29,
   56,   57,   58,   59,   30,  105,   21,   20,  110,  111,
   27,   56,   57,   58,   59,  119,  127,   21,   22,    3,
    4,   27,   30,   23,   60,   61,   62,   57,   36,   22,
   57,   57,   57,  113,   23,  121,   57,   24,   19,   27,
   57,   57,   57,   57,   36,   28,   57,   20,   24,  128,
  130,   56,   57,   58,   59,   36,  137,   21,   57,  129,
  131,   28,  132,   57,   57,   57,   57,   19,   35,   22,
  142,  144,   28,   36,   23,  134,   20,   57,   19,  162,
   56,   57,   58,   59,   35,  158,   21,   20,   24,  115,
   28,   56,   57,   58,   59,   35,  159,   21,   22,   31,
  148,  149,  160,   23,  161,  163,   19,   17,   16,   22,
   89,   90,   15,   35,   23,   20,   91,   24,   16,   56,
   57,   58,   59,   32,   87,   21,  136,   63,   24,   33,
   34,   92,  112,    0,   45,    0,   66,   22,   53,   54,
   67,    0,   23,   93,   66,   46,   53,   54,  138,  123,
  124,  125,  126,    0,   89,   90,   24,    0,    0,    0,
   91,    0,    0,   89,   90,   47,    0,  120,   68,   91,
   69,    0,   60,   61,   62,   92,   68,    0,   69,    0,
   60,   61,   62,    0,   92,  122,   49,   49,    0,    0,
    0,    0,   49,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   49,   49,
};
static const short yycheck[] = {                         28,
   12,  266,  259,   21,  259,  274,  259,  266,  279,  298,
  257,   40,  266,  274,   43,   45,   46,  276,   81,  266,
  278,  262,  275,  270,  271,  272,  273,  298,  287,  276,
  277,  286,   50,  286,  303,   64,   66,   55,   68,   69,
  257,  288,  307,   73,   74,   63,  293,  304,  307,  266,
  259,  304,  259,  307,   84,  296,  259,  263,  121,  276,
  307,  266,   80,  264,  265,   94,  275,   96,   97,  270,
  277,  288,  275,  259,  275,  263,  293,  286,  257,  258,
  110,  260,  261,  262,  285,  114,  258,  266,  275,  275,
  307,  270,  271,  272,  273,  304,  275,  276,  277,  129,
  286,  113,  132,  266,  134,  259,  259,  275,  274,  288,
  140,  274,  261,  281,  293,  294,  295,  296,  304,  266,
  266,  275,  275,  152,  142,  154,  144,  257,  307,  276,
  260,  261,  262,  163,  259,  259,  266,  266,  266,  289,
  270,  271,  272,  273,  289,  275,  276,  277,  264,  265,
  275,  275,  259,  300,  270,  305,  274,  259,  288,  306,
  307,  286,  274,  293,  294,  295,  296,  257,  275,  285,
  260,  261,  262,  275,  259,  266,  266,  307,  257,  304,
  270,  271,  272,  273,  286,  259,  276,  266,  258,  266,
  275,  270,  271,  272,  273,  291,  275,  276,  288,  267,
  268,  286,  304,  293,  294,  295,  296,  257,  259,  288,
  260,  261,  262,  274,  293,  299,  266,  307,  257,  304,
  270,  271,  272,  273,  275,  259,  276,  266,  307,  275,
  266,  270,  271,  272,  273,  286,  275,  276,  288,  281,
  266,  275,  258,  293,  294,  295,  296,  257,  259,  288,
  274,  274,  286,  304,  293,  261,  266,  307,  257,  291,
  270,  271,  272,  273,  275,  275,  276,  266,  307,  266,
  304,  270,  271,  272,  273,  286,  275,  276,  288,  276,
  258,  275,  275,  293,  275,  274,  257,  275,  275,  288,
  264,  265,    9,  304,  293,  266,  270,  307,    9,  270,
  271,  272,  273,  300,  266,  276,  113,   28,  307,  306,
  307,  285,   77,   -1,  276,   -1,  258,  288,  260,  261,
  262,   -1,  293,  297,  258,  287,  260,  261,  262,   89,
   90,   91,   92,   -1,  264,  265,  307,   -1,   -1,   -1,
  270,   -1,   -1,  264,  265,  307,   -1,  277,  290,  270,
  292,   -1,  294,  295,  296,  285,  290,   -1,  292,   -1,
  294,  295,  296,   -1,  285,  286,  264,  265,   -1,   -1,
   -1,   -1,  270,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  285,  286,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 307
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
"LT","NE","LJ","CN","CL","ES","IC","MC","LS","RS","BI","EX","NU",
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
"qualifier : EX VA IN element_expression",
"qualifier : LP tuple_indices RP IN element_expression",
"qualifier : ES EQ element_expression",
"qualifier : ES NE element_expression",
"qualifier : VA EQ VA",
"qualifier : VA inequality VA",
"qualifier : VA SS element_expression",
"qualifier : VA SE element_expression",
"qualifier : NU LE VA LE element_expression",
"qualifier : VA EQ NU DD element_expression",
"qualifier : VA IN element_expression",
"element_expression : element_subexpression",
"element_expression : element_expression PL element_subexpression",
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
"element_subexpression : NU",
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
"sum : SM sum_qualifiers number_subexpression",
"sum_qualifiers : US LC VA EQ NU RC CT LC element_expression RC",
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
#line 302 "mbolc.y"
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
string replaceAll(string a, string b, string c) {
  while (a.find(b) != string::npos) {
    a = a.substr(0, a.find(b)) + c + a.substr(a.find(b) + b.size());
  }
  return a;
}
int countStr(string a, string b) {
  int x = 0;
  while (a.find(b) != string::npos) {
    x++;
    a = a.substr(0, a.find(b)) + a.substr(a.find(b) + b.size());
  }
  return x;
}
bool quiet;
map<string, string> options;
void usage() {
  cout << "Usage: mbolc [options] input_file" << endl;
  cout << "Options:" << endl;
  int msize = 0;
  for (map<string, string>::iterator i = options.begin(); i != options.end(); i++) {
    if (i->first.size() > msize) {
      msize = i->first.size();
    }
  }
  for (map<string, string>::iterator i = options.begin(); i != options.end(); i++) {
    cout << "  " << i->first;
    for (int j = 0; j < msize + 2 - i->first.size(); j++) {
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
  string indentedCode = "";
  int depth = 0;
  while (!code.empty()) {
    string line;
    line = code.substr(0, code.find("\n") + 1);
    code = code.substr(code.find("\n") + 1);
    if (line.find("}") != string::npos) {
      depth--;
    }
    for (int j = 0; j < depth; j++) {
      indentedCode += "  ";
    }
    indentedCode += line;
    if (line.find("{") != string::npos) {
      depth++;
    }
  }
  return indentedCode;
}
int main(int argc, char* argv[]) {
  bool inputRead = false;
  quiet = false;
  string inputName;
  string outputDirectory = "./";
  string className;
  bool ast = false;
  bool hpp = false;
  bool bin = false;
  bool pdf = false;
  bool typ = false;
  bool img = false;
  bool cpx = false;
  options["-v"] = "Print version information and exit";
  options["-h"] = "Print help information and exit";
  options["-q"] = "Put CPLEX in quiet mode";
  options["-d <arg>"] = "Use <arg> as output directory";
  options["-typ"] = "Print types inferred by mbolc";
  options["-bin"] = "Compile a binary for default file I/O";
  options["-pdf"] = "Compile a pdf of the program";
  options["-img"] = "Compile a formatted pdf using imagemagick";
  options["-hpp"] = "Compile a hpp header of the program";
  options["-cpx"] = "User CPLEX as solver (COIN-OR symphony is deafult)";
  options["-ast"] = "Graphviz abstract syntax tree";
  for (int i = 1; i < argc; i++) {
    if (string(argv[i]) == "-q") {
      quiet = true;
    } else if (string(argv[i]) == "-v") {
      version();
    } else if (string(argv[i]) == "-h") {
      help();
    } else if (string(argv[i]) == "-cpx") {
      cpx = true;
    } else if (string(argv[i]) == "-typ") {
      typ = true;
    } else if (string(argv[i]) == "-ast") {
      ast = true;
    } else if (string(argv[i]) == "-pdf") {
      pdf = true;
    } else if (string(argv[i]) == "-img") {
      img = true;
    } else if (string(argv[i]) == "-bin") {
      bin = true;
    } else if (string(argv[i]) == "-hpp") {
      hpp = true;
    } else if (string(argv[i]) == "-d") {
      i++;
      if (i < argc) {
        outputDirectory = string(argv[i]);
        if (outputDirectory[outputDirectory.size() - 1] != '/') {
          outputDirectory += "/";
        }
      } else {
        badArgs();
      }
    } else if (!inputRead) {
      inputRead = true;
      inputName = string(argv[i]);
      if (inputName.find(".tex") != inputName.size() - 4) {
        cout << "Input file must be of the form *.tex" << endl;
        exit(1);
      }
      className = inputName.substr(0, inputName.size() - 4);
      if (className.find("/") != string::npos) {
        className = className.substr(className.rfind("/") + 1);
      }
    } else {
      badArgs();
    }
  }
  
  if (!inputRead) {
    badArgs();
  }
  
  map<string, Type*> types;
  if (hpp || bin || typ || ast) {
    yyin = fopen(inputName.c_str(), "r");
    yyparse();
    fclose(yyin);
    MbolElementVisitor* vTypes = new MbolElementVisitorTypeHelper();
    program->accept(*vTypes);
    types = ((MbolElementVisitorTypeHelper*)vTypes)->types;
  }
  
  if (ast) {
    MbolElementVisitorPrinter* dot = new MbolElementVisitorPrinter();
    program->accept(*dot);
    dot->end();
  }
  
  if (typ) {
    cout << "Program variables:" << endl;
    for (map<string, Type*>::iterator i = types.begin(); i != types.end(); i++) {
      if (!getTemporaries().count(i->first)) {
        if (i->second->isVariable) {
          cout << "  " << i->first << ": " << i->second->print() << endl;
        }
      }
    }
    cout << endl;
    cout << "Program constants:" << endl;
    for (map<string, Type*>::iterator i = types.begin(); i != types.end(); i++) {
      if (!getTemporaries().count(i->first)) {
        if (i->second->isConstant && !i->second->isLiteral) {
          cout << "  " << i->first << ": " << i->second->print() << endl;
        }
      }
    }
    cout << endl;
    cout << "Program constant temporaries:" << endl;
    for (map<string, Type*>::iterator i = types.begin(); i != types.end(); i++) {
      if (!getTemporaries().count(i->first)) {
        if (i->second->isTemporary) {
          cout << "  " << i->first << ": " << i->second->print() << endl;
        }
      }
    }
  }
  
  if (hpp || bin) {
    string code;
    MbolElementVisitor* vCplex = new MbolElementVisitorCPLEX(types, quiet, className);
    program->accept(*vCplex);
    code = ((MbolElementVisitorCPLEX*)vCplex)->code;
    if (cpx) {
      code = "#define CPLEX\n" + code;
    }
    code = indentCode(code);
    ofstream out((outputDirectory + className + ".hpp").c_str());
    out << code;
    out.close();
  }
  
  if (bin) {
    char* mbolHomeC = getenv("MBOL_HOME");
    if (mbolHomeC == NULL) {
      cout << "ERROR: must set environment variable \"MBOL_HOME\" to create binary for default file I/O" << endl;
      exit(1);
    }
    string mbolHome(mbolHomeC);
    if (mbolHome[mbolHome.size() - 1] != '/') {
      mbolHome += "/";
    }
    char* cplexHomeC = getenv("CPLEX_HOME");
    if (cplexHomeC == NULL) {
      cout << "ERROR: must set environment variable \"CPLEX_HOME\" to create binary for default file I/O" << endl;
      exit(1);
    }
    string cplexHome(cplexHomeC);
    if (cplexHome[cplexHome.size() - 1] != '/') {
      cplexHome += "/";
    }
    string cppName = outputDirectory + className + ".cpp";
    string cppCode = "#include<" + className + ".hpp>\nusing namespace std;\nint main(int argc,char* argv[]) {\n" + className + " x;\nstring input,output;\nif(argc >= 2) {\ninput = string(argv[1]);\n} else {\ninput = \"input.txt\";\n}\nif (argc >= 3) {\noutput = string(argv[2]);\n} else {\noutput = \"output.txt\";\n}\nx.readAll(input);\nx.solve();\nx.writeAll(output);\n}\n";
    ofstream cpp(cppName.c_str());
    cpp << indentCode(cppCode);
    cpp.close();
    
    string compileCmd;
    if (cpx) {
      compileCmd = "g++ -O3 -fopenmp -m64 -fPIC -static -static-libstdc++ -static-libgcc -fno-strict-aliasing -fexceptions -DNDEBUG -DIL_STD -I" + mbolHome + "include -I" + cplexHome + "cplex/include -I" + cplexHome + "concert/include -I" + outputDirectory + " " + cppName + " -o " + outputDirectory + className + " -L" + cplexHome + "cplex/lib/x86-64_sles10_4.1/static_pic -lilocplex -lcplex -L" + cplexHome + "concert/lib/x86-64_sles10_4.1/static_pic -lconcert -lm -pthread";
    } else {
      compileCmd = "g++ -I" + mbolHome + "include" + " -I" + outputDirectory + " " + cppName + " -o " + outputDirectory + className;
    }
    //cout << compileCmd << endl;
    system(compileCmd.c_str());
  }
  
  if (pdf || img) {
    char* mbolHomeC = getenv("MBOL_HOME");
    if (mbolHomeC == NULL) {
      cout << "ERROR: must set environment variable \"MBOL_HOME\" to create pdf" << endl;
      exit(1);
    }
    string mbolHome(mbolHomeC);
    if (mbolHome[mbolHome.size() - 1] != '/') {
      mbolHome += "/";
    }
    string texMainName = outputDirectory + className + "_main";
    ofstream texMain((texMainName + ".tex").c_str());
    texMain << "\\documentclass{article}" << endl;
    texMain << "\\input{" << mbolHome << "include/mbol.tex}" << endl;
    if (img) {
      texMain << "\\usepackage[paperwidth=20in,paperheight=8in]{geometry}" << endl;
    } else {
      texMain << "\\usepackage{fullpage}" << endl;
    }
    texMain << "\\begin{document}" << endl;
    texMain << "\\pagenumbering{gobble}" << endl;
    texMain << "\\input{" + inputName + "}" << endl;
    texMain << "\\end{document}" << endl;
    texMain.close();
    system(("pdflatex -output-directory " + outputDirectory + " " + texMainName + ".tex > /dev/null").c_str());
    if (img) {
      system(("convert -quality 100 -density 300 -trim " + texMainName + ".pdf " + texMainName + ".jpeg").c_str());
      system(("convert " + texMainName + ".jpeg " + texMainName + ".pdf").c_str());
    }
    system(("rm -rf " + texMainName + ".log").c_str());
    system(("rm -rf " + texMainName + ".aux").c_str());
    system(("rm -rf " + texMainName + ".tex").c_str());
    system(("rm -rf " + texMainName + ".jpeg").c_str());
    system(("mv " + texMainName + ".pdf " + texMainName.substr(0, texMainName.size() - 5) + ".pdf").c_str());
  }
  return 0;
}
#line 728 "y.tab.c"

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
  program = new Program(yystack.l_mark[-2].objectiveVal, yystack.l_mark[-1].constraintsVal);
  yyval.programVal = program;
}
break;
case 2:
#line 73 "mbolc.y"
	{
  yyval.objectiveVal = new Objective(yystack.l_mark[-6].objectiveTypeVal, yystack.l_mark[-4].programVariablesVal, yystack.l_mark[-1].numberExpressionVal);
}
break;
case 3:
#line 77 "mbolc.y"
	{
  yyval.programVariablesVal = new ProgramVariables(string(yystack.l_mark[0].sval));
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
  yyval.objectiveTypeVal = new ObjectiveType("max");
}
break;
case 6:
#line 87 "mbolc.y"
	{
  yyval.objectiveTypeVal = new ObjectiveType("min");
}
break;
case 7:
#line 91 "mbolc.y"
	{
  yyval.constraintsVal = yystack.l_mark[0].binaryConstraintVal;
}
break;
case 8:
#line 94 "mbolc.y"
	{
  yyval.constraintsVal = new Constraints(yystack.l_mark[0].constraintVal);
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
  for (list<Constraint*>::iterator i = yystack.l_mark[0].binaryConstraintVal->constraints.begin(); i != yystack.l_mark[0].binaryConstraintVal->constraints.end(); i++) {
    yystack.l_mark[-1].constraintsVal->constraints.push_back(*i);
  }
}
break;
case 11:
#line 106 "mbolc.y"
	{
  yyval.binaryConstraintVal = new Constraints(new Constraint(yystack.l_mark[-3].variableMap->variableName));
  yyval.binaryConstraintVal->constraints.push_back(new Constraint(new Equation(new NumberExpression(yystack.l_mark[-3].variableMap), new Inequality("<="), new NumberExpression(new NumberLiteral("1"))), new Equation(new NumberExpression(yystack.l_mark[-3].variableMap), new Inequality(">="), new NumberExpression(new NumberLiteral("0"))), yystack.l_mark[-6].qualifiersVal));
}
break;
case 12:
#line 111 "mbolc.y"
	{
  yyval.constraintVal = new Constraint(yystack.l_mark[-1].equationVal);
}
break;
case 13:
#line 114 "mbolc.y"
	{
  yyval.constraintVal = new Constraint(yystack.l_mark[-3].variableMap->variableName);
}
break;
case 14:
#line 117 "mbolc.y"
	{
  yyval.constraintVal = new Constraint(yystack.l_mark[-1].equationVal, yystack.l_mark[-4].qualifiersVal);
}
break;
case 15:
#line 120 "mbolc.y"
	{
  yyval.constraintVal = new Constraint(yystack.l_mark[-3].variableMap->variableName);
}
break;
case 16:
#line 124 "mbolc.y"
	{
  yyval.equationVal = new Equation(yystack.l_mark[-2].numberExpressionVal, yystack.l_mark[-1].inequalityVal, yystack.l_mark[0].numberExpressionVal);
}
break;
case 17:
#line 127 "mbolc.y"
	{
  yyval.equationVal = new Equation(yystack.l_mark[-2].numberExpressionVal, new Inequality("=="), yystack.l_mark[0].numberExpressionVal);
}
break;
case 18:
#line 131 "mbolc.y"
	{
  yyval.inequalityVal = new Inequality(">");
}
break;
case 19:
#line 134 "mbolc.y"
	{
  yyval.inequalityVal = new Inequality("<");
}
break;
case 20:
#line 137 "mbolc.y"
	{
  yyval.inequalityVal = new Inequality("!=");
}
break;
case 21:
#line 140 "mbolc.y"
	{
  yyval.inequalityVal = new Inequality("<=");
}
break;
case 22:
#line 143 "mbolc.y"
	{
  yyval.inequalityVal = new Inequality(">=");
}
break;
case 23:
#line 147 "mbolc.y"
	{
  yyval.qualifiersVal = new Qualifiers(yystack.l_mark[0].qualifierVal);
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
  yyval.tupleIndicesVal = new TupleIndices(yystack.l_mark[-2].sval, yystack.l_mark[0].sval);
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
  yyval.qualifierVal = new Qualifier(string(yystack.l_mark[-2].sval), "exists", yystack.l_mark[0].elementExpressionVal);
}
break;
case 28:
#line 164 "mbolc.y"
	{
  yyval.qualifierVal = new Qualifier(yystack.l_mark[-3].tupleIndicesVal, yystack.l_mark[0].elementExpressionVal);
}
break;
case 29:
#line 167 "mbolc.y"
	{
  yyval.qualifierVal = new Qualifier("0", new Inequality("=="), new SetSize(yystack.l_mark[0].elementExpressionVal));
}
break;
case 30:
#line 170 "mbolc.y"
	{
  yyval.qualifierVal = new Qualifier("0", new Inequality("!="), new SetSize(yystack.l_mark[0].elementExpressionVal));
}
break;
case 31:
#line 173 "mbolc.y"
	{
  yyval.qualifierVal = new Qualifier(string(yystack.l_mark[-2].sval), new Inequality("=="), string(yystack.l_mark[0].sval));
}
break;
case 32:
#line 176 "mbolc.y"
	{
  yyval.qualifierVal = new Qualifier(string(yystack.l_mark[-2].sval), yystack.l_mark[-1].inequalityVal, string(yystack.l_mark[0].sval));
}
break;
case 33:
#line 179 "mbolc.y"
	{
  yyval.qualifierVal = new Qualifier(string(yystack.l_mark[-2].sval), "subset", yystack.l_mark[0].elementExpressionVal);
}
break;
case 34:
#line 182 "mbolc.y"
	{
  yyval.qualifierVal = new Qualifier(string(yystack.l_mark[-2].sval), "subsetequal", yystack.l_mark[0].elementExpressionVal);
}
break;
case 35:
#line 185 "mbolc.y"
	{
  yyval.qualifierVal = new Qualifier(string(yystack.l_mark[-2].sval), "in", new ElementExpression(new ElementNumbers(string(yystack.l_mark[-4].sval), yystack.l_mark[0].elementExpressionVal)));
}
break;
case 36:
#line 188 "mbolc.y"
	{
  yyval.qualifierVal = new Qualifier(string(yystack.l_mark[-4].sval), "in", new ElementExpression(new ElementNumbers(string(yystack.l_mark[-2].sval), yystack.l_mark[0].elementExpressionVal)));
}
break;
case 37:
#line 191 "mbolc.y"
	{
  yyval.qualifierVal = new Qualifier(string(yystack.l_mark[-2].sval), "in", yystack.l_mark[0].elementExpressionVal);
}
break;
case 38:
#line 195 "mbolc.y"
	{
  yyval.elementExpressionVal = new ElementExpression(yystack.l_mark[0].elementSubexpressionVal);
}
break;
case 39:
#line 198 "mbolc.y"
	{
  yyval.elementExpressionVal = new ElementExpression(yystack.l_mark[-2].elementExpressionVal, new ElementOperator("+"), yystack.l_mark[0].elementSubexpressionVal);
}
break;
case 40:
#line 201 "mbolc.y"
	{
  yyval.elementExpressionVal = new ElementExpression(yystack.l_mark[-2].elementExpressionVal, new ElementOperator("reduce"), yystack.l_mark[0].elementSubexpressionVal);
}
break;
case 41:
#line 204 "mbolc.y"
	{
  yyval.elementExpressionVal = new ElementExpression(yystack.l_mark[-2].elementExpressionVal, new ElementOperator("union"), yystack.l_mark[0].elementSubexpressionVal);
}
break;
case 42:
#line 207 "mbolc.y"
	{
  yyval.elementExpressionVal = new ElementExpression(yystack.l_mark[-2].elementExpressionVal, new ElementOperator("intersect"), yystack.l_mark[0].elementSubexpressionVal);
}
break;
case 43:
#line 211 "mbolc.y"
	{
  yyval.numberExpressionVal = new NumberExpression(yystack.l_mark[0].numberSubexpressionVal);
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
  yyval.elementSubexpressionVal = new SetCreator(string(yystack.l_mark[-3].sval), yystack.l_mark[-1].qualifiersVal);
}
break;
case 47:
#line 226 "mbolc.y"
	{
  yyval.elementSubexpressionVal = new ElementSet(yystack.l_mark[-1].elementExpressionVal);
}
break;
case 48:
#line 229 "mbolc.y"
	{
  yyval.elementSubexpressionVal = new ElementParantheses(yystack.l_mark[-1].elementExpressionVal);
}
break;
case 49:
#line 232 "mbolc.y"
	{
  yyval.elementSubexpressionVal = new ElementVariable(string(yystack.l_mark[0].sval));
}
break;
case 50:
#line 235 "mbolc.y"
	{
  yyval.elementSubexpressionVal = new ElementLiteral(string(yystack.l_mark[0].sval));
}
break;
case 51:
#line 239 "mbolc.y"
	{
  yyval.numberSubexpressionVal = yystack.l_mark[0].sumVal;
}
break;
case 52:
#line 242 "mbolc.y"
	{
  yyval.numberSubexpressionVal = new SetSize(yystack.l_mark[-1].elementExpressionVal);
}
break;
case 53:
#line 245 "mbolc.y"
	{
  yyval.numberSubexpressionVal = new NumberPower(yystack.l_mark[-5].numberExpressionVal, yystack.l_mark[-1].numberExpressionVal);
}
break;
case 54:
#line 248 "mbolc.y"
	{
  yyval.numberSubexpressionVal = new Fraction(yystack.l_mark[-4].numberExpressionVal, yystack.l_mark[-1].numberExpressionVal);
}
break;
case 55:
#line 251 "mbolc.y"
	{
  yyval.numberSubexpressionVal = new NumberParantheses(yystack.l_mark[-1].numberExpressionVal);
}
break;
case 56:
#line 254 "mbolc.y"
	{
  yyval.numberSubexpressionVal = new NumberLiteral(string(yystack.l_mark[0].sval));
}
break;
case 57:
#line 257 "mbolc.y"
	{
  yyval.numberSubexpressionVal = yystack.l_mark[0].variableMap;
}
break;
case 58:
#line 261 "mbolc.y"
	{
  yyval.variableMap = new VariableMap(string(yystack.l_mark[0].sval));
}
break;
case 59:
#line 264 "mbolc.y"
	{
  yyval.variableMap = new VariableMap(string(yystack.l_mark[-4].sval), yystack.l_mark[-1].indicesVal);
}
break;
case 60:
#line 267 "mbolc.y"
	{
  yyval.variableMap = new VariableMap(string(yystack.l_mark[-2].sval), string(yystack.l_mark[0].sval));
}
break;
case 61:
#line 271 "mbolc.y"
	{
  yyval.numberOperatorVal = new NumberOperator("+");
}
break;
case 62:
#line 274 "mbolc.y"
	{
  yyval.numberOperatorVal = new NumberOperator("-");
}
break;
case 63:
#line 277 "mbolc.y"
	{
  yyval.numberOperatorVal = new NumberOperator("/");
}
break;
case 64:
#line 280 "mbolc.y"
	{
  yyval.numberOperatorVal = new NumberOperator("*");
}
break;
case 65:
#line 284 "mbolc.y"
	{
  yyval.indicesVal = new Indices(yystack.l_mark[0].elementExpressionVal);
}
break;
case 66:
#line 287 "mbolc.y"
	{
  yystack.l_mark[-2].indicesVal->elementExpressions.push_back(yystack.l_mark[0].elementExpressionVal);
}
break;
case 67:
#line 291 "mbolc.y"
	{
  yyval.sumVal = new Sum(string(yystack.l_mark[-2].sval), yystack.l_mark[-1].sumQualifiersVal, new NumberExpression(yystack.l_mark[0].numberSubexpressionVal));
}
break;
case 68:
#line 295 "mbolc.y"
	{
  yyval.sumQualifiersVal = new SumQualifiers(string(yystack.l_mark[-7].sval), string(yystack.l_mark[-5].sval), yystack.l_mark[-1].elementExpressionVal);
}
break;
case 69:
#line 298 "mbolc.y"
	{
  yyval.sumQualifiersVal = new SumQualifiers(yystack.l_mark[-1].qualifiersVal);
}
break;
#line 1354 "y.tab.c"
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
