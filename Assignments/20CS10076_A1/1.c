#include <stdio.h>

int main()
{
float salary;
printf("Enter Gautam Gambhir's salary: \n");
scanf("%f",&salary);
float dearness = 0.4*salary;
float rent = 0.2*salary;
float gross = salary - dearness - rent;
printf("Gambhir's gross salary is %f", gross);
return 0;
}
