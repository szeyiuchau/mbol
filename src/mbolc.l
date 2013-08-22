%{
  #include<classes.hpp>
  #include "y.tab.h"
  #define YY_SKIP_YYWRAP
  extern "C" int yywrap();
  int li=0;
%}
%%
\\\{" "*0" "*," "*1" "*\\\} return BI;
," "*\.\.\." "*, return DD;
"[" return LS;
"]" return RS;
\\mcon return MC;
\\intcon return IC;
\\ne return NE;
\\emptyset return ES;
":" return CL;
"<" return LT;
">" return GT;
\\frac return FR;
\\subseteq return SE;
\\subset return SS;
"^" return CT;
, return CO;
\\; ;
\\mathbb\{Z\} return ZC;
\\underset return UN;
"&" return AN;
\\\\  return EL;
\\begin\{mbol\} return AA;
\\end\{mbol\} return BB;
\\\{ return LR;
\\\} return RR;
\\setminus return SR;
"|" {
  li++;
  if(li%2) {
    return LI;
  } else {
    return LJ;
  }
};
"+" return PL;
\* return MU;
"/" return DI;
"-" return SB;
\\maxf return MA;
\\minf return MI;
\\con return CN;
(\\sum|\\prod) {
  if(strcmp(yytext,"\\sum")==0) {
    strcpy(yylval.sval,"+");
  }
  if(strcmp(yytext,"\\prod")==0) {
    strcpy(yylval.sval,"*");
  }
  return SM;
};
"\in" return IN;
"\ge" return GE;
"=" return EQ;
"\le" return LE;
"{" return LC;
"}" return RC;
"(" return LP;
")" return RP;
"_" return US;
"\cap" return SI;
"\cup" return SU;
\\pi {
  char* buf=new char[14];
  strcpy(buf,"3.14159265359");
  yylval.sval=buf;
  return NU;
};
([a-zA-Z]|\\alpha|\\theta|\\tau|\\beta|\\vartheta|\\upsilon|\\gamma|\\gamma|\\varpi|\\phi|\\delta|\\kappa|\\rho|\\varphi|\\epsilon|\\lambda|\\varrho|\\chi|\\varepsilon|\\mu|\\sigma|\\psi|\\zeta|\\nu|\\varsigma|\\omega|\\eta|\\xi|\\Gamma|\\Lambda|\\Sigma|\\Psi|\\Delta|\\Xi|\\Upsilon|\\Omega|\\Theta|\\Pi|\\Phi|\\alpha) {
  char* buf=new char[strlen(yytext)+1];
  if(yytext[0]=='\\') {
    strcpy(buf,yytext+1);
  } else {
    strcpy(buf,yytext);
  }
  yylval.sval=buf;
  return VA;
};

(\+|-){0,1}[0-9]+(\.[0-9]*){0,1} {
  char* buf=new char[strlen(yytext)+1];
  strcpy(buf,yytext);
  yylval.sval=buf;
  return NU;
};
%[^\n]*\n {yylineno++;};
\n {yylineno++;};
. ;
