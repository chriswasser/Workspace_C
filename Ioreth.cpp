
#include <iostream>
#include <thread>
#include <condition_variable>

using namespace std;

void add(int start, int finish, long long &sum, mutex &lock) {
    for(int i = start; i <= finish; ++i) {
        lock_guard<mutex> guard(lock);
        sum += i;
    }
}

int main() {
    int n = 19347; // add numbers form 1-n
    int startT1 = 1;
    int finishT1 = n / 2;
    int startT2 = (n / 2) + 1;
    int finishT2 = n;
    long long sum = 0;
    mutex lock;
    thread thread1(add, startT1, finishT1, ref(sum), ref(lock));
    thread thread2(add, startT2, finishT2, ref(sum), ref(lock));
    thread1.join();
    thread2.join();
    cout << "sum from 1 - " << n << " equals " << sum << endl;
    return EXIT_SUCCESS;
}
