#ifndef INT8_HPP
#define INT8_HPP
#include <iostream>
#include "IOperand.hpp"
#include "header.h"

class Int8: public IOperand {

public:
	Int8( int8_t value, std::string str );
	Int8( Int8 const & src );
	Int8 & operator=( Int8 const & rhs );
	~Int8( void );

	int	getPrecision( void ) const;
	eOperandType getType( void ) const;

	IOperand const * operator+( IOperand const & rhs ) const;
	IOperand const * operator-( IOperand const & rhs ) const;
	IOperand const * operator*( IOperand const & rhs ) const;
	IOperand const * operator/( IOperand const & rhs ) const;
	IOperand const * operator%( IOperand const & rhs ) const;

	std::string const & toString( void ) const;
private:
	Int8( void );
	int8_t _value;
	std::string _str;
};

#endif
