#include "Create.hpp"
#include "IOperand.hpp"
#include "Int8.hpp"
#include <iostream>
#include "header.h"
#include <stack>

int		main(void)
{
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
