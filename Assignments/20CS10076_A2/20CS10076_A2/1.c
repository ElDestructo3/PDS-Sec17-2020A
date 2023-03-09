#include <stdio.h>

int main()
{
int days,weeks,years,day2;
printf("Enter number of days of movie:");
scanf("%d",&days);

int num1,num2;
num1= days%365;
years = (days-num1)/365 ;

num2= num1%7;
weeks = (num1-num2)/7 ;



printf("%d years, %d weeks and %d days",years,weeks,num2);







}
