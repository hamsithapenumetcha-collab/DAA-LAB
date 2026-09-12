#include<stdio.h>

struct pair{
    int min;
    int max;
};

struct pair Minmax(int arr[],int low,int high){
 struct pair result;
 struct pair left, right;


 int mid=(low+high)/2;
 if(low==high){
    result.min=arr[low];
    result.max=arr[high];
    return result;
 }

 left=Minmax(arr,low,mid);
 right=Minmax(arr,mid+1,high);

 result.min=((left.min<right.min)?left.min:right.min);
 result.max=((left.max>right.max)?left.max:right.max);

 return result;
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

    struct pair result=Minmax(arr,0,size-1);

    printf("Minimum element is:%d\n",result.min);
    printf("Maximum element is:%d\n",result.max);

    return 0;
}




