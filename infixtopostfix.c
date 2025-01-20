#include <stdio.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
int precedence(char c) {
if (c == '^') return 3;
if (c == '*' || c == '/') return 2;
if (c == '+' || c == '-') return 1;
return 0;
}
int isOperator(char c) { return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'); }
void infixToPostfix(char* infix) {
char postfix[MAX]; int i, j = 0;
for (i = 0; infix[i] != '\0'; i++) {
if (isalnum(infix[i]))
postfix[j++] = infix[i];
else if (infix[i] == '(')
push(infix[i]);
else if (infix[i] == ')') {
while (stack[top] != '(')
postfix[j++] = pop();
pop(); // Remove '('
}
else if (isOperator(infix[i])) {
while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
postfix[j++] = pop();
push(infix[i]);
}
}
while (top != -1)
postfix[j++] = pop();
postfix[j] = '\0';
printf("Postfix: %s\n", postfix);
}
int main() {
char infix[MAX];
printf("Enter infix expression: ");
scanf("%s", infix);
infixToPostfix(infix);
return 0;
}