#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream myfile;

    myfile.open("file.txt");
    myfile << "Writing this to a file." << endl;
    myfile.close();
    return 0;
}