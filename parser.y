%{
#include <cstdio>
#include <iostream>
#include "Create.hpp"
#include "IOperand.hpp"
#include "Int8.hpp"
#include "header.h"
#include <stack>
#include <string>
#include <string.h>
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE	*yyin;
void yyerror(const char *s);

Create *factory = new Create;
std::stack <IOperand const *> vm;
%}

%union {
	IOperand const *oper;
	eOperandType eval;
	int		ival;
	char	*sval;
}

%token <ival> PUSH;
%token <ival> ASSERT;
%token <ival> COMMAND;
%token <eval> VAL;
%token <ival> FVAL;
%token <sval> INTEGER;
%token <sval> FLOAT;
%token <ival> EXIT;
%token <ival> SEP;
%type <oper> opera;

%%

s:
	instructs EXIT SEP { YYACCEPT; }

instructs:
		 instructs instr
		 | instr;

instr:
	PUSH opera
	{
	 	std::cout << $1 << std::endl;
	}
	| ASSERT opera
	{
	 	std::cout << $1 << std::endl;
	}
	| COMMAND endls
	{
	 	std::cout << $1 << std::endl;
	}

opera:
	 VAL '(' INTEGER ')' endls
	{
		IOperand const *tmp = factory->createOperand($1, $3);
	 	std::cout << $3 << std::endl;
		vm.push(tmp);
	}
	 | FVAL '(' FLOAT ')' endls
	{
	 	std::cout << $3 << std::endl;
	}

endls:
	 endls SEP
	 | SEP ;

%%

int	main(void)
{
	yyin = stdin;

	while (yyparse()) ;
	std::cout << "vm.top:\n";
	std::cout << vm.top()->toString() << std::endl;
	return (0);
}

void yyerror(const char *s)
{
	std::cout << "EEK, parse error!  Message: " << s << std::endl;
	exit(-1);
}
