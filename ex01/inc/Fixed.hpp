/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 10:42:22 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/08 16:41:23 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	private:
		int raw_;
		static const int fractional_bits_ = 8;

	public:
		// construcors
		Fixed();
		// ............ hier weiter ..............
		// copy constructor
		Fixed(const Fixed& other);
		// copy assignment operator
		Fixed& operator=(const Fixed &other);
		// deconstructor
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
