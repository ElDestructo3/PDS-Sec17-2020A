#include <stdio.h>
int factorial(int n) {
    if ((n==1)||(n==0)) {
        return 1;
    }
    else {
        return n*factorial(n-1);
    }
}
float power(float a,int b) {
    if (b==0) {
        return 1.000000;
    }
    if (b==1) {
        return a;
    }
    else {
        return a*power(a,b-1);
    }
}
float my_cos(int a,float b) {
    static float sum=0.0;
    
    static int count=0;
    if (a==0) {
        return sum;
    }
    else {
        float term=power(-1,count)*((power(b,2*count))/factorial(2*count));
        
        sum+=term;
        count++;
       
        return my_cos(a-1,b);

    }
}

int main() {
    float x;
    const float pi=3.141592;
    int term_count;
    printf("Enter value of x in degrees to compute cos x:");
    scanf("%f",&x);
    printf("Enter the number of terms upto which you wish to calculate the value:");
    scanf("%d",&term_count);
    if (x<0.0) {
        
    }
    float value;
    while(x>360) {
        x=x-360;
    }
    if (x<90) {
        value=my_cos(term_count,x*(pi/180));
        printf("The value of cos x is %f",value);
    }
    else if ((x>90)&&(x<180)) {
        value=-my_cos(term_count,(180-x)*(pi/180));
        printf("The value of cos x is %f",value);
    }
    else if ((x>180)&&(x<270)) {
        value=-my_cos(term_count,(x-180)*(pi/180));
        printf("The value of cos x is %f",value);
    }
    else {
        value= my_cos(term_count,(360-x)*(pi/180));
        printf("The value of cos x is %f",value);
    }
   
}