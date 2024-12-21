/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:29:52 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/21 16:20:52 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

enum	LiteralType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	INVALID
};

class	ScalarConverter {

private:

	ScalarConverter( void ); // Private constructor to make the class non-instantiable
	ScalarConverter( const ScalarConverter& other );
	ScalarConverter&	operator=( const ScalarConverter& other );
	~ScalarConverter( void );

	static LiteralType	detectType( const std::string& literal );
	static double		parseLiteral( const std::string& literal, LiteralType type );
	static void			printChar( double value );
	static void			printInt( double value );
	static void			printFloat( double value );
	static void			printDouble( double value );

public:

	static void	convert( const std::string& literal );

};

#endif
