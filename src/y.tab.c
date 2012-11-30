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
    3,    3,    5,    3,    3,    3,    3,    3,    3,    5,
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
    0,    0,    0,    0,    0,    0,    0,    2,    0,   62,
   59,    0,   51,    0,    0,    0,    0,   26,    0,    0,
   27,    0,    0,    0,    0,    0,    0,   20,    0,    0,
    0,   40,    0,   21,   22,    0,    0,    0,   46,   47,
    0,   31,    0,    0,    0,    0,    0,   61,   60,
};
static const short yydgoto[] = {                          2,
    5,    8,   21,   14,   22,  101,   77,   78,   54,   87,
   23,   30,   24,   38,   25,   39,  103,    6,
};
static const short yysindex[] = {                      -261,
 -257,    0,    0,    0, -283, -224, -222, -263, -247, -245,
    0, -200,    0, -215, -185, -126, -182,  -51, -191,    0,
 -190, -161,    0,  -95,    0, -245, -162, -143, -133, -121,
 -110, -148,  -90,  -20,    0,  -51,   30, -198,    0, -182,
    0, -262,    0,    0, -182,    0,    0,    0,    0,    0,
    0,    0, -182, -182,    0, -107,    0, -182, -246, -182,
    0,    0,  -51, -111,    1, -109, -116,  -51,  -51,  -51,
    0,    4, -108,  -83, -255,  -76,  -68,    0, -248, -248,
    0,    0,   28,  -66, -187,   54, -186,   24,  -77,    0,
 -262,    0,    0,    0,    0,  -72,  -51,  -63,  -51,  -51,
  -56,  -47, -251,  -51,  -51,  -52, -262,    0, -264,    0,
    0,  -51,    0, -182, -254, -182,   24,    0,   24,   24,
    0,  -45,  -44,  -24,   24,   24,  -29,    0,  -31,   24,
   78,    0,  102,    0,    0,  -51, -230,  -46,    0,    0,
   24,    0,   24,  -35, -159,  -16,   43,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -53,    0,    0,    0,    0,
    0,   -8,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -180,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -137,    0,   -2,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   -6,    0, -132, -129,
    0,    0,    0,    0,    0,    0,    0, -115,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -114,    0, -112,  -70,
    0,    0,    0,    0,  -48,  -28,    0,    0,    0,   63,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -26,    0,   -4,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  228,    0,    0,  240,   11,  165,    0,    0,
    0,    0,  -11,  -36,  -21,  244,    0,    0,
};
#define YYTABLESIZE 403
static const short yytable[] = {                         65,
   67,  118,   55,   73,  107,   34,  104,  123,   15,    3,
    4,   15,   55,   74,    7,   11,    1,   33,   13,   84,
   16,   46,   47,   48,   49,  124,   88,   17,   72,   74,
   17,  132,   81,   79,   12,   35,  129,   75,   76,   18,
  105,   80,   18,   27,   19,   36,   83,   19,   86,    9,
   55,   10,   20,   75,   76,   20,   37,   55,   55,   28,
  117,   55,  119,  120,   55,   68,   69,  125,  126,   85,
  142,  107,  112,   26,   15,  130,   50,   29,   50,   50,
   50,   50,   40,   33,   41,   50,   70,  110,  113,   50,
   50,   50,   50,   17,   50,   50,   50,   42,   71,  141,
  143,  115,  131,   57,  133,   18,   35,   50,  147,   55,
   19,   55,   50,   50,   50,   50,   36,   62,   20,   48,
   50,   48,   48,   48,   48,   63,   13,   37,   48,   12,
   58,   31,   48,   48,   48,   48,   32,   48,   48,   48,
   59,  146,   13,   57,   32,   12,   29,   68,   69,   97,
   48,   43,   44,   98,   60,   48,   48,   48,   48,   57,
   32,   15,   29,   48,   43,   44,   45,   82,   70,   92,
   33,   32,   32,   29,   46,   47,   48,   49,   61,   89,
   17,   99,  102,  100,  106,   50,   51,   52,   28,   91,
  107,   97,   18,   43,   44,  109,  114,   19,   50,   51,
   52,  116,  118,   50,   28,   20,   50,   50,   50,  121,
   24,  122,   50,  127,   35,   28,   50,   50,   50,   50,
  134,  135,   50,   99,   36,  100,   24,   50,   51,   52,
   25,  137,   23,  136,   50,   37,   15,   24,  145,   50,
   50,   50,   50,  138,  144,   33,   25,   50,   23,   46,
   47,   48,   49,   56,   30,   17,   64,   25,  148,   23,
   15,   43,   43,   53,   68,   69,    9,   18,   11,   33,
   30,  128,   19,   46,   47,   48,   49,   90,   96,   17,
   20,   30,   43,   43,   15,   70,    0,   68,   69,    0,
    0,   18,    0,   33,    0,   66,   19,   46,   47,   48,
   49,    0,  108,   17,   20,   36,   68,   69,   70,    0,
   15,   93,   94,   95,    0,   18,   37,  149,    0,   33,
   19,   58,    0,   46,   47,   48,   49,   70,   20,   17,
  111,    0,    0,    0,   15,    0,    0,   58,    0,    0,
    0,   18,    0,   33,    0,    0,   19,   46,   47,   48,
   49,    0,  139,   17,   20,    0,    0,    0,   15,    0,
    0,    0,    0,    0,    0,   18,    0,   33,    0,    0,
   19,   46,   47,   48,   49,    0,  140,   17,   20,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   18,
    0,    0,    0,    0,   19,    0,    0,    0,    0,    0,
    0,    0,   20,
};
static const short yycheck[] = {                         36,
   37,  266,   24,  266,  259,   17,  262,  259,  257,  267,
  268,  257,   34,  276,  298,  279,  278,  266,  266,  266,
  266,  270,  271,  272,  273,  277,   63,  276,   40,  276,
  276,  286,   54,   45,  298,  266,  301,  300,  301,  288,
  296,   53,  288,  259,  293,  276,   58,  293,   60,  274,
   72,  274,  301,  300,  301,  301,  287,   79,   80,  275,
   97,   83,   99,  100,   86,  264,  265,  104,  105,   59,
  301,  259,  259,  274,  257,  112,  257,  263,  259,  260,
  261,  262,  274,  266,  275,  266,  285,  275,  275,  270,
  271,  272,  273,  276,  275,  276,  277,  259,  297,  136,
  137,   91,  114,  266,  116,  288,  266,  288,  145,  131,
  293,  133,  293,  294,  295,  296,  276,  266,  301,  257,
  301,  259,  260,  261,  262,  274,  259,  287,  266,  259,
  274,  258,  270,  271,  272,  273,  263,  275,  276,  277,
  274,  301,  275,  259,  259,  275,  259,  264,  265,  258,
  288,  260,  261,  262,  276,  293,  294,  295,  296,  275,
  275,  257,  275,  301,  260,  261,  262,  275,  285,  286,
  266,  286,  263,  286,  270,  271,  272,  273,  289,  291,
  276,  290,  266,  292,  261,  294,  295,  296,  259,  299,
  259,  258,  288,  260,  261,  262,  274,  293,  294,  295,
  296,  274,  266,  257,  275,  301,  260,  261,  262,  266,
  259,  259,  266,  266,  266,  286,  270,  271,  272,  273,
  266,  266,  276,  290,  276,  292,  275,  294,  295,  296,
  259,  261,  259,  258,  288,  287,  257,  286,  274,  293,
  294,  295,  296,  275,  291,  266,  275,  301,  275,  270,
  271,  272,  273,   26,  259,  276,  277,  286,  275,  286,
  257,  264,  265,   24,  264,  265,  275,  288,  275,  266,
  275,  107,  293,  270,  271,  272,  273,  277,  275,  276,
  301,  286,  285,  286,  257,  285,   -1,  264,  265,   -1,
   -1,  288,   -1,  266,   -1,  266,  293,  270,  271,  272,
  273,   -1,  275,  276,  301,  276,  264,  265,  285,   -1,
  257,   68,   69,   70,   -1,  288,  287,  275,   -1,  266,
  293,  259,   -1,  270,  271,  272,  273,  285,  301,  276,
  277,   -1,   -1,   -1,  257,   -1,   -1,  275,   -1,   -1,
   -1,  288,   -1,  266,   -1,   -1,  293,  270,  271,  272,
  273,   -1,  275,  276,  301,   -1,   -1,   -1,  257,   -1,
   -1,   -1,   -1,   -1,   -1,  288,   -1,  266,   -1,   -1,
  293,  270,  271,  272,  273,   -1,  275,  276,  301,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  288,
   -1,   -1,   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  301,
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
#line 1154 "y.tab.c"
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
