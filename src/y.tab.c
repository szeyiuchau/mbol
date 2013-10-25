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
    0,    0,    0,    0,    0,    4,    0,    0,   66,   59,
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
static const short yysindex[] = {                      -256,
 -155,    0,    0,    0, -220, -211, -198,    0, -273,    0,
 -186, -199, -165,    0,    0,    0,    0, -252, -176, -163,
 -199,  -53, -166,    0, -148, -153,    0,  -92,    0,  103,
 -132, -235, -112, -257,    0, -114, -121, -120, -199, -253,
    0,  -19,    0,  -53,   90,  -73,    0, -199, -125,    0,
    0,    0, -199,    0,    0,    0,    0,    0,    0,    0,
 -199, -199,    0,  -53, -250,  -53,  -53, -100,  -77, -247,
  -53,  -53,  -99, -165,  -91,    0, -199, -150,    0,    0,
  -53, -106, -182, -113,  -25,  -53,  -53,  -53,    0,    5,
  -86,   69,   69,    0,   35,    0,  -84,   35,   35,    0,
  -76,  -72,  -65,   35,   35,  -66,    0, -199,   13,  110,
 -251, -169,   35,  -67,    0, -165,    0,    0,    0,    0,
  -48,    0, -261,    0,    0,  -53,  -58,  -31,  -75,    0,
 -246,    0,  -53,    0, -199, -216, -199,    0,   35,   35,
    0,   35, -196,    0, -130,   35,   37,    0,   61,  -70,
  -47,  -61,    0,    0,    0,    0,  -43,   72,  -42,  -29,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -222,    0,   31,    0,    0,    0,    0,    0,    0,
    0,  -34,  -26,    0, -207,    0,    0, -200, -190,    0,
    0,    0,    0, -129, -128,    0,    0,    0,    0,    0,
    0,    0, -157,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -51,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -127,  -88,
    0,  -87,    0,    0,    0, -139,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const short yygindex[] = {                         0,
    0,  223,   -9,    0,  241,    0,  151,  235,  -74,  190,
    0,    0,    0,    0,  -20,  -35,  -28,  -69,    0,    0,
};
#define YYTABLESIZE 406
static const short yytable[] = {                         63,
   42,   74,   25,  111,   43,   14,   36,   74,   83,   85,
   79,  102,   80,   63,   44,   96,  118,  119,  120,   96,
   81,    1,   37,  132,    7,   45,   71,   90,   95,  103,
   98,   99,   92,   94,   54,  104,  105,   54,   54,   54,
   93,  136,   74,   54,  138,  113,   75,   54,   54,   54,
   54,   38,   54,   54,   54,   97,  109,   19,   33,  145,
   72,   63,   11,   63,   63,   54,   20,   38,   32,  148,
   54,   54,   54,   54,   33,   12,   21,    7,   38,   17,
   63,   86,   87,   54,   32,   33,   38,  139,   22,  133,
  140,  142,  150,   23,  115,   32,   38,  146,  128,   40,
   30,   64,   88,   33,   13,  134,   24,   48,  151,   49,
   31,    3,    4,   32,  147,  110,  149,   64,   63,   65,
   63,   50,  160,   57,   57,   31,   57,   57,   57,   28,
   29,   35,   57,   69,   32,   65,   57,   57,   57,   57,
   33,   57,   57,   57,  152,   28,   29,   35,   73,   32,
  123,   76,   77,   78,   57,   33,   28,   29,   35,   57,
   57,   57,   57,   91,   19,  100,  106,   51,   52,   53,
   27,   34,   57,   20,   28,   29,   35,   54,   55,   56,
   57,  101,  108,   21,  114,  116,   27,   34,  122,  124,
   86,   87,  126,  125,  127,   22,  123,   27,   34,  144,
   23,   58,   59,   60,  155,   56,  135,   43,   56,   56,
   56,   88,   43,   24,   56,   27,   34,   44,   56,   56,
   56,   56,   44,   89,   56,  137,  143,  156,   45,  157,
  158,   15,  161,   45,   86,   87,   56,   19,   86,   87,
   17,   56,   56,   56,   56,  162,   20,  141,   16,   16,
   54,   55,   56,   57,   56,   88,   21,   82,  129,   88,
  117,   19,   61,  107,    0,    0,    0,    0,   22,   19,
   20,    0,    0,   23,   54,   55,   56,   57,   20,  121,
   21,    0,   54,   55,   56,   57,   24,  130,   21,    0,
    0,    0,   22,   19,   49,   49,    0,   23,   86,   87,
   22,    0,   20,    0,    0,   23,   54,   55,   56,   57,
   24,  153,   21,    0,    0,   49,   49,   19,   24,   88,
    0,    0,    0,    0,   22,   19,   20,    0,    0,   23,
   54,   55,   56,   57,   20,  154,   21,   43,   54,   55,
   56,   57,   24,    0,   21,    0,    0,   44,   22,    0,
    0,    0,    0,   23,    0,   84,   22,    0,   45,    0,
   64,   23,   51,   52,   65,   44,   24,   64,    0,   51,
   52,  131,    0,    0,   24,    0,   45,  159,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   66,    0,   67,    0,   58,   59,   60,   66,
    0,   67,    0,   58,   59,   60,
};
static const short yycheck[] = {                         28,
   21,  259,   12,   78,  266,  279,  259,  259,   44,   45,
   39,  259,  266,   42,  276,  266,   86,   87,   88,  266,
  274,  278,  275,  275,  298,  287,  262,   48,   64,  277,
   66,   67,   53,   62,  257,   71,   72,  260,  261,  262,
   61,  116,  259,  266,  306,   81,  304,  270,  271,  272,
  273,  259,  275,  276,  277,  306,   77,  257,  259,  306,
  296,   90,  274,   92,   93,  288,  266,  275,  259,  286,
  293,  294,  295,  296,  275,  274,  276,  298,  286,  266,
  109,  264,  265,  306,  275,  286,  263,  123,  288,  259,
  126,  127,  289,  293,  277,  286,  304,  133,  108,  263,
  266,  259,  285,  304,  303,  275,  306,  274,  305,  258,
  276,  267,  268,  304,  135,  266,  137,  275,  147,  259,
  149,  275,  158,  257,  258,  276,  260,  261,  262,  259,
  259,  259,  266,  266,  300,  275,  270,  271,  272,  273,
  306,  275,  276,  277,  275,  275,  275,  275,  261,  300,
  281,  266,  274,  274,  288,  306,  286,  286,  286,  293,
  294,  295,  296,  289,  257,  266,  266,  260,  261,  262,
  259,  259,  306,  266,  304,  304,  304,  270,  271,  272,
  273,  259,  274,  276,  291,  299,  275,  275,  275,  266,
  264,  265,  258,  266,  261,  288,  281,  286,  286,  275,
  293,  294,  295,  296,  275,  257,  274,  266,  260,  261,
  262,  285,  266,  306,  266,  304,  304,  276,  270,  271,
  272,  273,  276,  297,  276,  274,  258,  275,  287,  291,
  274,    9,  275,  287,  264,  265,  288,  257,  264,  265,
  275,  293,  294,  295,  296,  275,  266,  306,  275,    9,
  270,  271,  272,  273,  306,  285,  276,  277,  108,  285,
  286,  257,   28,   74,   -1,   -1,   -1,   -1,  288,  257,
  266,   -1,   -1,  293,  270,  271,  272,  273,  266,  275,
  276,   -1,  270,  271,  272,  273,  306,  275,  276,   -1,
   -1,   -1,  288,  257,  264,  265,   -1,  293,  264,  265,
  288,   -1,  266,   -1,   -1,  293,  270,  271,  272,  273,
  306,  275,  276,   -1,   -1,  285,  286,  257,  306,  285,
   -1,   -1,   -1,   -1,  288,  257,  266,   -1,   -1,  293,
  270,  271,  272,  273,  266,  275,  276,  266,  270,  271,
  272,  273,  306,   -1,  276,   -1,   -1,  276,  288,   -1,
   -1,   -1,   -1,  293,   -1,  266,  288,   -1,  287,   -1,
  258,  293,  260,  261,  262,  276,  306,  258,   -1,  260,
  261,  262,   -1,   -1,  306,   -1,  287,  306,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  290,   -1,  292,   -1,  294,  295,  296,  290,
   -1,  292,   -1,  294,  295,  296,
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
"sum : SM sum_qualifiers number_subexpression",
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
  bool ast = false;
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
  options["-ast"]="Graphviz abstract syntax tree";
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
    } else if(string(argv[i])=="-ast") {
      ast=true;
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
  if (hpp || bin || typ || ast) {
    yyin=fopen(inputName.c_str(),"r");
    yyparse();
    fclose(yyin);
    MbolElementVisitor* vTypes=new MbolElementVisitorTypeHelper();
    program->accept(*vTypes);
    types=((MbolElementVisitorTypeHelper*)vTypes)->types;
  }

  if (ast) {
    MbolElementVisitorPrinter* dot = new MbolElementVisitorPrinter();
    program->accept(*dot);
    dot->end();
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
#line 712 "y.tab.c"

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
  yyval.sumVal=new Sum(string(yystack.l_mark[-2].sval),yystack.l_mark[-1].sumQualifiersVal,new NumberExpression(yystack.l_mark[0].numberSubexpressionVal));
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
#line 1338 "y.tab.c"
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
