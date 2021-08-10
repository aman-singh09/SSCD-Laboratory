%{
#include<stdio.h>
#include<stdlib.h>	
%}
%token A B
%%
str:S '\n' {return 0;}
S:A S
|A B
;
%%
int main()
{
	printf("Enter the string:\n");
	yyparse();
	printf("Valid String.\n");
	return 0;
}
yyerror()
{
	printf("Invalid expression\n");
	exit(0);
}