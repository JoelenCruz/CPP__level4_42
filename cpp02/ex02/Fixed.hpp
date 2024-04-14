/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:11:22 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/05 19:52:21 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

#define PRINT(x) std::cout << x << std::endl;

class Fixed
{
    private:
        int _nbInt;
        int static const _nbFractional = 8;

    public:
		Fixed(void);
		Fixed(Fixed const &src);
        Fixed(const int value);
        Fixed(const float value); 
		~Fixed(void);
		
		Fixed &operator= (Fixed const &rhs);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		//* Overload of logic operators
		bool	operator > (const Fixed &rhs) const;
		bool	operator < (const Fixed &rhs) const;
		bool	operator >= (const Fixed &rhs) const;
		bool	operator <= (const Fixed &rhs) const;
		bool	operator == (const Fixed &rhs) const;
		bool	operator != (const Fixed &rhs) const;

		//* Overload of arithmetic operators
		Fixed	operator + (const Fixed &rhs) const;
		Fixed	operator - (const Fixed &rhs) const;
		Fixed	operator * (const Fixed &rhs) const;
		Fixed	operator / (const Fixed &rhs) const;

		//* Overload of increment/decrement operators
		Fixed	& operator ++ (void);
		Fixed	operator ++ (int);
		Fixed	& operator -- (void);
		Fixed	operator -- (int);

		//* Overload member functions
		static Fixed	&min(Fixed &lhs, Fixed &rhs);
		static Fixed	&min(Fixed const &lhs, Fixed const &rhs);
		static Fixed	&max(Fixed &lhs, Fixed &rhs);
		static Fixed	&max(Fixed const &lhs, Fixed const &rhs);
};

std::ostream & operator << (std::ostream & o, Fixed const & i);

#endif