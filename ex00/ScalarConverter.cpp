/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:22:44 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/26 16:30:44 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*-------------------------------------*/
/*  ScalarConverter Class constructor  */
/*-------------------------------------*/
ScalarConverter::ScalarConverter( void ) {}

/*------------------------------------------*/
/*  ScalarConverter Class copy constructor  */
/*------------------------------------------*/
ScalarConverter::ScalarConverter( const ScalarConverter& other ) { (void)other; }

/*--------------------------------------------------*/
/*  ScalarConverter Class copy assignment operator  */
/*--------------------------------------------------*/
ScalarConverter&	ScalarConverter::operator=( const ScalarConverter& other ) {

	(void)other;
	return *this;
}

/*------------------------------------*/
/*  ScalarConverter Class destructor  */
/*------------------------------------*/
ScalarConverter::~ScalarConverter( void ) {}

/*-------------------------------*/
/*  Define _detectType function  */
/*-------------------------------*/
LiteralType	ScalarConverter::_detectType( const std::string& literal ) {

	if ( literal == "nan" || literal == "nanf" )
		return NOTANUMBER;
	else if ( literal == "-inf" || literal == "-inff" )
		return MINUSINFINITY;
	else if ( literal == "+inf" || literal == "+inff" )
		return PLUSINFINITY;
	else if ( literal.size() == 3
			  && literal[0] == '\''
			  && literal[2] == '\''
			  && std::isprint( literal[1] ) )
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

/*---------------------------------*/
/*  Define _parseLiteral function  */
/*---------------------------------*/
double	ScalarConverter::_parseLiteral( const std::string& literal, LiteralType type ) {

	switch ( type ) {
		case CHAR:
			return static_cast<double>(literal[1]);
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

/*------------------------------*/
/*  Define _printChar function  */
/*------------------------------*/
void	ScalarConverter::_printChar( double value ) {

	std::cout << YELLOW
			  << "char: "
			  << RESET;

	if ( std::isnan( value ) || value < 0 || value > 127 )
		std::cout << PURPLE
				  << "impossible\n"
				  << RESET;
	else if ( !std::isprint( static_cast<int>(value) ) )
		std::cout << PURPLE
				  << "Non displayable\n"
				  << RESET;
	else
		std::cout << CYAN
				  << "'" << static_cast<char>(value) << "'\n"
				  << RESET;
}

/*-----------------------------*/
/*  Define _printInt function  */
/*-----------------------------*/
void	ScalarConverter::_printInt( double value ) {

	std::cout << YELLOW
			  << "int: "
			  << RESET;

	if ( std::isnan( value )
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max() )
		std::cout << CYAN
				  << "impossible\n"
				  << RESET;
	else
		std::cout << CYAN
				  << static_cast<int>(value) << std::endl
				  << RESET;
}

/*-------------------------------*/
/*  Define _printFloat function  */
/*-------------------------------*/
void	ScalarConverter::_printFloat( double value ) {

	std::cout << YELLOW
			  << "float: "
			  << RESET;

	if ( std::isnan( value ) )
		std::cout << CYAN
				  << "nanf\n"
				  << RESET;
	else if ( std::isinf( value ) )
		std::cout << CYAN
				  << ( value < 0 ? "-inff\n" : "+inff\n" )
				  << RESET;
	else
		std::cout << CYAN
				  << std::fixed << std::setprecision( 1 )
				  << static_cast<float>(value) << "f\n"
				  << RESET;
}

/*--------------------------------*/
/*  Define _printDouble function  */
/*--------------------------------*/
void	ScalarConverter::_printDouble( double value ) {

	std::cout << YELLOW
			  << "double: "
			  << RESET;

	if ( std::isnan( value ) )
		std::cout << CYAN
				  << "nan\n"
				  << RESET;
	else if ( std::isinf( value ) )
		std::cout << CYAN
				  << ( value < 0 ? "-inf\n" : "+inf\n" )
				  << RESET;
	else
		std::cout << CYAN
				  << std::fixed << std::setprecision( 1 )
				  << value << std::endl
				  << RESET;
}

/*---------------------------*/
/*  Define convert function  */
/*---------------------------*/
void	ScalarConverter::convert( const std::string& literal ) {

	LiteralType	type = _detectType( literal );
	double		value = 0;

	try {
		value = _parseLiteral( literal, type );

		_printChar( value );
		_printInt( value );
		_printFloat( value );
		_printDouble( value );
	} catch ( const std::exception& e ) {
		std::cerr << RED
				  << "ERROR: " << e.what()
				  << RESET << std::endl;
	}
}
