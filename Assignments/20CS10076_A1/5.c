#include <stdio.h>

int main()
{
  int input,d1,d2,d3,d4;
  printf("Enter a four digit number:");
  scanf("%d",&input);
  d1 = input%10 ;
  d2 = ((input -d1)/10)%10 ;
  d3 = ((input-10*d2-d1)/100)%10;
  d4 = ((input-100*d3-10*d2)/1000)%10;
  int sum;
  sum = d1+d2+d3+d4;
  printf("Sum of digits is %d",sum);


}
