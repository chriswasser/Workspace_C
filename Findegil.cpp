#include <iostream>

using namespace std;

// Typ      Referenz    Variablenname
// double   &           first / second
void swapV1(double &first, double &second) {
    double temp = first;
    first = second;
    second = temp;
}

// Typ      Pointer     Variablenname
// double   *           first / second
void swapV2(double *first, double *second) {
    double temp = *first;
    *first = *second;
    *second = temp;
}

// Typ      Referenz    Variablenname
// double*  &           firstPtr / secondPtr
void swapV3(double* &firstPtr, double* &secondPtr) {
    double* temp = firstPtr;
    firstPtr = secondPtr;
    secondPtr = temp;
}

// Typ      Pointer     Variablenname
// double*  *           firstPtr / secondPtr
void swapV4(double* *firstPtr, double* *secondPtr) {
    double* temp = *firstPtr;
    *firstPtr = *secondPtr;
    *secondPtr = temp;
}

int main() {
    double number1 = 2830.213;
    double number2 = 938.753;
    double *ptrNumber1 = &number1;
    double *ptrNumber2 = &number2;
    cout << "changing numbers:" << endl;
    cout << "number1 = " << number1  << " number2 = "<< number2 << endl;
    swapV1(number1, number2);
    cout << "number1 = " << number1  << " number2 = "<< number2 << endl;
    swapV2(&number1, &number2);
    cout << "number1 = " << number1  << " number2 = "<< number2 << endl;
    cout << endl << "changing pointers:" << endl;
    cout << "values: pointerNumber1 = " << *ptrNumber1  << " pointerNumber2 = " << *ptrNumber2 << endl;
    cout << "addresses: pointerNumber1 = " << ptrNumber1 << " pointerNumber2 = " << ptrNumber2 << endl;
    swapV3(ptrNumber1, ptrNumber2);
    cout << "values: pointerNumber1 = " << *ptrNumber1  << " pointerNumber2 = " << *ptrNumber2 << endl;
    cout << "addresses: pointerNumber1 = " << ptrNumber1 << " pointerNumber2 = " << ptrNumber2 << endl;
    swapV4(&ptrNumber1, &ptrNumber2);
    cout << "values: pointerNumber1 = " << *ptrNumber1  << " pointerNumber2 = " << *ptrNumber2 << endl;
    cout << "addresses: pointerNumber1 = " << ptrNumber1 << " pointerNumber2 = " << ptrNumber2 << endl;
    return EXIT_SUCCESS;
}
