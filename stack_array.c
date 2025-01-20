#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;
void push(int element) {
if (top == MAX_SIZE - 1) {
printf("Stack is full\n");
return;
}
top++;
stack[top] = element;
printf("%d pushed successfully\n", element);
}
int pop() {
if (top == -1) {
printf("Stack is empty\n");
return -1;
}
int poppedElement = stack[top];
top--;
return poppedElement;
}
int peek() {
if (top == -1) {
printf("Stack is empty\n");
return -1;
}
return stack[top];
}
void display() {
if (top == -1) {
printf("Stack is empty\n");
return;
}
printf("Stack elements: ");
for (int i = top; i >= 0; i--) {
printf("%d ", stack[i]);
}
printf("\n");
}
int main() {
int choice, element;
printf("\nMenu:\n");
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Peek\n");
printf("4. Display\n");
printf("5. Exit\n");
while (1) {
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter element to push: ");
scanf("%d", &element);
push(element);
break;
case 2:
element = pop();
if (element != -1) {
printf("%d popped successfully\n", element);
}
break;
case 3:
element = peek();
if (element != -1) {
printf("Top element: %d\n", element);
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