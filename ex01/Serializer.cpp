/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:08:00 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/22 18:45:57 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*-----------------------------*/
/*  Define serialize function  */
/*-----------------------------*/
uintptr_t	Serializer::serialize( Data* ptr ) {
	return reinterpret_cast<uintptr_t>(ptr);
}

/*-------------------------------*/
/*  Define deserialize function  */
/*-------------------------------*/
Data*	Serializer::deserialize( uintptr_t raw ) {
	return reinterpret_cast<Data*>(raw);
}
