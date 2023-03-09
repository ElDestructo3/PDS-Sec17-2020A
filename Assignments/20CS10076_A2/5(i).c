#include <stdio.h>

int main()

{
// (i) using temporary variable
int x,y ;
printf("Enter 2 numbers:\n");
scanf("%d %d",&x,&y);
int num;
num = x;
x=y;
y=num;
printf("the numbers when swapped are %d and %d",x,y);







}
