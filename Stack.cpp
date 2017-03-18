
// Content: constructors, RuleOfThree, var_args, iterator, initializer_list, std::vector

#include <iostream>
#include <vector>
#include <initializer_list>
#include <cstdarg>

using namespace std;

// implementing a Stack with an std::vector inside
// has the feature to take an initializer_list in the constructor
// is traversable with iterator
// Stack has a constructor which can take a various number of elements (var_args)

class Stack {

    class myiterator {

    private:

        const Stack& s;
        size_t index;

    public:

        myiterator(Stack& _s, size_t _index) : s(_s),index(_index) { }

        bool operator!=(const myiterator& iter) const {
            return (&s==&iter.s) && (index!=iter.index);
        }

        double operator*() const {
            return s.lifo[index];
        }

        const myiterator& operator++() {
            ++index;
            return *this;
        }
    };

private:

    vector<double> lifo;

public:

    Stack() : lifo{} { }

    Stack(const Stack& s) : Stack() {
        for(double d : s.lifo) {
            lifo.push_back(d);
        }
    }

    Stack(initializer_list<double> list) : Stack() {
        for(double d : list) {
            lifo.insert(lifo.begin(), d);
        }
    }

    Stack(int quantity, ... ) : Stack() {
        // the first int quantity denotes the number of double elements following
        va_list l;
        va_start(l, quantity);
        double d;
        while(quantity > 0) {
            d = va_arg(l, double);
            lifo.insert(lifo.begin(), d);
            quantity--;
        }
    }

    ~Stack() {
        lifo.clear();
    }

    Stack& operator=(Stack s) {
        swap(lifo, s.lifo);
        return *this;
    }

    myiterator begin() {
        return myiterator(*this, 0);
    }

    myiterator end() {
        return myiterator(*this, lifo.size());
    }

};

int main() {
    // testing initializer_list
    Stack s = {5.3,32,53,43.1,53};
    cout << "content of s:" << endl;
    for(double d : s) {
        cout << d << endl;
    }
    // testing var_args constructor
    Stack s2(7,533.243,324.3,12.2,4.,1.3,8.566,21424.4);
    cout << "content of s2:" << endl;
    for(double d : s2) {
        cout << d << endl;
    }
    // testing copy constructor and copy-assignment operator (=)
    Stack s3(s);
    Stack s4 = s3;
    cout << "content of s3:" << endl;
    for(double d : s3) {
        cout << d << endl;
    }
    cout << "content of s4:" << endl;
    for(double d : s4) {
        cout << d << endl;
    }
    s3 = s2;
    cout << "content of s3:" << endl;
    for(double d : s3) {
        cout << d << endl;
    }

    return EXIT_SUCCESS;
}
