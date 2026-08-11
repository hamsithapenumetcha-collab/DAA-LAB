#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; 
        }
        if (arr[mid] < target) {
            low = mid + 1; 
        } else {
            high = mid - 1;
        }
    }
    return -1; 
}

int main() {
    int size, target, choice, result = -1;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size]; 

    printf("Enter %d integers \n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nEnter the number to search for: ");
    scanf("%d", &target);

    printf("\n1. Linear Search\n2. Binary Search\n: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = linearSearch(arr, size, target);
            break;
        case 2:
            result = binarySearch(arr, size, target);
            break;
        default:
            printf("Invalid choice! Program exiting.\n");
            return 1;
    }

    if (result != -1) {
        printf("\nSuccess: Element found at index %d.\n", result);
    } else {
        printf("\nResult: Element not found in the array.\n");
    }

    return 0;
}
