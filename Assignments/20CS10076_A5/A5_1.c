#include <stdio.h>
int perfect_num(int n) {
    int sum=0;
    if (n==1) {
        return 0;
    }
    else {
        for (int i=1;i<n;i++) {
            if (n%i==0) {
                sum=sum+i;
            }

        }
        if (sum==n) {
            return 1;
        }
        else {
            return 0;
        }

    }


}
void print_perfect(int p, int q) {
    for (int i=p;i<=q;i++) {
        if (perfect_num(i)==1) {
            printf("%d is perfect number\n",i);
        }

        
    }

}
int main() {
    int a=0;
    int b=0;
    printf("Enter lower bound for range of printing perfect number:");
    scanf("%d",&a);
    printf("Enter upper bound for range of printing perfect number:");
    scanf("%d",&b);
    print_perfect(a,b);
    int num;
    scanf("%d",&num);
    printf("%d\n",num);

    return 0;

}
