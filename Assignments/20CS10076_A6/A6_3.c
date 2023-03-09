#include <stdio.h>
int a=0,b=0;
void int_to_bin(int number,int array[]) {
    static int n=15;
    if ((number==0)||(number==1)) {
        array[n--]=number;
        a=15-n;
        return;
    }
    else {
        int_to_bin(number%2,array);
        int_to_bin(number/2,array);
    }
    
    

}
void frac_to_bin(float number,int array[]) {
    static int m=0;
    if (number==0) {
        b=m;
        return;
    }
    else if (number==0.5) {
        array[m++]=1;
        
        frac_to_bin(2*number,array);
    }
    else if (number==1) {
        b=m;
        return;
    }
    else if (number>0.5) {
        array[m++]=1;
        
        frac_to_bin(2*number-1,array);
    }
    else if (number<0.5) {
        m++;
        
        frac_to_bin(2*number,array);
    }
    
    
}

int main() {
    int integral;
    float frac,num;
    int int_array[16]={0},frac_array[16]={0};
    printf("Enter the number for which the binary equivalent has to be obtained:");
    scanf("%f",&num);
    integral=num;
    frac=num-integral;
    int_to_bin(integral,int_array);
    frac_to_bin(frac,frac_array);
    for (int i = 16-a; i < 16; i++)
    {
        printf("%d",int_array[i]);
    } 
    
    printf(".");
    for (int i = 0; i < b; i++)
    {
        printf("%d",frac_array[i]);
    } 
    

    
}