#include <stdio.h>
void generator(int x,char a,char b,int array[]) {
    if (x%2==0) {
        
        for (int i=0;i<x/2;i++) {
            printf("%c",a);
        }
        for (int i=0;i<x/2;i++) {
            printf("%c",b);
        }
        printf("\n");

    }
    else {
        for (int i=0;i<(x+1)/2;i++) {
            printf("%c",a);
        }
        for (int i=0;i<(x-1)/2;i++) {
            printf("%c",b);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter a positive integral value of n for array size:");
    scanf("%d",&n);
    int array[n];
    for (int i=0;i<n;i++) {
        printf("Enter value %d:",i+1);
        scanf("%d",&array[i]);
    }
    char extra;
    char c1;
    char c2;
    printf("Enter the characters: "); 
    scanf(" %c,%c",&c1,&c2);
    
    for (int i=0;i<n;i++) {
        generator(array[i],c1,c2,array);
    }

    
    
}