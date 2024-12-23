/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:26:41 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/23 18:37:33 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

/*----------------------------*/
/*  Define generate function  */
/*----------------------------*/
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

/*-------------------------------------------*/
/*  Define identify function (with pointer)  */
/*-------------------------------------------*/
void	identify( Base* p ) {

	if ( dynamic_cast<A*>(p) )
		std::cout << GREEN << "A\n" << RESET;
	else if ( dynamic_cast<B*>(p) )
		std::cout << CYAN << "B\n" << RESET;
	else if ( dynamic_cast<C*>(p) )
		std::cout << PURPLE << "C\n" << RESET;
	else
		std::cout << "Unknown type\n";
}

/*---------------------------------------------*/
/*  Define identify function (with reference)  */
/*---------------------------------------------*/
void	identify( Base& p ) {

	try {
		(void)dynamic_cast<A&>(p);
		std::cout << GREEN << "A\n" << RESET;
	} catch ( std::bad_cast& ) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << CYAN << "B\n" << RESET;
	} catch ( std::bad_cast& ) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << PURPLE << "C\n" << RESET;
	} catch ( std::bad_cast& ) {}
}
