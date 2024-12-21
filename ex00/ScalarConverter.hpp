/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:29:52 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/21 22:12:21 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include "colors.hpp"

enum	LiteralType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NOTANUMBER,
	MINUSINFINITY,
	PLUSINFINITY,
	INVALID
};

class	ScalarConverter {

private:

	ScalarConverter( void ); // Private constructor to make the class non-instantiable
	ScalarConverter( const ScalarConverter& other );
	ScalarConverter&	operator=( const ScalarConverter& other );
	~ScalarConverter( void );

	static LiteralType	_detectType( const std::string& literal );
	static double		_parseLiteral( const std::string& literal, LiteralType type );
	static void			_printChar( double value );
	static void			_printInt( double value );
	static void			_printFloat( double value );
	static void			_printDouble( double value );

public:

	static void	convert( const std::string& literal );

};

#endif
