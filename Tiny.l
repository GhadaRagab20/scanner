/*********************************************************************/
/* File : tiny.l                                                     */
/* Lex spacification for TINT                                       */

%{
#include "global.h"
#include "util.h"
#include "scan.h"
char tokenString[MAXTOKENLEN+1];
%}

digit      [0-9]
number     {digit}+
letter     [a-zA-Z]
identifier {letter}+
newline    \n
whitespace [ \t]+

%%

"if"         {return IF;}
"then"       {return THEN;}
"else"       {return ELSE;}
"end"        {return END;}
"repeat"     {return REPEAT;}
"until"      {return UNTIL;}
"read"       {return READ;}
"write"      {return WRITE;}
":="         {return ASSIGN;}
"="          {return EQ;}
"<"          {return LT;}
"+"          {return PLUS;}
"-"          {return MINUS;}
"*"          {return TIMES;}
"/"          {return OVER;}
"("          {return LPAREN;}
")"          {return RPAREN;}
";"          {return SEMI;}
{number}     {return NUM;}
{identifier} {return ID;}
{newline}    {lineno++;}
{whitespace} {/* skip whitespace */}
"{"          {char c;
              do
              { c = input();
                if (c == EOF){brak;}
                if (c =='\n'){lineno++;}
              } while (c !='}');
              }
.             {return ERROR;}

%%

TokenType getToken(void)
{ static int firstTime =TRUE;
TokenType currentToken;
if (firstTime)
{firstTime =FALSE;
lineno++;
yyin=fopen("Tiny.text","r");
yyout=fopen("result.text","W+");
listig =yyout;
}
currentToken =yylex();
strncpy(tokenString,yytext,MAXTOKENLEN);
if(TraceScane) {
  fprinf(listing,"\t%d:",lineno);
  printToken(currentToken,tokenString);
}
  return currentToken;
}

int main(){
printf("Welcom \n");
while(getToken()){
printf("Done \n");
}
return 0;
}

