#include <stdio.h>

int main() {
    int P[100];
    int length=0;
    printf("Enter a length>=2 and less than 100:");
    if ((length<2)&&(length>100)) {
        printf("INVALID INPUT");
    }
    else {
        scanf("%d",&length);
        int L[5000];  //more than 100c2
        for (int i=0;i<length;i++) {
            printf("Enter number %d:\n",i+1);
            scanf("%d",&P[i]);
        }
        int k=0;
        printf("Possible groups: ");
        for (int i=0;i<length;i++) {
            for (int j=i+1;j<length;j++) {
                printf("(%d,%d),",P[i],P[j]);
                if (P[i]<P[j]) {
                    L[k]=P[j];
                    k++;                    
                }
                else {
                    L[k]=P[i];
                    k++;
                }
            }
        }
        printf("\nMaximum in each group is:");
        for (int i=0;i<k;i++) {
            printf("%d,",L[i]);
        }
        printf("\nGroups satisfying property are:");
        for (int m=0;m<length;m++) {
            for (int n=m+1;n<length;n++) {
                if (P[m]>P[n]) {
                    printf("(%d,%d),",P[m],P[n]);
                }
            }
        }

    }
    


}