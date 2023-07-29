#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_fixPointNum = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : _fixPointNum(num << _numFracBits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : _fixPointNum( roundf( num * (1 << _numFracBits)) )
{
	// std::cout << "Float constructor called" << std::endl;

	// converts to corresponding fixed-point value
}

Fixed::Fixed(const Fixed &obj)
{
	// std::cout << "Copy constructor called" << std::endl;
	// this->_fixPointNum = obj.getRawBits();
	*this = obj;
}

Fixed	&Fixed::operator=(const Fixed &obj)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this == &obj)
		return (*this);
	
	this->_fixPointNum = obj.getRawBits();
	return (*this);
}

// ======================= ADD THIS EX START ========================================

bool Fixed::operator>(Fixed const &obj)
{
	if (getRawBits() > obj.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<(Fixed const &obj)
{
	if (getRawBits() < obj.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(Fixed const &obj)
{
	if (getRawBits() >= obj.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(Fixed const &obj)
{
	if (getRawBits() <= obj.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(Fixed const &obj)
{
	if (getRawBits() == obj.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(Fixed const &obj)
{
	if (getRawBits() != obj.getRawBits())
		return true;
	return false;
}



Fixed Fixed::operator+(Fixed const &obj)
{
	return (Fixed( toFloat() + obj.toFloat() ));
}


Fixed Fixed::operator-(Fixed const &obj)
{
	return (Fixed( toFloat() - obj.toFloat() ));
}

Fixed Fixed::operator*(Fixed const &obj)
{
	return (Fixed( toFloat() * obj.toFloat() ));
}

Fixed Fixed::operator/(Fixed const &obj)
{
	return (Fixed( toFloat() / obj.toFloat() ));
}

Fixed &Fixed::operator++()
{
	this->_fixPointNum++;
	return (*this);
}

Fixed Fixed::operator++( int )
{
	Fixed	tmp(*this);

	this->_fixPointNum++;
	return tmp;
}

Fixed &Fixed::operator--()
{
	this->_fixPointNum--;
	return (*this);
}

Fixed Fixed::operator--( int )
{
	Fixed	tmp(*this);

	this->_fixPointNum--;
	return tmp;
}

Fixed&	Fixed::min( Fixed &obj1, Fixed &obj2 )
{
	if (obj1.getRawBits() < obj2.getRawBits())
		return obj1;
	return obj2;
}

const Fixed&	Fixed::min( const Fixed &obj1, const Fixed &obj2 )
{
	if (obj1.getRawBits() < obj2.getRawBits())
		return obj1;
	return obj2;
}

Fixed&	Fixed::max( Fixed &obj1, Fixed &obj2 )
{
	if (obj1.getRawBits() > obj2.getRawBits())
		return obj1;
	return obj2;
}

const Fixed& Fixed::max( const Fixed &obj1, const Fixed &obj2 )
{
	if (obj1.getRawBits() > obj2.getRawBits())
		return obj1;
	return obj2;
}


// ======================= ADD THIS EX END ========================================

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
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
