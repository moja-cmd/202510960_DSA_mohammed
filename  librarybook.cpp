#include "Library_Book.h"
#include "function.h"
#include <iostream>

int main()
{
    const int MAX_BOOKS = 100;
    LibraryBook library[MAX_BOOKS]; // Static Array of objects
    int currentBookCount = 0;
    int choice;

    std::cout << "====================================================\n";
    std::cout << " WELCOME TO KIGALI INDEPENDENT UNIVERSITY LIBRARY\n";
    std::cout << "====================================================\n";

    do
    {
        std::cout << "\n--- LIBRARY SYSTEM MENU ---\n";
        std::cout << "1. Add New Book\n";
        std::cout << "2. Display All Books\n";
        std::cout << "3. Borrow Book\n";
        std::cout << "4. Return Book\n";
        std::cout << "5. Search Book by ID\n";
        std::cout << "6. Display Overdue Books\n";
        std::cout << "7. Calculate Total Fines\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice (1-8): ";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            addBook(library, currentBookCount, MAX_BOOKS);
            break;
        case 2:
            displayBooks(library, currentBookCount);
            break;
        case 3:
            borrowBookMenu(library, currentBookCount);
            break;
        case 4:
            returnBookMenu(library, currentBookCount);
            break;
        case 5:
            searchBook(library, currentBookCount);
            break;
        case 6:
            displayOverdueBooks(library, currentBookCount);
            break;
        case 7:
            calculateTotalFines(library, currentBookCount);
            break;
        case 8:
            std::cout << "\nExiting the system. Thank you!\n";
            break;
        default:
            std::cout << "\nInvalid input choice! Please enter a number between 1 and 8.\n";
        }
    } while (choice != 8);

    return 0;
}