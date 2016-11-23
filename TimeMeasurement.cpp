#include <iostream>
#include <sys/time.h>

using namespace std;

int main() {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    // code to measure the time from
    gettimeofday(&end, NULL);
    double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6;
    cout << "Measured time: " << delta << endl;
    return EXIT_SUCCESS;
}
