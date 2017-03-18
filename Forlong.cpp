#include <iostream>

using namespace std;

int main() {
    int original = 8482;
    int manipulation = 241;
    int* manipulationPtr = &manipulation;

    cout << "start:" << endl;
    cout << "values: original = " << original << " manipulation = " << manipulation << endl;
    cout << "addresses: original = " << &original << " manipulationPtr = " << manipulationPtr << endl;

    cout << endl << "modify:" << endl;
    cout << "modify address: " << (manipulationPtr-1) << endl;
    *(manipulationPtr-1) = 3213;
    cout << "values: original = " << original << " manipulation = " << manipulation << endl;
    cout << "addresses: original = " << &original << " manipulationPtr = " << manipulationPtr << endl;

    cout << endl << "modify single bytes:" << endl;
    int32_t n = 0x12345678; // int n = ... normal auch moeglichs
    cout << "n=0x" << hex << n << endl;
    int8_t* pn = (int8_t*)(&n); // int8_t entspricht signed char -> kleinere Speichergroessen um Bytes anzusprechen
    *(pn+2) = (char)0xab;
    cout << "n=0x" << hex << n << endl;

    return EXIT_SUCCESS;
}
