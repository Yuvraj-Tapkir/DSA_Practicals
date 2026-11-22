#include <iostream>
using namespace std;

struct Node {
   int data;
   Node* next;

     Node(int value) {
       data = value;
       next = nullptr;
     }
};

class Queue {
private:
   Node* front;
   Node* rear;

public:
  Queue() {
     front = nullptr;
     rear = nullptr;
  }

     // Insert an element
     void enqueue(int value) {
         Node* newNode = new Node(value);

         if (rear == nullptr) {
             front = rear = newNode;
         } else {
             rear->next = newNode;
             rear = newNode;
         }

         cout << value << " inserted into the queue.\n";
     }

     // Delete an element

     void dequeue() {
       if (front == nullptr) {
           cout << "Queue is empty! Cannot delete.\n";
           return;
       }

         Node* temp = front;
         cout << "Deleted element: " << front->data << endl;

         front = front->next;

         if (front == nullptr) {
             rear = nullptr;
         }

         delete temp;
     }

     // Display queue elements
     void display() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return;
        }

         Node* temp = front;

         cout << "Queue elements: ";
         while (temp != nullptr) {
           cout << temp->data << " ";
           temp = temp->next;
         }

         cout << endl;
     }

     // Free allocated memory
     ~Queue() {
        while (front != nullptr) {
           Node* temp = front;
           front = front->next;
           delete temp;
        }

         rear = nullptr;
     }
};

int main() {
   Queue q;
   int choice, value;

     do {
       cout << "\n===== QUEUE MENU =====\n";
       cout << "1. Insert (Enqueue)\n";
       cout << "2. Delete (Dequeue)\n";
       cout << "3. Display Queue\n";
       cout << "4. Exit\n";
       cout << "Enter your choice: ";
       cin >> choice;

      switch (choice) {
        case 1:
           cout << "Enter value to insert: ";
           cin >> value;
           q.enqueue(value);
           break;

          case 2:
            q.dequeue();
            break;

          case 3:
            q.display();
            break;

          case 4:
            cout << "Exiting program...\n";
            break;

          default:
            cout << "Invalid choice! Please try again.\n";
      }

    } while (choice != 4);

    return 0;
}
