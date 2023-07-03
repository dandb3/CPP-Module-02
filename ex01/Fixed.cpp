#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void)
: _fixedPointNum(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	this->_fixedPointNum = (num << this->_fractionalBits);
}

Fixed::Fixed(const float num)
{
	this->_fixedPointNum = (int) roundf(num * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed& fixed)
: _fixedPointNum(fixed._fixedPointNum)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointNum = fixed._fixedPointNum;
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointNum;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointNum = raw;
}

float Fixed::toFloat(void) const
{
	return ((float) this->_fixedPointNum / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointNum >> this->_fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	return (os << fixed.toFloat());
}
