/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:22:44 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/21 19:55:32 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( const ScalarConverter& other ) { ( void )other; }

ScalarConverter&	ScalarConverter::operator=( const ScalarConverter& other ) {

	( void )other;
	return *this;
}

ScalarConverter::~ScalarConverter( void ) {}

LiteralType	ScalarConverter::_detectType( const std::string& literal ) {

	if ( literal == "nan" || literal == "nanf" )
		return NOTANUMBER;
	else if ( literal == "-inf" || literal == "-inff" )
		return MINUSINFINITY;
	else if ( literal == "+inf" || literal == "+inff" )
		return PLUSINFINITY;
	else if ( literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'' )
		return CHAR;
	else if ( literal.find( 'f' ) != std::string::npos )
		return FLOAT;
	else if ( literal.find( '.' ) != std::string::npos )
		return DOUBLE;
	else if ( std::all_of( literal.begin(), literal.end(), []( char c )
		{ return std::isdigit( c ) || c == '-' || c == '+'; } ) )
		return INT;
	else
		return INVALID;
}

double	ScalarConverter::_parseLiteral( const std::string& literal, LiteralType type ) {

	switch ( type ) {
		case CHAR:
			return static_cast<double>( literal[1] );
		case INT:
			return std::stoi( literal );
		case FLOAT:
			return std::stof( literal );
		case DOUBLE:
			return std::stod( literal );
		case NOTANUMBER:
			return std::numeric_limits<double>::quiet_NaN();
		case MINUSINFINITY:
			return -std::numeric_limits<double>::infinity();
		case PLUSINFINITY:
			return std::numeric_limits<double>::infinity();
		default:
			throw std::invalid_argument( "Invalid literal" );
	}
}

void	ScalarConverter::_printChar( double value ) {

	if ( std::isnan( value ) || value < 0 || value > 127 )
		std::cout << "char: impossible\n";
	else if ( !std::isprint( static_cast<int>( value ) ) )
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>( value ) << "'\n";
}

void	ScalarConverter::_printInt( double value ) {

	if ( std::isnan( value )
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max() )
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>( value ) << std::endl;
}

void	ScalarConverter::_printFloat( double value ) {

	if ( std::isnan( value ) )
		std::cout << "float: nanf\n";
	else if ( std::isinf( value ) )
		std::cout << ( value < 0 ? "-inff\n" : "+inff\n" );
	else
		std::cout << "float: " << std::fixed << std::setprecision( 1 )
				  << static_cast<float>( value ) << "f\n";
}

void	ScalarConverter::_printDouble( double value ) {

	if ( std::isnan( value ) )
		std::cout << "double: nan\n";
	else if ( std::isinf( value ) )
		std::cout << "double: " << ( value < 0 ? "-inf\n" : "+inf\n" );
	else
		std::cout << "double: " << std::fixed << std::setprecision( 1 )
				  << value << std::endl;
}

void	ScalarConverter::convert( const std::string& literal ) {

	LiteralType	type = _detectType( literal );
	double		value = 0;

	try {
		value = _parseLiteral( literal, type );

		switch ( type ) {
		case CHAR:
			_printChar( value );
			break;
		case INT:
			_printInt( value );
			break;
		case FLOAT:
		case DOUBLE:
		case NOTANUMBER:
		case MINUSINFINITY:
		case PLUSINFINITY:
			_printChar( value );
			_printInt( value );
			_printFloat( value );
			_printDouble( value );
			break;
		default:
			throw std::invalid_argument( "Invalid literal ");
		}
	} catch ( const std::exception& e ) {
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
}
