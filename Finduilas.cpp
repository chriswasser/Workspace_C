#include <iostream>

using namespace std;

// schlechte Aufgabe -> wird rausgenommen


int main() {
    int n1 = 239842;
    int n2 = 95447;
    int* p;
    int** pp;

    cout << "start:" << endl;
    cout << "n1 = " << n1 << " n2 = " << n2 << endl;
    // cout << "p = " << p << " pp = " << pp << endl;

    cout << endl << "initializing:" << endl,
    // *pp = &n2;
    p = &n2;
    pp = &p;
    cout << "n1 = " << n1 << " n2 = " << n2 << endl;
    cout << "p = " << p << " pp = " << pp << endl << endl;

    cout << "changing values:" << endl;
    *p = 2421;
    cout << "n1 = " << n1 << " n2 = " << n2 << endl;
    **pp = 1222;
    cout << "n1 = " << n1 << " n2 = " << n2 << endl;
    cout << "p = " << p << " pp = " << pp << endl;

    return EXIT_SUCCESS;
}
