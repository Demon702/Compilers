%{
#include "parser.tab.h"
int scope = 1;
%}

ws [ \t]+
comments \/\/.*
letter [A-Za-z]
digit [0-9]
operator [\+\-\*\/]
id (_|{letter})(_|{letter}|{digit})*
number {digit}+
fnumber {digit}*\.{digit}+
meta_char [;,\(\)\{\}?:]



%%
{ws} {;}
\n  {;}
{comments} {;}
"int" { store_token_name("INTEGER",yytext,yylineno);return INTEGER;}

"float" {store_token_name("FLOAT",yytext,yylineno); return FLOAT;}

"=" {store_token_name("ASSIGN_OP",yytext,yylineno); return ASSIGN;}


"void" { store_token_name("VOID",yytext,yylineno); scope = 0; return VOID;}


"return" { store_token_name("RETURN",yytext,yylineno); return RETURN;}



"while" { store_token_name("WHILE",yytext,yylineno);return WHILE;}
"if" { store_token_name("IF",yytext,yylineno);return IF;}
"else" { store_token_name("ELSE",yytext,yylineno);return ELSE;}
"do" { store_token_name("DO",yytext,yylineno);return DO;}

"&&" { store_token_name("AND",yytext,yylineno);return AND;}
"||" { store_token_name("OR",yytext,yylineno);return OR;}
"!" { store_token_name("NOT",yytext,yylineno);return NOT;}

"<" { store_token_name("LESS_THAN",yytext,yylineno);return LESS_THAN;}
"<=" { store_token_name("LESS_THAN_EQUAL",yytext,yylineno);return LESS_THAN_EQUAL;}
">" { store_token_name("GREATER_THAN",yytext,yylineno);return GREATER_THAN;}
">=" { store_token_name("GREATER_THAN_EQUAL",yytext,yylineno);return GREATER_THAN_EQUAL;}
"==" { store_token_name("EQUAL",yytext,yylineno);return EQUAL;}
"!=" { store_token_name("NOT_EQUAL",yytext,yylineno);return NOT_EQUAL;}

"print" { store_token_name("PRINT",yytext,yylineno);return PRINT;}

{number} {yylval.integer_value=atoi(yytext);
 store_token_name("NUM",yytext,yylineno); return INTEGER_NUMBER ;}

{fnumber} {yylval.double_value=atof(yytext);
 store_token_name("FNUM",yytext,yylineno);return DOUBLE_NUMBER ;}

{id}  {yylval.string_value = new std::string(yytext); store_token_name("NAME",yytext,yylineno); return NAME;}

{operator} {store_token_name("ARITHOP",yytext,yylineno);return yytext[0];} 

{meta_char} {  store_token_name("META CHAR",yytext,yylineno);return yytext[0];}


.			{				fprintf(stderr,"cs316: Error in line: %d Unknown character found\n", yylineno);
				exit(-1);}
%%
