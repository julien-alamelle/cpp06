#include "Base.hpp"
#include <cmath>
#include <iostream>

Base::~Base() {;}

Base * generate() {
	int i = rand();
	switch (i%3) {
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

void identify(Base* p) {
	Base* res;
	res = dynamic_cast<A*> (p);
	if (res) {
		std::cout << "real type is A\n";
		return;
	}
	res = dynamic_cast<B*> (p);
	if (res) {
		std::cout << "real type is B\n";
		return;
	}
	res = dynamic_cast<C*> (p);
	if (res) {
		std::cout << "real type is C\n";
		return;
	}
	std::cout << "woopsie\n";
}

void identify(Base& p) {
	try {
		(void) dynamic_cast<A&> (p);
		std::cout << "real type is A\n";
		return;
	}
	catch (std::exception e) {
		(void) e;
	}
	try {
		(void) dynamic_cast<B&> (p);
		std::cout << "real type is B\n";
		return;
	}
	catch (std::exception e) {
		(void) e;
	}
	try {
		(void) dynamic_cast<C&> (p);
		std::cout << "real type is C\n";
		return;
	}
	catch (std::exception e) {
		(void) e;
	}
	std::cout << "woopsie\n";
}
