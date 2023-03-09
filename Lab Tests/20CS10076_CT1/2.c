#include <stdio.h> 


int main() {
    int N;
    printf("Enter N:");
    scanf("%d",&N);
    while(N<=0) {
        printf("Invalid N. Enter proper value of N:");
        scanf("%d",&N);
    }
    
    int max_pos;int max;
    int min_pos;int min;
    int array[N];
    min=array[0];
    min_pos=0;
    for (int i=0;i<N;i++) {
        printf("Enter number %d:",i+1);
        scanf("%d",&array[i]);
    }
    
    for (int i=1;i<N;i++) {
        if (array[i]<min) {
            min=array[i];
            min_pos=i;
        }

    }
    max=array[0];
    max_pos=0;
    for (int i=1;i<N;i++) {
        if (array[i]>max) {
            max=array[i];
            max_pos=i;
        }

    }
    printf("Max=%d,position of max=%d\n",max,max_pos);
    printf("Min=%d,position of min=%d\n",min,min_pos);
    for (int i=0;i<min_pos;i++) {
        int temp=array[i];
        array[i]=array[min_pos];
        array[min_pos]=temp;
    }
    for (int i=max_pos+1;i<N;i++) {
        int temp=array[i];
        array[i]=array[max_pos];
        array[max_pos]=temp;
    }
    for (int i=0;i<N;i++) {
        printf("%d ",array[i]);

    }
}