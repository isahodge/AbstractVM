/*
 * deifinitions
 */

%{
//%option noyywrap
#include <iostream>
#include <string.h>
#include "IOperand.hpp"
#include "header.h"
#define YY_DECL extern "C" int yylex()
#include "parser.tab.h"
%}
DIGIT	[-]?[0-9]+
FLOAT	[-]?[0-9]+\.[0-9]+
INSTR	[a-z]+

%%

{DIGIT}	{ yylval.sval = strdup(yytext); return INTEGER; }
{FLOAT} { yylval.sval = strdup(yytext); return FLOAT; }
push	{ yylval.ival = 1; return PUSH; }
assert	{ yylval.ival = 2; return ASSERT; }
pop		{ yylval.ival = 3; return COMMAND; }
dump	{ yylval.ival = 4; return COMMAND; }
print	{ yylval.ival = 5; return COMMAND; }
add		{ yylval.ival = 6; return COMMAND; }
sub		{ yylval.ival = 7; return COMMAND; }
mul		{ yylval.ival = 8; return COMMAND; }
div		{ yylval.ival = 9; return COMMAND; }
mod		{ yylval.ival = 10; return COMMAND; }
int8	{ yylval.eval = Int8; return VAL; }
int16	{ yylval.eval = Int16; return VAL; }
int32	{ yylval.eval = Int32; return VAL; }
float	{ yylval.eval = Float; return FVAL; }
double	{ yylval.eval = Double; return FVAL; }
exit	{ if (yyin != stdin) return EXIT; }
{INSTR}	{ std::cout << "unrecognized command/value "  << yytext; }
\;\;	{ if (yyin == stdin) return EXIT; }
\;.*	;
\(		return '(';
\)		return ')';
[\n\r]	return SEP;
[ \t\n]	;
.		std::cout << "lexical error: character not in dictionary\n";

%%
