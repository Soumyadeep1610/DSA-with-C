#include <stdio.h>
#include <stdlib.h>
// Definition of a node in the circular doubly linked list
struct Node {
int data;
struct Node* next;
struct Node* prev;
};
// Function prototypes
struct Node* createCircularDoublyLinkedList();
void displayList(struct Node* head);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void deleteFromBeginning(struct Node** head);
void deleteFromEnd(struct Node** head);
void deleteAfterNode(struct Node** head, struct Node* target);
void deleteList(struct Node** head);
// Main function
int main() {
struct Node* head = NULL;
int choice, data;
struct Node* target;
while (1) {
printf("\nCircular Doubly Linked List Menu:\n");
printf("1. Create Circular Doubly Linked List\n");
printf("2. Display the List\n");
printf("3. Insert at Beginning\n");
printf("4. Insert at End\n");
printf("5. Delete from Beginning\n");
printf("6. Delete from End\n");
printf("7. Delete After a Given Node\n");
printf("8. Delete the Entire List\n");
printf("9. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
head = createCircularDoublyLinkedList();
break;
case 2:
displayList(head);
break;
case 3:
printf("Enter data to insert at beginning: ");
scanf("%d", &data);
insertAtBeginning(&head, data);
break;
case 4:
printf("Enter data to insert at end: ");
scanf("%d", &data);
insertAtEnd(&head, data);
break;
case 5:
deleteFromBeginning(&head);
break;
case 6:
deleteFromEnd(&head);
break;
case 7:
printf("Enter target node value after which to delete: ");
scanf("%d", &data);
target = head;
if (target != NULL) {
do {
if (target->data == data) break;
target = target->next;
} while (target != head);
}
deleteAfterNode(&head, target);
break;
case 8:
deleteList(&head);
break;
case 9:
exit(0);
default:
printf("Invalid choice. Please try again.\n");
}
}
return 0;
}
// Function to create a circular doubly linked list
struct Node* createCircularDoublyLinkedList() {
struct Node* head = NULL;
struct Node* newNode;
int data, n, i;
printf("Enter number of nodes: ");
scanf("%d", &n);
for (i = 0; i < n; i++) {
printf("Enter data for node %d: ", i + 1);
scanf("%d", &data);
newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
if (head == NULL) {
head = newNode;
newNode->next = head;
newNode->prev = head;
} else {
struct Node* tail = head->prev;
tail->next = newNode;
newNode->prev = tail;
newNode->next = head;
head->prev = newNode;
}
}
return head;
}
// Function to display the circular doubly linked list
void displayList(struct Node* head) {
struct Node* temp = head;
if (temp == NULL) {
printf("The list is empty.\n");
return;
}
printf("Circular Doubly Linked List: ");
do {
printf("%d ", temp->data);
temp = temp->next;
} while (temp != head);
printf("\n");
}
// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
if (*head == NULL) {
newNode->next = newNode;
newNode->prev = newNode;
*head = newNode;
} else {
struct Node* tail = (*head)->prev;
newNode->next = *head;
newNode->prev = tail;
tail->next = newNode;
(*head)->prev = newNode;
*head = newNode;
}
}
// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
if (*head == NULL) {
newNode->next = newNode;
newNode->prev = newNode;
*head = newNode;
} else {
struct Node* tail = (*head)->prev;
tail->next = newNode;
newNode->prev = tail;
newNode->next = *head;
(*head)->prev = newNode;
}
}
// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
if (*head == NULL) {
printf("The list is already empty.\n");
return;
}
struct Node* temp = *head;
if (temp->next == *head) {
free(temp);
*head = NULL;
} else {
struct Node* tail = (*head)->prev;
tail->next = temp->next;
temp->next->prev = tail;
*head = temp->next;
free(temp);
}
}
// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
if (*head == NULL) {
printf("The list is already empty.\n");
return;
}
struct Node* tail = (*head)->prev;
if (tail == *head) {
free(tail);
*head = NULL;
} else {
struct Node* newTail = tail->prev;
newTail->next = *head;
(*head)->prev = newTail;
free(tail);
}
}
// Function to delete a node after a given node
void deleteAfterNode(struct Node** head, struct Node* target) {
if (target == NULL || target->next == *head) {
printf("No node to delete after the target node.\n");
return;
}
struct Node* toDelete = target->next;
if (toDelete == *head) {
if (toDelete->next == *head) {
free(toDelete);
*head = NULL;
} else {
struct Node* tail = (*head)->prev;
tail->next = *head;
(*head)->prev = tail;
free(toDelete);
}
} else {
target->next = toDelete->next;
toDelete->next->prev = target;
free(toDelete);
}
}
// Function to delete the entire list
void deleteList(struct Node** head) {
if (*head == NULL) {
printf("The list is already empty.\n");
return;
}
struct Node* current = *head;
struct Node* nextNode;
do {
nextNode = current->next;
free(current);
current = nextNode;
} while (current != *head);
*head = NULL;
printf("The entire list has been deleted.\n");
}