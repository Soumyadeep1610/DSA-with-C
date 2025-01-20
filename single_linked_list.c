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
Node* insertBeforeNode(Node* head, int targetData, int newData);
Node* insertAfterNode(Node* head, int targetData, int newData);
Node* deleteFromBeginning(Node* head);
Node* deleteFromEnd(Node* head);
Node* deleteAfterNode(Node* head, int targetData);
Node* deleteList(Node* head);
int main() {
Node* head = NULL;
int choice, data, targetData;
while (1) {
printf("\nMenu:\n");
printf("1. Create a single linked list\n");
printf("2. Display the elements of the list\n");
printf("3. Insert a node at the beginning\n");
printf("4. Insert a node at the end\n");
printf("5. Insert a node before a given node\n");
printf("6. Insert a node after a given node\n");
printf("7. Delete a node from the beginning\n");
printf("8. Delete a node from the end\n");
printf("9. Delete a node after a given node\n");
printf("10. Delete the entire list\n");
printf("11. Exit\n");
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
printf("Enter the target data before which to insert: ");
scanf("%d", &targetData);
printf("Enter the new data to insert: ");
scanf("%d", &data);
head = insertBeforeNode(head, targetData, data);
break;
case 6:
printf("Enter the target data after which to insert: ");
scanf("%d", &targetData);
printf("Enter the new data to insert: ");
scanf("%d", &data);
head = insertAfterNode(head, targetData, data);
break;
case 7:
head = deleteFromBeginning(head);
break;
case 8:
head = deleteFromEnd(head);
break;
case 9:
printf("Enter the target data after which to delete: ");
scanf("%d", &targetData);
head = deleteAfterNode(head, targetData);
break;
case 10:
head = deleteList(head);
break;
case 11:
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
temp->next = NULL;
if (head == NULL) {
head = temp;
} else {
p = head;
while (p->next != NULL) {
p = p->next;
}
p->next = temp;
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
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}

Node* insertAtBeginning(Node* head, int data) {
Node* temp = (Node*)malloc(sizeof(Node));
if (temp == NULL) {
printf("Memory allocation failed.\n");
exit(1);
}
temp->data = data;
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
temp->next = NULL;
if (head == NULL) {
return temp;
}
while (p->next != NULL) {
p = p->next;
}
p->next = temp;
return head;
}

Node* insertBeforeNode(Node* head, int targetData, int newData) {
Node* temp = (Node*)malloc(sizeof(Node));
Node* p = head;
Node* prev = NULL;
if (temp == NULL) {
printf("Memory allocation failed.\n");
exit(1);
}
temp->data = newData;
temp->next = NULL;
if (head == NULL) {
printf("The list is empty.\n");
free(temp);
return head;
}
if (head->data == targetData) {
temp->next = head;
return temp;
}
while (p != NULL && p->data != targetData) {
prev = p;
p = p->next;
}
if (p == NULL) {
printf("Target node not found.\n");
free(temp);
return head;
}
prev->next = temp;
temp->next = p;
return head;
}

Node* insertAfterNode(Node* head, int targetData, int newData) {
Node* temp = (Node*)malloc(sizeof(Node));
Node* p = head;
if (temp == NULL) {
printf("Memory allocation failed.\n");
exit(1);
}
temp->data = newData;
temp->next = NULL;
while (p != NULL && p->data != targetData) {
p = p->next;
}
if (p == NULL) {
printf("Target node not found.\n");
free(temp);
return head;
}
temp->next = p->next;
p->next = temp;
return head;
}

Node* deleteFromBeginning(Node* head) {
Node* temp;
if (head == NULL) {
printf("The list is empty.\n");
return NULL;
}
temp = head;
head = head->next;
free(temp);
return head;
}

Node* deleteFromEnd(Node* head) {
Node* temp;
Node* p;
if (head == NULL) {
printf("The list is empty.\n");
return NULL;
}
if (head->next == NULL) {
free(head);
return NULL;
}
p = head;
while (p->next->next != NULL) {
p = p->next;
}
temp = p->next;
p->next = NULL;
free(temp);
return head;
}

Node* deleteAfterNode(Node* head, int targetData) {
Node* p = head;
Node* temp;
while (p != NULL && p->data != targetData) {
p = p->next;
}
if (p == NULL || p->next == NULL) {
printf("Target node not found or no node to delete after the target.\n");
return head;
}
temp = p->next;
p->next = temp->next;
free(temp);
return head;
}

Node* deleteList(Node* head) {
Node* temp;
while (head != NULL) {
temp = head;
head = head->next;
free(temp);
}
return NULL;
}