#include <stdio.h>
#include <stdlib.h>

void print_arr(int* arr, int size) {
    for (int i=0;i<size;i++) {
        printf("%d ",arr[i]);
    }

}
void merge(int* arr1,int*arr2, int* arr3,int m,int n) {
    if ((m==0)&&(n>0)) {
        *arr3=*arr2;
        merge(arr1,arr2+1,arr3+1,m,n-1);
    }
    else if ((m==0)&&(n==0)) {
        return;
    }
    else if ((m>0)&&(n==0)) {
        *arr3=*arr1;
        merge(arr1+1,arr2,arr3+1,m-1,n);
    }
    else {
        if (*arr1>*arr2) {
            *arr3=*arr2;
            merge(arr1,arr2+1,arr3+1,m,n-1);
        }
        else  {
            *arr3=*arr1;
            merge(arr1+1,arr2,arr3+1,m-1,n);
        }
    }
}

int main() {
    int m,n;
    
    printf("Enter a value of m for size of first sorted array:");
    scanf("%d",&m);
    int *arr1=(int*) malloc(m*sizeof(int));
    for (int i=0;i<m;i++) {
        printf("Enter element number %d:",i+1);
        scanf("%d",&arr1[i]);
    }

    printf("Enter a value of n for size of second sorted array:");
    scanf("%d",&n);
    int *arr2=(int*) malloc(n*sizeof(int));
    for (int i=0;i<n;i++) {
        printf("Enter element number %d:",i+1);
        scanf("%d",&arr2[i]);
    }
    
    printf("The first sorted array entered is:");
    print_arr(arr1,m);
    printf("\n");

    printf("The second sorted array entered is:");
    print_arr(arr2,n);
    int *arr3=(int*) malloc((m+n)*sizeof(int));

    merge(arr1,arr2,arr3,m,n);
    printf("\nThe eleemnts of the merged sorted array is:");

    print_arr(arr3,m+n);

}