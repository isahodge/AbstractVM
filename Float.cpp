#include "Float.hpp"
#include <string>

Float::Float( void ) {}

Float::~Float( void ) {}

Float::Float( Float const & src ) {
	*this = src;
}

Float::Float( float value, std::string const & str ): _value( value ), _str( str ) {}

class Float & Float::operator=( Float const & rhs ) {
	this->_str = rhs.toString();
	return *this;
}

eOperandType Float::getType( void ) const {
	return ::Float;
}

int		Float::getPrecision( void ) const {
	return 3;
}

std::string const & Float::toString( void ) const {
	return _str;
}

IOperand const * Float::operator+( IOperand const & rhs ) const {
		double tmp = _value;
		tmp++;
		return (&rhs);
}

IOperand const * Float::operator-( IOperand const & rhs ) const {
		return (&rhs);
}

IOperand const * Float::operator*( IOperand const & rhs ) const {
		return (&rhs);
}

IOperand const * Float::operator/( IOperand const & rhs ) const {
		return (&rhs);
}

IOperand const * Float::operator%( IOperand const & rhs ) const {
		return (&rhs);
}
