#include <iostream>
using namespace std;

const int MAX = 100;

// Display all marks (Traversal)
void display(int marks[], int n)
{
    if (n == 0)
    {
        cout << "No marks available.\n";
        return;
    }

    cout << "Student Marks:\n";
    for (int i = 0; i < n; i++)
        cout << "Student " << i + 1 << ": " << marks[i] << endl;
}

// Insert a mark
void insert(int marks[], int &n)
{
    if (n == MAX)
    {
        cout << "Array is full.\n";
        return;
    }

    int pos, mark;

    cout << "Enter position: ";
    cin >> pos;

    if (pos < 1 || pos > n + 1)

    {
        cout << "Invalid position.\n";
        return;
    }

    cout << "Enter mark: ";
    cin >> mark;

    if (mark < 0 || mark > 100)
    {
        cout << "Invalid mark.\n";
        return;
    }

    for (int i = n; i >= pos; i--)
        marks[i] = marks[i - 1];

    marks[pos - 1] = mark;
    n++;

    cout << "Mark inserted successfully.\n";
}

// Delete a mark
void deleteMark(int marks[], int &n)
{
    if (n == 0)
    {
        cout << "No marks available.\n";
        return;
    }

    int pos;

    cout << "Enter position to delete: ";
    cin >> pos;

    if (pos < 1 || pos > n)
    {
        cout << "Invalid position.\n";
        return;
    }

    for (int i = pos - 1; i < n - 1; i++)
        marks[i] = marks[i + 1];

    n--;

    cout << "Mark deleted successfully.\n";
}

// Search for a mark
void search(int marks[], int n)
{
    int mark;
    bool found = false;

    cout << "Enter mark to search: ";
    cin >> mark;

    for (int i = 0; i < n; i++)
    {
        if (marks[i] == mark)
        {
            cout << "Mark found at position " << i + 1 << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Mark not found.\n";
}

int main()
{
    int marks[MAX], n = 0, choice;

    do
    {
         cout << "\n--- Student Mark Analysis System ---\n";
         cout << "1. Insert Mark\n";
         cout << "2. Delete Mark\n";
         cout << "3. Search Mark\n";
         cout << "4. Display Marks\n";
         cout << "5. Exit\n";
         cout << "Enter choice: ";
         cin >> choice;

         switch (choice)
         {
         case 1:
             insert(marks, n);
             break;

         case 2:
             deleteMark(marks, n);

             break;

         case 3:
             search(marks, n);
             break;

         case 4:
             display(marks, n);
             break;

         case 5:
             cout << "Program ended.\n";
             break;

         default:
             cout << "Invalid choice.\n";
         }

    } while (choice != 5);

    return 0;
}
