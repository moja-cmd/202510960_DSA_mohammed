#include "function.h"
#include <iostream>
#include <iomanip>

void addBook(LibraryBook books[], int &bookCount, int maxBooks)
{
    if (bookCount >= maxBooks)
    {
        std::cout << "\nError: Library database is full!\n";
        return;
    }

    int id;
    std::string title, author;

    std::cout << "\nEnter Book ID (integer): ";
    std::cin >> id;

    // Check if ID already exists
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].getBookID() == id)
        {
            std::cout << "Error: A book with ID " << id << " already exists!\n";
            return;
        }
    }

    std::cin.ignore(); // Clear buffer
    std::cout << "Enter Book Title: ";
    std::getline(std::cin, title);
    std::cout << "Enter Author Name: ";
    std::getline(std::cin, author);

    // Store into object array
    books[bookCount] = LibraryBook(id, title, author);
    bookCount++;
    std::cout << "\nBook successfully added!\n";
}

void displayBooks(const LibraryBook books[], int bookCount)
{
    if (bookCount == 0)
    {
        std::cout << "\nNo books available in the system library.\n";
        return;
    }

    std::cout << "\n-------------------------------------------------------------------------------------------------\n";
    std::cout << std::left << std::setw(8) << "ID"
              << std::setw(25) << "Title"
              << std::setw(20) << "Author"
              << std::setw(15) << "Status"
              << std::setw(18) << "Borrower"
              << std::setw(15) << "Days Kept"
              << "Current Fine\n";
    std::cout << "-------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < bookCount; i++)
    {
        books[i].displayBookDetails();
    }
    std::cout << "-------------------------------------------------------------------------------------------------\n";
}

void borrowBookMenu(LibraryBook books[], int bookCount)
{
    int id;
    std::cout << "\nEnter Book ID to borrow: ";
    std::cin >> id;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].getBookID() == id)
        {
            if (books[i].getBorrowStatus())
            {
                std::cout << "Sorry, this book is currently already borrowed by " << books[i].getBorrowerName() << ".\n";
                return;
            }

            std::string name;
            int days;
            std::cin.ignore();
            std::cout << "Enter Student Borrower Name: ";
            std::getline(std::cin, name);
            std::cout << "Enter expected number of days to borrow: ";
            std::cin >> days;

            books[i].setBorrowerName(name);
            books[i].setDaysBorrowed(days);
            books[i].setBorrowStatus(true);
            std::cout << "\nBook successully checked out to " << name << "!\n";
            return;
        }
    }
    std::cout << "Book ID not found.\n";
}

void returnBookMenu(LibraryBook books[], int bookCount)
{
    int id;
    std::cout << "\nEnter Book ID to return: ";
    std::cin >> id;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].getBookID() == id)
        {
            if (!books[i].getBorrowStatus())
            {
                std::cout << "This book is already sitting in the library.\n";
                return;
            }

            double fine = books[i].calculateFine();
            if (fine > 0)
            {
                std::cout << "Warning: This book is overdue! Please collect a fine of RWF " << fine << ".\n";
            }

            // Reset status
            books[i].setBorrowerName("");
            books[i].setDaysBorrowed(0);
            books[i].setBorrowStatus(false);
            std::cout << "Book returned successfully.\n";
            return;
        }
    }
    std::cout << "Book ID not found.\n";
}

void searchBook(const LibraryBook books[], int bookCount)
{
    int id;
    std::cout << "\nEnter Book ID to search: ";
    std::cin >> id;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].getBookID() == id)
        {
            std::cout << "\nBook Found:\n";
            std::cout << "-------------------------------------------------------------------------------------------------\n";
            books[i].displayBookDetails();
            std::cout << "-------------------------------------------------------------------------------------------------\n";
            return;
        }
    }
    std::cout << "Book with ID " << id << " does not exist.\n";
}

void displayOverdueBooks(const LibraryBook books[], int bookCount)
{
    bool foundAny = false;

    std::cout << "\n--- OVERDUE BOOKS LIST ---\n";
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].isOverdue())
        {
            if (!foundAny)
            {
                std::cout << std::left << std::setw(8) << "ID"
                          << std::setw(25) << "Title"
                          << std::setw(18) << "Borrower"
                          << std::setw(15) << "Days Kept"
                          << "Fine Amount\n";
                std::cout << "--------------------------------------------------------------------------------\n";
            }
            std::cout << std::left << std::setw(8) << books[i].getBookID()
                      << std::setw(25) << books[i].getTitle()
                      << std::setw(18) << books[i].getBorrowerName()
                      << std::setw(15) << books[i].getDaysBorrowed()
                      << "RWF " << books[i].calculateFine() << "\n";
            foundAny = true;
        }
    }

    if (!foundAny)
    {
        std::cout << "Excellent! No books are currently overdue.\n";
    }
}

void calculateTotalFines(const LibraryBook books[], int bookCount)
{
    double totalFine = 0;
    for (int i = 0; i < bookCount; i++)
    {
        totalFine += books[i].calculateFine();
    }
    std::cout << "\n=========================================\n";
    std::cout << " Total Outstanding Fines: RWF " << totalFine << "\n";
    std::cout << "=========================================\n";
}