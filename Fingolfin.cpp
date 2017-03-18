#include <iostream>
#include <string>

using namespace std;

int main() {
    const char* str = "Wie geht's?";
    const char* charPtr = str;
    cout << "start:" << endl;
    cout << "string: " << str << endl;
    cout << "string address: " << &str << endl;
    cout << "charPtr address: " << &charPtr << endl;

    cout << endl << "output every char, its ASCII-value and its address:" << endl;
    while(*charPtr != '\0') {
        cout << "current character: " << (char) *charPtr << endl;
        cout << "current ASCII: " << (int) *charPtr << endl;
        cout << "current address: " << &charPtr << endl;
        charPtr = charPtr + 1;
    }
    cout << "current character: " << (char) *charPtr << endl;
    cout << "current ASCII: " << (int) *charPtr << endl;

    return EXIT_SUCCESS;
}
