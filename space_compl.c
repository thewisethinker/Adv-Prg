#include <stdio.h>
#include <stdlib.h>

int constantSpaceSum(int arr[], int n, size_t *auxMem) {
    int sum = 0;
    int i;

    *auxMem = 0;

    for (i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}

int linearSpaceCopy(int arr[], int n, size_t *auxMem) {
    int *copy = (int *)malloc(n * sizeof(int));
    int sum = 0;
    int i;

    if (!copy) return -1;

    *auxMem = n * sizeof(int);

    for (i = 0; i < n; i++)
        copy[i] = arr[i];

    for (i = 0; i < n; i++)
        sum += copy[i];

    free(copy);
    return sum;
}

int quadraticSpaceMatrix(int n, size_t *auxMem) {
    int **matrix;
    int i, j, count = 0;

    matrix = (int **)malloc(n * sizeof(int *));
    if (!matrix) return -1;

    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        if (!matrix[i]) return -1;
    }

    *auxMem = (n * sizeof(int *)) + (n * n * sizeof(int));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            matrix[i][j] = count++;

    for (i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);

    return count;
}

int main() {
    int n = 10000;
    int *arr;
    size_t auxMem;

    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = i;

    printf("Constant Space Result: %d\n",
           constantSpaceSum(arr, n, &auxMem));
    printf("Auxiliary Memory Used: %zu bytes\n", auxMem);
    printf("Auxiliary Space Complexity: O(1)\n\n");

    printf("Linear Space Result: %d\n",
           linearSpaceCopy(arr, n, &auxMem));
    printf("Auxiliary Memory Used: %zu bytes\n", auxMem);
    printf("Auxiliary Space Complexity: O(n)\n\n");

    quadraticSpaceMatrix(1000, &auxMem);
    printf("Quadratic Space Done (n = 1000)\n");
    printf("Auxiliary Memory Used: %zu bytes\n", auxMem);
    printf("Auxiliary Space Complexity: O(n^2)\n");

    free(arr);
    return 0;
}
