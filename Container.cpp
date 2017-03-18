
#include <iostream>

using namespace std;

template <typename T>
class Container {

public:

    T content;

    typedef T content_type;

    Container(T _content) : content(_content) { }

    T getContent() {
        return content;
    }

    void setContent(T _content) {
        content = _content;
    }

    template <typename S>
    bool sameContent(const Container<S>& c) {
        if(content == c.content) {
            return true;
        } else {
            return false;
        }
    }

    bool sameType(const Container<T>&) {
        return true;
    }

    template <typename S>
    bool sameType(const Container<S>&) {
        return false;
    }

};

int main() {
    Container<string> str("Hello World!");
    cout << "str\t=\t" << str.getContent() << " (string)" << endl;
    Container<long long> ll(241987ll);
    cout << "ll\t=\t" << ll.getContent() << " (long)" << endl;
    Container<long long> ll2(241212145127ll);
    cout << "ll2\t=\t" << ll2.getContent() << " (long)" << endl;
    Container<int> i(241987);
    cout << "i\t=\t" << i.getContent() << " (int)" << endl;
    cout << "ll and i sameContent?\t" << ll.sameContent(i) << endl;
    cout << "ll and ll2 sameContent?\t" << ll.sameContent(ll2) << endl;
    cout << "ll and i sameType?\t" << ll.sameType(i) << endl;
    cout << "ll and ll2 sameType?\t" << ll.sameType(ll2) << endl;
    return EXIT_SUCCESS;
}
