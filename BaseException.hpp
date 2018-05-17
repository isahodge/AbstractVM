#ifndef BASEEXCEPTION_HPP
#define BASEEXCEPTION_HPP
#include <exception>
#include <iostream>

class BaseException: public std::exception {

public:
	BaseException( std::string const & message );
	BaseException( BaseException const & src );
	BaseException & operator=( BaseException const & rhs );
	~BaseException( void ) throw() ;

	const char* what() const throw();

protected:
	BaseException( void );
	std::string _msg;
};

#endif
