#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

int board[MAX];
int solutionCount = 0;

void printSolution(int n) {
    solutionCount++;
    printf("Solution %d:\n", solutionCount);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                printf(" Q ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int row, int col) {
    for (int prevRow = 0; prevRow < row; prevRow++) {
        int prevCol = board[prevRow];
        if (prevCol == col || abs(prevRow - row) == abs(prevCol - col)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int row, int n) {
    if (row == n) {
        printSolution(n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;           
            solveNQueens(row + 1, n);  
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens (N): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX);
        return 1;
    }
    solveNQueens(0, n);

    if (solutionCount == 0) {
        printf("No solution exists for N = %d.\n", n);
    } else {
        printf("Total solutions found: %d\n", solutionCount);
    }

    return 0;
}
