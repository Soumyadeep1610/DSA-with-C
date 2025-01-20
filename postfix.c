#include <stdio.h>
#include <ctype.h>
#define MAX 100
int stack[MAX], top = -1;
void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }
int evaluatePostfix(char* expr) {
int i, op1, op2;
for (i = 0; expr[i] != '\0'; i++) {
if (isdigit(expr[i]))
push(expr[i] - '0');
else {
op2 = pop();
op1 = pop();
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
printf("Enter postfix expression: ");
scanf("%s", expr);
printf("Result: %d\n", evaluatePostfix(expr));
return 0;
}