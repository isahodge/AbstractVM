#include "Double.hpp"
#include <string>

Double::Double( void ) {}

Double::~Double( void ) {}

Double::Double( Double const & src ) {
	*this = src;
}

Double::Double( double value, std::string const & str ): _value( value ), _str( str ) {}

class Double & Double::operator=( Double const & rhs ) {
	this->_str = rhs.toString();
	return *this;
}

eOperandType Double::getType( void ) const {
	return ::Double;
}

int		Double::getPrecision( void ) const {
	return 4;
}

std::string const & Double::toString( void ) const {
	return _str;
}

IOperand const * Double::operator+( IOperand const & rhs ) const {
	double tmp = _value;
	tmp++;
		return (&rhs);
}

IOperand const * Double::operator-( IOperand const & rhs ) const {
		return (&rhs);
}

IOperand const * Double::operator*( IOperand const & rhs ) const {
		return (&rhs);
}

IOperand const * Double::operator/( IOperand const & rhs ) const {
		return (&rhs);
}

IOperand const * Double::operator%( IOperand const & rhs ) const {
		return (&rhs);
}
