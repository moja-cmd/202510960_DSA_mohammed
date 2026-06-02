#include <iostream>
#include <string>
#include "notepad.h"

using namespace std;

int main()
{
    int choice;
    string filename;

    do
    {
        // Display the Notepad Menu
        cout << "=== SIMPLE NOTEPAD ===" << endl;
        cout << "1. Write File" << endl;
        cout << "2. Read File" << endl;
        cout << "3. Append File" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter filename to create/overwrite (e.g., notes.txt): ";
            cin >> filename;
            cin.ignore();
            writeFile(filename);
            break;

        case 2:
            cout << "Enter filename to read: ";
            cin >> filename;
            readFile(filename);
            break;

        case 3:
            cout << "Enter filename to append to: ";
            cin >> filename;
            cin.ignore();
            appendFile(filename);
            break;

        case 4:
            cout << "Exiting Notepad. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice! Please select an option from 1 to 4.\n"
                 << endl;
        }
    } while (choice != 4);

    return 0;
}