#include<stdio.h>
#define SIZE 10

int hashTable[SIZE];

void initialize()
{
    int i;
    for(i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int key)
{
    int index = key % SIZE;
    int start = index;

    while(hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;

        if(index == start)
        {
            printf("Hash table is full!\n");
            return;
        }
    }

    hashTable[index] = key;
}

void display()
{
    int i;

    printf("\nHash Table:\n");
    for(i = 0; i < SIZE; i++)
    {
        if(hashTable[i] == -1)
            printf("%d : Empty\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}

int main()
{
    int n, key, i;

    initialize();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}