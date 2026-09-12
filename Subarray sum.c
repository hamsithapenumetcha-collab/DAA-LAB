#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int max_of_three(int a, int b, int c) {
    return max(max(a, b), c);
}

int find_max_crossing_subarray(int arr[], int low, int mid, int high) {
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int j = mid + 1; j <= high; j++) {
        sum += arr[j];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    return left_sum + right_sum;
}

int find_max_subarray(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }

    int mid = low + (high - low) / 2;

    int left_sum = find_max_subarray(arr, low, mid);
    int right_sum = find_max_subarray(arr, mid + 1, high);
    int cross_sum = find_max_crossing_subarray(arr, low, mid, high);

    return max_of_three(left_sum, right_sum, cross_sum);
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_sum = find_max_subarray(arr, 0, n - 1);
    
    printf("\nThe maximum contiguous subarray sum is: %d\n", max_sum);
    
    return 0;
}
