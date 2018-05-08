#ifndef INT16_HPP
#define INT16_HPP
#include <iostream>
#include "IOperand.hpp"
#include "header.h"

class Int16: public IOperand {

public:
	Int16( int16_t value, std::string const & str );
	Int16( Int16 const & src );
	Int16 & operator=( Int16 const & rhs );
	~Int16( void );

	int	getPrecision( void ) const;
	eOperandType getType( void ) const;

	IOperand const * operator+( IOperand const & rhs ) const;
	IOperand const * operator-( IOperand const & rhs ) const;
	IOperand const * operator*( IOperand const & rhs ) const;
	IOperand const * operator/( IOperand const & rhs ) const;
	IOperand const * operator%( IOperand const & rhs ) const;

	std::string const & toString( void ) const;
private:
	Int16( void );
	int16_t _value;
	std::string	_str;
	
};

#endif
