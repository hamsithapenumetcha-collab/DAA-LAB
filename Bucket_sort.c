#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node* next;
};

struct Node* insertionSort(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* sorted = NULL;
    struct Node* current = head;

    while (current != NULL) {
        struct Node* next = current->next;
        
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}

void bucketSort(float arr[], int n) {
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        int bucketIndex = (int)(n * arr[i]);
        
        if (bucketIndex >= n) {
            bucketIndex = n - 1;
        }

        newNode->next = buckets[bucketIndex];
        buckets[bucketIndex] = newNode;
    }

    int arrIndex = 0;
    for (int i = 0; i < n; i++) {
        buckets[i] = insertionSort(buckets[i]);
        
        struct Node* temp = buckets[i];
        while (temp != NULL) {
            arr[arrIndex++] = temp->data;
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(buckets);
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    float* arr = (float*)malloc(n * sizeof(float));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d numbers between 0.0 and 1.0 (e.g., 0.23, 0.89):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted array: \n");
    printArray(arr, n);

    free(arr);

    return 0;
}
