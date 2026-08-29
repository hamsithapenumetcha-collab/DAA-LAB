#include <stdio.h>
#define SIZE 100
int hashTable[SIZE];

void initialize()
{
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key)
{
    if (key < 0)
        key = -key;

    return key % SIZE;
}

int search(int key)
{
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
            return 1;

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    return 0;
}

void insert(int key)
{
    int index = hashFunction(key);

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

int main()
{
    int n, T;
    int a[SIZE];

    initialize();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target value T: ");
    scanf("%d", &T);

    for (int i = 0; i < n; i++)
    {
        int required = T - a[i];

        if (search(required))
        {
            printf("Yes\n");
            printf("Pair: %d + %d = %d\n",
                   required, a[i], T);
            return 0;
        }

        insert(a[i]);
    }

    printf("No\n");

    return 0;
}