#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_fixPointNum = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : _fixPointNum(num << _numFracBits)
{
	std::cout << "Int constructor called" << std::endl;
}

// Fixed::Fixed(const float num) : _fixPointNum( (int)(num * (1 << _numFracBits)) )
Fixed::Fixed(const float num) : _fixPointNum( roundf( num * (1 << _numFracBits)) )
{
	std::cout << "Float constructor called" << std::endl;
	// converts to corresponding fixed-point value
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	// this->_fixPointNum = obj.getRawBits();
	*this = obj;
}

Fixed	&Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &obj)
		return (*this);
	
	this->_fixPointNum = obj.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const
{
	return (this->_fixPointNum);
}


void	Fixed::setRawBits( int const raw)
{
	this->_fixPointNum = raw;
}

float	Fixed::toFloat( void ) const
{
	// convert fixed-point value to a floting-point value
	return (this->getRawBits() / (float)(1 << this->_numFracBits));
}

int	Fixed::toInt( void ) const
{
	return (this->_fixPointNum >> this->_numFracBits);
}

std::ostream &operator<<( std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return out;
}
