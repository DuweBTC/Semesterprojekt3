#include <fstream>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    system("Python3 Read.py");
    
    string line;
    ifstream readFile ("text.txt");
    if (readFile.is_open()){
        while (getline(readFile, line)){
            //cout << line << endl;
        }
        readFile.close();
        cout << "C++: " << line << endl;
    }

    else cout << "C++: " << "unable to open file" << endl;
    
    return 0;
}