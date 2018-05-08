#ifndef CREATE_HPP
#define CREATE_HPP
#include "IOperand.hpp"
#include "header.h"
#include <iostream>
#include <vector>

class Create {

public:
	Create( void );
	~Create( void );
	IOperand const * createOperand( eOperandType type, std::string const & value ) const;

private:
	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;
	std::vector<IOperand const *(Create::*)(std::string const &) const> functionVector;
};

#endif
