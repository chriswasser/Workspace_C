#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include <condition_variable>
#include <cmath>

using namespace std;

/*
 * mutex locks all threads to only one thread is working on a specific part of the code until
 * it is unlocked / destroyed by going out of scope
 * lock_guard: exists from creation to it's destruction when going out of scope
 * unique_lock: more features than lock_guard, e.g. lock after creation, manual unlock (used for condition_variables)
 */

bool stop = false;
queue<int> work;

void consume(condition_variable & cv, mutex & m) {
    cout << "start in consumer" << endl;

    double sum = 0;

    cout << "consumer starting to work" << endl;
    while(!stop) {
        unique_lock<mutex> lk(m);

        cv.wait(lk);
        int current = work.front();
        work.pop();
        sum += current;
    }

    cout << "consumer exiting" << endl;
    cout << "consumer result for sum: " << sum << endl;
}

void produce() {

    cout << "start in producer" << endl;
    condition_variable cv;
    mutex m;
    cout << "producer starting the consumer" << endl;
    thread consumer(consume, ref(cv), ref(m));

    cout << "producer filling queue with work" << endl;
    for(int i = 0; i < 1000000000; ++i) {
        if(!stop) {
            unique_lock<mutex> lk(m);
            work.push(i);
            cv.notify_one();
        } else {
            break;
        }
    }

    cout << "producer waiting for consumer to join" << endl;
    consumer.join();

}

/* producer-consumer could be implemented so that main makes both threads and stops them both.
 * Right now is the problem: If producer and worker are finished before main sets stop; worker is
 * waiting for a signal from the producer, but never receives one, which leads to a deadlock/racecondition.
 */

int main() {

    cout << "start in main" << endl;
    thread producer(produce);
    cout << "main sleeps for 3 seconds" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "main setting stop" << endl;
    stop = true;
    cout << "main waiting for producer to join" << endl;
    producer.join();

    return EXIT_SUCCESS;
}
