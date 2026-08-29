#include <stdio.h>

#define SIZE 100

void initialise(int hash[])
{
    for (int i = 0; i < SIZE; i++)
        hash[i] = 0;
}

void insert(int hash[], int key)
{
    hash[key]++;
}

int search(int hash[], int key)
{
    return hash[key];
}

int main()
{
    int a[100], n;
    int hash[SIZE];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements (0 to 99):\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    initialise(hash);

    for (int i = 0; i < n; i++)
        insert(hash, a[i]);

    printf("\nElement\tFrequency\n");

    for (int i = 0; i < SIZE; i++)
    {
        if (search(hash, i) > 0)
            printf("%d\t%d\n", i, search(hash, i));
    }

    return 0;
}