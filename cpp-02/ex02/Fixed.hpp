#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &obj);
		~Fixed();
		Fixed &operator=(Fixed const &obj);

		bool	operator>(Fixed const &obj);
		bool	operator<(Fixed const &obj);
		bool	operator>=(Fixed const &obj);
		bool	operator<=(Fixed const &obj);
		bool	operator==(Fixed const &obj);
		bool	operator!=(Fixed const &obj);

		Fixed	operator+(Fixed const &obj);
		Fixed	operator-(Fixed const &obj);
		Fixed	operator*(Fixed const &obj);
		Fixed	operator/(Fixed const &obj);

		Fixed&	operator++();
		Fixed	operator++( int );
		Fixed&	operator--();
		Fixed	operator--( int );

		static Fixed		&min( Fixed &obj1, Fixed &obj2 );
		static const Fixed&	min( const Fixed &obj1, const Fixed &obj2 );
		static Fixed&		max( Fixed &obj1, Fixed &obj2 );
		static const Fixed&	max( const Fixed &obj1, const Fixed &obj2 );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
	private:
		int					_fixPointNum;
		static const int	_numFracBits = 8;
};

std::ostream &operator<<( std::ostream &out, const Fixed &obj);

#endif
