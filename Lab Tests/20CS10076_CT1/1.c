#include <stdio.h>

int main() {
    float sin=0;
    float term;
    float sum=0;
    int count=0;

    printf("Enter a value of x for which the approximate value of sin x has to be calculated:");
    scanf("%f",&term);
    float x=term;
    for (int i=0;;i++) {
        
        sum=sum+term;
        
        if ((term<1e-5)&&(term>-1e-5)) {
            count=i+1;
            break;
        }
        printf("Term to be added is %f\n",term);
        
        
            
            
            if ((i%2==0)&&(term<0)) {
                term=-term;
            }
            if ((i%2!=0)&&(term>0)) {
                term=-term;
            }
            
            term= (-1)* (term)*(x/(2*i+2))*(x/(2*i+3)) ;
             
            
        
        
        
        
    }
    printf("Approx value of sinx is %f",sum);
    printf("\nThe number of terms considered is %d",count-1);




}