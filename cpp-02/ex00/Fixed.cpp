#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_fixPointNum = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixPointNum = obj.getRawBits();
}

Fixed	&Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &obj)
		return (*this);
	
	this->_fixPointNum = obj._fixPointNum;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixPointNum);
}


void	Fixed::setRawBits( int const raw)
{
	_fixPointNum = raw;
	
}
