#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right]; // Selecting the last element as pivot
    int i = left;
    
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[right]);
    return i;
}

int quick_select(int arr[], int left, int right, int k) {
    if (k > 0 && k <= right - left + 1) {  
        
        int pivot_index = partition(arr, left, right);
        
       
        if (pivot_index - left == k - 1) {
            return arr[pivot_index];
        }
        
        if (pivot_index - left > k - 1) {
            return quick_select(arr, left, pivot_index - 1, k);
        }
        
        return quick_select(arr, pivot_index + 1, right, k - (pivot_index - left + 1));
    }
    
    return -1; 
}

int main() {
    int n,k;
    printf("Enter the size of array: \n");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the array elements: \n");
    
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d",&k);

    if (k < 1 || k > n) {
        printf("Invalid value of K! K must be between 1 and %d.\n", n);
        return 1;
    }
    
    int result = quick_select(arr, 0, n - 1, k);

    if (result != -1) {
        printf("\nThe %dth smallest element in the array is: %d\n", k, result);
    }

    return 0;
}
