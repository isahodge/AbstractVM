#include "Int8.hpp"
#include "Create.hpp"
#include <climits>

class Create;

Int8::Int8( void ) {}

Int8::~Int8( void ) {}

Int8::Int8( Int8 const & src ) {
	*this = src;
}

Int8::Int8( int8_t value, std::string str ): _value( value ), _str( str ) {}

class Int8 & Int8::operator=( Int8 const & rhs ) {
	this->_str = rhs.toString();
	return *this;
}

eOperandType Int8::getType( void ) const {
	return ::Int8;
}

int		Int8::getPrecision( void ) const {
	return 0;
}

std::string const & Int8::toString( void ) const {
	return _str;
}
//need error handling: limits
IOperand const * Int8::operator+( IOperand const & rhs ) const {
	Create instance;
	const IOperand *result;
	double ret;

	ret = this->_value - 48 + std::stod(rhs.toString());
	if (rhs.getPrecision() == 0 || rhs.getPrecision() == 1 || rhs.getPrecision() == 2)
		result = instance.createOperand(rhs.getType(), std::to_string(static_cast<int>(ret)));
	else
		result = instance.createOperand(rhs.getType(), std::to_string(ret));
	return result;
}

IOperand const * Int8::operator-( IOperand const & rhs ) const {
	return (&rhs);
}

IOperand const * Int8::operator*( IOperand const & rhs ) const{
	return (&rhs);
}

IOperand const * Int8::operator/( IOperand const & rhs ) const {
	return (&rhs);
}

IOperand const * Int8::operator%( IOperand const & rhs ) const {
	return (&rhs);
}