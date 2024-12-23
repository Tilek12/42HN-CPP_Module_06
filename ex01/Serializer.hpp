/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:50:49 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/22 18:45:04 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include "colors.hpp"
#include "Data.hpp"

/*---------------------------*/
/*  Define Serializer class  */
/*---------------------------*/
class	Serializer {

public:

	Serializer( void ) = delete; // Non-instantiable class
	Serializer( const Serializer& ) = delete;
	Serializer&	operator=( const Serializer& ) = delete;
	~Serializer( void ) = delete;

	static uintptr_t	serialize( Data* ptr );
	static Data*		deserialize( uintptr_t raw );

};

#endif
