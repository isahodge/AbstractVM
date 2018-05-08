#include "Int16.hpp"

Int16::Int16( void ) {}

Int16::~Int16( void ) {}

Int16::Int16( Int16 const & src ) {
	*this = src;
}

Int16::Int16( int16_t value, std::string const & str ): _value( value ), _str( str ) {}

class Int16 & Int16::operator=( Int16 const & rhs ) {
	this->_str = rhs.toString();
	return *this;
}

eOperandType Int16::getType( void ) const {
	return ::Int16;
}

int		Int16::getPrecision( void ) const {
	return 1;
}

std::string const & Int16::toString( void ) const {
	return _str;
}

IOperand const * Int16::operator+( IOperand const & rhs ) const {
	double tmp = _value;
	tmp++;
		return (&rhs);
}

IOperand const * Int16::operator-( IOperand const & rhs ) const {
		return (&rhs);
}

IOperand const * Int16::operator*( IOperand const & rhs ) const {
		return (&rhs);
}

IOperand const * Int16::operator/( IOperand const & rhs ) const {
		return (&rhs);
}

IOperand const * Int16::operator%( IOperand const & rhs ) const {
		return (&rhs);
}
