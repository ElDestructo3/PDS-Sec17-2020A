#include <stdio.h>

int main() {
  int a,b,c,d,e;
  printf("Enter a number\n");
  scanf("%d", &a);
  printf("Enter a number\n");
  scanf("%d", &b);
  printf("Enter a number\n");
  scanf("%d", &c);
  printf("Enter a number\n");
  scanf("%d", &d);
  printf("Enter a number\n");
  scanf("%d", &e);

  float avg = (a+b+c+d+e)/5 ;
  printf("The average is %f", avg);
  return 0;


}
