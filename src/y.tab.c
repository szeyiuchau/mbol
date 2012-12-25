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
#define LS 303
#define RS 304
#define NU 305
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
    4,    7,    1,    3,    1,    1,    1,    2,    4,    6,
    7,    3,    3,    1,    1,    1,    1,    1,    1,    3,
    3,    3,    5,    3,    3,    3,    3,    3,    3,    5,
    5,    3,    1,    3,    3,    3,    1,    2,    3,    5,
    3,    3,    1,    1,    3,    7,    7,    3,    1,    1,
    5,    3,    1,    1,    1,    1,    1,    3,    5,   10,
   10,    4,
};
static const short yydefred[] = {                         0,
    0,    0,    5,    6,    0,    0,    0,    0,    7,    0,
    0,    0,    1,    8,    3,    0,    0,    0,    0,    0,
    0,   49,    0,   44,    0,   37,    0,    0,    0,    0,
    0,   19,    0,    0,    0,    0,    0,    0,    0,    0,
   43,    0,    0,    0,   33,    0,    9,   18,   17,    0,
   53,   54,   55,   56,   14,   15,   16,    0,    0,   38,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    4,    0,    0,    0,    0,   52,    0,    0,
    0,    0,    0,    0,    0,    0,   45,    0,    0,    0,
   39,    0,   26,    0,    0,   27,    0,    0,    0,    0,
    0,    0,   20,    0,    0,    0,    0,    0,   10,    0,
    0,    0,   42,    0,   41,   36,   35,   34,    0,   21,
   22,    0,    0,    0,    2,    0,   62,   59,    0,   51,
    0,    0,    0,    0,   31,    0,   11,    0,    0,    0,
   40,    0,    0,   46,   47,    0,    0,    0,    0,   61,
   60,
};
static const short yydgoto[] = {                          2,
    5,    8,    9,   16,   23,   65,   31,   32,   59,  110,
   24,   36,   25,   44,   26,   45,   67,    6,
};
static const short yysindex[] = {                      -277,
 -177,    0,    0,    0, -290, -264, -199, -198,    0, -252,
 -206, -229,    0,    0,    0, -154, -242, -251, -204, -208,
 -218,    0, -187,    0,  -84,    0,   67, -189, -193, -139,
 -256,    0, -111, -148, -147, -110, -132, -146,  -88, -227,
    0, -208,   13, -106,    0, -204,    0,    0,    0, -204,
    0,    0,    0,    0,    0,    0,    0, -204, -204,    0,
 -208,  -73, -208, -208,  -71,  -62, -134, -208, -208,  -68,
 -229,  -72,    0, -204,  -18, -204,  -69,    0, -208,  -83,
   19,  -96, -191, -208, -208, -208,    0, -253,   50,   50,
    0,  -65,    0,  -65,  -65,    0,  -51,  -32,  -13,  -65,
  -65,  -15,    0, -204,  -33,   79, -140,   -3,    0,  -28,
  -65,  -21,    0, -229,    0,    0,    0,    0,  -10,    0,
    0, -208, -122,   -9,    0, -238,    0,    0, -208,    0,
 -204, -248, -204,  -65,    0,  -65,    0,   11,  -65,    5,
    0,   42,  -26,    0,    0,   14,  -82,   16,   69,    0,
    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -44,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -164,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -124,
    0,  -29,    0,    0,    0,    0,    0,    0,   17,   22,
    0, -250,    0, -141, -136,    0,    0,    0,    0, -119,
  -85,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   36,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -79,    0,  -45,    0,    0,   44,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const short yygindex[] = {                         0,
    0,    0,  286,    0,  197,  280,  -59,  235,    0,    0,
    0,    0,  -17,  -37,  -25,   76,    0,    0,
};
#define YYTABLESIZE 375
static const short yytable[] = {                         60,
    1,   40,   71,   17,   81,   83,   37,    7,   32,   10,
   71,   38,   39,   15,   60,  107,   51,   52,   53,   54,
   35,  119,   19,   92,   32,   94,   95,   93,   88,   17,
  100,  101,   89,   91,   20,   32,   27,  141,   39,   21,
   90,  111,   51,   52,   53,   54,   28,   72,   19,   80,
   17,   22,   17,   32,  132,   46,  105,   41,  108,   18,
   20,   39,   60,   60,   60,   21,  138,   42,   68,   19,
   29,   19,   84,   85,   11,   30,   66,   22,   43,   60,
   13,   20,   60,   20,  134,  136,   21,   47,   21,    3,
    4,  139,   50,   86,  115,   50,   50,   50,   22,    7,
   22,   50,   69,   12,   33,   50,   50,   50,   50,  149,
   50,   50,   50,  140,   60,  142,   60,   29,   71,   78,
   34,   70,   28,   50,   98,   74,   75,   79,   50,   50,
   50,   50,   48,   29,  127,   48,   48,   48,   28,   24,
   50,   48,   99,   41,   29,   48,   48,   48,   48,   28,
   48,   48,   48,   42,   73,   24,   77,   84,   85,  116,
  117,  118,   29,   48,   43,   76,   24,   28,   48,   48,
   48,   48,   17,   25,   38,   48,   49,   50,   86,   23,
   48,   39,  135,   41,   24,   51,   52,   53,   54,   25,
   87,   19,   93,   42,   96,   23,   97,  102,   84,   85,
   25,  104,  114,   20,   43,  109,   23,  112,   21,   55,
   56,   57,   50,   30,  120,   50,   50,   50,   25,   86,
   22,   50,  148,   17,   23,   50,   50,   50,   50,   30,
  129,   50,   39,  121,   43,   43,   51,   52,   53,   54,
   30,  125,   19,   50,  122,  123,  130,  106,   50,   50,
   50,   50,  131,   17,   20,   43,   43,   28,   30,   21,
   50,   17,   39,  133,  146,  137,   51,   52,   53,   54,
   39,   22,   19,  128,   51,   52,   53,   54,   82,  144,
   19,   29,   84,   85,   20,  143,   30,  147,   42,   21,
  150,   13,   20,   14,   57,  113,   12,   21,   17,   43,
  124,   22,   58,   86,   58,  103,   17,   39,    0,   22,
   57,   51,   52,   53,   54,   39,  145,   19,   58,   51,
   52,   53,   54,    0,   61,   19,   48,   49,   62,   20,
    0,    0,   84,   85,   21,    0,   61,   20,   48,   49,
  126,    0,   21,  151,    0,    0,   22,    0,    0,    0,
    0,    0,    0,   86,   22,    0,   63,    0,   64,    0,
   55,   56,   57,    0,    0,    0,    0,    0,   63,    0,
   64,    0,   55,   56,   57,
};
static const short yycheck[] = {                         25,
  278,   19,  259,  257,   42,   43,  258,  298,  259,  274,
  259,  263,  266,  266,   40,   75,  270,  271,  272,  273,
  263,  275,  276,   61,  275,   63,   64,  266,   46,  257,
   68,   69,   50,   59,  288,  286,  266,  286,  266,  293,
   58,   79,  270,  271,  272,  273,  276,  304,  276,  277,
  257,  305,  257,  304,  114,  274,   74,  266,   76,  266,
  288,  266,   88,   89,   90,  293,  305,  276,  262,  276,
  300,  276,  264,  265,  274,  305,  266,  305,  287,  105,
  279,  288,  108,  288,  122,  123,  293,  275,  293,  267,
  268,  129,  257,  285,  286,  260,  261,  262,  305,  298,
  305,  266,  296,  303,  259,  270,  271,  272,  273,  147,
  275,  276,  277,  131,  140,  133,  142,  259,  259,  266,
  275,  261,  259,  288,  259,  274,  274,  274,  293,  294,
  295,  296,  257,  275,  275,  260,  261,  262,  275,  259,
  305,  266,  277,  266,  286,  270,  271,  272,  273,  286,
  275,  276,  277,  276,  266,  275,  289,  264,  265,   84,
   85,   86,  304,  288,  287,  276,  286,  304,  293,  294,
  295,  296,  257,  259,  263,  260,  261,  262,  285,  259,
  305,  266,  305,  266,  304,  270,  271,  272,  273,  275,
  297,  276,  266,  276,  266,  275,  259,  266,  264,  265,
  286,  274,  299,  288,  287,  275,  286,  291,  293,  294,
  295,  296,  257,  259,  266,  260,  261,  262,  304,  285,
  305,  266,  305,  257,  304,  270,  271,  272,  273,  275,
  259,  276,  266,  266,  264,  265,  270,  271,  272,  273,
  286,  275,  276,  288,  258,  261,  275,  266,  293,  294,
  295,  296,  274,  257,  288,  285,  286,  276,  304,  293,
  305,  257,  266,  274,  291,  275,  270,  271,  272,  273,
  266,  305,  276,  277,  270,  271,  272,  273,  266,  275,
  276,  300,  264,  265,  288,  275,  305,  274,  276,  293,
  275,  275,  288,    8,  259,  277,  275,  293,  257,  287,
  104,  305,  259,  285,   25,   71,  257,  266,   -1,  305,
  275,  270,  271,  272,  273,  266,  275,  276,  275,  270,
  271,  272,  273,   -1,  258,  276,  260,  261,  262,  288,
   -1,   -1,  264,  265,  293,   -1,  258,  288,  260,  261,
  262,   -1,  293,  275,   -1,   -1,  305,   -1,   -1,   -1,
   -1,   -1,   -1,  285,  305,   -1,  290,   -1,  292,   -1,
  294,  295,  296,   -1,   -1,   -1,   -1,   -1,  290,   -1,
  292,   -1,  294,  295,  296,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 305
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
"LT","NE","LJ","CN","CL","ES","IC","MC","LS","RS","NU",
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
"constraint : CN LC VA IN ZC RC",
"constraint : CN LS qualifiers RS LC equation RC",
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
#line 678 "y.tab.c"

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
    yyval.constraintVal=new Constraint(string(yystack.l_mark[-3].sval));
}
break;
case 11:
#line 100 "mbolc.y"
	{
    yyval.constraintVal=new Constraint(yystack.l_mark[-1].equationVal,yystack.l_mark[-4].qualifiersVal);
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
#line 1259 "y.tab.c"
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
