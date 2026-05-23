#include <iostream>
using namespace std;
void status(string name, float m1, float m2, float m3)
{
    float total = m1 + m2 + m3;
    float average = total / 3;
    cout << "\n\t\t==========RESULTS============" << endl;
    cout << "\n\t\tSTUDENT NAME : " << name << endl;
    cout << "\n\t\tTOTAL MARKS : " << total << endl;
    cout << "\n\t\tTHE AVERAGE IS : " << average << endl;
    cout << "\n\t\t============ STATUS ============\n";

    if (average >= 50)
    {
        cout << "You earned this success through your hard work and determination ."
                "Wishing you continued success\n"
             << endl;
        cout << "\033[32m";
        cout << "\t\t========== PASSED ============\n"
             << endl;
        cout << "\033[0m";
    }
    else
    {
        cout << "\033[31m";
        cout << "\t\t============ FAILED ============\n"
             << endl;
        cout << "\033[0m";
        cout << "Failure is not the end , it's a lesson and a new chance to grow stronger."
                "Believe in yourself, work hard, and success will come. \n"
             << endl;
    }
}
int main()
{
    string name;
    float mark1, mark2, mark3;
    char choise;
    do
    {
        cout << "\t\t===================================" << endl;
        cout << "\t\tStudent Result Management System" << endl;
        cout << "\t\t===================================" << endl;

        cout << "Enter name of student : " << endl;
        cin >> name;

        cout << "Enter mark for course 1 : " << endl;
        cin >> mark1;

        cout << "Enter mark for course 2 : " << endl;
        cin >> mark2;

        cout << "Enter mark for course 3 : " << endl;
        cin >> mark3;

        status(name, mark1, mark2, mark3);

        cout
            << "do you want to insert another student (y/n) ? " << endl;
        cin >> choise;

    } while (choise == 'y' || choise == 'Y');

    cout << "Thanke you for using our system " << endl;
    return 0;
}