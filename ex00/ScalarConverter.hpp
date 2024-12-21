/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:29:52 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/21 15:44:03 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class	ScalarConverter {

private:

	ScalarConverter( void ); // Private constructor to make the class non-instantiable
	ScalarConverter( const ScalarConverter& other );
	ScalarConverter&	operator=( const ScalarConverter& other );
	~ScalarConverter( void );

	static void	printChar( double value );
	static void	printInt( double value );
	static void	printFloat( double value );
	static void	printDouble( double value );
	static bool	isPseudoLiteral( const std::string& literal );
	static bool	isFloatLiteral( const std::string& literal );
	static bool	isDoubleLiteral( const std::string& literal );
	static bool	isIntLiteral( const std::string& literal );
	static bool	isCharLiteral( const std::string& literal );

public:

	static void	convert( const std::string& value );

};

#endif
