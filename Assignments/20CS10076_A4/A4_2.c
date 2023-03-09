#include <stdio.h> 

int main() {
    int n;
    
    printf("Enter a value of n:");
    scanf("%d",&n);
    int array[n+3];
    for (int i=0;i<n+3;i++) {
        printf("Enter number %d:",i+1);
        scanf("%d",&array[i]);
    }
    int repeated_value=0;
    int count=0;
    for (int i=0;i<n+3;i++) {
        for (int j=i+1;j<n+3;j++) {
            if (array[i]==array[j]) {
                repeated_value=array[i];
                
            }
        }

        
    }
    printf("Repeated value is %d\n",repeated_value);
    for (int i=0;i<n+3;i++) {
        if (array[i]==repeated_value) {
            count=i;
            break;
        }
    }
    printf("Values before first occurence of repeated number is:\n");
    for (int i=0;i<count;i++) {
        printf("%d\n",array[i]);
    }
    



}