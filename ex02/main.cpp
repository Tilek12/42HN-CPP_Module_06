/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:45:46 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/22 21:27:26 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/*-----------------*/
/*  Main function  */
/*-----------------*/
int	main( void ) {

	Base*	base = generate();

	std::cout << "Identified by pointer: ";
	identify( base );

	std::cout << "Identified by reference: ";
	identify( *base );

	delete base;

	return 0;
}
