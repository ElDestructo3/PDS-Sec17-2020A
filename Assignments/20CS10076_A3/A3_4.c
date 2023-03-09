#include <stdio.h>

int main() {
    int n;
    int max;
    int second_max;
    printf("Enter a number more than 1 :");
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        if (i<1) {
            printf("Enter a distinct number %d:",i+1);
            scanf("%d",&max);
            continue;
        }
            int temp; 
            printf("Enter a distinct number %d:",i+1);
            scanf("%d",&temp);
            if ((temp<max)&&(temp>second_max)) {
                second_max=temp;

            }
            else if (temp>max) {
                second_max=max;
                max=temp;

            }
            else {
                continue;
            }

            
        
        

    }
    printf("%d",second_max);
    
}