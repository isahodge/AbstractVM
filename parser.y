%{
#include <cstdio>
#include <iostream>
#include "Create.hpp"
#include "IOperand.hpp"
#include "Int8.hpp"
#include "header.h"
#include "Instr.hpp"
#include <stack>
#include <queue>
#include <string>
#include <string.h>
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE	*yyin;
void yyerror(const char *s);

Create *factory = new Create;
//std::stack <IOperand const *> vm;
std::queue <Instr const *> instructions;
//won't need stack, if we're able to assign eOperandType to queue after push & assert 
%}

%union {
	IOperand const	*oper;
	eOperandType	eval;
	int				ival;
	char			*sval;
}

%token <ival> PUSH;
%token <ival> ASSERT;
%token <ival> COMMAND;
%token <eval> VAL;
%token <eval> FVAL;
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
		 | instr ;

instr:
	PUSH opera
	{
		Instr const *in;
		in = new Instr($1, $2);
		instructions.push(in);
	}
	| ASSERT opera
	{
		Instr const *in;
		in = new Instr($1, $2);
		instructions.push(in);
	}
	| COMMAND endls
	{
		Instr const *in;
		in = new Instr($1);
		instructions.push(in);
	}
	| error endls ;

opera:
	 VAL '(' INTEGER ')' endls
	{
		$$ = factory->createOperand($1, $3);
	}
	 | FVAL '(' FLOAT ')' endls
	{
		$$ = factory->createOperand($1, $3);
	}

endls:
	 endls SEP
	 | SEP ;

%%

int	main(int argc, char **argv)
{
	yyin = stdin;
	if (argc == 2)
	{
		FILE *file = fopen(argv[1], "r");
		if (!file)
		{
			std::cout << "Could not open file\n";
			return (-1);
		}
		yyin = file;
	}
	while (yyparse()) 
	{ 
		if (feof(yyin))
			break ;
	}
	std::cout << "End of program" << std::endl;
	vm_execute(instructions);
	return (0);
}

void yyerror(const char *s)
{
	std::cout << "EEK, parse error!  Message: " << s << std::endl;
}
