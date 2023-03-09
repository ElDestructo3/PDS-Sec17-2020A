#include <stdio.h>

int main() {
    int sum;
    while(1) {
        int num;
        
        printf("Enter upto 10 positive number less than 100. Break the sequence with a negative number: ");
        scanf("%d",&num);
        if (num<0) {
            
            break;
        }
        else if (num>100) {
            continue;
        }
        else {
            sum=sum+num;
        }

    }
    printf("%d",sum);
}