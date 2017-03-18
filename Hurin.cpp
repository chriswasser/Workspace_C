#include <iostream>
#include <vector>
#include <cstdlib>
#include <initializer_list>

using namespace std;

template <typename T>
class MyQueue {

    class myiterator {

    private:

        const MyQueue & q;
        size_t index;

    public:

        myiterator(const MyQueue & _q, size_t _index) : q(_q), index(_index) { }

        bool operator!=(const myiterator& rhs) const {
            return (&q == &rhs.q) && (index!=rhs.index);
        }

        double operator*() const {
            return q.fifo[index];
        }

        const myiterator& operator++() {
            ++index;
            return *this;
        }
	};

private:

    vector<T> fifo;

public:

	typedef T value_type;

	myiterator begin() const {
		return myiterator(*this, 0);
	}

	myiterator end() const {
		return myiterator(*this, fifo.size());
	}

    MyQueue(const initializer_list<T>& i) {
        for(T element : i) {
            fifo.push_back(element);
        }
    }

    void enqueue(T i) {
        fifo.push_back(i);
    }

    T dequeue() {
        T value = fifo[0];
        fifo.erase(fifo.begin());
        return value;
    }

    friend ostream & operator<<(ostream & os, const MyQueue & q) {
        unsigned int i;
        os << "begin [ ";
        for (i = 0; i < q.fifo.size(); i++) {
            os << q.fifo[i] << " ";
        }
        os << "] end";
        return os;
    }

};

int main() {
    MyQueue<double> q = {3.21,2.213,4,2123.2,21213.3,421,12.89};
    cout << "Current state of the queue: " << q << endl;
    cout << "Processing element: " << q.dequeue() << endl;
    cout << "Processing element: " << q.dequeue() << endl;
    q.enqueue(3);
    q.enqueue(827);
    cout << "Current state of the queue: " << q << endl;
    cout << "The queue's content is currently:" << endl;
    for(auto i : q) {
        cout << i << endl;
    }
    return 0;
}
