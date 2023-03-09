#include <stdio.h>
#include <stdlib.h>

int main() {
    int m,n,k,l;
    
    printf("Enter the dimensions of the matrix separated by space:");
    scanf("%d %d",&m,&n);
    int ** M= (int**) malloc(m*sizeof(int*));
    for (int i=0;i<m;i++) {
        M[i]=(int *) malloc(n*sizeof(int));
    }

    printf("Enter the elements of matrix(0 or 1).");
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            printf("Enter element at index (%d,%d):",i,j);
            scanf("%d",&M[i][j]);
        }
    }
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            printf("%d ",M[i][j]);
            
        }
        printf("\n");
    } 
    printf("Enter the values of k and l separated by space for size of submatrix:");
    scanf("%d %d",&k,&l);

    int num_submatrix= (m-k+1)*(n-l+1);  // for choosing k consective rows out of m there are m-k+1 ways, similarly for columns
    int submatrix [k][l][num_submatrix];
    int count=0;
    for (int i=0;i<=m-k;i++) {
        for (int j=0;j<=n-l;j++) {
            for (int a=0;a<k;a++) {
                for (int b=0;b<l;b++) {
                    submatrix[a][b][count]= M[i+a][j+b];
                }
            }
            count++;
        }
    }
    printf("The sub matrices are: \n");
    for (int i=0;i<num_submatrix;i++) {
        printf("Sub-matrix S%d is:\n",i+1);
        for (int j=0;j<k;j++) {
            for (int p=0;p<l;p++) {
                printf("%d ",submatrix[j][p][i]);
            }
            printf("\n");
        }
        printf("\n");
    }
    int num_distances= (num_submatrix*(num_submatrix-1))/2 ;
    int hamming_distances[num_distances];
    int num_ham=0;
    for (int i=0;i<num_submatrix-1;i++) {
        for (int j=i+1;j<num_submatrix;j++) {
            int counter=0;
            for (int a=0;a<k;a++) {
                for (int b=0;b<l;b++) {
                    if (submatrix[a][b][i]!=submatrix[a][b][j]) {
                        counter++;
                    }
                }
            }
            printf("D(S%d,S%d)=%d\n",i+1,j+1,counter);
            hamming_distances[num_ham++]=counter;
        }
    }
    int min=100000,max=0;
    for (int i=0;i<num_distances;i++) {
        if (hamming_distances[i]>max) {
            max=hamming_distances[i];
        }
        if (hamming_distances[i]<min) {
            min=hamming_distances[i];
        }

    }
    for (int i=0;i<num_distances;i++) {
        if (hamming_distances[i]==max) {
            int temp1=(i+1)/(n-l+1) ;
            int temp2=((i+1)%(n-l+1));
            printf("D(S%d,S%d)=%d has max hamming distance.\n ",temp1+1,temp2+1,max);
        }
        if (hamming_distances[i]==min) {
            int temp1=(i+1)/(n-l+1) ;
            int temp2=((i+1)%(n-l+1));
            printf("D(S%d,S%d)=%d has min hamming distance.\n ",temp1+1,temp2+1,min);
        }

    }

    





}