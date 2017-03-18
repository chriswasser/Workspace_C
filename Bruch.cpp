
// Content: RuleOfThree, Setter, Getter, Exception, OperatorOverloading

#include <iostream>

using namespace std;

class Bruch {

private:

    int zaehler;
    int nenner;

public:

    Bruch(int _zaehler, int _nenner) : zaehler(_zaehler) {
        if(_nenner != 0) {
            nenner = _nenner;
        } else {
            throw invalid_argument("No division by 0!");
        }
    }

    Bruch(Bruch& b) : Bruch(b.zaehler, b.nenner){ }

    Bruch& operator=(Bruch b) {
        swap(nenner, b.nenner);
        swap(zaehler, b.zaehler);
        return *this;
    }

    ~Bruch() { }

    friend ostream & operator<<(ostream & os, const Bruch& b) {
        os << "(" << b.zaehler << "/" << b.nenner << ")";
        return os;
    }

    Bruch& operator+=(const Bruch& b) {
        // es wird angenommen dass die Brueche den selben nenner haben
        zaehler += b.zaehler;
        return *this;
    }

    friend Bruch operator+(Bruch b1, const Bruch& b2) {
        b1 += b2;
        return b1;
    }

    friend bool operator==(const Bruch& b1, const Bruch& b2) {
        return ((b1.zaehler == b2.zaehler) && (b1.nenner == b2.nenner));
    }

    void setZaehler(int _zaehler) {
        zaehler = _zaehler;
    }

    int getZaehler() {
        return zaehler;
    }

    void setNenner(int _nenner) {
        if(_nenner != 0) {
            nenner = _nenner;
        } else {
            throw invalid_argument("No division by 0!");
        }
    }

    int getNenner() {
        return nenner;
    }

};

int main() {

    return EXIT_SUCCESS;
}
