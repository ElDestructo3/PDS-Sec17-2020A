#include <stdio.h>

int main() 
{
    int total;
    for (int i=0;;i++) {
        int num;
        float avg;
        printf("Enter a number for the list and stop with -1:");

        scanf("%d",&num);
        if (num==-1) {
            break;
        }
        total= total+num;
        avg=(float)total/(i+1) ; 
        printf("Average after entering %d numbers is %f\n",i+1,avg);


    }
}