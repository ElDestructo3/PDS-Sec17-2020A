#include <stdio.h>
// using neither temporary variable nor arithmetic operator
int main()
{
int x,y ;
printf("Enter 2 numbers:\n");
scanf("%d %d",&x,&y);

x= (x|y)^(y=x);
printf("%d and %d",x,y);




}
