#include <stdio.h>

int main()
{
  int length,breadth,radius,area1,perimeter1 ;
  float area2,perimeter2;
  printf("Enter length of rectangle:");
  scanf("%d",&length);
  printf("Enter breadth of rectangle:");
  scanf("%d", &breadth);
  printf("Enter radius of circle:");
  scanf("%d",&radius);
  area1 = length*breadth ;
  area2 = 3.14*radius*radius;
  perimeter1 = 2*(length + breadth);
  perimeter2 = 2*3.14*radius;
  printf("Area of rectangle is %d, and its perimeter is %d\n",area1, perimeter1);
  printf("Area of circle is %f, and its perimeter is %f\n",area2, perimeter2);


}
