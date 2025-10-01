#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure without typedef
struct Assignment {
    int studentID;
    char title[100];
    char date[11];   // Format: DD-MM-YYYY
    char status[10]; // "Submitted" or "Pending"
    struct Assignment* next;
};

struct Assignment* head = NULL;

// Create a new node
struct Assignment* createNode(int id, const char* title, const char* date, const char* status) {
    struct Assignment* newNode = (struct Assignment*)malloc(sizeof(struct Assignment));
    newNode->studentID = id;
    strcpy(newNode->title, title);
    strcpy(newNode->date, date);
    strcpy(newNode->status, status);
    newNode->next = NULL;
    return newNode;
}

// Add new record
void addSubmission(int id, const char* title, const char* date, const char* status) {
    struct Assignment* newNode = createNode(id, title, date, status);
    newNode->next = head;
    head = newNode;
    printf("Submission record added.\n");
}

// Update status
void updateStatus(int id, const char* title, const char* newStatus) {
    struct Assignment* temp = head;
    while (temp != NULL) {
        if (temp->studentID == id && strcmp(temp->title, title) == 0) {
            strcpy(temp->status, newStatus);
            printf("Status updated to %s.\n", newStatus);
            return;
        }
        temp = temp->next;
    }
    printf("Record not found.\n");
}

// Search by student ID
void searchByStudentID(int id) {
    struct Assignment* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (temp->studentID == id) {
            printf("ID: %d | Title: %s | Date: %s | Status: %s\n", temp->studentID, temp->title, temp->date, temp->status);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("No submissions found for Student ID %d.\n", id);
    }
}

// Display all records
void displayAll() {
    struct Assignment* temp = head;
    if (temp == NULL) {
        printf("No records to display.\n");
        return;
    }
    while (temp != NULL) {
        printf("ID: %d | Title: %s | Date: %s | Status: %s\n", temp->studentID, temp->title, temp->date, temp->status);
        temp = temp->next;
    }
}

// Free memory
void freeList(struct Assignment* node) {
    while (node != NULL) {
        struct Assignment* temp = node;
        node = node->next;
        free(temp);
    }
}

// Menu
void menu() {
    int choice, id;
    char title[100], date[11], status[10];

    while (1) {
        printf("\n--- Student Assignment Submission Tracker ---\n");
        printf("1. Add Submission Record\n");
        printf("2. Update Submission Status\n");
        printf("3. Search by Student ID\n");
        printf("4. Display All Records\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter Student ID: ");
                scanf("%d", &id);
                getchar(); // consume newline
                printf("Enter Assignment Title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // remove newline
                printf("Enter Submission Date (DD-MM-YYYY): ");
                scanf("%10s", date);
                getchar();
                printf("Enter Status (Submitted/Pending): ");
                scanf("%9s", status);
                addSubmission(id, title, date, status);
                break;
            case 2:
                printf("Enter Student ID: ");
                scanf("%d", &id);
                getchar();
                printf("Enter Assignment Title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0';
                printf("Enter New Status (Submitted/Pending): ");
                scanf("%9s", status);
                updateStatus(id, title, status);
                break;
            case 3:
                printf("Enter Student ID: ");
                scanf("%d", &id);
                searchByStudentID(id);
                break;
            case 4:
                displayAll();
                break;
            case 5:
                freeList(head);
                printf("Exiting program.\n");
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
