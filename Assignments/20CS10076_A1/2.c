#include <stdio.h>

int main() {
  float celsius,fahrenheit;
  printf("Enter your city temperature in Fahrenheit: ");
  scanf("%f",&fahrenheit);
  celsius= (fahrenheit-32)* 5/9 ;

  float kelvin = celsius+273.15;

  printf("The temperature in Celsius is %f and in Kelvin is %f.",celsius, kelvin);
  return 0;




}
