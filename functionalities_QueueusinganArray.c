#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int queue[MAX_SIZE];
int front = -1;
int rear = -1;
void enqueue(int element) {
if (rear == MAX_SIZE - 1) {
printf("Queue is full\n");
return;
}
if (front == -1) {
front = 0;
}
rear++;
queue[rear] = element;
printf("%d enqueued successfully\n", element);
}
int dequeue() {
if (front == -1) {
printf("Queue is empty\n");
return -1;
}
int deletedElement = queue[front];
if (front == rear) {
front = rear = -1;
}
else {
front++;
}
return deletedElement;
}
int peep() {
if (front == -1) {
printf("Queue is empty\n");
return -1;
}
return queue[front];
}
void display() {
if (front == -1) {
printf("Queue is empty\n");
return;
}
printf("Queue elements: ");
for (int i = front; i <= rear; i++) {
printf("%d ", queue[i]);
}
printf("\n");
}
int main() {
int choice, element;
printf("\nMenu:\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Peep\n");
printf("4. Display\n");
printf("5. Exit\n");
while (1) {
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter element to enqueue: ");
scanf("%d", &element);
enqueue(element);
break;
case 2:
element = dequeue();
if (element != -1) {
printf("%d dequeued successfully\n", element);
}
break;
case 3:
element = peep();
if (element != -1) {
printf("Front element: %d\n", element);
}
break;
case 4:
display();
break;
case 5:
exit(0);
default:
printf("Invalid choice\n");
}
}
return 0;
}