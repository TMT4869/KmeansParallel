#include <iostream>
#include <fstream>
using namespace std;

bool compare_files(string file1, string file2);

int main() {
    cout << "The output of sequential and parallel is the same:";
    if (compare_files("parallel.txt", "sequential.txt")) {
        cout << "True\n";
    }
    else {
        cout << "False\n";
    }
    return 0;
}


bool compare_files(string file1, string file2) {
    ifstream f1(file1);
    ifstream f2(file2);

    if (!f1 || !f2) {
        cerr << "Unable to open file(s)\n";
        return false;
    }

    string line1, line2;
    while (!f1.eof() && !f2.eof()) {
        getline(f1, line1);
        getline(f2, line2);
        if (line1 != line2) {
            return false;
        }
    }

    if (f1.eof() != f2.eof()) {
        return false;
    }

    f1.close();
    f2.close();

    return true;
}
