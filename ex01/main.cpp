/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:15:38 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/22 15:17:12 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main( void ) {

	Data originalData = {42, "Example", 3.14};

	// Serialize the pointer to Data
	uintptr_t raw = Serializer::serialize(&originalData);

	// Deserialize back to a Data pointer
	Data* deserializedData = Serializer::deserialize(raw);

	// Verify the result
	std::cout << "Original Data Address: " << &originalData << std::endl;
	std::cout << "Deserialized Data Address: " << deserializedData << std::endl;

	if (&originalData == deserializedData) {
		std::cout << "Serialization and deserialization are successful!" << std::endl;
	} else {
		std::cout << "Serialization and deserialization failed." << std::endl;
	}

	// Output the data for verification
	std::cout << "Deserialized Data: { "
			  << "id: " << deserializedData->id << ", "
			  << "name: \"" << deserializedData->name << "\", "
			  << "value: " << deserializedData->value << " }" << std::endl;

	return 0;
}
