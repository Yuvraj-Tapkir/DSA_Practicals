#include <iostream>
using namespace std;

const int SIZE = 10;
int parking[SIZE];

// Initialize parking slots
void initialize()
{
    for (int i = 0; i < SIZE; i++)
        parking[i] = -1;
}

// Insert vehicle
void insertVehicle(int vehicle)
{
    int index = vehicle % SIZE;

    for (int i = 0; i < SIZE; i++)
    {
        int pos = (index + i) % SIZE;

         if (parking[pos] == -1)
         {

            parking[pos] = vehicle;
            cout << "Vehicle parked at slot " << pos << endl;
            return;
        }
    }

    cout << "Parking lot is full.\n";
}

// Search vehicle
void searchVehicle(int vehicle)
{
    int index = vehicle % SIZE;

    for (int i = 0; i < SIZE; i++)
    {
        int pos = (index + i) % SIZE;

        if (parking[pos] == vehicle)
        {
            cout << "Vehicle found at slot " << pos << endl;
            return;
        }

        if (parking[pos] == -1)
            break;
    }

    cout << "Vehicle not found.\n";
}

// Delete vehicle
void deleteVehicle(int vehicle)
{
    int index = vehicle % SIZE;

    for (int i = 0; i < SIZE; i++)
    {
        int pos = (index + i) % SIZE;

        if (parking[pos] == vehicle)
        {
            parking[pos] = -1;
            cout << "Vehicle removed from slot " << pos << endl;
            return;
        }

        if (parking[pos] == -1)

            break;
    }

    cout << "Vehicle not found.\n";
}

// Display parking slots
void display()
{
    cout << "\nParking Slots:\n";

    for (int i = 0; i < SIZE; i++)
    {
        if (parking[i] == -1)
            cout << "Slot " << i << ": Empty\n";
        else
            cout << "Slot " << i << ": " << parking[i] << endl;
    }
}

int main()
{
    initialize();

    int choice, vehicle;

    do
    {
         cout << "\n--- Parking Lot Management System ---\n";
         cout << "1. Park Vehicle\n";
         cout << "2. Remove Vehicle\n";
         cout << "3. Search Vehicle\n";
         cout << "4. Display Parking Slots\n";
         cout << "5. Exit\n";
         cout << "Enter choice: ";
         cin >> choice;

         switch (choice)
         {
         case 1:
             cout << "Enter vehicle number: ";
             cin >> vehicle;
             insertVehicle(vehicle);
             break;

         case 2:
             cout << "Enter vehicle number: ";
             cin >> vehicle;

           deleteVehicle(vehicle);
           break;

       case 3:
           cout << "Enter vehicle number: ";
           cin >> vehicle;
           searchVehicle(vehicle);
           break;

       case 4:
           display();
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
