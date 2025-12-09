/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 10:42:21 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/09 14:32:50 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed(void)
	:	raw_(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int nbr)
	:	raw_(nbr * (1 << fractional_bits_))
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float nbr)
	:	raw_(static_cast<int>(roundf(nbr * (1 << fractional_bits_))))
{
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	raw_ = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		raw_ = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	return (raw_);
}

void Fixed::setRawBits(int const raw)
{
	raw_ = raw;
}

float Fixed::toFloat(void) const
{
	float val;

	val = (float)getRawBits() / (1 << fractional_bits_);
	return (val);
}

int Fixed::toInt(void) const
{
	int val;

	val = getRawBits() / (1 << fractional_bits_);
	return (val);
}

std::ostream& operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}

// ##### EX02 STUFF #####

bool Fixed::operator>(const Fixed &other) const
{
	return (raw_ > other.raw_);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (raw_ < other.raw_);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (raw_ >= other.raw_);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (raw_ <= other.raw_);	
}

bool Fixed::operator==(const Fixed &other) const
{
	return (raw_ == other.raw_);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (raw_ != other.raw_);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed res;
	
	res.raw_ = raw_ + other.raw_;
	return (res);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed res;
	
	res.raw_ = raw_ - other.raw_;
	return (res);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed res;
	
	long tmp = static_cast<long>(raw_) * static_cast<long>(other.raw_);
	res.raw_ = static_cast<int>(tmp >> fractional_bits_);
	return (res);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed res;
	
	long tmp = (static_cast<long>(raw_) << fractional_bits_);
	res.raw_ = static_cast<int>(tmp / other.raw_);
	return (res);
}

Fixed& Fixed::operator++(void)
{
	raw_++;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	raw_--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed res(*this);
	raw_++;
	return(res);
}

Fixed Fixed::operator--(int)
{
	Fixed res(*this);
	raw_--;
	return(res);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}
