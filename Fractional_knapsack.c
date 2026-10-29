#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int V[n + 1][W + 1];
    
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                V[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                V[i][w] = max(val[i - 1] + V[i - 1][w - wt[i - 1]], V[i - 1][w]);
            } else {
                V[i][w] = V[i - 1][w];
            }
        }
    }
    return V[n][W];
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];

    printf("Enter the values of the %d items:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &val[i]);
    }

    printf("\nEnter the weights of the %d items:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &wt[i]);
    }

    printf("\nEnter the maximum capacity of the knapsack: ");
    scanf("%d", &W);

    printf("\nMaximum value that can be obtained: %d\n", knapsack(W, wt, val, n));

    return 0;
}
