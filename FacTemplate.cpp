#include <iostream>
#include <cstdlib>

using namespace std;

template <int n>
class Faculty {

public:

	enum {
		fac = n * Faculty<n - 1>::fac
	};

};

template <>
class Faculty<0> {

public:

	enum {
		fac = 1
	};

};

int main() {

	cout << "Calculating the faculty of numbers at compile time with template programming:" << endl;
	cout << 10 << "! = " << Faculty<10>::fac << endl;
	return EXIT_SUCCESS;
}
