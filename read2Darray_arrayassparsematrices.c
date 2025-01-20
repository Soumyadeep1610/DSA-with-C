#include <stdio.h>
void printSparseMatrix(int sparse[][3], int size) {
printf("Sparse Matrix Representation:\n");
printf("Row\tColumn\tValue\n");
for (int i = 0; i < size; i++) {
printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
}
}
int main() {
int rows, cols;
printf("Enter number of rows and columns: ");
scanf("%d %d", &rows, &cols);
int matrix[rows][cols];
printf("Enter the elements of matrix:\n");
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
scanf("%d", &matrix[i][j]);
}
}
int non_zero = 0;
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
if (matrix[i][j] != 0) {
non_zero++;
}
}
}
int sparse[non_zero][3], k = 0;
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
if (matrix[i][j] != 0) {
sparse[k][0] = i;
sparse[k][1] = j;
sparse[k][2] = matrix[i][j];
k++;
}
}
}
printSparseMatrix(sparse, non_zero);
return 0;
}