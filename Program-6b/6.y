%{
    #include<stdio.h>
    #include<stdlib.h>
    int id = 0, key = 0, op = 0;
    extern FILE *yyin;
%}

%token ID KEY OP

%%
input:ID input		{++id;}
      |KEY input	{++key;}
      |OP input	{++op;}
      |ID	{++id;}
      |KEY	{++key;}
      |OP	{++op;}
      ;
%%

void main()
{
    yyin = fopen("xyz.c","r");
    yyparse();
    printf("Keywords= %d\n",key);
    printf("Identifiers= %d\n",id);
    printf("Operators= %d\n",op);
}

yyerror()
{
    printf("Error");
    exit(0);
}