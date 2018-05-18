#include "Create.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "BaseException.hpp"
#include "Template.hpp"
#include "header.h"
#include <vector>
#include <sstream>
#include <string>
#include <float.h>


Create::Create( void ) {
	functionVector.push_back(&Create::createInt8);
	functionVector.push_back(&Create::createInt16);
	functionVector.push_back(&Create::createInt32);
	functionVector.push_back(&Create::createFloat);
	functionVector.push_back(&Create::createDouble);
	std::cout << "Create const called\n";
}

Create::Create( Create const & src )
{
	*this = src;
}

Create & Create::operator=( Create const & rhs )
{
	return *this;
}

Create::~Create( void ) {
	std::cout << "Create decon called\n";
}

IOperand const * Create::createOperand( eOperandType type, std::string const & value ) const {
	try {
		IOperand const *p = (this->*functionVector[type])(value);
		return p;
	}
	catch (BaseException &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return NULL;
}

IOperand const * Create::createInt8( std::string const & value ) const {
	char val;
	val = (char)std::strtol(value.c_str(), NULL, 10);
	std::cout << (int)val << std::endl;
	if(val < std::strtol(value.c_str(), NULL, 10))
	{
		throw BaseException("Exception: Overflow on Int8 in Create");
	}
	else if (std::strtol(value.c_str(), NULL, 10) < 0 && val >= 0)
	{
		throw BaseException("Exception: Underflow on Int8");
	}
	return (new Int <int8_t> (val, value, Int8));	
}

IOperand const * Create::createInt16( std::string const & value ) const {
	short val;
	val = (short)std::strtol(value.c_str(), NULL, 10);
	if(val < std::strtol(value.c_str(), NULL, 10))
	{
		throw BaseException("Exception: Overflow on Int16");
	}
	else if (std::strtol(value.c_str(), NULL, 10) < 0 && val >= 0)
	{
		throw BaseException("Exception: Underflow on Int16");
	}
	return (new Int <int16_t> (val, value, Int16));	
}

IOperand const * Create::createInt32( std::string const & value ) const {
	int val;
	val = (int)std::strtol(value.c_str(), NULL, 10);
	if(val < std::strtol(value.c_str(), NULL, 10))
	{
		throw BaseException("Exception: Overflow on Int32");
	}
	else if (std::strtol(value.c_str(), NULL, 10) < 0 && val >= 0)
	{
		throw BaseException("Exception: Underflow on Int32");
	}
	return (new Int <int32_t> (val, value, Int32));	
}

IOperand const * Create::createFloat( std::string const & value ) const {
	float val;
	val = (float)std::strtod(value.c_str(), NULL);
	return (new Int <float> (val, value, Float));	
}

IOperand const * Create::createDouble( std::string const & value ) const {
	double val;
	val = 0;
	try {
		val = std::stod(value, NULL);
	}
	catch (std::out_of_range &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return (new Int <double> (val, value, Double));	
}
