#include <iostream>
#include <chrono>

using namespace std;

static long long numbers[100] = { 0LL };

// calculate the n th fibonacci number
long long fibonacci(int n) {
	if (numbers[n] == 0) {
		numbers[n] = (n == 1 || n == 2) ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
	}
	return numbers[n];
}

int main() {
	// request for a new input; -1 stops the program
	while(true) {
		int n;
		cout << "please enter a number:" << endl;
		cin >> n;
		if (n == -1) {
			break;
		}
		// time measurement start
		auto t1 = std::chrono::high_resolution_clock::now();
		long long result = fibonacci(n);
		auto t2 = std::chrono::high_resolution_clock::now();
		// time measurement end
		// output the result
		cout << "fibonacci number " << n << " is: " << result << endl;
		cout << "this calculation took " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " ms" << endl;
		cout << "enter -1 to stop calculating." << endl;
	}
	// end message
	cout << "calculations finished, exiting now." << endl;
	return EXIT_SUCCESS;
}
