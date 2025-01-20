#include <stdio.h>
#include <stdlib.h>
int main() {
int *arr;
int n, search, found = 0;
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
printf("Enter element to search: ");
scanf("%d", &search);
for (int i = 0; i < n; i++) {
if (arr[i] == search) {
found = 1;
printf("Element %d found at index %d.\n", search, i);
break;
}
}
if (!found) {
printf("Element not found.\n");
}
free(arr);
return 0;
}