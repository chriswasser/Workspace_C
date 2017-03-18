
#include <iostream>

using namespace std;

class Bruch {

private:

	int zaehler;
	int nenner;

public:

	// default constructor
	Bruch() : zaehler(1), nenner(1) { }

	// parameter constructor
	Bruch(int z, int n) : zaehler(z) {
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
	int getZaehler() const {
		return zaehler;
	}

	// Setter Zaehler
	void setZaehler(int z) {
		zaehler = z; // this->zaehler = z;
	}

	// Getter Nenner
	int getNenner() const {
		return nenner;
	}

	// Setter Nenner
	void setNenner(int n) {
		if (n != 0) {
			nenner = n; // this->nenner = n;
		} else {
			throw "Unallowed Nenner Value!";
		}
	}

};

int main() {
	Bruch a;
	Bruch b(6, 4);
	Bruch c(b);
	cout << "a = " << a << " b = " << b << " c = " << c << endl;
	b.setNenner(5);
	b.setZaehler(1);
	a = c;
	cout << "a = " << a << " b = " << b << " c = " << c << endl;
	try {
		b.setNenner(0);
	} catch(...) {
		cout << "Fehler after calling b.setNenner(0)" << endl;
	}
	return EXIT_SUCCESS;
}
