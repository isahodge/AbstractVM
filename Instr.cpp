#include "Instr.hpp"
#include <cstdlib>

Instr::Instr( void ) {}

Instr::~Instr( void ) {}

Instr::Instr( Instr const & src ) {
	*this = src;
}

Instr & Instr::operator=( Instr const & rhs ) {
	_operand = rhs.getOperand();
	_instruction = rhs.getInstruction();
	return *this;
}

Instr::Instr( int instruction, IOperand const *operand ): _instruction( instruction ), _operand( operand ) {}

Instr::Instr( int instruction ): _instruction( instruction ), _operand( NULL ) {}

IOperand const *Instr::getOperand( void ) const {
	return _operand;
}

int		Instr::getInstruction( void ) const {
	return _instruction;
}
