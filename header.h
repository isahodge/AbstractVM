#ifndef HEADER_H
#define HEADER_H
#include <queue>
#include "Instr.hpp"

enum eOperandType {Int8, Int16, Int32, Float, Double};

void	vm_execute(std::queue <Instr const *>& q);

#endif
