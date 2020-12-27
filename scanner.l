%option noyywrap
LETTER [a-zA-Z_]
DIGIT [0-9]
WHITE_SPACE [ \t\n] 
%{
// #  include "parser.tab.h"//该文件由后面的parser.y生成。主要定义了token 的值。和yylval变量
# include <stdio.h>
# include "parser.tab.h"

%}

%% 

"while"     {/*printf("KEY WORDS: %s \n", yytext);*/ return WHILE; }
"for"       {/*printf("KEY WORDS: %s \n", yytext);*/ return FOR; }
"break"     {/*printf("KEY WORDS: %s \n", yytext);*/ return BREAK; }
"continue"  {/*printf("KEY WORDS: %s \n", yytext);*/ return CONTINUE; }
"if"        {/*printf("KEY WORDS: %s \n", yytext);*/ return IF; }
"else"      {/*printf("KEY WORDS: %s \n", yytext);*/ return ELSE; }
"then"      {/*printf("KEY WORDS: %s \n", yytext);*/ return THEN; }
"printf"    {/*printf("KEY WORDS: %s \n", yytext);*/ return PRINTF; }
"scanf"     {/*printf("KEY WORDS: %s \n", yytext);*/ return SCANF; }
"return"    {/*printf("KEY WORDS: %s \n", yytext);*/ return RETURN; }
"void"      {/*printf("KEY WORDS: %s \n", yytext);*/ return VOID; }
"\''"       {/*printf("KEY WORDS: %s \n", yytext);*/ return S_QUO; /* 单引号 */}
"\""        {/*printf("KEY WORDS: %s \n", yytext);*/ return D_QUO; /* 双引号 */}
"int"       {/*printf("KEY WORDS: %s \n", yytext);*/ return INT; }
","         {/*printf("KEY WORDS: %s \n", yytext);*/ return COMMA; }
";"         {/*printf("KEY WORDS: %s \n", yytext);*/ return SEMI; }
"="         {/*printf("KEY WORDS: %s \n", yytext);*/ return ASSIGN_OP; }
"("         {/*printf("KEY WORDS: %s \n", yytext);*/ return '('; }
")"         {/*printf("KEY WORDS: %s \n", yytext);*/ return ')'; }
"["         {/*printf("KEY WORDS: %s \n", yytext);*/ return '['; }
"]"         {/*printf("KEY WORDS: %s \n", yytext);*/ return ']'; }
"{"         {/*printf("KEY WORDS: %s \n", yytext);*/ return '{'; }
"}"         {/*printf("KEY WORDS: %s \n", yytext);*/ return '}'; }

{LETTER}([a-zA-Z_]|{DIGIT})*  {yylval.str = strdup(yytext);/*printf("ID: %s\n; ", yytext);*/ return IDENTIFIER;  }


(([1-9]){DIGIT}*)|0  {yylval.str = strdup(yytext); /*printf("CONST TYPE: int VALUE: %s\n", yylval.str);*/ return CONST; }


"+"    {/*printf("ALOGRITHM OPERARION: %s \n", yytext);*/ return ADD; /* 加 addition*/}
"-"    {/*printf("ALOGRITHM OPERARION: %s \n", yytext);*/ return SUB; /* 减 substraction*/}
"*"    {/*printf("ALOGRITHM OPERARION: %s \n", yytext);*/ return MUL; /* 乘 */}
"/"    {/*printf("ALOGRITHM OPERARION: %s \n", yytext);*/ return DIV; /* 除 */}
"%"    {/*printf("ALOGRITHM OPERARION: %s \n", yytext);*/ return MOD; /* 取余 */}
"^"    {/*printf("ALOGRITHM OPERARION: %s \n", yytext);*/ return POW; /* 求幂 */}

"=="   {/*printf("RELATION OPERARION: %s \n", yytext);*/ return EQ_OP; /*EQual_OPeration*/}
">"    {/*printf("RELATION OPERARION: %s \n", yytext);*/ return GT_OP; /*Greater_Than_OPeration*/}
"<"    {/*printf("RELATION OPERARION: %s \n", yytext);*/ return LT_OP; /*Less_Than_OPeration*/}
">="   {/*printf("RELATION OPERARION: %s \n", yytext);*/ return GE_OP; /*Greater_Equal_OPeration*/}
"<="   {/*printf("RELATION OPERARION: %s \n", yytext);*/ return LE_OP; /*Less_Equal_OPeration*/}
"!="   {/*printf("RELATION OPERARION: %s \n", yytext);*/ return NE_OP; /*Not_Equal_OPeraiont*/}

"&&"   {/*printf("LOGICAL OPERARION: %s \n", yytext);*/ return AND; /*logical_AND_operation*/ }
"||"   {/*printf("LOGICAL OPERARION: %s \n", yytext);*/ return OR; }
"!"    {/*printf("LOGICAL OPERARION: %s \n", yytext);*/ return NOT; }
"&"    {/*printf("KEY WORDS: %s \n", yytext);*/ return SINGLAND; }


[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       { /* DO NOTHING */ }
"//"[^\n]*   {/* DO NOTHING */}
{WHITE_SPACE} { /* ignore white space */ }
.       {printf("ERROR!!"); }
%%