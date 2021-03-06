#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP
#include "header.h"

template <class T>
class Int: public IOperand {

public:

	Int( T value, std::string str, eOperandType type ): _value( value ), _str( str ), _type( type ) {}

	Int( Int const & src )
	{
		*this = src;
	}

	Int & operator=( Int const & rhs )
	{
		this->_str = rhs.toString();
		return *this;
	}

	~Int( void ) {}

	int	getPrecision( void ) const
	{
		return _type;
	}

	eOperandType getType( void ) const
	{
		return _type;
	}

	IOperand const * result( IOperand const & rhs, double ret ) const
	{
		Create factory;

		if (this->getPrecision() < rhs.getPrecision())
		{
			if (rhs.getPrecision() >= 3)
				return (factory.createOperand(rhs.getType(),
						std::to_string(static_cast<double>(ret))));
			else
				return (factory.createOperand(rhs.getType(),
						std::to_string(static_cast<long>(ret))));
		}
		else
		{
			if (this->getPrecision() >= 3)
				return (factory.createOperand(this->getType(),
						std::to_string(static_cast<double>(ret))));
			else
				return ( factory.createOperand(this->getType(),
						std::to_string(static_cast<long>(ret))));
		}
		return NULL;	
	}

	IOperand const * operator+( IOperand const & rhs ) const
	{
		double ret;

		ret = 0;
		try {
			ret = this->_value + std::stod(rhs.toString(), NULL);
		}
		catch (std::out_of_range &ex)
		{
			throw;
		}
		return result(rhs, ret);
	}

	IOperand const * operator-( IOperand const & rhs ) const
	{
		double ret;

		ret = 0;
		try {
			ret = this->_value - std::stod(rhs.toString(), NULL);
		}
		catch (std::out_of_range &ex)
		{
			throw;
		}
		return result(rhs, ret);
	}

	IOperand const * operator*( IOperand const & rhs ) const
	{
		double ret;

		ret = 0;
		try {
			ret = this->_value * std::stod(rhs.toString(), NULL);
		}
		catch (std::out_of_range &ex)
		{
			std::cout << ex.what() << std::endl;
			throw;
		}
		return result(rhs, ret);
	}

	IOperand const * operator/( IOperand const & rhs ) const
	{
		double ret;

		ret = 0;
		if (std::strtod(rhs.toString().c_str(), NULL) == 0)
			throw BaseException("Exception: division by 0");
		ret = this->_value / std::strtod(rhs.toString().c_str(), NULL);
		return result(rhs, ret);
	}

	IOperand const * operator%( IOperand const & rhs ) const
	{
		double ret;

		try {
			if (std::stod(rhs.toString(), NULL) == 0)
				throw BaseException("Exception: mod by 0");
		}
		catch (std::out_of_range &ex)
		{
			//std::cout << ex.what() << std::endl;
			throw;
		}
		ret = (long long int)this->_value % std::strtol(rhs.toString().c_str(), NULL, 10);
		return result(rhs, ret);
	}

	std::string const & toString( void ) const
	{
		return _str;
	}

private:

	Int( void );
	T _value;
	std::string _str;
	eOperandType _type;
};

#endif
