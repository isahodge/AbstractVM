#include "BaseException.hpp"
#include <cstdlib>
#include <iostream>

BaseException::BaseException( void ) {}

BaseException::~BaseException( void ) throw() {}

BaseException::BaseException( BaseException const & src ) {
	*this = src;
}

BaseException & BaseException::operator=( BaseException const & rhs ) {
	_msg = rhs.what();
	return *this;
}

BaseException::BaseException( std::string const & message ): _msg( message ) {}

const char*	BaseException::what( void ) const throw() {
	return _msg.c_str();
}
