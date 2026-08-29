#include<stdio.h>
#define SIZE 11

int hashTable[SIZE];

void initialise(){
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int key){
    int start = key % SIZE; 
    int index = start;
    int i = 1;
    
    while (hashTable[index] != -1){
        if (i >= SIZE) {
            printf("Hash table is full or element cannot be inserted!\n");
            return;
        }
        
        index = (start + i * i) % SIZE;
        i++;
    }
    hashTable[index] = key;
}

void display(){
    int i;
    printf("\nHASH TABLE\n");
    for(i = 0; i < SIZE; i++){
        if(hashTable[i] == -1)
            printf("%d : Empty\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}

int main(){
    int i, n, key;
    initialise();
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &key);
        insert(key);
    }
    
    display();
    return 0;
}
