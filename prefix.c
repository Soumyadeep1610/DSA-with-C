#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
int stack[MAX], top = -1;
void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }
int evaluatePrefix(char* expr) {
int i, op1, op2;
int len = strlen(expr);
for (i = len - 1; i >= 0; i--) {
if (isdigit(expr[i]))
push(expr[i] - '0'); else {
op1 = pop();
op2 = pop();
switch (expr[i]) {
case '+': push(op1 + op2); break;
case '-': push(op1 - op2); break;
case '*': push(op1 * op2); break;
case '/': push(op1 / op2); break;
}
}
}
return pop();
}
int main() {
char expr[MAX];
printf("Enter prefix expression: ");
scanf("%s", expr);
printf("Result: %d\n", evaluatePrefix(expr));
return 0;
}