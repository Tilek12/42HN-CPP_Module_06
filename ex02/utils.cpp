/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:26:41 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/22 20:41:53 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

Base*	generate( void ) {

	srand( static_cast<unsigned int>(time(0)) );
	int	randomValue = rand() % 3;
	switch ( randomValue ) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return nullptr;
	}
}

void	identify( Base* p ) {

	if ( dynamic_cast<A*>(p) )
		std::cout << "A\n";
	else if ( dynamic_cast<B*>(p) )
		std::cout << "B\n";
	else if ( dynamic_cast<C*>(p) )
		std::cout << "C\n";
	else
		std::cout << "Unknown type\n";
}

void	identify( Base& p ) {

	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
	} catch ( std::bad_cast& ) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
	} catch ( std::bad_cast& ) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
	} catch ( std::bad_cast& ) {}
}
