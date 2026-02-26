/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL, *prev = NULL;

    // Input number of elements
    scanf("%d", &n);

    // Create linked list
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Input key to delete
    scanf("%d", &key);

    temp = head;

    // If head node contains key
    if(temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
    } else {
        // Traverse to find key
        while(temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // If key found
        if(temp != NULL) {
            prev->next = temp->next;
            free(temp);
        }
    }

    // Print updated list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}