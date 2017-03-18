#include <iostream>
#include <cstdlib>
#include <thread>

using namespace std;

static long long fac[100] = {0LL};

long long f(long long a) {
	std::this_thread::sleep_for(std::chrono::milliseconds(100)); // waiting thread to see time measurement
	if(fac[a] != 0) {
		return fac[a];
	} else {
		if (a == 1) {
			fac[a] = 1;
			return fac[a];
		}
		fac[a] = f(a-1)*a;
		return fac[a];
	}
}


int main() {
	long long n;
	while (true) {
		cout << "please enter a number:" << endl;
		cin >> n;
		if(n!=-1) {
			cout << "calculating " << n << "!" << endl;
			auto t1 = std::chrono::high_resolution_clock::now();
			long long result = f(n);
			auto t2 = std::chrono::high_resolution_clock::now();
			cout << "the result is: " << result << endl;
			cout << "and calculation took " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " ms" << endl;
		} else {
			cout << "exiting program now" << endl;
			break;
		}
	}
    return EXIT_SUCCESS;
}
