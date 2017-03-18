#include <iostream>
#include <fstream>

using namespace std;

// reads a file
// takes every line
// counts the individual characters
// writes the quantities into a new file (format: 'CHAR' (ASCII) #QUANTITY)

int main() {
    // file to be read and output filename
    string inputFilename = "Test.txt";
    string outputFilename = "Test.out";

    // counting chars
    string line;
    int quantity[26] = { 0 };
    ifstream reader(inputFilename);
    if(reader.is_open()) {
        while(!reader.eof()) {
            getline(reader, line);
            for(int i = 0; i < (int) line.length(); ++i) {
                if(line[i] >= 'A' && line[i] <= 'Z') {
                    quantity[(int) (line[i] - 'A')] += 1;
                }
            }
        }
    } else {
        cout << "Datei nicht gefunden!" << endl;
    }
    reader.close();

    // writing quantities into output file
    ofstream writer(outputFilename);
    for(int i = 0; i < (int) (sizeof(quantity) / sizeof(int)); ++i) {
        writer << "'" << (char)('A' + i) << "' (" << ('A' + i) << ") #" << quantity[i] << endl;
    }
    writer.close();

    return EXIT_SUCCESS;
}
