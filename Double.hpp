#ifndef DOUBLE_HPP
#define DOUBLE_HPP
#include <iostream>
#include "IOperand.hpp"
#include "header.h"

class Double: public IOperand {

public:
	Double( double value, std::string const & str );
	Double( Double const & src );
	Double & operator=( Double const & rhs );
	~Double( void );

	int	getPrecision( void ) const;
	eOperandType getType( void ) const;

	IOperand const * operator+( IOperand const & rhs ) const;
	IOperand const * operator-( IOperand const & rhs ) const;
	IOperand const * operator*( IOperand const & rhs ) const;
	IOperand const * operator/( IOperand const & rhs ) const;
	IOperand const * operator%( IOperand const & rhs ) const;

	std::string const & toString( void ) const;

private:
	Double( void );
	double _value;
	std::string _str;
	
};

#endif
