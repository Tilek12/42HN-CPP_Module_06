/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:57:38 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/21 20:21:59 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main( int argc, char **argv ) {

	if ( argc != 2 ) {
		std::cerr << RED << "\tUsage: ./convert <literal>\n" << RESET;
		return 1;
	}

	ScalarConverter::convert( argv[1] );

	return 0;
}
