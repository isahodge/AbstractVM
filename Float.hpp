#ifndef FLOAT_HPP
#define FLOAT_HPP
#include <iostream>
#include "IOperand.hpp"
#include "header.h"

class Float: public IOperand {

public:
	Float( float value, std::string const & str );
	Float( Float const & src );
	Float & operator=( Float const & rhs );
	~Float( void );

	int	getPrecision( void ) const;
	eOperandType getType( void ) const;

	IOperand const * operator+( IOperand const & rhs ) const;
	IOperand const * operator-( IOperand const & rhs ) const;
	IOperand const * operator*( IOperand const & rhs ) const;
	IOperand const * operator/( IOperand const & rhs ) const;
	IOperand const * operator%( IOperand const & rhs ) const;

	std::string const & toString( void ) const;
private:
	Float( void );
	float _value;
	std::string _str;
	
};

#endif
