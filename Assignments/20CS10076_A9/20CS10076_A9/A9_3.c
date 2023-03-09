#include <stdio.h>
void bubbleSort(int arr[], int n) { // ascending
   int i, j; 
   for (i = 0; i < n-1; i++) { 
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]){ 
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp; 
           }
       }
   }
}  

int main() {
    int n,m,k;
    
    printf("Enter number of tests:");
    scanf("%d",&n);
    printf("Enter number of marks in first file: ");
    scanf("%d",&m);
    int arr[n];
    FILE * fp1,*fp2,*fp;
    fp1=fopen("list1_file.txt","w");
    fp2=fopen("list2_file.txt","w");
    fp=fopen("merge_list.txt","w");
    for (int i=0;i<n;i++) {
        int temp;
        printf("Enter mark %d:",i+1);
        scanf("%d",&temp);
        arr[i]=temp;
        if (i>=m) {
            fprintf(fp2,"%d ",temp);
        }
        else {
            fprintf(fp1,"%d ",temp);
        }
        fprintf(fp,"%d ",temp);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp);
    fp1=fopen("list1_file.txt","r");
    char c;
    c=fgetc(fp1);
    printf("First file has :");
    while (c!=EOF) {
        printf("%c",c);
        c=fgetc(fp1);
    }
    fclose(fp1);
    fp2=fopen("list2_file.txt","r");
    
    c=fgetc(fp2);
    printf("\nSecond file has :");
    while (c!=EOF) {
        printf("%c",c);
        c=fgetc(fp2);
    }
    fclose(fp2);
    fp=fopen("merge_list.txt","r");
    
    c=fgetc(fp);
    printf("\nMerged file has :");
    while (c!=EOF) {
        printf("%c",c);
        c=fgetc(fp);
    }
    fclose(fp);
    bubbleSort(arr,n);
    fp=fopen("merge_list.txt","w");
    for (int i=0;i<n;i++) {
        fprintf(fp,"%d ",arr[i]);
    }
    fclose(fp);
    fp=fopen("merge_list.txt","r");
    
    c=fgetc(fp);
    printf("\nMerged file after sorting has :");
    while (c!=EOF) {
        printf("%c",c);
        c=fgetc(fp);
    }
    fclose(fp);
    printf("Enter the number of the top students less than %d for which average marks has to be calculated: ",n);
    scanf("%d",&k);
    int sum;
    float avg;
    for (int i=n-k;i<n;i++) {
        sum+=arr[i];
    }
    avg= (float) sum/k ;
    printf("Average for the top %d marks is %f",k,avg);
    fp=fopen("merge_list.txt","a");
    fprintf(fp,"%f",avg);
    fclose(fp);
    fp=fopen("merge_list.txt","r");
    
    c=fgetc(fp);
    printf("\nMerged file after sorting with average appended has :");
    while (c!=EOF) {
        printf("%c",c);
        c=fgetc(fp);
    }
    fclose(fp);

}