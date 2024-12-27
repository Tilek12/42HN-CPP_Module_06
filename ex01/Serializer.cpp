/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:08:00 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/27 14:45:41 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*--------------------------------*/
/*  Serializer Class constructor  */
/*--------------------------------*/
Serializer::Serializer( void ) {}

/*-------------------------------------*/
/*  Serializer Class copy constructor  */
/*-------------------------------------*/
Serializer::Serializer( const Serializer& other ) { (void)other; }

/*---------------------------------------------*/
/*  Serializer Class copy assignment operator  */
/*---------------------------------------------*/
Serializer&	Serializer::operator=( const Serializer& other ) {

	(void)other;
	return *this;
}

/*-------------------------------*/
/*  Serializer Class destructor  */
/*-------------------------------*/
Serializer::~Serializer( void ) {}

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
