#include<stdio.h>

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low,int high,int pivot){
    int i=low+1;
    int j=high;

    while(i<j){
        while(pivot>arr[i]){
            i++;
        }
        while(pivot<arr[j]){
            j--;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}


void quicksort(int arr[],int low,int high){
    int pivot=arr[low];
    if(low<high){
        int pi=partition(arr,low,high,pivot);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main(){
    int size;
    printf("Enter the size of array: ");
    scanf("%d",&size);

    int arr[size];
    printf("Enter the array elements: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    quicksort(arr,0,size-1);
    
    printf("Sorted array: \n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}