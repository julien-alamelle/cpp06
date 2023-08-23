#include "Base.hpp"
#include <iostream>
#include <ctime>
#include <cmath>

int main() {
	srand(time(0));

	for (int i = 0; i < 10; ++i) {
		Base * b = generate();
		identify(b);
		identify(*b);
		delete b;
	}
	return 0;
}
