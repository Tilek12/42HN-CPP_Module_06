/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:08:00 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/22 15:13:59 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	Serializer::serialize( Data* ptr ) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize( uintptr_t raw ) {
	return reinterpret_cast<Data*>(raw);
}
