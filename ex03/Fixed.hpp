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

	bool operator>(const Fixed& fixed) const;
	bool operator<(const Fixed& fixed) const;
	bool operator>=(const Fixed& fixed) const;
	bool operator<=(const Fixed& fixed) const;
	bool operator==(const Fixed& fixed) const;
	bool operator!=(const Fixed& fixed) const;

	Fixed operator+(const Fixed& fixed) const;
	Fixed operator-(const Fixed& fixed) const;
	Fixed operator*(const Fixed& fixed) const;
	Fixed operator/(const Fixed& fixed) const;

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed& x, Fixed& y);
	static const Fixed& min(const Fixed& x, const Fixed& y);
	static Fixed& max(Fixed& x, Fixed& y);
	static const Fixed& max(const Fixed& x, const Fixed& y);

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
