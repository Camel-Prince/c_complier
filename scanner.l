%option noyywrap
LETTER [a-zA-Z_]
DIGIT [0-9]
WHITE_SPACE [ \t] 
%{
// #  include "parser.tab.h"//该文件由后面的parser.y生成。主要定义了token 的值。和yylval变量
# include <stdio.h>
# include "parser.tab.h"
# include "AST.h"

// enum yytokentype{
//     WHILE = 258,
//     FOR = 259,
//     IF  = 260,
//     PRINTF = 261,
//     SCANF = 262,
//     INT = 263,
//     IDENTIFIER = 264,
//     CONST = 265, //声明token
//     ADD = 266,
//     SUB = 267,
//     MUL = 268,
//     DIV = 269,
//     POW = 270,
//     MOD = 271,
//     EQ_OP = 272, 
//     GT_OP = 273,
//     LT_OP = 274,
//     GE_OP = 275,
//     LE_OP = 276, 
//     NE_OP = 278,
//     AND = 279,
//     OR = 280,
//     NOT = 281,
//     EOL = 282,
//     ELSE = 283，
//     THEN = 284，
//     S_QUO = 285，
//     D_QUO = 286，
//     SEMI = 287,
//     COMMA = 288
// };
// int yylval;
%}

%% 

"while"     {printf("KEY WORDS: %s \n", yytext); return WHILE; }
"for"       {printf("KEY WORDS: %s \n", yytext); return FOR; }
"if"        {printf("KEY WORDS: %s \n", yytext); return IF; }
"else"      {printf("KEY WORDS: %s \n", yytext); return ELSE; }
"then"      {printf("KEY WORDS: %s \n", yytext); return THEN; }
"printf"    {printf("KEY WORDS: %s \n", yytext); return PRINTF; }
"scanf"     {printf("KEY WORDS: %s \n", yytext); return SCANF; }
"\''"       {printf("KEY WORDS: %s \n", yytext); return S_QUO; /* 单引号 */}
"\""        {printf("KEY WORDS: %s \n", yytext); return D_QUO; /* 双引号 */}
"int"       {printf("KEY WORDS: %s \n", yytext); return INT; }
","         {printf("KEY WORDS: %s \n", yytext); return COMMA; }
";"         {printf("KEY WORDS: %s \n", yytext); return SEMI; }
"="         {printf("KEY WORDS: %s \n", yytext); return '='; }
"("         {printf("KEY WORDS: %s \n", yytext); return '('; }
")"         {printf("KEY WORDS: %s \n", yytext); return ')'; }
"{"         {printf("KEY WORDS: %s \n", yytext); return '{'; }
"}"         {printf("KEY WORDS: %s \n", yytext); return '}'; }


{LETTER}([a-zA-Z_]|{DIGIT})*  {printf("ID: %s\n; ", yytext); return IDENTIFIER;  }


[+-]?[1-9]{DIGIT}* {yylval.number = atoi(yytext); printf("CONST TYPE: int VALUE: %d\n", yylval.number); return CONST; }


"+"    {printf("ALOGRITHM OPERARION: %s \n", yytext); return ADD; /* 加 */}
"-"    {printf("ALOGRITHM OPERARION: %s \n", yytext); return SUB; /* 减 */}
"*"    {printf("ALOGRITHM OPERARION: %s \n", yytext); return MUL; /* 乘 */}
"/"    {printf("ALOGRITHM OPERARION: %s \n", yytext); return DIV; /* 除 */}
"%"    {printf("ALOGRITHM OPERARION: %s \n", yytext); return MOD; /* 取余 */}
"^"    {printf("ALOGRITHM OPERARION: %s \n", yytext); return POW; /* 求幂 */}

"=="   {printf("RELATION OPERARION: %s \n", yytext); return EQ_OP; /*EQual_OPeration*/}
">"    {printf("RELATION OPERARION: %s \n", yytext); return GT_OP; /*Greater_Than_OPeration*/}
"<"    {printf("RELATION OPERARION: %s \n", yytext); return LT_OP; /*Less_Than_OPeration*/}
">="   {printf("RELATION OPERARION: %s \n", yytext); return GE_OP; /*Greater_Equal_OPeration*/}
"<="   {printf("RELATION OPERARION: %s \n", yytext); return LE_OP; /*Less_Equal_OPeration*/}
"!="   {printf("RELATION OPERARION: %s \n", yytext); return NE_OP; /*Not_Equal_OPeraiont*/}

"&&"   {printf("LOGICAL OPERARION: %s \n", yytext); return AND; /*logical_AND_operation*/ }
"||"   {printf("LOGICAL OPERARION: %s \n", yytext); return OR; }
"!"    {printf("LOGICAL OPERARION: %s \n", yytext); return NOT; }

\n     { return EOL; }

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       { /* DO NOTHING */ }
"//"[^\n]*   {/* DO NOTHING */}
{WHITE_SPACE} {count(); /* ignore white space */ }
.       {printf("ERROR!!"); }
%%

// int main(int argc, char** argv){

//     if(argc > 1){
//         if(!(yyin = fopen(argv[1], "r"))){
//             perror(argv[1]);
//             return 1;
//         }
//     }
//     while(1){
//         yylex();
//     }
    
//     return 0;
// }