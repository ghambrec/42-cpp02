/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 10:42:21 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/09 13:46:27 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
