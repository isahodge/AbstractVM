#include "Int8.hpp"
#include "Create.hpp"
#include "BaseException.hpp"
#include <climits>
#include <cstdlib>

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

IOperand const * Int8::operator+( IOperand const & rhs ) const {
	Create factory;
	const IOperand *result;
	int ret;

	std::cout << "Int8[" << (int)this->_value << "]" << std::endl;
	try {
		ret = this->_value + std::strtol(rhs.toString().c_str(), NULL, 10);
		if (ret < std::strtol(_str.c_str(), NULL, 10))
			throw BaseException("Exception: addition overflow");
	}
	catch (BaseException &ex)
	{//handle overflow; mod by max?
		std::cout << ex.what() << std::endl;
	}
	if (this->getPrecision() < rhs.getPrecision())
		result = factory.createOperand(rhs.getType(), std::to_string(static_cast<int>(ret)));
	else
		result = factory.createOperand(this->getType(), std::to_string(static_cast<int>(ret)));
	return result;
}

IOperand const * Int8::operator-( IOperand const & rhs ) const {
	Create factory;
	const IOperand *result;
	int ret;

	std::cout << "Int8[" << (int)this->_value << "]" << std::endl;
	try {
		ret = this->_value - std::strtol(rhs.toString().c_str(), NULL, 10);
		if (ret > std::strtol(_str.c_str(), NULL, 10))
			throw BaseException("Exception: subtraction underflow");
	}
	catch (BaseException &ex)
	{//handle underflow; mod by min?
		std::cout << ex.what() << std::endl;
	}
	if (this->getPrecision() < rhs.getPrecision())
		result = factory.createOperand(rhs.getType(), std::to_string(static_cast<int>(ret)));
	else
		result = factory.createOperand(this->getType(), std::to_string(static_cast<int>(ret)));
	return result;
}

IOperand const * Int8::operator*( IOperand const & rhs ) const{
	Create factory;
	const IOperand *result;
	int ret;

	std::cout << "Int8[" << (int)this->_value << "]" << std::endl;
	try {
		ret = this->_value * std::strtol(rhs.toString().c_str(), NULL, 10);
		if (ret < std::strtol(_str.c_str(), NULL, 10))
			throw BaseException("Exception: multiplication overflow");
	}
	catch (BaseException &ex)
	{//handle overflow; mod by max?
		std::cout << ex.what() << std::endl;
	}
	if (this->getPrecision() < rhs.getPrecision())
		result = factory.createOperand(rhs.getType(), std::to_string(static_cast<int>(ret)));
	else
		result = factory.createOperand(this->getType(), std::to_string(static_cast<int>(ret)));
	return result;
}

IOperand const * Int8::operator/( IOperand const & rhs ) const {
	Create factory;
	const IOperand *result;
	int ret;

	std::cout << "Int8[" << (int)this->_value << "]" << std::endl;
	if (std::strtol(rhs.toString().c_str(), NULL, 10) == 0)
		throw BaseException("Exception: division by 0");
	ret = this->_value / std::strtol(rhs.toString().c_str(), NULL, 10);
	if (this->getPrecision() < rhs.getPrecision())
		result = factory.createOperand(rhs.getType(), std::to_string(static_cast<int>(ret)));
	else
		result = factory.createOperand(this->getType(), std::to_string(static_cast<int>(ret)));
	return result;
}

IOperand const * Int8::operator%( IOperand const & rhs ) const {
	Create factory;
	const IOperand *result;
	int ret;

	std::cout << "Int8[" << (int)this->_value << "]" << std::endl;
	if (std::strtol(rhs.toString().c_str(), NULL, 10) == 0)
		throw BaseException("Exception: mod by 0");
	ret = this->_value % std::strtol(rhs.toString().c_str(), NULL, 10);
	if (this->getPrecision() < rhs.getPrecision())
		result = factory.createOperand(rhs.getType(), std::to_string(static_cast<int>(ret)));
	else
		result = factory.createOperand(this->getType(), std::to_string(static_cast<int>(ret)));
	return result;
}
