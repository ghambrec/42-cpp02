/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 10:42:22 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/09 13:01:22 by ghambrec         ###   ########.fr       */
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
		// member functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	};
	
std::ostream& operator<<(std::ostream &os, const Fixed &obj);
