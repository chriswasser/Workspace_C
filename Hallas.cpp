
#include <iostream>

using namespace std;

template <typename T>
class Bruch {

private:

	T zaehler;
	T nenner;

public:

    typedef T value_type;

    // default constructor
	Bruch() : zaehler(1), nenner(1) { }

	// parameter constructor
	Bruch(T z, T n) : zaehler(z) {
		if (n != 0) {
			nenner = n;
		} else {
			throw "Unallowed Nenner Value";
		}
	}

	// copy constructor
	Bruch(const Bruch& b) : zaehler(b.zaehler), nenner(b.nenner) { }

	// copy assignment operator
	Bruch& operator=(const Bruch& b) {
		zaehler = b.zaehler; // alternative: this->zaehler = b.zaehler;
		nenner = b.nenner; // alternative: this->nenner = b.nenner;
		return *this;
	}

	// destructor
	~Bruch() {
		cout << "Destructor of Bruch" << endl;
	}

	// toString Methode
	friend ostream& operator<<(ostream& os, const Bruch& b) {
		os << "(" << b.zaehler << "/" << b.nenner << ")";
		return os;
	}

	// Getter Zaehler
	T getZaehler() const {
		return zaehler;
	}

	// Setter Zaehler
	void setZaehler(T z) {
		zaehler = z; // this->zaehler = z;
	}

	// Getter Nenner
	T getNenner() const {
		return nenner;
	}

	// Setter Nenner
	void setNenner(T n) {
		if (n != 0) {
			nenner = n; // this->nenner = n;
		} else {
			throw "Unallowed Nenner Value!";
		}
	}

};

int main() {
    Bruch<long> a;
	Bruch<long> b(70, 101);
	Bruch<long> c(b);
	cout << "a = " << a << " b = " << b << " c = " << c << endl;
	b.setZaehler(48);
    b.setNenner(100);
	a = c;
	cout << "a = " << a << " b = " << b << " c = " << c << endl;
	try {
		b.setNenner(0);
	} catch(...) {
		cout << "Fehler after calling b.setNenner(0)" << endl;
	}
	return EXIT_SUCCESS;
}
