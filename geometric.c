#include<stdio.h>

//1st approach-Time Complexity O(n)
long long sum1(int x,int n){
    long long total_sum = 1;
    long long current_term = 1;
    for(int i=0;i<n;i++){
        current_term *= x;
        total_sum += current_term;
    }
    return total_sum;
}

long long power(long long x,int power){
    long long result = 1;
    while(power>0){
        if(power%2==1){
            result *= x;
        }
        x *= x;
        power /=2;
    }
    return result;
}

//2nd approach-Time Complexity O(logn)
long long sum2(int x,int n){
    if(x==1){
        return n+1;
    }
    long long numerator= power(x,n+1)-1;
    return numerator/(x-1);
}

int main(){
    int x,n,choice,Sum;
    printf("Enter the value of x: \n");
    scanf("%d",&x);
    printf("Enter the value of n: \n");
    scanf("%d",&n);

    printf("1.Sum1: - O(n) \n2.Sum2: - O(logn) \n");
    scanf("%d",&choice);
    
    switch(choice){
        case 1: Sum=sum1(x,n);
                printf("Sum of the series is %d \n",Sum);
                break;
        case 2: Sum=sum2(x,n);
                 printf("Sum of the series is %d \n",Sum);
                break;
    }
    return 0;
}
    












