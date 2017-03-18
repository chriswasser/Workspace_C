#include <iostream>
#include <cstdlib>

using namespace std;

class Complex {

private:

    double real;
    double imaginary;

public:

    Complex(double r, double i) : real(r), imaginary(i) {
        cout << "Constructor success!" << endl;
    }

    Complex & operator+(const Complex & c2) {
        return *this+=c2;
    }

    Complex & operator+=(const Complex & c) {
        real += c.real;
        imaginary += c.imaginary;
        return *this;
    }

    Complex & operator*(const Complex & c2) {
        return *this *= c2;
    }

    Complex & operator*=(Complex c) {
        real = real*c.real - imaginary*c.imaginary;
        imaginary = real*c.imaginary + imaginary*c.real;
        return *this;
    }

    Complex & operator-(const Complex & c2) {
        return *this -= c2;
    }

    Complex & operator-=(Complex c) {
        real -= c.real;
        imaginary -= c.imaginary;
        return *this;
    }

    friend ostream & operator<<(ostream & os, const Complex & c) {
        os << "Complex: " << c.real << " + (" << c.imaginary << ") * i";
        return os;
    }

};

int main() {
    Complex c1(12,3);
    Complex c2(5,-9);
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    c1 += c2;
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    c2 = c2 + c1;
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    return 0;
}
