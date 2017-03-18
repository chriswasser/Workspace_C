
#include <iostream>
#include <chrono>
#include <ctime>
#include <time.h>

using namespace std;

static long long numbers[100] = { 0LL };

long long fibonacci(int n) {
    if(numbers[n] == 0) {
        numbers[n] = (n==1 || n==2) ? 1 : fibonacci(n-1) + fibonacci(n-2);
    }
    return numbers[n];
}

int main() {
    cout << "------------------------------------------" << endl;
    cout << "welcome to the fibonacci number generator:" << endl;
    cout << "------------------------------------------" << endl;
    while(true) {
        cout << "please enter your desired number:" << endl;
        int n;
        cin >> n;
        if (n == -1) {
            break;
        }
        auto tStart = std::chrono::high_resolution_clock::now();
        clock_t Start = clock();
        long long result = fibonacci(n);
        clock_t Ende = clock();
        double cpu_time_used = ((double) (Ende-Start)) / CLOCKS_PER_SEC;
        auto tEnd = std::chrono::high_resolution_clock::now();
        cout << "the " << n << "th fibonacci number is " << result << endl;
        cout << "(chrono) Calculation took " << std::chrono::duration_cast<std::chrono::milliseconds>(tEnd - tStart).count() << " ms" << endl;
        cout << "(time.h) Calculation took " << (cpu_time_used*100) << " ms" << endl;
        cout << "to stop calculating enter -1" << endl;
    }
    cout << "exiting program now" << endl;
    return EXIT_SUCCESS;
}
