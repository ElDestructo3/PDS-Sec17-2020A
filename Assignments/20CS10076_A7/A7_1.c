#include <stdio.h>
#define MAX 100
int array_num[MAX]={0};
void swap(int *x,int *y)
{
    int t;
     t   = *x;
    *x   = *y;
    *y   =  t;
}
int a=0;
int* input_array(int *arr,int *size) {
    
    
    
    for (a=0;a<MAX;a++) {
        int num=0;
        printf("Enter number %d:",a+1);
        scanf("%d",&num);
        if (num<0) {
            break;
        }
        else {
            arr[a]=num;
           
        }
    }
    size=&a;
    
    return size;
}
int* reverse_array(int* arr,int* size) {
    for (int i=0;i<(*size/2)+1;i++) {
        swap(&arr[i],&arr[*size-i-1]);
    }
    return size;

}
int* check_unique_array(int* arr,int* size) {
    int count=1;
    int *ptr;
    ptr=&count;
    for (int i=0;i<*size;i++) {
        for (int j=i+1;j<*size;j++) {
            if (arr[i]==arr[j]) {
                *ptr=0;
                break;
            }
        }
    }
    
    return ptr;
}

int main() {
    printf("Max size of array is = %d\n",MAX);
    printf("Enter upto 100 elements and end with negative number.\n");
    int *p;
    int *q=input_array(array_num,p);    
    printf("Length of the array=%d\n",*q);
    int *r;
    r=reverse_array(array_num,q);
    printf("%d\n",*q);
    printf("The array when reversed is =");
   
    for (int i=0;i<a;i++) {
        printf("%d, ",array_num[i]);
    }
    
    int *ptr;
    printf("\n");
    ptr=check_unique_array(array_num,q);
    if (*ptr==1) {
        printf("Elements are unique.");
    }
    else {
        printf("ELements are not unique.");
    }

   
    
}