#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int seatNo;
    char passengerName[50];
    int age;
    char trainName[50];

     struct Node *prev;
     struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertAtBeginning() {
    struct Node *newNode;

     newNode = (struct Node *)malloc(sizeof(struct Node));

     printf("Enter seat number: ");
     scanf("%d", &newNode->seatNo);

     printf("Enter passenger name: ");
     scanf(" %[^\n]", newNode->passengerName);

     printf("Enter passenger age: ");
     scanf("%d", &newNode->age);

     printf("Enter train name: ");
     scanf(" %[^\n]", newNode->trainName);

     newNode->prev = NULL;
     newNode->next = head;

     if (head != NULL) {
         head->prev = newNode;
     }

     head = newNode;

    printf("Reservation inserted at beginning.\n");
}

// Insert at end
void insertAtEnd() {
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter seat number: ");
    scanf("%d", &newNode->seatNo);

    printf("Enter passenger name: ");
    scanf(" %[^\n]", newNode->passengerName);

    printf("Enter passenger age: ");
    scanf("%d", &newNode->age);

    printf("Enter train name: ");
    scanf(" %[^\n]", newNode->trainName);

    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Reservation inserted at end.\n");
}

// Insert at position
void insertAtPosition() {
    struct Node *newNode;
    struct Node *temp;
    int position, i;

    printf("Enter position: ");

scanf("%d", &position);

if (position < 1) {
    printf("Invalid position.\n");
    return;
}

newNode = (struct Node *)malloc(sizeof(struct Node));

printf("Enter seat number: ");
scanf("%d", &newNode->seatNo);

printf("Enter passenger name: ");
scanf(" %[^\n]", newNode->passengerName);

printf("Enter passenger age: ");
scanf("%d", &newNode->age);

printf("Enter train name: ");
scanf(" %[^\n]", newNode->trainName);

// Insert at beginning
if (position == 1) {
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;

    printf("Reservation inserted at position %d.\n", position);
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
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    printf("Reservation inserted at position %d.\n", position);
}

// Delete at beginning
void deleteAtBeginning() {
    struct Node *temp;

    if (head == NULL) {
        printf("Reservation list is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    printf("Deleted reservation:\n");
    printf("Seat Number    : %d\n", temp->seatNo);
    printf("Passenger Name : %s\n", temp->passengerName);

    free(temp);
}

// Delete at end
void deleteAtEnd() {
    struct Node *temp;

    if (head == NULL) {
        printf("Reservation list is empty.\n");
        return;
    }

    temp = head;

    if (temp->next == NULL) {
        printf("Deleted reservation:\n");

        printf("Seat Number    : %d\n", temp->seatNo);
        printf("Passenger Name : %s\n", temp->passengerName);

        free(temp);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;

    printf("Deleted reservation:\n");
    printf("Seat Number    : %d\n", temp->seatNo);
    printf("Passenger Name : %s\n", temp->passengerName);

    free(temp);
}

// Display reservations
void display() {
    struct Node *temp;
    int count = 1;

    if (head == NULL) {
        printf("Reservation list is empty.\n");
        return;
    }

    temp = head;

    printf("\n========== TRAIN RESERVATIONS ==========\n");

    while (temp != NULL) {
        printf("\nReservation %d\n", count);
        printf("Seat Number    : %d\n", temp->seatNo);
        printf("Passenger Name : %s\n", temp->passengerName);
        printf("Age            : %d\n", temp->age);
        printf("Train Name     : %s\n", temp->trainName);

        temp = temp->next;
        count++;
    }

    printf("\n========================================\n");
}

// Search reservation by seat number
void search() {
    struct Node *temp;
    int seatNo;
    int found = 0;

    if (head == NULL) {
        printf("Reservation list is empty.\n");
        return;
    }

    printf("Enter seat number to search: ");
    scanf("%d", &seatNo);

    temp = head;

    while (temp != NULL) {
        if (temp->seatNo == seatNo) {
            printf("\nReservation found!\n");
            printf("Seat Number    : %d\n", temp->seatNo);
            printf("Passenger Name : %s\n", temp->passengerName);
            printf("Age            : %d\n", temp->age);
            printf("Train Name     : %s\n", temp->trainName);

            found = 1;
            break;
        }

        temp = temp->next;
    }

    if (!found) {
        printf("Reservation not found.\n");
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n====== TRAIN RESERVATION SYSTEM ======\n");
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
