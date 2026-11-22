#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char phone[15];
    int duration;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertAtBeginning() {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter caller name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter phone number: ");
    scanf("%s", newNode->phone);

    printf("Enter call duration (minutes): ");
    scanf("%d", &newNode->duration);

    newNode->next = head;
    head = newNode;

    printf("Call log inserted at beginning.\n");
}

// Insert at end
void insertAtEnd() {

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;

    printf("Enter caller name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter phone number: ");
    scanf("%s", newNode->phone);

    printf("Enter call duration (minutes): ");
    scanf("%d", &newNode->duration);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Call log inserted at end.\n");
}

// Insert at a specific position
void insertAtPosition() {
    struct Node *newNode, *temp;
    int position, i;

    printf("Enter position: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter caller name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter phone number: ");

    scanf("%s", newNode->phone);

    printf("Enter call duration (minutes): ");
    scanf("%d", &newNode->duration);

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        printf("Call log inserted at position %d.\n", position);
        return;
    }

    temp = head;

    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position does not exist.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Call log inserted at position %d.\n", position);
}

// Delete from beginning
void deleteAtBeginning() {
    struct Node *temp;

    if (head == NULL) {
        printf("Call log is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("Deleted call log: %s - %s\n", temp->name, temp->phone);

    free(temp);
}

// Delete from end

void deleteAtEnd() {
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("Call log is empty.\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted call log: %s - %s\n", head->name, head->phone);
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    printf("Deleted call log: %s - %s\n", temp->name, temp->phone);

    free(temp);
}

// Display all call logs
void display() {
    struct Node *temp;
    int count = 1;

    if (head == NULL) {
        printf("Call log is empty.\n");
        return;
    }

    temp = head;

    printf("\n========== CALL LOG ==========\n");

    while (temp != NULL) {
        printf("\nCall %d\n", count);
        printf("Name     : %s\n", temp->name);
        printf("Phone    : %s\n", temp->phone);
        printf("Duration : %d minutes\n", temp->duration);

        temp = temp->next;
        count++;
    }

    printf("\n==============================\n");
}

// Search call log by phone number
void search() {
    struct Node *temp;
    char phone[15];
    int found = 0;

    if (head == NULL) {
        printf("Call log is empty.\n");
        return;
    }

    printf("Enter phone number to search: ");
    scanf("%s", phone);

    temp = head;

    while (temp != NULL) {
        if (strcmp(temp->phone, phone) == 0) {
            printf("\nCall log found!\n");
            printf("Name     : %s\n", temp->name);
            printf("Phone    : %s\n", temp->phone);
            printf("Duration : %d minutes\n", temp->duration);

            found = 1;
            break;
        }

        temp = temp->next;
    }

    if (!found) {
        printf("Call log not found.\n");
    }
}

// Main function
int main() {
    int choice;

    while (1) {

printf("\n====== CALL LOG MANAGEMENT ======\n");
printf("1. Insert at Beginning\n");
printf("2. Insert at End\n");
printf("3. Insert at Position\n");
printf("4. Delete at Beginning\n");
printf("5. Delete at End\n");
printf("6. Display\n");
printf("7. Search\n");
printf("8. Exit\n");

printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
    case 1:
        insertAtBeginning();
        break;

   case 2:
       insertAtEnd();
       break;

   case 3:
       insertAtPosition();
       break;

   case 4:
       deleteAtBeginning();
       break;

   case 5:
       deleteAtEnd();
       break;

   case 6:
       display();
       break;

   case 7:
       search();
       break;

   case 8:
       printf("Exiting program...\n");
       exit(0);

   default:
       printf("Invalid choice. Please try again.\n");

        }
    }

    return 0;
}
