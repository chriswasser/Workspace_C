#include <iostream>
#include <vector>

using namespace std;

// satz is set
// satz content is put into reverse in reverse order
// reverse is printed to std::out
// satz is deleted

int main() {
    vector<string> reverse;
    {
        vector<string> satz = { "Mein" , "Name", "ist", "Christian", "Wassermann"};
        for(string wort : satz) {
            reverse.insert(reverse.begin(), wort);
        }
        for(string wort : reverse) {
            cout << wort << " ";
        }
        cout << endl;
    } // make satz go out of scope to call the destructor
    return EXIT_SUCCESS;
}
