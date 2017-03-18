#include <iostream>
#include <cstdarg>

using namespace std;

double add(double d, ... ) {
    va_list zahlen;
    va_start(zahlen, d);
    double sum = 0;
    double n = d;
    while(n != 0) {
        sum += n;
        n = va_arg(zahlen, double);
    }
    return sum;
}

int main() {
    double z1 = 2.123;
    double z2 = 3.2321;
    double z3 = 92.4;
    double z4 = 3.34;
    double z5 = 10.3857;
    double z6 = 1;
    double z7 = 0;
    cout << "Summe: " << add(z1, z2, z3, z4, z5, z6, z7) << endl;
    return EXIT_SUCCESS;
}
