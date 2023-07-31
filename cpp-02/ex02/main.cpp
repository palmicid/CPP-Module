#include "Fixed.hpp"

int	main()
{
	{
		Fixed		a;
		Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std:: endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}

	std::cout << "================== END OF EXAMPLE TEST =====================" << std::endl;

	std::cout << "TEST BOOL" << std::endl;
	// == , != , >=, <= , >, <
	Fixed	a( 5.05f );
	Fixed	b( 10.42f );
	Fixed	c( -3.21f );
	Fixed	d( a );

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	// == and !=

	std::cout << "operator ==" << std::endl;
	std::cout << "	a == d ? " << (a == d) << std::endl;
	std::cout << "	a == b ? " << (a == b) << std::endl;

	std::cout << "operator !=" << std::endl;
	std::cout << "	a != d ? " << (a != d) << std::endl;
	std::cout << "	a != b ? " << (a != b) << std::endl;


	// >= and <=

	std::cout << "operator >=" << std::endl;
	std::cout << "	a >= b ? " << (a >= b) << std::endl;
	std::cout << "	a >= d ? " << (a >= d) << std::endl;
	std::cout << "	a >= c ? " << (a >= c) << std::endl;

	std::cout << "operator <=" << std::endl;
	std::cout << "	a <= b ? " << (a <= b) << std::endl;
	std::cout << "	a <= d ? " << (a <= d) << std::endl;
	std::cout << "	a <= c ? " << (a <= c) << std::endl;

	// > and <

	std::cout << "operator >" << std::endl;
	std::cout << "	a > b ? " << (a > b) << std::endl;
	std::cout << "	a > d ? " << (a > d) << std::endl;
	std::cout << "	a > c ? " << (a > c) << std::endl;

	std::cout << "operator <" << std::endl;
	std::cout << "	a < b ? " << (a < b) << std::endl;
	std::cout << "	a < d ? " << (a < d) << std::endl;
	std::cout << "	a < c ? " << (a < c) << std::endl;

	// + - * /
	std::cout << "\n\nTEST + - * /\n" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	// +
	std::cout << "operator +" << std::endl;
	std::cout << "	a + b ? " << (a + b) << std::endl;
	std::cout << "	a + c ? " << (a + c) << std::endl;
	std::cout << "	c + c ? " << (c + c) << std::endl;

	std::cout << "operator -" << std::endl;
	std::cout << "	a - b ? " << (a - b) << std::endl;
	std::cout << "	a - c ? " << (a - c) << std::endl;
	std::cout << "	c - c ? " << (c - c) << std::endl;

	std::cout << "operator *" << std::endl;
	std::cout << "	a * b ? " << (a * b) << std::endl;
	std::cout << "	a * c ? " << (a * c) << std::endl;
	std::cout << "	c * c ? " << (c * c) << std::endl;

	std::cout << "operator /" << std::endl;
	std::cout << "	a / b ? " << (a / b) << std::endl;
	std::cout << "	a / c ? " << (a / c) << std::endl;
	std::cout << "	c / c ? " << (c / c) << std::endl;

	// min
	std::cout << "MIN" << std::endl;
	std::cout << "	a vs b ? " << Fixed::min(a, b) << std::endl;
	std::cout << "	b vs a ? " << Fixed::min(b, a) << std::endl;
	std::cout << "	b vs c ? " << Fixed::min(b, c) << std::endl;
	std::cout << "	c vs b ? " << Fixed::min(c, b) << std::endl;

	// max
	std::cout << "MAX" << std::endl;
	std::cout << "	a vs b ? " << Fixed::max(a, b) << std::endl;
	std::cout << "	b vs a ? " << Fixed::max(b, a) << std::endl;
	std::cout << "	b vs c ? " << Fixed::max(b, c) << std::endl;
	std::cout << "	c vs b ? " << Fixed::max(c, b) << std::endl;

	return 0;
}