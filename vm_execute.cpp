#include "IOperand.hpp"
#include "Create.hpp"
#include "header.h"
#include "Instr.hpp"
#include "BaseException.hpp"
#include "Template.hpp"
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <cstdio>

//arithmetic function that takes ina a pointer to one of the funcitons below: lhs, rhs, vm, fptr
//add, sub, mul, div, mod functions, params: lhs rhs vm

void	vm_execute(std::queue <Instr const *>& q)
{
	std::vector<IOperand const *> vm;
	std::vector<IOperand const *>::reverse_iterator dump_it;

	std::cout << "Executing instructions:\n";
	while (!q.empty())
	{
		switch (q.front()->getInstruction()) {
			case 1:
				std::cout << "push\n";
				vm.push_back(q.front()->getOperand());
				break ;
			case 2:
				std::cout << "assert\n";
				try {
				if (!vm.empty() && q.front()->getOperand()->getType() == vm.back()->getType() &&
						!q.front()->getOperand()->toString().compare(vm.back()->toString()))
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
					vm.pop_back();
				}
				catch (BaseException &ex)
				{
					std::cout << ex.what() <<std::endl;
				}
				break ;
			case 4:
				std::cout << "dump\n";
				for (dump_it = vm.rbegin();
						dump_it != vm.rend(); ++dump_it)
					std::cout << (*dump_it)->toString() << std::endl;
				break ;
			case 5:
				std::cout << "print\n";
				try {
				if (!vm.empty() && vm.back()->getType() == Int8)
				{
					std::cout << (char)(std::stoi(vm.back()->toString(), NULL, 10)) <<
						std::endl;
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
					std::cout << (char)(std::stoi(vm.back()->toString(), NULL, 10)) << std::endl;
				}
				else
					throw BaseException("Exception: Not enough operands to perform instruction");
				const IOperand *rhs = vm.back();
				vm.pop_back();
				const IOperand *lhs = vm.back();
				vm.pop_back();
				vm.push_back(*lhs + *rhs);
				}
				catch (BaseException &ex)
				{
					std::cout << ex.what() <<std::endl;
				}
				break ;
			case 7:
				std::cout << "sub\n";
				try {
				if (!vm.empty() && vm.size() >= 2)
				{
					std::cout << (char)(std::stoi(vm.back()->toString(), NULL, 10)) << std::endl;
				}
				else
					throw BaseException("Exception: Not enough operands to perform instruction");
				const IOperand *rhs = vm.back();
				vm.pop_back();
				const IOperand *lhs = vm.back();
				vm.pop_back();
				vm.push_back(*lhs - *rhs);
				}
				catch (BaseException &ex)
				{
					std::cout << ex.what() <<std::endl;
				}
				break ;
			case 8:
				std::cout << "mul\n";
				try {
				if (!vm.empty() && vm.size() >= 2)
				{
					std::cout << (char)(std::stoi(vm.back()->toString(), NULL, 10)) << std::endl;
				}
				else
					throw BaseException("Exception: Not enough operands to perform instruction");
				const IOperand *rhs = vm.back();
				vm.pop_back();
				const IOperand *lhs = vm.back();
				vm.pop_back();
				vm.push_back(*lhs * *rhs);
				}
				catch (BaseException &ex)
				{
					std::cout << ex.what() <<std::endl;
				}
				break ;
			case 9: {
				std::cout << "div\n";
				try {
				if (!vm.empty() && vm.size() >= 2)
					std::cout << (char)(std::stoi(vm.back()->toString(), NULL, 10)) <<
						std::endl;
				else
					throw BaseException("Exception: Not enough operands to perform instruction");
				}
				catch (BaseException &ex)
				{
					std::cout << ex.what() <<std::endl;
				}
				try {
				const IOperand *rhs = vm.back();
				vm.pop_back();
				const IOperand *lhs = vm.back();
				vm.pop_back();
				vm.push_back(*lhs / *rhs);
				}
				catch (BaseException &ex)
				{
					//repush lhs?
					std::cout << ex.what() <<std::endl;
				}
				break ;
					}
			case 10: {
				std::cout << "mod\n";
				try {
				if (!vm.empty() && vm.size() >= 2)
					std::cout << (char)(std::stoi(vm.back()->toString(), NULL, 10)) <<
						std::endl;
				else
					throw BaseException("Exception: Not enough operands to perform instruction");
				}
				catch (BaseException &ex)
				{
					std::cout << ex.what() <<std::endl;
				}
				try {
				const IOperand *rhs = vm.back();
				vm.pop_back();
				const IOperand *lhs = vm.back();
				vm.pop_back();
				vm.push_back(*lhs % *rhs);
				}
				catch (BaseException &ex)
				{
					//repush lhs?
					std::cout << ex.what() <<std::endl;
				}
				break ;
					 }
		}
		q.pop();
	}
}
