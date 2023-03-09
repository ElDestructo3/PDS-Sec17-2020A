#include <stdio.h>

int main()
{
  int profit,sale;
  printf("Enter total sales price:" );
  scanf("%d",&sale);
  printf("Enter total profit:");
  scanf("%d", &profit);
  float cost;
  cost = (sale-profit)/18 ;
  printf("Cost per item is %f",cost);
}
