%{
    #include<list>
    #include<iostream>
list<string> tokens;
%}
%%
[a-zA-Z]+ {
    tokens.push_back(string(yytext));
};
(\+|-){0,1}[0-9]+(\.[0-9]*){0,1} {
    tokens.push_back(string(yytext));
};
"(" tokens.push_back("(");
")" tokens.push_back(")");
"{" tokens.push_back("{");
"}" tokens.push_back("}");
"," tokens.push_back(",");
. ;
\n ;
%%
int yywrap() {
return 1;
}
list<string> getTokens(string s) {
    tokens.clear();
    yyin=fopen(s.c_str(),"r");
    yylex();
    fclose(yyin);
    return tokens;
}
