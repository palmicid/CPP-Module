#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_fixPointNum = 0;
}

Fixed::Fixed(int fpn, const int nfb) : _fixPointNum(fpn), _numFracBits(nfb)
{

}

Fixed::Fixed(const Fixed &)
{
}

Fixed	Fixed::operator=(Fixed const& obj)
{
	Fixed ret(obj._fixPointNum, obj._numFracBits);

	// ret._fixPointNum = obj._fixPointNum;
	// ret._numFracBits = obj._numFracBits;
	return (ret);
}
~Fixed();

int		getRawBits( void ) const;
void	setRawBits( int const raw);