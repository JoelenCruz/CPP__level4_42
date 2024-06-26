/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:13:28 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/03/30 16:00:31 by jcruz-da         ###   ########.fr       */
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
		~Fixed(void);
		
		Fixed &operator= (Fixed const &rhs);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};


#endif