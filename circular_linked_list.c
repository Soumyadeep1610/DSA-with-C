#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
int data;
struct Node* next;
} Node;

Node* createList();
void displayList(Node* head);
Node* insertAtBeginning(Node* head, int data);
Node* insertAtEnd(Node* head, int data);
Node* deleteFromBeginning(Node* head);
Node* deleteFromEnd(Node* head);
Node* deleteAfterNode(Node* head, int targetData);
Node* deleteList(Node* head);
int main() {
Node* head = NULL;
int choice, data, targetData;
while (1) {
printf("\nMenu:\n");
printf("1. Create a circular linked list\n");
printf("2. Display the elements of the list\n");
printf("3. Insert a node at the beginning\n");
printf("4. Insert a node at the end\n");
printf("5. Delete a node from the beginning\n");
printf("6. Delete a node from the end\n");
printf("7. Delete a node after a given node\n");
printf("8. Delete the entire list\n");
printf("9. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
head = createList();
break;
case 2:
displayList(head);
break;
case 3:
printf("Enter the data to insert at the beginning: ");
scanf("%d", &data);
head = insertAtBeginning(head, data);
break;
case 4:
printf("Enter the data to insert at the end: ");
scanf("%d", &data);
head = insertAtEnd(head, data);
break;
case 5:
head = deleteFromBeginning(head);
break;
case 6:
head = deleteFromEnd(head);
break;
case 7:
printf("Enter the target data after which to delete: ");
scanf("%d", &targetData);
head = deleteAfterNode(head, targetData);
break;
case 8:
head = deleteList(head);
break;
case 9:
exit(0);
default:
printf("Invalid choice. Please try again.\n");
}
}
return 0;
}

Node* createList() {
Node* head = NULL;
Node* temp = NULL;
Node* p = NULL;
int data, n, i;
printf("Enter the number of nodes: ");
scanf("%d", &n);
if (n <= 0) {
printf("Invalid number of nodes.\n");
return NULL;
}
for (i = 0; i < n; i++) {
temp = (Node*)malloc(sizeof(Node));
if (temp == NULL) {
printf("Memory allocation failed.\n");
exit(1);
}
printf("Enter data for node %d: ", i + 1);
scanf("%d", &data);
temp->data = data;
if (head == NULL) {
head = temp;
head->next = head;
} else {
p = head;
while (p->next != head) {
p = p->next;
}
p->next = temp;
temp->next = head;
}
}
return head;
}

void displayList(Node* head) {
Node* temp = head;
if (temp == NULL) {
printf("The list is empty.\n");
return;
}
do {
printf("%d -> ", temp->data);
temp = temp->next;
} while (temp != head);
printf("(head)\n");
}

Node* insertAtBeginning(Node* head, int data) {
Node* temp = (Node*)malloc(sizeof(Node));
Node* p = head;
if (temp == NULL) {
printf("Memory allocation failed.\n");
exit(1);
}
temp->data = data;
if (head == NULL) {
temp->next = temp;
return temp;
}
while (p->next != head) {
p = p->next;
}
p->next = temp;
temp->next = head;
return temp;
}

Node* insertAtEnd(Node* head, int data) {
Node* temp = (Node*)malloc(sizeof(Node));
Node* p = head;
if (temp == NULL) {
printf("Memory allocation failed.\n");
exit(1);
}
temp->data = data;
if (head == NULL) {
temp->next = temp;
return temp;
}
while (p->next != head) {
p = p->next;
}
p->next = temp;
temp->next = head;
return head;
}

Node* deleteFromBeginning(Node* head) {
Node* temp = head;
Node* p;
if (head == NULL) {
printf("The list is empty.\n");
return NULL;
}
if (head->next == head) {
free(head);
return NULL;
}
p = head;
while (p->next != head) {
p = p->next;
}
p->next = head->next;
head = head->next;
free(temp);
return head;
}

Node* deleteFromEnd(Node* head) {
Node* temp = head;
Node* prev = NULL;
if (head == NULL) {
printf("The list is empty.\n");
return NULL;
}
if (head->next == head) {
free(head);
return NULL;
}
while (temp->next != head) {
prev = temp;
temp = temp->next;
}
prev->next = head;
free(temp);
return head;
}

Node* deleteAfterNode(Node* head, int targetData) {
Node* temp = head;
Node* toDelete = NULL;
if (head == NULL) {
printf("The list is empty.\n");
return NULL;
}
do {
if (temp->data == targetData) {
toDelete = temp->next;
if (toDelete == head) {
printf("No node to delete after the target.\n");
return head;
}
temp->next = toDelete->next;
free(toDelete);
return head;
}
temp = temp->next;
} while (temp != head);
printf("Target node not found.\n");
return head;
}

Node* deleteList(Node* head) {
Node* temp;
if (head == NULL) {
return NULL;
}
Node* current = head;
do {
temp = current;
current = current->next;
free(temp);
} while (current != head);
return NULL;
}