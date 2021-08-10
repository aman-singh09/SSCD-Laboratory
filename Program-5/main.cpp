#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char op[2], arg1[5], arg2[5], res[5];
FILE *fp1, *fp2;
int main()
{
  fp1 = fopen("input.txt", "r");
  fp2 = fopen("output.txt", "w");
  while (!feof(fp1))
  {
    fscanf(fp1, "%s%s%s%s", res, arg1, op, arg2);
    if (strcmp(op, "+") == 0)
    {
      fprintf(fp2, "MOV R0, %s\n", arg1);
      fprintf(fp2, "ADD R0, %s\n", arg2);
      fprintf(fp2, "MOV %s, R0\n\n", res);
    }
    if (strcmp(op, "*") == 0)
    {
      fprintf(fp2, "MOV R0, %s\n", arg1);
      fprintf(fp2, "MUL R0, %s\n", arg2);
      fprintf(fp2, "MOV %s, R0\n\n", res);
    }
    if (strcmp(op, "=") == 0)
    {
      fprintf(fp2, "MOV R0, %s\n", arg1);
      fprintf(fp2, "STORE %s, R0\n\n", res);
    }
  }
  fclose(fp1);
  fclose(fp2);
}