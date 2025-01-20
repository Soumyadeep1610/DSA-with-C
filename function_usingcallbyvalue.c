#include <stdio.h>
void modifyArray(int arr[], int size) {
printf("Inside function (Call by Value):\n");
for (int i = 0; i < size; i++) {
arr[i] = arr[i] + 5;
printf("%d ", arr[i]);
}
printf("\n");
}
int main() {
int arr[] = {1, 2, 3, 4, 5};
int size = 5;
modifyArray(arr, size);
printf("In main (Call by Value):\n");
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
return 0;
