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

	IOperand const * operator+( IOperand const & rhs ) const
	{
		Create factory;
		const IOperand *result;
		int ret;

		std::cout << "Int[" << (int)this->_value << "]" << std::endl;
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
			result = factory.createOperand(rhs.getType(),
					std::to_string(static_cast<int>(ret)));
		else
			result = factory.createOperand(this->getType(),
					std::to_string(static_cast<int>(ret)));
		return result;
	}

	IOperand const * operator-( IOperand const & rhs ) const
	{
		Create factory;
		const IOperand *result;
		int ret;

		std::cout << "Int[" << (int)this->_value << "]" << std::endl;
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
			result = factory.createOperand(rhs.getType(),
					std::to_string(static_cast<int>(ret)));
		else
			result = factory.createOperand(this->getType(),
					std::to_string(static_cast<int>(ret)));
		return result;
	}

	IOperand const * operator*( IOperand const & rhs ) const
	{
		Create factory;
		const IOperand *result;
		int ret;

		std::cout << "Int[" << (int)this->_value << "]" << std::endl;
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
			result = factory.createOperand(rhs.getType(),
					std::to_string(static_cast<int>(ret)));
		else
			result = factory.createOperand(this->getType(),
					std::to_string(static_cast<int>(ret)));
		return result;
	}

	IOperand const * operator/( IOperand const & rhs ) const
	{
		Create factory;
		const IOperand *result;
		int ret;

		std::cout << "Int[" << (int)this->_value << "]" << std::endl;
		if (std::strtol(rhs.toString().c_str(), NULL, 10) == 0)
			throw BaseException("Exception: division by 0");
		ret = this->_value / std::strtol(rhs.toString().c_str(), NULL, 10);
		if (this->getPrecision() < rhs.getPrecision())
			result = factory.createOperand(rhs.getType(),
					std::to_string(static_cast<int>(ret)));
		else
			result = factory.createOperand(this->getType(),
					std::to_string(static_cast<int>(ret)));
		return result;
	}

	IOperand const * operator%( IOperand const & rhs ) const
	{
		Create factory;
		const IOperand *result;
		int ret;

		std::cout << "Int[" << (int)this->_value << "]" << std::endl;
		if (std::strtol(rhs.toString().c_str(), NULL, 10) == 0)
			throw BaseException("Exception: mod by 0");
		ret = this->_value % std::strtol(rhs.toString().c_str(), NULL, 10);
		if (this->getPrecision() < rhs.getPrecision())
			result = factory.createOperand(rhs.getType(),
					std::to_string(static_cast<int>(ret)));
		else
			result = factory.createOperand(this->getType(),
					std::to_string(static_cast<int>(ret)));
		return result;
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
