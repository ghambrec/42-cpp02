/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 10:42:22 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/09 14:10:14 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int raw_;
		static const int fractional_bits_ = 8;

	public:
		// construcors
		Fixed();
		Fixed(const int nbr);
		Fixed(const float nbr);
		// copy constructor
		Fixed(const Fixed& other);
		// copy assignment operator
		Fixed& operator=(const Fixed &other);
		// deconstructor
		~Fixed();

		// ##### OVERLOAD OPERATORS #####
		// comparison
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		// arithmetic
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		// increment / decrement
		Fixed& operator++(void);
		Fixed& operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		// member functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		// static member functions
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(Fixed const &a, Fixed const &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(Fixed const &a, Fixed const &b);
	};
	
std::ostream& operator<<(std::ostream &os, const Fixed &obj);
