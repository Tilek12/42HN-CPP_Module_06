/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:15:38 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/22 17:47:06 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main( void ) {

	Data originalData = { 42, "Example", 3.14 };

	// Serialize the pointer to Data
	uintptr_t raw = Serializer::serialize( &originalData );

	// Deserialize back to a Data pointer
	Data* deserializedData = Serializer::deserialize( raw );

	// Verify the result
	std::cout << YELLOW << "Original Data Address:\t   " << RESET
			  << CYAN << &originalData << std::endl << RESET;

	std::cout << YELLOW << "Deserialized Data Address: " << RESET
			  << CYAN << deserializedData << std::endl << RESET;

	std::cout << YELLOW << "raw: " << RESET
			  << CYAN << raw << std::endl << RESET;

	if ( &originalData == deserializedData ) {
		std::cout << GREEN
				  << "Serialization and deserialization are successful!\n"
				  << RESET;
	} else {
		std::cout << PURPLE
				  << "Serialization and deserialization failed.\n"
				  << RESET;
	}

	// Output the data for verification
	std::cout << YELLOW << "Deserialized Data: " << RESET
			  << B_CYAN << "{ " << RESET
			  << YELLOW << "id: " << RESET
			  << CYAN << deserializedData->id << RESET
			  << YELLOW << ", name: " << RESET
			  << CYAN << "\"" << deserializedData->name << "\"" << RESET
			  << YELLOW << ", value: " << RESET
			  << CYAN << deserializedData->value << RESET
			  << B_CYAN << " }\n" << RESET;

	return 0;
}
