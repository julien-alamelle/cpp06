#pragma once

#include <string>

class ScalarConverter {

public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &);
	~ScalarConverter();
	ScalarConverter&	operator=(const ScalarConverter &);

	void static convert(std::string);
};

