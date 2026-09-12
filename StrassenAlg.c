#include <stdio.h>

int main()
{
    int A[2][2], B[2][2], C[2][2];
    int p1, p2, p3, p4, p5, p6, p7;

    printf("Enter Matrix A:\n");
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            scanf("%d", &B[i][j]);

    p1 = A[0][0] * (B[0][1] - B[1][1]);
    p2 = (A[0][0] + A[0][1]) * B[1][1];
    p3 = (A[1][0] + A[1][1]) * B[0][0];
    p4 = A[1][1] * (B[1][0] - B[0][0]);
    p5 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    p6 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
    p7 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);

    C[0][0] = p5 + p4 - p2 + p6;
    C[0][1] = p1 + p2;
    C[1][0] = p3 + p4;
    C[1][1] = p5 + p1 - p3 - p7;

    printf("Result:\n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}