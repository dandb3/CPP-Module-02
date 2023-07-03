#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed
{
private:
	static const int _fractionalBits = 8;
	int _fixedPointNum;

public:
	Fixed(void);
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed& fixed);
	~Fixed(void);

	Fixed& operator=(const Fixed& fixed);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
