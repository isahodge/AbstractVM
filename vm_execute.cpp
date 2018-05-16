#include "IOperand.hpp"
#include "Create.hpp"
#include "header.h"
#include "Instr.hpp"
#include <queue>
#include <stack>
#include <iostream>

void	vm_execute(std::queue <Instr const *>& q)
{
	std::cout << "Executing instructions:\n";
	while (!q.empty())
	{
		switch (q.front()->getInstruction()) {
			case 1:
				std::cout << "push\n";
				break ;
			case 2:
				std::cout << "assert\n";
				break ;
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
		q.pop();
	}
}
