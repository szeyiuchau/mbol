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
#line 15 "mbolc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int ival;
    char* sval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 43 "y.tab.c"

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
#define PR 294
#define GT 295
#define LT 296
#define NE 297
#define LJ 298
#define CN 299
#define CL 300
#define ES 301
#define NU 302
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,   19,   19,    2,    2,    3,    3,    4,    4,
    4,    5,    5,    6,    6,    6,    6,    6,    7,    7,
   18,   18,    8,    8,    8,    8,    8,    8,    8,    8,
    8,   15,   15,   15,   15,   14,   14,   14,   17,   17,
   17,   17,   16,   16,   16,   16,   16,   16,   16,   16,
   16,    9,    9,    9,    9,   10,   10,   11,   13,   13,
   12,   12,
};
static const short yylen[] = {                            2,
    4,    7,    1,    3,    1,    1,    4,    5,    1,    3,
    3,    3,    3,    1,    1,    1,    1,    1,    1,    3,
    1,    3,    5,    3,    3,    3,    3,    3,    3,    5,
    3,    1,    3,    3,    3,    1,    2,    3,    5,    3,
    3,    1,    1,    3,    7,    7,    3,    1,    1,    5,
    3,    1,    1,    1,    1,    1,    3,    5,    1,    1,
   10,    4,
};
static const short yydefred[] = {                         0,
    0,    0,    5,    6,    0,    0,    0,    0,    0,    0,
    1,    0,    3,    0,   59,    0,    0,    0,    0,   60,
   48,    0,    0,   43,    0,    0,   36,    0,    0,    0,
    0,    0,    0,    0,   42,    0,    0,    0,   32,    0,
    7,    0,    0,    0,   18,   17,    0,   52,   53,   54,
   55,   14,   15,   16,    0,    0,   37,    0,    4,    0,
   10,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   44,    0,    0,    0,    0,    0,    0,   19,    0,    0,
    0,    0,   38,    8,    0,    0,    0,    0,   41,    0,
   40,   35,   34,   33,    0,    0,    0,    0,    0,    0,
   21,    0,    0,    0,    0,    0,    0,    0,    0,    2,
    0,   50,    0,    0,    0,    0,   26,    0,    0,   27,
    0,    0,    0,    0,    0,   20,    0,   62,   58,    0,
    0,   39,    0,   22,    0,    0,    0,   45,   46,    0,
    0,    0,    0,    0,    0,   61,
};
static const short yydgoto[] = {                          2,
    5,    6,    8,   22,   23,  100,   77,   78,   56,   86,
   24,   44,   25,   26,   38,   27,   39,  102,   14,
};
static const short yysindex[] = {                      -267,
 -140,    0,    0,    0, -286, -258, -246, -217, -248, -249,
    0, -239,    0, -178,    0,  -68, -242, -197, -227,    0,
    0, -211, -188,    0, -168,   -5,    0, -249, -173, -186,
 -190, -254, -162,   71,    0, -197,  -94, -215,    0, -242,
    0, -247, -129, -128,    0,    0, -242,    0,    0,    0,
    0,    0,    0,    0, -242, -242,    0, -124,    0, -242,
    0, -197, -121, -120,  -78, -108, -132, -197, -197, -197,
    0,   96, -184,  -69, -255,  -73,  -61,    0, -210, -242,
  229,  229,    0,    0,  121, -175, -121,  -74,    0, -247,
    0,    0,    0,    0,  -66, -197,  -60, -197, -197,  -47,
    0, -256, -197, -197,  -46, -247,   59, -165,  154,    0,
 -197,    0, -242, -245, -242, -121,    0, -121, -121,    0,
  -45,  -32, -121, -121,  -30,    0, -262,    0,    0, -121,
  179,    0,  204,    0, -197, -242,  -43,    0,    0, -121,
  229,  -58,  -44, -242,  -41,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   38,    0,    0,    0,    0,
    0,    0,  -40,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -136,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -92,  -48,    0, -109,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -39,    0,    0,    0,
 -113, -112,    0,    0,    0,    0,  -86,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -250,    0, -200, -172,    0,
    0,    0, -170, -157,    0,    0,    0,    0,    0,  -84,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -144,
 -137,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,  209,    0,  213,  -53,  135,    0,    0,
    0,    0,    0,  -17,  -31,  -24,  147,    0,    0,
};
#define YYTABLESIZE 531
static const short yytable[] = {                         34,
   63,   57,  121,  117,   65,   67,  103,   15,   31,   57,
    1,   35,    7,  106,   15,    9,   16,   13,   73,   62,
  122,   36,   72,   33,   31,  108,   17,   10,   74,   81,
   87,   83,   37,   17,   28,   31,  114,   82,   18,  137,
  132,  104,   85,   19,   20,   18,   40,   57,   68,   69,
   19,   20,   21,   75,   76,  107,   57,   57,   29,   21,
   57,   11,  109,   41,  116,   74,  118,  119,   35,   70,
   42,  123,  124,   96,   29,   45,   46,   97,   36,  130,
   29,   12,   71,  111,   57,   29,   28,   60,   24,   37,
   75,   76,   59,  106,   43,  131,   30,  133,   61,  112,
   32,   25,   28,  140,   24,   98,   57,   99,   57,  128,
   52,   53,   54,   28,   23,   24,   57,   25,  141,  145,
   49,   30,   49,   49,   49,   49,    3,    4,   25,   49,
   23,   68,   69,   49,   49,   49,   49,   30,   49,   49,
   49,   23,   68,   69,   79,   13,   12,   80,   30,   49,
   84,   49,   70,   91,   42,   42,   49,   49,   49,   49,
   49,   13,   12,   70,   51,   49,   51,   51,   51,   51,
   88,   66,   56,   51,   57,   42,   42,   51,   51,   51,
   51,   36,   51,   51,   51,   68,   69,  105,   56,   31,
   57,   90,   37,   51,   32,   51,  101,  106,   89,  113,
   51,   51,   51,   51,   51,  117,   70,  115,   47,   51,
   47,   47,   47,   47,   92,   93,   94,   47,  120,  125,
  134,   47,   47,   47,   47,  135,   47,   47,   47,  144,
  136,  142,  143,  146,    9,   11,   58,   47,   55,   47,
  126,    0,    0,    0,   47,   47,   47,   47,   47,    0,
    0,   15,    0,   47,   45,   46,   47,    0,    0,    0,
   33,    0,    0,    0,   48,   49,   50,   51,    0,    0,
   17,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   18,    0,    0,    0,    0,   19,   20,   52,
   53,   54,    0,    0,   49,    0,   21,   49,   49,   49,
    0,    0,    0,   49,    0,    0,    0,   49,   49,   49,
   49,    0,    0,   49,    0,    0,   96,    0,   45,   46,
  127,    0,    0,    0,    0,   49,    0,   15,    0,    0,
   49,   49,   49,   49,   49,    0,   33,    0,    0,   49,
   48,   49,   50,   51,    0,    0,   17,   64,   98,    0,
   99,    0,   15,   52,   53,   54,    0,    0,   18,    0,
    0,   33,    0,   19,   20,   48,   49,   50,   51,    0,
   95,   17,   21,    0,    0,    0,    0,   15,    0,    0,
    0,    0,    0,   18,    0,    0,   33,    0,   19,   20,
   48,   49,   50,   51,    0,  110,   17,   21,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   18,    0,
   15,    0,    0,   19,   20,    0,    0,    0,    0,   33,
    0,    0,   21,   48,   49,   50,   51,    0,    0,   17,
  129,    0,    0,    0,    0,   15,    0,    0,    0,    0,
    0,   18,    0,    0,   33,    0,   19,   20,   48,   49,
   50,   51,    0,  138,   17,   21,    0,    0,    0,    0,
   15,    0,    0,    0,    0,    0,   18,    0,    0,   33,
    0,   19,   20,   48,   49,   50,   51,    0,  139,   17,
   21,    0,    0,    0,    0,   15,    0,    0,    0,    0,
    0,   18,    0,    0,   33,    0,   19,   20,   48,   49,
   50,   51,    0,    0,   17,   21,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   18,    0,    0,    0,
    0,   19,   20,    0,    0,    0,    0,    0,    0,    0,
   21,
};
static const short yycheck[] = {                         17,
   32,   26,  259,  266,   36,   37,  262,  257,  259,   34,
  278,  266,  299,  259,  257,  274,  266,  266,  266,  274,
  277,  276,   40,  266,  275,   79,  276,  274,  276,   47,
   62,   56,  287,  276,  274,  286,   90,   55,  288,  302,
  286,  297,   60,  293,  294,  288,  274,   72,  264,  265,
  293,  294,  302,  301,  302,  266,   81,   82,  259,  302,
   85,  279,   80,  275,   96,  276,   98,   99,  266,  285,
  259,  103,  104,  258,  275,  260,  261,  262,  276,  111,
  259,  299,  298,  259,  109,  286,  259,  274,  259,  287,
  301,  302,  266,  259,  263,  113,  275,  115,  289,  275,
  263,  259,  275,  135,  275,  290,  131,  292,  133,  275,
  295,  296,  297,  286,  259,  286,  141,  275,  136,  144,
  257,  259,  259,  260,  261,  262,  267,  268,  286,  266,
  275,  264,  265,  270,  271,  272,  273,  275,  275,  276,
  277,  286,  264,  265,  274,  259,  259,  276,  286,  286,
  275,  288,  285,  286,  264,  265,  293,  294,  295,  296,
  297,  275,  275,  285,  257,  302,  259,  260,  261,  262,
  291,  266,  259,  266,  259,  285,  286,  270,  271,  272,
  273,  276,  275,  276,  277,  264,  265,  261,  275,  258,
  275,  300,  287,  286,  263,  288,  266,  259,  277,  274,
  293,  294,  295,  296,  297,  266,  285,  274,  257,  302,
  259,  260,  261,  262,   68,   69,   70,  266,  266,  266,
  266,  270,  271,  272,  273,  258,  275,  276,  277,  274,
  261,  275,  291,  275,  275,  275,   28,  286,   26,  288,
  106,   -1,   -1,   -1,  293,  294,  295,  296,  297,   -1,
   -1,  257,   -1,  302,  260,  261,  262,   -1,   -1,   -1,
  266,   -1,   -1,   -1,  270,  271,  272,  273,   -1,   -1,
  276,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  288,   -1,   -1,   -1,   -1,  293,  294,  295,
  296,  297,   -1,   -1,  257,   -1,  302,  260,  261,  262,
   -1,   -1,   -1,  266,   -1,   -1,   -1,  270,  271,  272,
  273,   -1,   -1,  276,   -1,   -1,  258,   -1,  260,  261,
  262,   -1,   -1,   -1,   -1,  288,   -1,  257,   -1,   -1,
  293,  294,  295,  296,  297,   -1,  266,   -1,   -1,  302,
  270,  271,  272,  273,   -1,   -1,  276,  277,  290,   -1,
  292,   -1,  257,  295,  296,  297,   -1,   -1,  288,   -1,
   -1,  266,   -1,  293,  294,  270,  271,  272,  273,   -1,
  275,  276,  302,   -1,   -1,   -1,   -1,  257,   -1,   -1,
   -1,   -1,   -1,  288,   -1,   -1,  266,   -1,  293,  294,
  270,  271,  272,  273,   -1,  275,  276,  302,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  288,   -1,
  257,   -1,   -1,  293,  294,   -1,   -1,   -1,   -1,  266,
   -1,   -1,  302,  270,  271,  272,  273,   -1,   -1,  276,
  277,   -1,   -1,   -1,   -1,  257,   -1,   -1,   -1,   -1,
   -1,  288,   -1,   -1,  266,   -1,  293,  294,  270,  271,
  272,  273,   -1,  275,  276,  302,   -1,   -1,   -1,   -1,
  257,   -1,   -1,   -1,   -1,   -1,  288,   -1,   -1,  266,
   -1,  293,  294,  270,  271,  272,  273,   -1,  275,  276,
  302,   -1,   -1,   -1,   -1,  257,   -1,   -1,   -1,   -1,
   -1,  288,   -1,   -1,  266,   -1,  293,  294,  270,  271,
  272,  273,   -1,   -1,  276,  302,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  288,   -1,   -1,   -1,
   -1,  293,  294,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  302,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 302
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
"BB","CC","DD","EL","AN","UN","SR","RR","LR","LI","ZC","SE","CT","SS","FR","PR",
"GT","LT","NE","LJ","CN","CL","ES","NU",
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
"qualifier : NU LE VA LE number_expression",
"qualifier : VA IN element_expression",
"element_expression : element_subexpression",
"element_expression : element_expression SR element_subexpression",
"element_expression : element_expression SU element_subexpression",
"element_expression : element_expression SI element_subexpression",
"number_expression : number_subexpression",
"number_expression : number_expression number_subexpression",
"number_expression : number_expression operator number_subexpression",
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
"number_subexpression : VA US element_expression",
"operator : PL",
"operator : SB",
"operator : DI",
"operator : MU",
"indices : element_expression",
"indices : indices CO element_expression",
"sum : sum_product sum_product_qualifiers LP number_expression RP",
"sum_product : SM",
"sum_product : PR",
"sum_product_qualifiers : US LC VA EQ NU RC CT LC number_subexpression RC",
"sum_product_qualifiers : US LC qualifiers RC",

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
#line 843 "mbolc.y"
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
#line 644 "y.tab.c"

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
#line 24 "mbolc.y"
	{
    
    /* if a variable has no declare type, then it is a constant that must be provided by the user*/
    for(map<string,string>::iterator i=varType.begin();i!=varType.end();i++) {
        if(declType[i->first]=="") {
            setDeclType(i->first,"constant");
        }
    }
    
    /* find basic elements which will be integers*/
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
    
    /* BFS search to figure out distance to each node which reveals its element type*/
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
    
    /* take care of simple variables*/
    for(map<string,string>::iterator i=varType.begin();i!=varType.end();i++) {
        if(i->second=="a number"&&!typeMap.count(i->first)) {
            if(declType[i->first]=="variable") {
                if(intConstraints.count(i->first)) {
                    typeMap[i->first]="MyIloIntVar";
                    typeMap["RET_"+i->first.substr(0,i->first.size()-4)]="int";
                } else {
                    /*cout << i->first << endl;*/
                    typeMap[i->first]="MyIloNumVar";
                    typeMap["RET_"+i->first.substr(0,i->first.size()-4)]="double";
                }
            } else {
                typeMap[i->first]="double";
            }
        }
    }
    
    /* setup constant ints with types*/
    /*for(map<string,string>::iterator i=varType.begin();i!=varType.end();i++) {
        if(i->second=="constant") {
            typeMap[i->first]="int";
        }
    }*/
    
    /* get types of the map objects (real/integer variables in mathematical program)*/
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
    
    /* if a variable had the cardinality operator applied to it, then it is a set even if labeled an int*/
    for(set<string>::iterator i=weakSet.begin();i!=weakSet.end();i++) {
        if(typeMap[*i]=="int") {
            typeMap[*i]="set<int>";
        }
    }
    
    /* start making all the cppCode*/
    hppCode="#include<set>\n#include<map>\n#include<ilcplex/ilocplex.h>\n#include<mbol.hpp>\nusing namespace std;\n#ifndef MBOL_"+className+"\n#define MBOL_"+className+"\nclass "+className+" {\npublic:\nbool init();\nbool solve();\n"+className+"();\n~"+className+"();\nbool hasInitialized;\nIloCplex cplex;\nIloEnv env;\ndouble objValue;\nIloExpr objExp;\n";
    
    /* create struct for returning variables */
    hppCode+="// Variable results\n";
    for(map<string,string>::iterator i=declType.begin();i!=declType.end();i++) {
        if(i->second=="variable") {
            string retName=i->first.substr(0,i->first.size()-4);
            hppCode+="TYPE_RET_"+retName+"_ "+retName+";\n";
        }
    }
    
    
    /* making arguments which are constants in the program*/
    hppCode+="// Constants in the program that you must initialize\n";
    for(map<string,string>::iterator i=declType.begin();i!=declType.end();i++) {
        if(i->second=="constant") {
            hppCode+="TYPE_"+i->first+"_ "+i->first+";\n";
        }
    }
    
    /* declare CPLEX variables (actual variables in program)*/
    hppCode+="// Variables used by the CPLEX program\n";
    for(map<string,string>::iterator i=declType.begin();i!=declType.end();i++) {
        if(i->second=="variable") {
            hppCode+="TYPE_"+i->first+"_ "+i->first+";\n";
        }
    }
    hppCode+="};\n#endif\n";
    cppCode=className+"::"+className+"() {\nhasInitialized=false;\n}\nbool "+className+"::init() {\n";
    cppCode+="IloModel model(env);\ng_env=env;\ntry {\n";
    
    
    /* take care of simple variables*/
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
    
    /* this contains most of the logic of the program*/
    cppCode+=declarations+strs[yystack.l_mark[-2].ival]+strs[yystack.l_mark[-1].ival];
    cppCode+="IloCplex tempCplex(model);\ncplex=tempCplex;\n";
    if(quiet) {
        cppCode+="cplex.setOut(env.getNullStream());\n";
    }
    cppCode+="}\ncatch(IloException& ex) {\ncout << ex << endl;\nreturn false;\n}\nhasInitialized=true;\nreturn true;\n}\nbool "+className+"::solve() {\nif(!hasInitialized) {\ninit();\n}\nif(!hasInitialized) {\nreturn false;\n}\ntry{\ncplex.solve();\nobjValue=cplex.getValue(objExp);\n";
    
    
    
    /* fill in simple variable values*/
    for(map<string,string>::iterator i=declType.begin();i!=declType.end();i++) {
        if(i->second=="variable"&&varType[i->first]=="a number"&&mapTypes.count(i->first)==0) {
            cppCode+=i->first.substr(0,i->first.size()-4)+"=cplex.getValue("+i->first+");\n";
        }
    }
    
    /* fill in map variable values*/
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
    
    /* real types put in the cppCode*/
    for(map<string,string>::iterator i=typeMap.begin();i!=typeMap.end();i++) {
        hppCode=replaceAll(hppCode,"TYPE_"+i->first+"_",i->second);
        cppCode=replaceAll(cppCode,"TYPE_"+i->first+"_",i->second);
    }
}
break;
case 2:
#line 364 "mbolc.y"
	{
    int n=strs.size();
    strs[n]="{\n"+scopeStuff[yystack.l_mark[-1].ival]+"IloExpr tempObjExp(env);\nobjExp=tempObjExp;\nobjExp=objExp+"+strs[yystack.l_mark[-1].ival]+";\n"+strs[yystack.l_mark[-6].ival]+"\n}\n";
    yyval.ival=n;
}
break;
case 3:
#line 370 "mbolc.y"
	{
    setDeclType(string(yystack.l_mark[0].sval),"variable (return)");
    setDeclType(string(yystack.l_mark[0].sval)+"_var","variable");
}
break;
case 4:
#line 374 "mbolc.y"
	{
    setDeclType(string(yystack.l_mark[0].sval),"variable (return)");
    setDeclType(string(yystack.l_mark[0].sval)+"_var","variable");
}
break;
case 5:
#line 379 "mbolc.y"
	{
    int n=strs.size();
    strs[n]="IloObjective obj=IloMaximize(env,objExp);\nmodel.add(obj);";
    yyval.ival=n;
}
break;
case 6:
#line 384 "mbolc.y"
	{
    int n=strs.size();
    strs[n]="IloObjective obj=IloMinimize(env,objExp);\nmodel.add(obj);";
    yyval.ival=n;
}
break;
case 7:
#line 390 "mbolc.y"
	{
    int n=strs.size();
    strs[n]=strs[yystack.l_mark[-1].ival];
    yyval.ival=n;
}
break;
case 8:
#line 395 "mbolc.y"
	{
    int n=strs.size();
    strs[n]=strs[yystack.l_mark[-4].ival]+strs[yystack.l_mark[-1].ival];
    yyval.ival=n;
}
break;
case 9:
#line 401 "mbolc.y"
	{
    int n=strs.size();
    strs[n]="// Line "+convert(yylineno)+" of optimization program\n{\n"+strs[yystack.l_mark[0].ival]+"\n}\n";
    yyval.ival=n;
}
break;
case 10:
#line 406 "mbolc.y"
	{
    intConstraints.insert(string(yystack.l_mark[-2].sval)+"_var");
}
break;
case 11:
#line 409 "mbolc.y"
	{
    int n=strs.size();
    strs[n]="// Line "+convert(yylineno)+" of optimization program\n"+scopeStuff[yystack.l_mark[0].ival]+strs[yystack.l_mark[0].ival]+"\n"+strs[yystack.l_mark[-2].ival];
    int numbrackets=0;
    for(int i=0;i<strs[yystack.l_mark[0].ival].size();i++) {
        if(strs[yystack.l_mark[0].ival][i]=='}') {
            numbrackets--;
        }
        if(strs[yystack.l_mark[0].ival][i]=='{') { 
            numbrackets++;
        }
    }
    for(int i=0;i<numbrackets;i++) {
        strs[n]=strs[n]+"\n}";
    }
    strs[n]+="\n";
    yyval.ival=n;
}
break;
case 12:
#line 428 "mbolc.y"
	{
    int n=strs.size();
    strs[n]=scopeStuff[yystack.l_mark[-2].ival]+"IloExpr expLHS(env);\nexpLHS=expLHS+"+strs[yystack.l_mark[-2].ival]+";\n"+scopeStuff[yystack.l_mark[0].ival]+"IloExpr expRHS(env);\nexpRHS=expRHS+"+strs[yystack.l_mark[0].ival]+";\nmodel.add(expLHS"+strs[yystack.l_mark[-1].ival]+"expRHS);";
    yyval.ival=n; 
}
break;
case 13:
#line 433 "mbolc.y"
	{
    int n=strs.size();
    strs[n]=scopeStuff[yystack.l_mark[-2].ival]+"IloExpr expLHS(env);\nexpLHS=expLHS+"+strs[yystack.l_mark[-2].ival]+";\n"+scopeStuff[yystack.l_mark[0].ival]+"IloExpr expRHS(env);\nexpRHS=expRHS+"+strs[yystack.l_mark[0].ival]+";\nmodel.add(expLHS == expRHS);";
    yyval.ival=n; 
}
break;
case 14:
#line 439 "mbolc.y"
	{
    int n=strs.size();
    strs[n]=">";
    yyval.ival=n;
}
break;
case 15:
#line 444 "mbolc.y"
	{
    int n=strs.size();
    strs[n]="<";
    yyval.ival=n;
}
break;
case 16:
#line 449 "mbolc.y"
	{
    int n=strs.size();
    strs[n]="!=";
    yyval.ival=n;
}
break;
case 17:
#line 454 "mbolc.y"
	{
    int n=strs.size();
    strs[n]="<=";
    yyval.ival=n;
}
break;
case 18:
#line 459 "mbolc.y"
	{
    int n=strs.size();
    strs[n]=">=";
    yyval.ival=n;
}
break;
case 19:
#line 465 "mbolc.y"
	{
    int n=strs.size();
    strs[n]=scopeStuff[yystack.l_mark[0].ival]+strs[yystack.l_mark[0].ival];
    yyval.ival=n;
}
break;
case 20:
#line 470 "mbolc.y"
	{
    int n=strs.size();
    strs[n]=strs[yystack.l_mark[-2].ival]+"\n"+scopeStuff[yystack.l_mark[0].ival]+strs[yystack.l_mark[0].ival];
    yyval.ival=n;
}
break;
case 21:
#line 476 "mbolc.y"
	{
    int n=strs.size();
    tupleHolder[n].push_back(string(yystack.l_mark[0].sval));
    yyval.ival=n;
}
break;
case 22:
#line 481 "mbolc.y"
	{
    int n=strs.size();
    tupleHolder[n]=tupleHolder[yystack.l_mark[-2].ival];
    tupleHolder[n].push_back(string(yystack.l_mark[0].sval));
    yyval.ival=n;
}
break;
case 23:
#line 488 "mbolc.y"
	{
    int n=strs.size();
    string tv=tempElement();
    scopeStuff[n]=scopeStuff[yystack.l_mark[0].ival];
    setGraphEdge(tv,strs[yystack.l_mark[0].ival],1);
    strs[n]="for(TYPE_"+strs[yystack.l_mark[0].ival]+"_::iterator "+tv+"="+strs[yystack.l_mark[0].ival]+".begin();"+tv+"!="+strs[yystack.l_mark[0].ival]+".end();"+tv+"++) {";
    for(int i=0;i<tupleHolder[yystack.l_mark[-3].ival].size();i++) {
        strs[n]+="\nTYPE_"+tupleHolder[yystack.l_mark[-3].ival][i]+"_ "+tupleHolder[yystack.l_mark[-3].ival][i]+"="+tv+"->e"+convert(i)+";";
        setDeclType(tupleHolder[yystack.l_mark[-3].ival][i],"temporary");
    }
    tupleType[tv]=tupleHolder[yystack.l_mark[-3].ival];
    yyval.ival=n;
}
break;
case 24:
#line 501 "mbolc.y"
	{
    int n=strs.size();
scopeStuff[n]=scopeStuff[yystack.l_mark[0].ival];
    strs[n]="if("+strs[yystack.l_mark[0].ival]+".empty()) {";
    yyval.ival=n;
}
break;
case 25:
#line 507 "mbolc.y"
	{
    int n=strs.size();
scopeStuff[n]=scopeStuff[yystack.l_mark[0].ival];
    strs[n]="if(!"+strs[yystack.l_mark[0].ival]+".empty()) {";
    yyval.ival=n;
}
break;
case 26:
#line 513 "mbolc.y"
	{
    int n=strs.size();
    strs[n]="if("+string(yystack.l_mark[-2].sval)+"=="+string(yystack.l_mark[0].sval)+") {";
    yyval.ival=n;
}
break;
case 27:
#line 518 "mbolc.y"
	{
    int n=strs.size();
    strs[n]="if("+string(yystack.l_mark[-2].sval)+strs[yystack.l_mark[-1].ival]+string(yystack.l_mark[0].sval)+") {";
    yyval.ival=n;
}
break;
case 28:
#line 523 "mbolc.y"
	{
    string tv1=tempElement();
    string tv2=tempElement();
    int n=strs.size();
    setVarType(string(yystack.l_mark[-2].sval),"an element");
    setDeclType(string(yystack.l_mark[-2].sval),"temporary");
    scopeStuff[n]=scopeStuff[yystack.l_mark[0].ival]+"TYPE_"+tv1+"_ "+tv1+"=powerset("+strs[yystack.l_mark[0].ival]+");\n"+tv1+".erase("+strs[yystack.l_mark[0].ival]+");\n";
    setGraphTriple(strs[yystack.l_mark[0].ival],tv2,string(yystack.l_mark[-2].sval));
    setGraphEdge(string(yystack.l_mark[-2].sval),tv1,1);
    setGraphEdge(strs[yystack.l_mark[0].ival],tv1,1);
    setGraphEdge(tv2,tv1,1);
    strs[n]="for(TYPE_"+tv1+"_::iterator "+tv2+"="+tv1+".begin();"+tv2+"!="+tv1+".end();"+tv2+"++) {\nTYPE_"+string(yystack.l_mark[-2].sval)+"_ "+string(yystack.l_mark[-2].sval)+"=*"+tv2+";";
    yyval.ival=n;
}
break;
case 29:
#line 537 "mbolc.y"
	{
    string tv1=tempElement();
    string tv2=tempElement();
    int n=strs.size();
    setVarType(string(yystack.l_mark[-2].sval),"an element");
    setDeclType(string(yystack.l_mark[-2].sval),"temporary");
    scopeStuff[n]=scopeStuff[yystack.l_mark[0].ival]+"TYPE_"+tv1+"_ "+tv1+"=powerset("+strs[yystack.l_mark[0].ival]+");\n";
    setGraphTriple(strs[yystack.l_mark[0].ival],tv2,string(yystack.l_mark[-2].sval));
    setGraphEdge(string(yystack.l_mark[-2].sval),tv1,1);
    setGraphEdge(strs[yystack.l_mark[0].ival],tv1,1);
    setGraphEdge(tv2,tv1,1);
    strs[n]="for(TYPE_"+tv1+"_::iterator "+tv2+"="+tv1+".begin();"+tv2+"!="+tv1+".end();"+tv2+"++) {\nTYPE_"+string(yystack.l_mark[-2].sval)+"_ "+string(yystack.l_mark[-2].sval)+"=*"+tv2+";";
    yyval.ival=n;
}
break;
case 30:
#line 551 "mbolc.y"
	{
    /*    setDeclType(string($3),"temporary");*/
    /*    setVarType(string($3),"an element");*/
    setGraph[string(yystack.l_mark[-2].sval)];
    int n=strs.size();
    strs[n]="for(int "+string(yystack.l_mark[-2].sval)+"="+string(yystack.l_mark[-4].sval)+";"+string(yystack.l_mark[-2].sval)+"<="+strs[yystack.l_mark[0].ival]+";"+string(yystack.l_mark[-2].sval)+"++) {";
    yyval.ival=n;
}
break;
case 31:
#line 559 "mbolc.y"
	{
    setDeclType(string(yystack.l_mark[-2].sval),"temporary");
    setVarType(string(yystack.l_mark[-2].sval),"an element");
    string tv=tempExp();
    int n=strs.size();
    scopeStuff[n]=scopeStuff[yystack.l_mark[0].ival];
    setGraphEdge(string(yystack.l_mark[-2].sval),strs[yystack.l_mark[0].ival],1);
    strs[n]="for(TYPE_"+strs[yystack.l_mark[0].ival]+"_::iterator "+tv+"="+strs[yystack.l_mark[0].ival]+".begin();"+tv+"!="+strs[yystack.l_mark[0].ival]+".end();"+tv+"++) {\nTYPE_"+string(yystack.l_mark[-2].sval)+"_ "+string(yystack.l_mark[-2].sval)+"=*"+tv+";";
    yyval.ival=n; 
}
break;
case 32:
#line 570 "mbolc.y"
	{
    int n=strs.size();
    scopeStuff[n]=scopeStuff[yystack.l_mark[0].ival];
    strs[n]=strs[yystack.l_mark[0].ival];
    yyval.ival=n;
}
break;
case 33:
#line 576 "mbolc.y"
	{
    int n=strs.size();
    string tv=tempElement();
    setGraphTriple(tv,strs[yystack.l_mark[-2].ival],strs[yystack.l_mark[0].ival]);
    scopeStuff[n]=scopeStuff[yystack.l_mark[-2].ival]+scopeStuff[yystack.l_mark[0].ival]+"TYPE_"+tv+"_ "+tv+"="+strs[yystack.l_mark[-2].ival]+";\nfor(TYPE_"+strs[yystack.l_mark[0].ival]+"_::iterator iter="+strs[yystack.l_mark[0].ival]+".begin();iter!="+strs[yystack.l_mark[0].ival]+".end();iter++) {\n"+tv+".erase(*iter);\n}\n";
    strs[n]=tv;
    yyval.ival=n;
}
break;
case 34:
#line 584 "mbolc.y"
	{
    int n=strs.size();
    string tv=tempElement();;
    setGraphTriple(tv,strs[yystack.l_mark[-2].ival],strs[yystack.l_mark[0].ival]);
    scopeStuff[n]=scopeStuff[yystack.l_mark[-2].ival]+scopeStuff[yystack.l_mark[0].ival]+"TYPE_"+tv+"_ "+tv+"="+strs[yystack.l_mark[-2].ival]+";\n"+tv+".insert("+strs[yystack.l_mark[0].ival]+".begin(),"+strs[yystack.l_mark[0].ival]+".end());\n";
    strs[n]=tv;
    yyval.ival=n;
}
break;
case 35:
#line 592 "mbolc.y"
	{
    int n=strs.size();
    string tv=tempElement();
    setGraphTriple(tv,strs[yystack.l_mark[-2].ival],strs[yystack.l_mark[0].ival]);
    scopeStuff[n]=scopeStuff[yystack.l_mark[-2].ival]+scopeStuff[yystack.l_mark[0].ival]+"TYPE_"+tv+"_ "+tv+";\nfor(TYPE_"+strs[yystack.l_mark[0].ival]+"_::iterator iter="+strs[yystack.l_mark[0].ival]+".begin();iter!="+strs[yystack.l_mark[0].ival]+".end();iter++) {\nif("+strs[yystack.l_mark[-2].ival]+".count(*iter)) {\n"+tv+".insert(*iter);\n}\n}\n";
    strs[n]=tv;
    yyval.ival=n;
}
break;
case 36:
#line 601 "mbolc.y"
	{
    int n=strs.size();
    scopeStuff[n]=scopeStuff[yystack.l_mark[0].ival];
    strs[n]=strs[yystack.l_mark[0].ival];
    yyval.ival=n;
}
break;
case 37:
#line 607 "mbolc.y"
	{
    int n=strs.size();
    scopeStuff[n]=scopeStuff[yystack.l_mark[-1].ival]+scopeStuff[yystack.l_mark[0].ival];
    strs[n]=strs[yystack.l_mark[-1].ival]+"*"+strs[yystack.l_mark[0].ival];
    /*type(strs[$2],"number");*/
    yyval.ival=n;
}
break;
case 38:
#line 614 "mbolc.y"
	{
    int n=strs.size();
    scopeStuff[n]=scopeStuff[yystack.l_mark[-2].ival]+scopeStuff[yystack.l_mark[0].ival];
    strs[n]=strs[yystack.l_mark[-2].ival]+strs[yystack.l_mark[-1].ival]+strs[yystack.l_mark[0].ival];
    yyval.ival=n;
}
break;
case 39:
#line 621 "mbolc.y"
	{
    int n=strs.size();
    string tv=tempElement();
    scopeStuff[n]="TYPE_"+tv+"_ "+tv+";\n"+strs[yystack.l_mark[-1].ival]+"\n"+tv+".insert("+string(yystack.l_mark[-3].sval)+");";
    setDeclType(string(yystack.l_mark[-3].sval),"temporary");
    setVarType(string(yystack.l_mark[-3].sval),"an element");
    setGraphEdge(string(yystack.l_mark[-3].sval),tv,1);
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
    yyval.ival=n;
}
break;
case 40:
#line 644 "mbolc.y"
	{
    int n=strs.size();
    string tv=tempElement();
    scopeStuff[n]=scopeStuff[yystack.l_mark[-1].ival];
    setGraphEdge(strs[yystack.l_mark[-1].ival],tv,1);
    scopeStuff[n]+="TYPE_"+tv+"_ "+tv+";\n"+tv+".insert("+strs[yystack.l_mark[-1].ival]+");\n";
    strs[n]=tv;
    yyval.ival=n;
}
break;
case 41:
#line 653 "mbolc.y"
	{
    int n=strs.size();
    scopeStuff[n]=scopeStuff[yystack.l_mark[-1].ival];
    strs[n]="("+strs[yystack.l_mark[-1].ival]+")";
    yyval.ival=n;
}
break;
case 42:
#line 659 "mbolc.y"
	{
    int n=strs.size();
    strs[n]=string(yystack.l_mark[0].sval);
    setVarType(strs[n],"an element");
    setGraph[string(yystack.l_mark[0].sval)]; 
    yyval.ival=n;
}
break;
case 43:
#line 667 "mbolc.y"
	{
    int n=strs.size();
    scopeStuff[n]=scopeStuff[yystack.l_mark[0].ival];
    strs[n]=strs[yystack.l_mark[0].ival];
    yyval.ival=n;
}
break;
case 44:
#line 673 "mbolc.y"
	{
    int n=strs.size();
    weakSet.insert(strs[yystack.l_mark[-1].ival]);
    scopeStuff[n]=scopeStuff[yystack.l_mark[-1].ival];
    strs[n]=strs[yystack.l_mark[-1].ival]+".size()";
    setGraphEdge(strs[yystack.l_mark[-1].ival],strs[n],1);
    yyval.ival=n;
}
break;
case 45:
#line 681 "mbolc.y"
	{
    int n=strs.size();
    string tv1=tempExp();
    string tv2=tempExp();
    string tv3=tempExp();
    scopeStuff[n]=scopeStuff[yystack.l_mark[-5].ival]+scopeStuff[yystack.l_mark[-1].ival]+"double "+tv1+"="+strs[yystack.l_mark[-5].ival]+";\ndouble "+tv2+"="+strs[yystack.l_mark[-1].ival]+";\ndouble "+tv3+"=pow("+tv1+","+tv2+");\n";
    strs[n]=tv3;
    yyval.ival=n;
}
break;
case 46:
#line 690 "mbolc.y"
	{
    int n=strs.size();
    string tv1=tempExp();
    string tv2=tempExp();
    string tv3=tempExp();
    scopeStuff[n]=scopeStuff[yystack.l_mark[-4].ival]+scopeStuff[yystack.l_mark[-1].ival]+"IloExpr "+tv1+"(env);\n"+tv1+"="+tv1+"+"+strs[yystack.l_mark[-4].ival]+";\nIloExpr "+tv2+"(env);\n"+tv2+"="+tv2+"+"+strs[yystack.l_mark[-1].ival]+";\nIloExpr "+tv3+"(env);\n"+tv3+"="+tv3+"+"+tv1+"/"+tv2+";\n";
    strs[n]=tv3;
    yyval.ival=n;
}
break;
case 47:
#line 699 "mbolc.y"
	{
    int n=strs.size();
    string tv=tempExp();
    scopeStuff[n]=scopeStuff[yystack.l_mark[-1].ival];
    scopeStuff[n]+="IloExpr "+tv+"(env);\n"+tv+"="+tv+"+"+strs[yystack.l_mark[-1].ival]+";\n";
    strs[n]=tv;
    yyval.ival=n;
}
break;
case 48:
#line 707 "mbolc.y"
	{
    int n=strs.size();
    strs[n]=string(yystack.l_mark[0].sval);
    /*    setVarType(strs[n],"a number");*/
    yyval.ival=n;
}
break;
case 49:
#line 713 "mbolc.y"
	{
    int n=strs.size();
    strs[n]=string(yystack.l_mark[0].sval);
    if(declType[strs[n]]=="variable (return)") {
        strs[n]+="_var";
    }
    setVarType(strs[n],"a number");
    yyval.ival=n;
}
break;
case 50:
#line 722 "mbolc.y"
	{
    int n=strs.size();
    strs[n]=string(yystack.l_mark[-4].sval);
    if(declType[strs[n]]=="variable (return)") {
        strs[n]+="_var";
    }
    setVarType(strs[n],"a number");
    scopeStuff[n]=scopeStuff[yystack.l_mark[-1].ival];
    int i=0;
    list<string> vars;
    while(strs[yystack.l_mark[-1].ival].find("[",i)!=string::npos) {
        vars.push_back(strs[yystack.l_mark[-1].ival].substr(strs[yystack.l_mark[-1].ival].find("[",i)+1,strs[yystack.l_mark[-1].ival].find("]",i)-strs[yystack.l_mark[-1].ival].find("[",i)-1));
        i=strs[yystack.l_mark[-1].ival].find("[",i+1);
    }
    mapTypes[strs[n]].push_back(vars);
    mapTypeReasons[strs[n]].push_back(yylineno);
    strs[n]+=strs[yystack.l_mark[-1].ival];
    yyval.ival=n;
}
break;
case 51:
#line 741 "mbolc.y"
	{
    int n=strs.size();
    strs[n]=string(yystack.l_mark[-2].sval);
    if(declType[strs[n]]=="variable (return)") {
        strs[n]+="_var";
    }
    setVarType(strs[n],"a number");
    scopeStuff[n]=scopeStuff[yystack.l_mark[0].ival];
    int i=0;
    list<string> vars;
    vars.push_back(strs[yystack.l_mark[0].ival]);
    mapTypes[strs[n]].push_back(vars);
    mapTypeReasons[strs[n]].push_back(yylineno);
    strs[n]+="["+strs[yystack.l_mark[0].ival]+"]";
    yyval.ival=n;
}
break;
case 52:
#line 758 "mbolc.y"
	{
    int n=strs.size();
    strs[n]="+";
    yyval.ival=n;
}
break;
case 53:
#line 763 "mbolc.y"
	{
    int n=strs.size();
    strs[n]="-";
    yyval.ival=n;
}
break;
case 54:
#line 768 "mbolc.y"
	{
    int n=strs.size();
    strs[n]="/";
    yyval.ival=n;
}
break;
case 55:
#line 773 "mbolc.y"
	{
    int n=strs.size();
    strs[n]="*";
    yyval.ival=n;
}
break;
case 56:
#line 779 "mbolc.y"
	{
    int n=strs.size();
    scopeStuff[n]=scopeStuff[yystack.l_mark[0].ival];
    strs[n]="["+strs[yystack.l_mark[0].ival]+"]";
    yyval.ival=n;
}
break;
case 57:
#line 785 "mbolc.y"
	{
    int n=strs.size();
    scopeStuff[n]=scopeStuff[yystack.l_mark[-2].ival]+scopeStuff[yystack.l_mark[0].ival];
    strs[n]=strs[yystack.l_mark[-2].ival]+"["+strs[yystack.l_mark[0].ival]+"]";
    yyval.ival=n;
}
break;
case 58:
#line 792 "mbolc.y"
	{
    int n=strs.size();
    string tv1=tempExp();
    string tv2=tempExp();
    scopeStuff[n]=scopeStuff[yystack.l_mark[-3].ival]+"IloExpr "+tv1+"(env);\n";
    if(strs[yystack.l_mark[-4].ival]=="*") {
        scopeStuff[n]+=tv1+"="+tv1+"+1;\n";
    }
    scopeStuff[n]+=strs[yystack.l_mark[-3].ival]+"\n"+scopeStuff[yystack.l_mark[-1].ival]+"IloExpr "+tv2+"(env);\n"+tv2+"="+tv2+"+"+strs[yystack.l_mark[-1].ival]+";\n"+tv1+"="+tv1+strs[yystack.l_mark[-4].ival]+tv2+";\n";
    int numbrackets=0;
    for(int i=0;i<strs[yystack.l_mark[-3].ival].size();i++) {
        if(strs[yystack.l_mark[-3].ival][i]=='}') {
            numbrackets--;
        }
        if(strs[yystack.l_mark[-3].ival][i]=='{') { 
            numbrackets++;
        }
    }
    for(int i=0;i<numbrackets;i++) {
        scopeStuff[n]=scopeStuff[n]+"}\n";
    }
    strs[n]=tv1;
    yyval.ival=n;
}
break;
case 59:
#line 817 "mbolc.y"
	{
    int n=strs.size();
    strs[n]="+";
    yyval.ival=n;
}
break;
case 60:
#line 822 "mbolc.y"
	{
    int n=strs.size();
    strs[n]="*";
    yyval.ival=n;
}
break;
case 61:
#line 828 "mbolc.y"
	{
    int n=strs.size();
    typeMap[string(yystack.l_mark[-7].sval)]="int";
    strs[n]="for(int "+string(yystack.l_mark[-7].sval)+"="+string(yystack.l_mark[-5].sval)+";"+string(yystack.l_mark[-7].sval)+"<="+strs[yystack.l_mark[-1].ival]+";"+string(yystack.l_mark[-7].sval)+"++) {";
    setDeclType(string(yystack.l_mark[-7].sval),"temporary");
    yyval.ival=n;
}
break;
case 62:
#line 835 "mbolc.y"
	{
    int n=strs.size();
    scopeStuff[n]=scopeStuff[yystack.l_mark[-1].ival];
    strs[n]=strs[yystack.l_mark[-1].ival];
    yyval.ival=n;
}
break;
#line 1834 "y.tab.c"
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
