#include <stdio.h>
// (ii) using arithmetic operator and not temporary variable
int main()
{
int x,y ;
printf("Enter 2 numbers:\n");
scanf("%d %d",&x,&y);
x = x+y -(y=x);
printf("%d and %d",x,y);




}
