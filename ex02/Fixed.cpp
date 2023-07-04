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
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointNum = (num << this->_fractionalBits);
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointNum = static_cast<int>(roundf(num * (1 << this->_fractionalBits)));
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
	return (static_cast<float>(this->_fixedPointNum) / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointNum >> this->_fractionalBits);
}

bool Fixed::operator>(const Fixed& fixed) const
{
	return (this->_fixedPointNum > fixed._fixedPointNum);
}

bool Fixed::operator<(const Fixed& fixed) const
{
	return (this->_fixedPointNum < fixed._fixedPointNum);
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	return (this->_fixedPointNum >= fixed._fixedPointNum);
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	return (this->_fixedPointNum <= fixed._fixedPointNum);
}

bool Fixed::operator==(const Fixed& fixed) const
{
	return (this->_fixedPointNum == fixed._fixedPointNum);
}

bool Fixed::operator!=(const Fixed& fixed) const
{
	return (this->_fixedPointNum != fixed._fixedPointNum);
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
	Fixed result;

	result._fixedPointNum = this->_fixedPointNum + fixed._fixedPointNum;
	return result;
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	Fixed result;

	result._fixedPointNum = this->_fixedPointNum - fixed._fixedPointNum;
	return result;
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed& Fixed::operator++()
{
	++this->_fixedPointNum;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed result(*this);

	++this->_fixedPointNum;
	return result;
}

Fixed& Fixed::operator--()
{
	--this->_fixedPointNum;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed result(*this);

	--this->_fixedPointNum;
	return result;
}

Fixed& Fixed::min(Fixed& x, Fixed& y)
{
	return ((x < y) ? x : y);
}

const Fixed& Fixed::min(const Fixed& x, const Fixed& y)
{
	return ((x < y) ? x : y);
}

Fixed& Fixed::max(Fixed& x, Fixed& y)
{
	return ((x > y) ? x : y);
}

const Fixed& Fixed::max(const Fixed& x, const Fixed& y)
{
	return ((x > y) ? x : y);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	return (os << fixed.toFloat());
}
