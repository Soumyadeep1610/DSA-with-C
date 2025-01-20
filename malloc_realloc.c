#include <stdio.h>
#include <stdlib.h>
int main() {
int *arr;
int n, newSize;
printf("Enter number of elements: ");
scanf("%d", &n);
arr = (int *)malloc(n * sizeof(int));
if (arr == NULL) {
printf("Memory not allocated.\n");
return 0;
}
printf("Enter %d elements:\n", n);
for (int i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}
printf("Enter new size: ");
scanf("%d", &newSize);
arr = (int *)realloc(arr, newSize * sizeof(int));
printf("Enter %d new elements:\n", newSize - n);
for (int i = n; i < newSize; i++) {
scanf("%d", &arr[i]);
}
printf("Array elements after reallocation are:\n");
for (int i = 0; i < newSize; i++) {
printf("%d ", arr[i]);
}
free(arr);
return 0;
}