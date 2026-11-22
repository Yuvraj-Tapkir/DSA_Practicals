#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

struct Task {
   int id;
   string name;
   int priority;
};

deque<Task> tasks;
int nextId = 1;

// Add task at the front
void addFront() {
   Task t;
   t.id = nextId++;

    cout << "Enter task name: ";
    cin.ignore();
    getline(cin, t.name);

    cout << "Enter priority (higher number = higher priority): ";
    cin >> t.priority;

    tasks.push_front(t);
    cout << "Task added at the front successfully!\n";
}

// Add task at the rear
void addRear() {
   Task t;
   t.id = nextId++;

    cout << "Enter task name: ";
    cin.ignore();
    getline(cin, t.name);

    cout << "Enter priority (higher number = higher priority): ";
    cin >> t.priority;

    tasks.push_back(t);
    cout << "Task added at the rear successfully!\n";
}

// Process the highest-priority task
void processTask() {
   if (tasks.empty()) {
       cout << "No tasks available to process.\n";
       return;
   }

    auto it = max_element(
       tasks.begin(), tasks.end(),
       [](const Task &a, const Task &b) {
          return a.priority < b.priority;
       }
    );

    cout << "\nProcessing Task:\n";
    cout << "ID      : " << it->id << '\n';
    cout << "Name : " << it->name << '\n';
    cout << "Priority : " << it->priority << '\n';

    tasks.erase(it);
}

// Display all pending tasks
void displayTasks() {
   if (tasks.empty()) {
       cout << "No pending tasks.\n";
       return;
   }

    cout << "\n--- Pending Tasks ---\n";
    cout << "ID\tName\t\tPriority\n";

    for (const Task &t : tasks) {
       cout << t.id << '\t'
          << t.name << "\t\t"
          << t.priority << '\n';
    }
}

// Main menu
int main() {
   int choice;

    do {
      cout << "\n===== TASK SCHEDULER =====\n";
      cout << "1. Add Task at Front\n";
      cout << "2. Add Task at Rear\n";
      cout << "3. Process Highest-Priority Task\n";
      cout << "4. Display Pending Tasks\n";
      cout << "5. Exit\n";
      cout << "Enter your choice: ";
      cin >> choice;

      switch (choice) {
        case 1:
           addFront();
           break;

         case 2:
           addRear();
           break;

         case 3:
           processTask();
           break;

         case 4:
           displayTasks();
           break;

         case 5:
           cout << "Exiting Task Scheduler...\n";
           break;

         default:
           cout << "Invalid choice! Please try again.\n";
       }
    } while (choice != 5);

    return 0;
}
