/*
 * deifinitions
 */
%option noyywrap

%{
#include "Create.hpp"
#include "IOperand.hpp"
#include "Int8.hpp"
#include <iostream>
#include "header.h"
#include <stack>
%}

DIGIT	[0-9]

%%

{DIGIT}+	printf("a digit %s\n", yytext);
push	printf("recognized the push command\n");
pop		printf("recognized the pop command\n");
dump	printf("recognized the dump command\n");
assert	printf("recognized the assert command\n");
add		printf("recognized the add command\n");
sub		printf("recognized the sub command\n");
mul		printf("recognized the mul command\n");
div		printf("recognized the div command\n");
mod		printf("recognized the mod command\n");
print	printf("recognized the print command\n");
exit	printf("recognized the exit command\n");
[ \t\n]+          /* eat up whitespace */

%%

int		main(void)
{
	yyin = stdin;
	yylex();
	Create factory;
	std::stack <IOperand const *> vm;

	vm.push(factory.createOperand(Int8, "10"));
	vm.push(factory.createOperand(Int8, "5"));
	const IOperand *lhs = vm.top();
	vm.pop();
	const IOperand *rhs = vm.top();
	vm.pop();
	vm.push(*lhs + *rhs);
	std::cout << vm.top()->toString() << std::endl;
	return (0);
}
