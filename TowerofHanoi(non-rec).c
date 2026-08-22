#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Stack {
    int capacity;
    int top;
    int *array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack) {
    return (stack->top == stack->capacity - 1);
}

int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

void push(struct Stack* stack, int item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top--];
}

void moveDisksBetweenTwoPoles(struct Stack *src, struct Stack *dest, char s, char d) {
    int pole1TopDisk = pop(src);
    int pole2TopDisk = pop(dest);

    // When pole 1 is empty
    if (pole1TopDisk == -1) {
        push(src, pole2TopDisk);
        printf("Move disk %d from '%c' to '%c'\n", pole2TopDisk, d, s);
    }
    // When pole 2 is empty
    else if (pole2TopDisk == -1) {
        push(dest, pole1TopDisk);
        printf("Move disk %d from '%c' to '%c'\n", pole1TopDisk, s, d);
    }
    // When top disk of pole1 is smaller than top disk of pole2
    else if (pole1TopDisk < pole2TopDisk) {
        push(dest, pole2TopDisk);
        push(dest, pole1TopDisk);
        printf("Move disk %d from '%c' to '%c'\n", pole1TopDisk, s, d);
    }
    // When top disk of pole1 is greater than top disk of pole2
    else {
        push(src, pole1TopDisk);
        push(src, pole2TopDisk);
        printf("Move disk %d from '%c' to '%c'\n", pole2TopDisk, d, s);
    }
}

void iterativeHanoi(int num_of_disks, struct Stack *src, struct Stack *aux, struct Stack *dest) {
    int i, total_num_of_moves;
    char s = 'A', a = 'B', d = 'C';

    if (num_of_disks % 2 == 0) {
        char temp = d;
        d = a;
        a = temp;
    }
    total_num_of_moves = pow(2, num_of_disks) - 1;

    for (i = num_of_disks; i >= 1; i--) {
        push(src, i);
    }

    for (i = 1; i <= total_num_of_moves; i++) {
        if (i % 3 == 1) {
            moveDisksBetweenTwoPoles(src, dest, s, d);
        } else if (i % 3 == 2) {
            moveDisksBetweenTwoPoles(src, aux, s, a);
        } else if (i % 3 == 0) {
            moveDisksBetweenTwoPoles(aux, dest, a, d);
        }
    }
}

int main() {
    int num_of_disks;
    
    printf("Enter the number of disks: ");
    if (scanf("%d", &num_of_disks) != 1 || num_of_disks <= 0) {
        printf("Please enter a valid positive number.\n");
        return 1;
    }

    struct Stack *src = createStack(num_of_disks);
    struct Stack *aux = createStack(num_of_disks);
    struct Stack *dest = createStack(num_of_disks);

    iterativeHanoi(num_of_disks, src, aux, dest);

    free(src->array); free(src);
    free(aux->array); free(aux);
    free(dest->array); free(dest);

    return 0;
}
