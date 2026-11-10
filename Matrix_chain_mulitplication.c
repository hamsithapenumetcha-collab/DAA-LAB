#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printOptimalParenthesis(int i, int j, int n, int *s) {
    if (i == j) {
        printf("A%d", i);
        return;
    }
    printf("(");

    printOptimalParenthesis(i, *((s + i * n) + j), n, s);
    printOptimalParenthesis(*((s + i * n) + j) + 1, j, n, s);
    printf(")");
}

void matrixChainOrder(int p[], int n) {
    // Dynamically allocating memory for 2D arrays dp and s
    int (*dp)[n] = malloc(sizeof(int[n][n]));
    int (*s)[n] = malloc(sizeof(int[n][n]));

    if (dp == NULL || s == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", dp[1][n - 1]);
    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(1, n - 1, n, (int *)s);
    printf("\n");

    free(dp);
    free(s);
}

int main() {
    int num_matrices;

    printf("Enter the number of matrices: ");
    if (scanf("%d", &num_matrices) != 1 || num_matrices < 1) {
        printf("Invalid number of matrices.\n");
        return 1;
    }

    int size = num_matrices + 1;
    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the dimensions array elements (%d elements):\n", size);
    printf("(e.g., for 3 matrices A1(10x20), A2(20x30), A3(30x40), enter: 10 20 30 40)\n");
    for (int i = 0; i < size; i++) {
        printf("Dimension [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    matrixChainOrder(arr, size);

    free(arr);

    return 0;
}
