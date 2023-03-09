#include <stdio.h>

int main() {
    int n;
    
    printf("Enter value of n:\n");
    scanf("%d",&n);
    int array[n];
    for (int i=0; i<n;i++) {
        printf("Enter number %d:",i+1);
        scanf("%d",&array[i]);
    }
    int k;
    printf("Enter k<%d for number of values to be deleted:",n);
    scanf("%d",&k);
    int shrinked_array[n-k];
    for (int i=0;i<n-k;i++) {
        shrinked_array[i]=array[i+k];
    }
    if (k>n) {
        printf("INVALID INPUT");
    }
    else {
    printf("Array after deletion is :\n");
    for (int i=0;i<n-k;i++) {
        printf("%d ",shrinked_array[i]);
    }
    int m;
    printf("\nEnter the number of values to be added at end of array:");
    scanf("%d",&m);
    int appended_array[n-k+m];
    for (int i=0;i<n-k;i++) {
        appended_array[i]=shrinked_array[i];
    }
    for (int i=0;i<m;i++) {
        printf("Enter value %d to be appended:",i+1);
        scanf("%d",&appended_array[n-k+i]);
    }
    printf("Array after initialization is :\n");
    for (int i=0;i<n-k+m;i++) {
        printf("%d ",appended_array[i]);
    }
    }

}