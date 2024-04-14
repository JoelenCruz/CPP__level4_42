/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:25:49 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/09 21:52:25 by jcruz-da         ###   ########.fr       */
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
};

std::ostream & operator << (std::ostream & o, Fixed const & i);

#endif