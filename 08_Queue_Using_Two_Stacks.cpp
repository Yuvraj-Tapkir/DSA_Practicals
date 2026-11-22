#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> s1, s2;

public:
    // Insert an element into the queue
    void enqueue(int value) {
        s1.push(value);
        cout << value << " inserted into the queue.\n";
    }

    // Delete an element from the queue
    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty! Cannot delete.\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Deleted element: " << s2.top() << endl;
        s2.pop();
    }

    // Display all queue elements
    void display() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!\n";
            return;
        }

        stack<int> temp1 = s1;
        stack<int> temp2 = s2;
        stack<int> temp3;

        cout << "Queue elements: ";

        // Display elements already transferred to s2
        while (!temp2.empty()) {
            cout << temp2.top() << " ";
            temp2.pop();
        }

        // Reverse s1 to display its elements in FIFO order
        while (!temp1.empty()) {
            temp3.push(temp1.top());
            temp1.pop();
        }

            while (!temp3.empty()) {
                cout << temp3.top() << " ";
                temp3.pop();
            }

            cout << endl;
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
