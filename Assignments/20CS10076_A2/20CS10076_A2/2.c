#include <stdio.h>

int main()
{
int num;
printf("Enter a 4-digit number:\n");
scanf("%d",&num);



int digit1= num%10;
int num_left1= (num-digit1)/10;

int digit2 = num_left1%10;
int num_left2 = (num_left1-digit2)/10;

int digit3 = num_left2%10;
int digit4 = (num_left2-digit3)/10 ;

int reversed_number= digit4 + digit3*10 + digit2*100 + digit1*1000;
printf("Reversed number is :%d\n",reversed_number);

int subtract,difference;
subtract = num-reversed_number;

if (subtract>0) {
    difference = subtract;
    printf("Difference is %d\n", difference);
}
else {
    difference= -subtract;
    printf("Difference is %d\n",difference);

}





}
