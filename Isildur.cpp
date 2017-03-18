
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void sleep(int seconds) {
    cout << "thread: " << this_thread::get_id() << " sleeping for " << seconds << "seconds." << endl;
    this_thread::sleep_for(chrono::seconds(seconds));
    cout << "woke up." << endl;
}

int main() {
    cout << "creating threads:" << endl;
    thread thread1(sleep, 1);
    thread thread2(sleep, 2);
    thread thread3(sleep, 3);
    cout << "waiting for thread1 to finish..." << endl;
    thread1.join();
    cout << "waiting for thread2 to finish..." << endl;
    thread2.join();
    cout << "waiting for thread3 to finish..." << endl;
    thread3.join();
    cout << "all threads have finished, exiting now." << endl;
    return EXIT_SUCCESS;
}
