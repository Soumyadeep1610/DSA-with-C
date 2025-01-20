#include <stdio.h>
#include <stdlib.h>
// Definition of a node in the doubly linked list
struct Node {
int data;
struct Node* next;
struct Node* prev;
};
// Function prototypes
struct Node* createDoublyLinkedList();
void displayList(struct Node* head);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void insertBeforeNode(struct Node** head, struct Node* target, int data);
void insertAfterNode(struct Node** head, struct Node* target, int data);
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
printf("\nDoubly Linked List Menu:\n");
printf("1. Create Doubly Linked List\n");
printf("2. Display the List\n");
printf("3. Insert at Beginning\n");
printf("4. Insert at End\n");
printf("5. Insert Before a Given Node\n");
printf("6. Insert After a Given Node\n");
printf("7. Delete from Beginning\n");
printf("8. Delete from End\n");
printf("9. Delete After a Given Node\n");
printf("10. Delete the Entire List\n");
printf("11. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
head = createDoublyLinkedList();
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
printf("Enter data to insert before a node: ");
scanf("%d", &data);
printf("Enter target node value: ");
scanf("%d", &target->data);
insertBeforeNode(&head, target, data);
break;
case 6:
printf("Enter data to insert after a node: ");
scanf("%d", &data);
printf("Enter target node value: ");
scanf("%d", &target->data);
insertAfterNode(&head, target, data);
break;
case 7:
deleteFromBeginning(&head);
break;
case 8:
deleteFromEnd(&head);
break;
case 9:
printf("Enter target node value after which to delete: ");
scanf("%d", &target->data);
deleteAfterNode(&head, target);
break;
case 10:
deleteList(&head);
break;
case 11:
exit(0);
default:
printf("Invalid choice. Please try again.\n");
}
}
return 0;
}
// Function to create a doubly linked list
struct Node* createDoublyLinkedList() {
struct Node* head = NULL;
int data, n, i;
printf("Enter number of nodes: ");
scanf("%d", &n);
for (i = 0; i < n; i++) {
printf("Enter data for node %d: ", i + 1);
scanf("%d", &data);
insertAtEnd(&head, data);
}
return head;
}
// Function to display the doubly linked list
void displayList(struct Node* head) {
struct Node* temp = head;
if (temp == NULL) {
printf("The list is empty.\n");
return;
}
printf("Doubly Linked List: ");
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = *head;
newNode->prev = NULL;
if (*head != NULL)
(*head)->prev = newNode;
*head = newNode;
}
// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
struct Node* temp = *head;
newNode->data = data;
newNode->next = NULL;
if (*head == NULL) {
newNode->prev = NULL;
*head = newNode;
return;
}
while (temp->next != NULL)
temp = temp->next;
temp->next = newNode;
newNode->prev = temp;
}
// Function to insert a node before a given node
void insertBeforeNode(struct Node** head, struct Node* target, int data) {
if (target == NULL) {
printf("Target node is NULL.\n");
return;
}
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->prev = target->prev;
newNode->next = target;
if (target->prev != NULL)
target->prev->next = newNode;
else
*head = newNode;
target->prev = newNode;
}
// Function to insert a node after a given node
void insertAfterNode(struct Node** head, struct Node* target, int data) {
if (target == NULL) {
printf("Target node is NULL.\n");
return;
}
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = target->next;
newNode->prev = target;
target->next = newNode;
if (newNode->next != NULL)
newNode->next->prev = newNode;
}
// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
if (*head == NULL) {
printf("The list is already empty.\n");
return;
}
struct Node* temp = *head;
*head = (*head)->next;
if (*head != NULL)
(*head)->prev = NULL;
free(temp);
}
// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
if (*head == NULL) {
printf("The list is already empty.\n");
return;
}
struct Node* temp = *head;
while (temp->next != NULL)
temp = temp->next;
if (temp->prev != NULL)
temp->prev->next = NULL;
else
*head = NULL;
free(temp);
}
// Function to delete a node after a given node
void deleteAfterNode(struct Node** head, struct Node* target) {
if (target == NULL || target->next == NULL) {
printf("No node to delete after the target node.\n");
return;
}
struct Node* temp = target->next;
target->next = temp->next;
if (temp->next != NULL)
temp->next->prev = target;
free(temp);
}
// Function to delete the entire list
void deleteList(struct Node** head) {
struct Node* current = *head;
struct Node* next;
while (current != NULL) {
next = current->next;
free(current);
current = next;
}
*head = NULL;
printf("The entire list has been deleted.\n");
}