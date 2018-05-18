#include "IOperand.hpp"
#include "Create.hpp"
#include "header.h"
#include "Instr.hpp"
#include "BaseException.hpp"
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <cstdio>

void	vm_execute(std::queue <Instr const *>& q)
{
	std::stack<IOperand const *> vm;
	std::vector<IOperand const *> vm_dump;
	std::vector<IOperand const *>::reverse_iterator dump_it;

	std::cout << "Executing instructions:\n";
	while (!q.empty())
	{
		switch (q.front()->getInstruction()) {
			case 1:
				std::cout << "push\n";
				vm.push(q.front()->getOperand());
				vm_dump.push_back(q.front()->getOperand());
				break ;
			case 2:
				std::cout << "assert\n";
				try {
				if (!vm.empty() && q.front()->getOperand()->getType() == vm.top()->getType() &&
						!q.front()->getOperand()->toString().compare(vm.top()->toString()))
					std::cout << "Assert true\n";
				else
					throw BaseException("Exception: False Assert");
				}
				catch (BaseException &ex)
				{
					std::cout << ex.what() <<std::endl;
				}
				break ;
			case 3:
				std::cout << "pop\n";
				try {
					if (vm.empty())
						throw BaseException("Exception: Pop on empty stack");
					vm.pop();
					vm_dump.pop_back();
				}
				catch (BaseException &ex)
				{
					std::cout << ex.what() <<std::endl;
				}
				break ;
			case 4:
				std::cout << "dump\n";
				for (dump_it = vm_dump.rbegin();
						dump_it != vm_dump.rend(); ++dump_it)
					std::cout << (*dump_it)->toString() << std::endl;
				break ;
			case 5:
				std::cout << "print\n";
				try {
				if (!vm.empty() && vm.top()->getType() == Int8)
				{
					std::cout << (char)(std::stoi(vm.top()->toString(), NULL, 10)) << std::endl;
				}
				else
					throw BaseException("Exception: False Assert with print operation");
				}
				catch (BaseException &ex)
				{
					std::cout << ex.what() <<std::endl;
				}
				break ;
			case 6:
				std::cout << "add\n";
				try {
				if (!vm.empty() && vm.size() >= 2)
				{
					std::cout << (char)(std::stoi(vm.top()->toString(), NULL, 10)) << std::endl;
				}
				else
					throw BaseException("Exception: Not enough operands to perform instruction");
				const IOperand *rhs = vm.top();
				vm.pop();
				vm_dump.pop_back();
				const IOperand *lhs = vm.top();
				vm.pop();
				vm_dump.pop_back();
				vm.push(*lhs + *rhs);
				vm_dump.push_back(*lhs + *rhs);
				}
				catch (BaseException &ex)
				{
					std::cout << ex.what() <<std::endl;
				}
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
