#include <stdio.h>
#include <string.h>
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
void reverse(char* exp) {
int len = strlen(exp), i;
for (i = 0; i < len / 2; i++) {
char temp = exp[i];
exp[i] = exp[len - i - 1];
exp[len - i - 1] = temp;
}
}
void infixToPrefix(char* infix) {
char prefix[MAX]; int i, j = 0;
reverse(infix);
for (i = 0; infix[i] != '\0'; i++) {
if (isalnum(infix[i]))
prefix[j++] = infix[i];
else if (infix[i] == ')')
push(infix[i]);
else if (infix[i] == '(') {
while (stack[top] != ')')
prefix[j++] = pop();
pop(); // Remove ')'
}
else if (isOperator(infix[i])) {
while (top != -1 && precedence(stack[top]) > precedence(infix[i]))
prefix[j++] = pop();
push(infix[i]);
}
}
while (top != -1)
prefix[j++] = pop();
prefix[j] = '\0';
reverse(prefix);
printf("Prefix: %s\n", prefix);
}
int main() {
char infix[MAX];
printf("Enter infix expression: ");
scanf("%s", infix);
infixToPrefix(infix);
return 0;
}