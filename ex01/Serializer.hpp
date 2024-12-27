/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:50:49 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/23 20:24:05 by tkubanyc         ###   ########.fr       */
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

private:

	Serializer( void ); // Non-instantiable class
	Serializer( const Serializer& );
	Serializer&	operator=( const Serializer& );
	~Serializer( void );

public:

	static uintptr_t	serialize( Data* ptr );
	static Data*		deserialize( uintptr_t raw );

};

#endif
