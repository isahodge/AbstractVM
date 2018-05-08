#include "Int32.hpp"
#include <string>

Int32::Int32( void ) {}

Int32::~Int32( void ) {}

Int32::Int32( Int32 const & src ) {
	*this = src;
}

Int32::Int32( int value, std::string const & str ): _value( value ), _str( str ) {}

class Int32 & Int32::operator=( Int32 const & rhs ) {
	this->_str = rhs.toString();
	return *this;
}

eOperandType Int32::getType( void ) const {
	return ::Int32;
}

int		Int32::getPrecision( void ) const {
	return 2;
}
//static_cast<class Int32*>(this)->_value
std::string const & Int32::toString( void ) const {
	return _str;
}
//stoi(rhs.toString)
IOperand const * Int32::operator+( IOperand const & rhs ) const {
	double tmp;
	tmp = _value + stod(rhs.toString());
		return (&rhs);
}

IOperand const * Int32::operator-( IOperand const & rhs ) const {
		return (&rhs);
}

IOperand const * Int32::operator*( IOperand const & rhs ) const {
		return (&rhs);
}

IOperand const * Int32::operator/( IOperand const & rhs ) const {
		return (&rhs);
}

IOperand const * Int32::operator%( IOperand const & rhs ) const {
		return (&rhs);
}
