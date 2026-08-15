#include<stdio.h>
int main(){
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

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
            int temp= arr[j];
            arr[j]= arr[j+1];
            arr[j+1]=temp;
            }
        }
    }
    
    int result=arr[k-1];
    printf("%dth smallest element in the array is: %d \n",k,result);

    return 0;
}
