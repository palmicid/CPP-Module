#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &obj);
		Fixed &operator=(Fixed const &obj);
		~Fixed();

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
