#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Enter size of list:");
    scanf("%d",&n);
    int *p =(int*) malloc(n*sizeof(int));
    printf("Enter the integers in the list.\n");
    for (int i=0;i<n;i++) {
        
        printf("Enter number %d:",i+1);
        scanf("%d",p+i);
    }
    printf("The numbers in the list are: ");
    for (int i=0;i<n;i++) {
        printf("%d ",*(p+i));
    }
    printf("\n");
    int m;
    printf("Enter new size of list:");
    scanf("%d",&m);

    p=(int*) realloc(p,m);
    if (m>n) {   // inputting and storing additional numbers if size of list is increased
        printf("Enter the %d additional numbers.\n",m-n);
        for (int i=n;i<m;i++) {
            printf("Enter number %d:",i-n+1);
            scanf("%d",p+i);
        }
    }
    printf("The numbers in the list are: ");
    for (int i=0;i<m;i++) {
        printf("%d ",*(p+i));
    }
    printf("\n");
    free(p);
    
}