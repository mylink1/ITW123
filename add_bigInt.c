/* ALGORITHM
    1.) raed the first long integer as the string.
    read each character from the string
    convert to integer
    create a node for each int
    insert each at begging of linked list

    2.) Repeat the first step for the second number

    Applications such as security algorithms andcryptography require storing and manipulatingintegers of unlimited size
    Desirable to use a linked list for storing andmanipulating integers of arbitrary length

    Steps for Addition of two long integers
     Traverse the two linked lists in parallel from left to right.
     During traversal, corresponding digits and a carry fromprior digits sum are added, then stored in the new nodeof the resultant linked list
*/

#include<stdio.h>
#include<stdlib.h>

// Define a structure for the linked list node
struct node {
    int digit;
    struct node* next;
};

// Function to create a new node and append it to the linked list
struct node* insertNode(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->digit = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// Function to print the linked list (used to print the integer)
void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->digit);
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two linked lists representing two long integers
struct node* addTwoNumbers(struct node* l1, struct node* l2) {
    struct node* result = NULL;
    struct node* p1 = l1;
    struct node* p2 = l2;
    int carry = 0;

    while (p1 != NULL || p2 != NULL) {
        int sum = carry;

        if (p1 != NULL) {
            sum += p1->digit;
            p1 = p1->next;
        }
        if (p2 != NULL) {
            sum += p2->digit;
            p2 = p2->next;
        }

        // Add the new digit to the result (sum % 10)
        result = insertNode(result, sum % 10);

        // Update the carry for the next step
        carry = sum / 10;
    }

    // If there is any carry left after the last addition
    if (carry > 0) {
        result = insertNode(result, carry);
    }

    return result;
}

// Reverse the linked list (since we are adding from least significant digit)
struct node* reverseList(struct node* head) {
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main() {
    struct node* num1 = NULL;
    struct node* num2 = NULL;

    // Input for first number (in reverse order for easier addition)
    num1 = insertNode(num1, 3); // 3
    num1 = insertNode(num1, 4); // 4
    num1 = insertNode(num1, 2); // 2  -> Represents the number 243

    // Input for second number (in reverse order)
    num2 = insertNode(num2, 4); // 4
    num2 = insertNode(num2, 6); // 6
    num2 = insertNode(num2, 5); // 5  -> Represents the number 564

    // Reverse the linked lists to handle MSD to LSD addition
    num1 = reverseList(num1);
    num2 = reverseList(num2);

    // Print the numbers
    printf("First number: ");
    printList(num1);
    printf("Second number: ");
    printList(num2);

    // Add the two numbers
    struct node* sum = addTwoNumbers(num1, num2);

    // Reverse the result to show the correct number
    sum = reverseList(sum);

    // Print the result
    printf("Sum: ");
    printList(sum);

    return 0;
}
