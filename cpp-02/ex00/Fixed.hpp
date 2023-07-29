#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &obj);
		Fixed &operator=(Fixed const &obj);
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw);
	private:
		int					_fixPointNum;
		static const int	_numFracBits = 8;
};

#endif
