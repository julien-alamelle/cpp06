#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>

ScalarConverter::ScalarConverter() {;}
ScalarConverter::ScalarConverter(const ScalarConverter &src) {(void) src;}
ScalarConverter::~ScalarConverter() {;}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter &src) {
	(void) src;
	return (*this);
}

typedef std::string::iterator strit;

bool static getdouble(std::string s, double &ret) {
	//check if number
	strit it = s.begin();
	bool digit = false;
	bool point = false;
	if (*it == '+' || *it == '-') ++it;
	while (it != s.end()) {
		if (*it == '.' && !point) point = true;
		else if (*it >= '0' && *it <= '9') digit = true;
		else {
			digit = false;
			break;
		}
		++it;
	}
	if (digit || s == "inf" || s == "inff" || s == "-inf" || s == "-inff" || s == "nan" || s == "nanf") {
		ret = strtod(s.c_str(), 0);
		return false;
	}
	if (s.length() == 1) {
		ret = static_cast<double> (s.at(0));
		return false;
	}
	return true;
}

void static printchar(double d) {
	std::cout << "char: ";
	if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
		std::cout << "impossible\n";
	else if (d >= 128 || d < 32)
		std::cout << "Non displayable\n";
	else
		std::cout << static_cast<char> (d) << std::endl;
}

void ScalarConverter::convert(std::string s) {
	double d;
	if (getdouble(s, d)) {
		std::cout << s << " : not a valid literal\n";
		return;
	}
	printchar(d);
	std::cout << "int: "    << static_cast<int> (d) << std::endl;
	std::cout << "float: "  << static_cast<float> (d) << std::endl;
	std::cout << "double: " << d << std::endl;
}
