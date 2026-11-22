#include <iostream>
#include <string>
using namespace std;

struct Friend
{
    string name;
    string mobile;
};

const int MAX = 50;

// Display phone book
void display(Friend f[], int n)
{
    cout << "\nPhone Book:\n";

    for (int i = 0; i < n; i++)
        cout << f[i].name << " - " << f[i].mobile << endl;
}

// Sentinel Search
int sentinelSearch(Friend f[], int n, string key)
{
    if (n == 0)
        return -1;

    string last = f[n - 1].name;
    f[n - 1].name = key;

    int i = 0;

    while (f[i].name != key)
        i++;

    f[n - 1].name = last;

    if (i < n - 1 || last == key)
        return i;

    return -1;
}

// Insert friend in sorted order
void insertFriend(Friend f[], int &n)
{
    if (n == MAX)
    {
        cout << "Phone book is full.\n";
        return;
    }

    Friend newFriend;

    cout << "Enter name: ";
    cin >> newFriend.name;

    int pos = sentinelSearch(f, n, newFriend.name);

    if (pos != -1)
    {
        cout << "Friend already exists.\n";
        return;
    }

    cout << "Enter mobile number: ";
    cin >> newFriend.mobile;

    int i = n - 1;

    while (i >= 0 && f[i].name > newFriend.name)
    {
        f[i + 1] = f[i];
        i--;
    }

    f[i + 1] = newFriend;
    n++;

    cout << "Friend added successfully.\n";
}

int main()
{
    Friend f[MAX];
    int n = 0;
    int choice;

   do
   {
        cout << "\n--- FRIEND PHONE BOOK ---\n";
        cout << "1. Insert Friend\n";
        cout << "2. Search Friend\n";
        cout << "3. Display Phone Book\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            insertFriend(f, n);
        }
        else if (choice == 2)
        {
            string name;

           cout << "Enter name to search: ";
           cin >> name;

           int pos = sentinelSearch(f, n, name);

           if (pos != -1)
               cout << "Friend found: " << f[pos].name
                    << " - " << f[pos].mobile << endl;
           else
               cout << "Friend not found.\n";
        }
        else if (choice == 3)
        {
            display(f, n);
        }
        else if (choice == 4)
        {
            cout << "Program ended.\n";
        }
        else
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
