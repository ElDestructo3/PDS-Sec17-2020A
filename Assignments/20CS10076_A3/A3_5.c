#include <stdio.h>

int main() {
    int count=0;
    for (int i=0;;i++) {
        int digit_1= i%10;
        int digit_2= ((i-digit_1)/10)%10 ;
        int digit_3 = ((i-digit_2*10-digit_1)/100)%10 ;
        int digit_4 = ((i-digit_3*100-digit_2*10-digit_1)/1000)%10 ;
        int sum_digit=digit_1*digit_1*digit_1+digit_2*digit_2*digit_2 + digit_3*digit_3*digit_3+digit_4*digit_4*digit_4;
        if (i==sum_digit ) {
            count++;
            printf("%d\n",i);
        }
        if (count==5) {
            break;
        }
        
        
    }
}