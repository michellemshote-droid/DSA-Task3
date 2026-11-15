// Program to represent a sparse matrix using arrays.
#include <stdio.h>

int main() {
    int matrix[10][10];
    int sparse[100][3];

    int rows, cols;
    int k = 1;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter matrix elements:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Store matrix information
    sparse[0][0] = rows;
    sparse[0][1] = cols;

    // Store non-zero elements
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

    sparse[0][2] = k - 1;

    printf("\nSparse Matrix Representation:\n");
    printf("Row  Column  Value\n");

    for (int i = 0; i < k; i++) {
        printf("%d      %d       %d\n",
               sparse[i][0],
               sparse[i][1],
               sparse[i][2]);
    }

    return 0;
}
