#include <stdio.h>
#include <math.h>
void int_to_bin(int a,int b[]) {
    int count=0;
    int temp1=a;
    int temp2=a;
    while (temp1!=0){
        temp1=temp1/2;
        count++;
    }
   
    
    printf("%d in binary is :",temp2);
    for (int i=15;i>=16-count;i--)
     {
        b[i]=a%2;
        a=a/2;
        
    }
    for (int i=0;i<16;i++) {
        printf("%d",b[i]);
    }
    printf("\n");

}
void xor(int x[],int a[],int b[]) {
    for (int i=0;i<16;i++) {
        x[i]=a[i]^b[i];
    }
}
int bin_to_int(int y[]) {
    int num=0;
    for (int i=0;i<16;i++){
        num=num+y[i]*pow(2,15-i);

    }
    return num;
}
int main() {
    int i1,i2;
    printf("Enter number 1:");
    scanf("%d",&i1);
    printf("Enter number 2:");
    scanf("%d",&i2);
    int b1[16]={0},b2[16]={0};
    int x[16]={0};
    int_to_bin(i1,b1);
    int_to_bin(i2,b2);
    xor(x,b1,b2);
    printf("X=%d",bin_to_int(x));

}

