#include <stdio.h>
int absolute(int a,int b) {
    if (a>b){
        return a-b;
    }
    else {
        return b-a;
    }
}
void print_abs(int arr[],int arrSize) {
    static int i=0;
    printf("The absolute difference of %d and %d is: %d.\n",arr[i],arr[i+1],absolute(arr[i],arr[i+1]));
    i++;
    if (i==arrSize-1) {
        return;
    }
    print_abs(arr,arrSize);
}
int main() {
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);
    int array[n];
    for (int i=0;i<n;i++) {
        printf("Enter element %d:",i+1);
        scanf("%d",&array[i]);
    }
    print_abs(array,n);
}