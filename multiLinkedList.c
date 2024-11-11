/*
Multi-Linked List
In a multi-linked list,
 Each node can have N number of pointers to othernodes
 Generally used to organize multiple orders of one setof elements
 Structure of Multi-linked list:
 Depends on the structure of a node
 A single node generally contains two things
 A list of pointers
 All the relevant data

Use cases of Multi-Linked Lists
 Multiple orders of one set of elements
 Representation of a sparse matrix
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct Node {
    char name[100];
    int age;
    struct Node* nextByName;  // Pointer for sorting by name
    struct Node* nextByAge;   // Pointer for sorting by age
} Node;

// Function to create a new node
Node* createNode(const char* name, int age) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->nextByName = NULL;
    newNode->nextByAge = NULL;
    return newNode;
}

// Function to insert a node sorted by name
void insertByName(Node** head, const char* name, int age) {
    Node* newNode = createNode(name, age);

    // If the list is empty or the new node should be inserted at the head
    if (*head == NULL || strcmp(name, (*head)->name) < 0) {
        newNode->nextByName = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        Node* prev = NULL;

        // Traverse the list to find the correct position
        while (current != NULL && strcmp(name, current->name) > 0) {
            prev = current;
            current = current->nextByName;
        }

        // Insert the new node in the correct position
        if (prev == NULL) {
            newNode->nextByName = *head;
            *head = newNode;
        } else {
            prev->nextByName = newNode;
            newNode->nextByName = current;
        }
    }
}

// Function to insert a node sorted by age
void insertByAge(Node** head, const char* name, int age) {
    Node* newNode = createNode(name, age);

    // If the list is empty or the new node should be inserted at the head
    if (*head == NULL || age < (*head)->age) {
        newNode->nextByAge = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        Node* prev = NULL;

        // Traverse the list to find the correct position
        while (current != NULL && age > current->age) {
            prev = current;
            current = current->nextByAge;
        }

        // Insert the new node in the correct position
        if (prev == NULL) {
            newNode->nextByAge = *head;
            *head = newNode;
        } else {
            prev->nextByAge = newNode;
            newNode->nextByAge = current;
        }
    }
}

// Function to print the linked list sorted by name
void printListByName(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("Name: %s, Age: %d\n", current->name, current->age);
        current = current->nextByName;
    }
}

// Function to print the linked list sorted by age
void printListByAge(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("Name: %s, Age: %d\n", current->name, current->age);
        current = current->nextByAge;
    }
}

int main() {
    Node* headByName = NULL;
    Node* headByAge = NULL;

    // Insert nodes into both lists
    insertByName(&headByName, "Alice", 25);
    insertByName(&headByName, "Bob", 30);
    insertByName(&headByName, "Charlie", 22);
    insertByName(&headByName, "Eve", 28);
    insertByName(&headByName, "David", 27);

    insertByAge(&headByAge, "Alice", 25);
    insertByAge(&headByAge, "Bob", 30);
    insertByAge(&headByAge, "Charlie", 22);
    insertByAge(&headByAge, "Eve", 28);
    insertByAge(&headByAge, "David", 27);

    // Print the list sorted by name
    printf("Sorted linked list by name:\n");
    printListByName(headByName);

    // Print the list sorted by age
    printf("\nSorted linked list by age:\n");
    printListByAge(headByAge);

    return 0;
}
