#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        q1.pop();
    }

    void top() {

         if (q1.empty()) {
             cout << "Stack is empty\n";
             return;
         }

            cout << "Top element: " << q1.front() << endl;
     }

     void display() {
         if (q1.empty()) {
             cout << "Stack is empty\n";
             return;
         }

            queue<int> temp = q1;

         cout << "Stack elements: ";
         while (!temp.empty()) {
             cout << temp.front() << " ";
             temp.pop();
         }
         cout << endl;
     }
};

int main() {
    Stack s;
    int choice, x;

     do {
            cout << "\n1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

         switch (choice) {
             case 1:
                 cout << "Enter element: ";
                 cin >> x;
                 s.push(x);
                 break;

               case 2:
                   s.pop();
                   break;

           case 3:
               s.top();
               break;

           case 4:
               s.display();
               break;

           case 5:
               cout << "Exiting...\n";
               break;

           default:
               cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
