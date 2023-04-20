#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	static const int fractionalBits_ = 8;
	int fixedPointNum_;

public:
	Fixed(void);
	Fixed(const Fixed& fixed);
	~Fixed(void);

	Fixed& operator=(const Fixed& fixed);

	int getRawBits(void) const;
	void setRawBits(int const raw);

};

#endif
