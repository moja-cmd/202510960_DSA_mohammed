#include <iostream>
#include <fstream>
#include <string>
#include "notebad.h"

using namespace std;


void writeFile(string filename) {
    ofstream outFile(filename); // Open file in default write mode 
    
    if (!outFile) {
        cout << "Error: Could not create or open the file." << endl;
        return;
    }
    
    cout << "Enter text (Type 'END' on a new line to stop):" << endl;
    string line;
    
    
    while (getline(cin, line)) {
        if (line == "END") {
            break;
        }
        outFile << line << endl;
    }
    
    outFile.close(); 
    cout << "File saved successfully." << endl;
}

void readFile(string filename) {
    ifstream inFile(filename); 
    
    if (!inFile) {
        cout << "Error: File '" << filename << "' not found!" << endl;
        return;
    }
    
    cout << "\n____File Contents____" << endl;
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    cout << "________________________\n" << endl;
    
    inFile.close();
}

void appendFile(string filename) {
    ofstream outFile(filename, ios::app);
    
    if (!outFile) {
        cout << "Error: Could not open the file for appending." << endl;
        return;
    }
    
    cout << "Enter text to append (Type 'END' on a new line to stop):" << endl;
    string line;
    
    while (getline(cin, line)) {
        if (line == "END") {
            break;
        }
        outFile << line << endl;
    }
    
    outFile.close();
    cout << "Text appended successfully." << endl;
}