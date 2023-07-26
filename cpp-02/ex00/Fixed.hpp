#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		Fixed(int fpn, const int nfb);
		Fixed(const Fixed &);
		Fixed operator=(Fixed const& obj);
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw);
	private:
		int					_fixPointNum;
		static const int	_numFracBits;
};

#endif
