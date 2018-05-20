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

void	add(const IOperand *lhs, const IOperand *rhs, std::vector<IOperand const *> &vm)
{
	vm.push_back(*lhs + *rhs);
}

void	sub(const IOperand *lhs, const IOperand *rhs, std::vector<IOperand const *> &vm)
{
	vm.push_back(*lhs - *rhs);
}

void	mul(const IOperand *lhs, const IOperand *rhs, std::vector<IOperand const *> &vm)
{
	vm.push_back(*lhs * *rhs);
}

void	div(const IOperand *lhs, const IOperand *rhs, std::vector<IOperand const *> &vm)
{
	vm.push_back(*lhs / *rhs);
}

void	mod(const IOperand *lhs, const IOperand *rhs, std::vector<IOperand const *> &vm)
{
	vm.push_back(*lhs % *rhs);
}

void	arithmetic(std::vector<IOperand const *> &vm, void (*operate)(const IOperand *lhs, const IOperand *rhs, std::vector<IOperand const *> &vm))
{
	try {
		if (vm.empty() || vm.size() < 2)
			throw BaseException("Exception: Not enough operands to perform instruction");
		const IOperand *rhs = vm.back();
		vm.pop_back();
		const IOperand *lhs = vm.back();
		vm.pop_back();
		try {
			operate(lhs, rhs, vm);
		}
		catch (BaseException &ex)
		{
			throw;
		}
	}
	catch (BaseException &ex)
	{
		std::cout << ex.what() <<std::endl;
	}
	catch (std::out_of_range &ex)
	{
		std::cout << ex.what() <<std::endl;
	}

}

void	arith_dm(std::vector<IOperand const *> &vm, void (*operate)(const IOperand *lhs, const IOperand *rhs, std::vector<IOperand const *> &vm))
{
	try {
		if (vm.empty() || vm.size() < 2)
			throw BaseException("Exception: Not enough operands to perform instruction");
		const IOperand *rhs = vm.back();
		vm.pop_back();
		const IOperand *lhs = vm.back();
		vm.pop_back();
		try	{
		operate(lhs, rhs, vm);
		}
		catch (BaseException &ex)
		{
			throw;
		}
	}
	catch (BaseException &ex)
	{
		std::cout << ex.what() <<std::endl;
	}
	catch (std::out_of_range &ex)
	{
		std::cout << ex.what() <<std::endl;
	}
}

void	vm_execute(std::queue <Instr const *>& q)
{
	std::vector<IOperand const *> vm;
	std::vector<IOperand const *>::reverse_iterator dump_it;

	while (!q.empty() && q.front()->getInstruction() != 11)
	{
		switch (q.front()->getInstruction()) {
			case 1:
				if (q.front()->getOperand())
					vm.push_back(q.front()->getOperand());
				break ;
			case 2:
				try {
					if (!vm.empty() && q.front()->getOperand() &&
							q.front()->getOperand()->getType() == vm.back()->getType() &&
							!q.front()->getOperand()->toString().compare(vm.back()->toString()))
						std::cout << "";
					else
						throw BaseException("Exception: False Assert");
				}
				catch (BaseException &ex)
				{
					std::cout << ex.what() <<std::endl;
				}
				break ;
			case 3:
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
				for (dump_it = vm.rbegin();
						dump_it != vm.rend(); ++dump_it)
					std::cout << (*dump_it)->toString() << std::endl;
				break ;
			case 5:
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
				arithmetic(vm, add);
				break ;
			case 7:
				arithmetic(vm, sub);
				break ;
			case 8:
				arithmetic(vm, mul);
				break ;
			case 9: {
				arith_dm(vm, div);
				break ;
					}
			case 10: {
				arith_dm(vm, mod);
				break ;
					 }
			case 11: {
				break ;
					 }
		}
		q.pop();
	}
	if (q.empty() || q.front()->getInstruction() != 11)
		throw BaseException("Exception: No exit command");
}
