/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:45:46 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/23 18:38:08 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

/*-----------------*/
/*  Main function  */
/*-----------------*/
int	main( void ) {

	Base*	base = generate();

	std::cout << YELLOW << "Identified by pointer: " << RESET;
	identify( base );

	std::cout << YELLOW << "Identified by reference: " << RESET;
	identify( *base );

	delete base;

	return 0;
}
