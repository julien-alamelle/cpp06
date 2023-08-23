#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av) {
	if (ac > 2)	std::cout <<"please provide a least 1 argument\n";
	for (int i = 1; i < ac; ++i) ScalarConverter::convert(std::string(av[i]));
	return (0);
}
