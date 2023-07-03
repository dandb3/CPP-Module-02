#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	static const int _fractionalBits = 8;
	int _fixedPointNum;

public:
	Fixed(void);
	Fixed(const Fixed& fixed);
	~Fixed(void);

	Fixed& operator=(const Fixed& fixed);

	int getRawBits(void) const;
	void setRawBits(int const raw);

};

#endif
