%{
#include <stdio.h>
int c=0;
%}
%%
"/*"[a-zA-Z0-9' '\t\n'^/*''^*/']+"*/" {c++;fprintf(yyout," ");}
"//".* {c++; fprintf(yyout," ");}
. {fprintf(yyout,"%s",yytext);}
%%
int main()
{
yyin=fopen("input.txt", "r");
yyout=fopen("output.txt", "w");
yylex();
fprintf(yyout, "%s", yytext);
printf("The total number of comment lines are: %d\n", c);
return 0;
}
int yywrap()
{
return -1;
}