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
	 	std::cout << $1 << std::endl;
	}
	| ASSERT opera
	{
	 	std::cout << $1 << std::endl;
	}
	| COMMAND endls
	{
		switch ($1) {
			case 3: 
				std::cout << "pop\n";
				break ;
			case 4:
				std::cout << "dump\n";
				break ;
			case 5:
				std::cout << "print\n";
				break ;
			case 6:
				std::cout << "add\n";
				break ;
			case 7:
				std::cout << "sub\n";
				break ;
			case 8:
				std::cout << "mul\n";
				break ;
			case 9:
				std::cout << "div\n";
				break ;
			case 10:
				std::cout << "mod\n";
				break ;
		}
	 	std::cout << $1 << std::endl;
	}
	| error endls ;

opera:
	 VAL '(' INTEGER ')' endls
	{
		$$ = factory->createOperand($1, $3);
	 	std::cout << $3 << std::endl;
		vm.push($$);
	}
	 | FVAL '(' FLOAT ')' endls
	{
		$$ = factory->createOperand($1, $3);
	 	std::cout << $3 << std::endl;
		vm.push($$);
	}

endls:
	 endls SEP
	 | SEP ;

%%

int	main(void)
{
	yyin = stdin;

	while (yyparse()) 
	{ 
		if (feof(yyin))
			break ;
	}
	if (!vm.empty())
	{
		std::cout << "vm.top:\n";
		std::cout << vm.top()->toString() << std::endl;
		std::cout << "vm.size:\n";
		std::cout << vm.size() << std::endl;
	}
	std::cout << "End of program" << std::endl;
	return (0);
}

void yyerror(const char *s)
{
	std::cout << "EEK, parse error!  Message: " << s << std::endl;
}
