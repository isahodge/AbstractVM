#ifndef INTSTR_HPP
#define INTSTR_HPP

class IOperand;

class Instr {

public:
	Instr( int instruction, IOperand const *operand );
	Instr( int instruction );
	Instr( Instr const & src );
	Instr & operator=( Instr const & rhs );
	~Instr( void );

	int	getInstruction( void ) const;
	IOperand const *getOperand( void ) const;

private:
	Instr( void );
	int _instruction;
	IOperand const *_operand;
};

#endif
