#include <stdio.h>
#include <stdlib.h>
int ** read_matrix(int rows,int columns, int**arr) {  //reads all elements of matrix
    for (int i=0;i<rows;i++) {
        for (int j=0;j<columns;j++) {
            printf("Enter the element of index (%d,%d):",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    return arr;
}
void sort_rows(int* arr,int size) { //takes each row of matrix as input and sorts in ascending order
    
   for (int i=0; i<size-1;i++) {   
        for (int j=0; j<size-i-1;j++) {
            if (arr[j]>arr[j+1]){ 
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp; 
           }
       }
   }
}

void print_matrix(int**matrix,int rows,int columns) {  // prints all the elements of the matrix
    for (int i=0;i<rows;i++) {
        for (int j=0;j<columns;j++) {
            printf("%d ",*(*(matrix+i)+j));
        }
        printf("\n");
    }
}
int binarySearch(int *arr, int l, int h, int key) {   // Binary Sort algorithm
    while (l!=h) {
        int m = (l + h) / 2;
        if (key<=arr[m]) {
            h=m;
        }
        else {
            l=m+1;
        }
    }
    if (key == arr[l]){
        return l;
    }
    return -1;
}
int index_element(int** matrix,int rows,int columns,int key) {  // takes matrix as input and gives (row index)*(number of columns) + column index as output 
    
    for (int i=0;i<rows;i++) {
        int ans=binarySearch(matrix[i],0,columns-1,key);
        if (ans==-1) {
            continue;
        }
        else {
            return i*columns + ans;
        }
    }
    return -1;       

}


int main() {
    int r,c;
    printf("Enter the number of rows for matrix:");
    scanf("%d",&r);
    printf("Enter the number of columns for matrix:");
    scanf("%d",&c);
    int **arr = (int**) malloc(r*sizeof(int*));
    for (int i=0;i<r;i++) {
        arr[i]= (int*) malloc(c*sizeof(int));
    }
    arr=read_matrix(r,c,arr);
    printf("The array before sorting is:\n");
    print_matrix(arr,r,c);
    for (int i=0;i<r;i++) {
        sort_rows(arr[i],c);
    }
    printf("The array after sorting is:\n");
    print_matrix(arr,r,c);
    printf("Enter the key value to be found:");
    int key,key_r,key_c;
    scanf("%d",&key);
    int ans=index_element(arr,r,c,key);
    if (ans==-1) {
        printf("Key is not in matrix.");
    }
    else {   
        key_r=(ans)/c ;       // finding out the row index and column index from the output of index_element function 
        key_c = ans%c ;
        printf("Index of element to be found is (%d,%d).",key_r,key_c);
    }
    for (int i=0;i<r;i++) {
        free(arr[i]);
    }
    free(arr);
}