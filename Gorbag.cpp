#include <iostream>
#include <math.h>

using namespace std;

// getting used to lambda expressions in C++

int main() {

	// add 3 numbers and return the sum

	double first, second, third;

	cout << endl << "please enter three numbers:" << endl;
	cin >> first;
	cin >> second;
	cin >> third;

	auto add = [] (double a, double b, double c) -> double { return a+b+c; };

	cout << "results:" << endl;
	cout << "sum = " << add(first, second, third) << endl;

	// checks if a given number is contained in an interval

	double start, end;

	cout << endl << "please enter an interval:" << endl;
	cin >> start;
	cin >> end;

	int value = 4;

	auto isContained = [=] (int d) -> string {
		if (start <= d && end >= d) {
			return "yes";
		} else {
			return "no";
		}
	};

	cout << "is " << value << " contained in [" << start << ";" << end << "]?" << endl;
	cout << "answer: " << isContained(value) << endl;

	// sets a local variable from z to -z without taking a parameter

	int z;

	cout << endl << "please enter a number:" << endl;
	cin >> z;

	auto setNegative = [&z] () -> void { z = -z; };

	cout << "the given number " << z;
	setNegative();
	cout << " has been changed to " << z << endl;

	// evaluates the lambda expression f and f(x) is returned

	int x;

	cout << endl << "please enter a number:" << endl;
	cin >> x;

	auto f = [] (int x) -> double { return sqrt(5*x); };

	cout << "f(x) = (5 * x) ^ (1/2)" << endl;
	cout << "f(" << x << ") = " << f(x) << endl << endl;

	cout << "lambda test finished, exiting now." << endl;

	return EXIT_SUCCESS;
}
