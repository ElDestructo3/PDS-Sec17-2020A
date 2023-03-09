#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int colour;
    int age;
} house ;
int find_correct_house(house** grid,int n) {
    int num=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (grid[i][j].colour==0) {
                int k,l,m,o;             // setting k and l to be the row indices before and after the row containing the house
                                         // setting m and o to be the column indices before and after the column containing the house
                if (i==0) {              // if else statement to check for border cases and reduce the range appropriately
                    k=0;
                }
                else {
                    k=i-1;
                }
                if (i==n-1) {
                    l=i;
                }
                else {
                    l=i+1;
                }
                if (j==0) {
                    m=0;
                }
                else {
                    m=j-1;
                }
                if (j==n-1) {
                    o=0;
                }
                else {
                    o=j+1;
                }
                int temp=0;
                for (int a=k;a<=l;a++) {
                    for (int b=m;b<=o;b++) {
                        if (grid[a][b].colour==1) {
                            temp++;
                        }
                    }
                }
                if (temp>1) {
                    num++;
                }
            }
        }
    }
    return num;
}

int main() {
    printf("Enter the value of N for dimension of array:");
    int N;
    scanf("%d",&N);
    house **arr = (house**) malloc(N*sizeof(house*));
    for (int i=0;i<N;i++) {
        arr[i]= (house*) malloc(N*sizeof(house));
    }
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            printf("Enter colour of house at index (%d,%d) (1 for orange,0 for blue and -1 if no house is present):",i,j);
            scanf("%d",&(arr[i][j].colour));
            if (arr[i][j].colour==-1) {
                arr[i][j].age=0;
            }
            else {
                printf("Enter the age of the house:");
                scanf("%d",&(arr[i][j].age));
            }
            
        }
    }
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            printf("%2d ",arr[i][j].colour);
        }
        printf("\n");
    }
    int ans=find_correct_house(arr,N);
    printf("The number of houses satisfying the asked property is :%d",ans);
    for (int i=0;i<N;i++) {
        free(arr[i]);
    }
    free(arr);
}
