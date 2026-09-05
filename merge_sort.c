#include<stdio.h>

void merge(int arr[],int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=low;
    int b[20];

    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            b[k]=arr[i];
            i++; k++;
        }
        else{
            b[k]=arr[j];
            j++; k++;
        }
    }
    if(i>mid){
        while(j<=high){
            b[k]=arr[j];
            j++; k++;
        }
    }
    if(j>high){
        while(i<=mid){
            b[k]=arr[i];
            i++; k++;
        }
    }
    for(i=low;i<=high;i++){
        arr[i]=b[i];
    }

}

void mergesort(int arr[],int low,int high){
    int mid=(low+high)/2;
    if(low<high){
       mergesort(arr,low,mid);
       mergesort(arr,mid+1,high);
       merge(arr,low,mid,high);
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

    mergesort(arr,0,size-1);
    
    printf("Sorted array: \n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

    return 0;

}
