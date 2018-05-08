#ifndef INT32_HPP
#define INT32_HPP
#include <iostream>
#include "IOperand.hpp"
#include "header.h"

class Int32: public IOperand {

public:
	Int32( int value, std::string const & str );
	Int32( Int32 const & src );
	Int32 & operator=( Int32 const & rhs );
	~Int32( void );

	int	getPrecision( void ) const;
	eOperandType getType( void ) const;

	IOperand const * operator+( IOperand const & rhs ) const;
	IOperand const * operator-( IOperand const & rhs ) const;
	IOperand const * operator*( IOperand const & rhs ) const;
	IOperand const * operator/( IOperand const & rhs ) const;
	IOperand const * operator%( IOperand const & rhs ) const;

	std::string const & toString( void ) const;

private:
	Int32( void );
	int _value;
	std::string _str;
	
};

#endif
