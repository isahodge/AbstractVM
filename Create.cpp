#include "Create.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "header.h"
#include <vector>
#include <sstream>

Create::Create( void ) {
	functionVector.push_back(&Create::createInt8);
	functionVector.push_back(&Create::createInt16);
	functionVector.push_back(&Create::createInt32);
	functionVector.push_back(&Create::createFloat);
	functionVector.push_back(&Create::createDouble);
	std::cout << "Create const called\n";
}

Create::~Create( void ) {
	std::cout << "Create decon called\n";
}
//need error handling: limits
IOperand const * Create::createOperand( eOperandType type, std::string const & value ) const {
	IOperand const *p = (this->*functionVector[type])(value);
	return p;
}

IOperand const * Create::createInt8( std::string const & value ) const {
	char val;
	std::stringstream ss(value);
	ss >> val;
	return (new class Int8(val, value));	
}

IOperand const * Create::createInt16( std::string const & value ) const {
	short val;
	std::stringstream ss(value);
	ss >> val;
	return (new class Int16(val, value));	
}

IOperand const * Create::createInt32( std::string const & value ) const {
	int val;
	std::stringstream ss(value);
	ss >> val;
	return (new class Int32(val, value));	
}

IOperand const * Create::createFloat( std::string const & value ) const {
	float val;
	std::stringstream ss(value);
	ss >> val;
	return (new class Float(val, value));	
}

IOperand const * Create::createDouble( std::string const & value ) const {
	double val;
	std::stringstream ss(value);
	ss >> val;
	return (new class Double(val, value));	
}
