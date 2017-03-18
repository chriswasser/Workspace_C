#include <iostream>
#include <cstdlib>

using namespace std;

template<int B, int N>
class Expo {
	
public:

	enum {
		result = B * Expo<B,N-1>::result
	};
	
};

template<int B>
class Expo <B,0> {
	
public:

	enum {
		result = 1
	};

};

int main() {

	cout << "Calculating B^N at compile time:" << endl;
	cout << "2^10 = " << Expo<2,10>::result << endl;
	return EXIT_SUCCESS;
}
