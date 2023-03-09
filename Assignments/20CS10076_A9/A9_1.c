#include <stdio.h>
int isPrime(int n)
{
	int i;
	for(i=2;i<=n/2;i++) {
	    if(n%i!=0){
			continue;
        }
		else {
			return 0;
        }
	}
	return 1;
}


int main() {
    FILE *fp,*fp1,*fp2,*fp3;
    fp=fopen("int_file.txt","w");
    int n;
    printf("Enter the number of positive integers to be read:");
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        printf("Enter value %d:",i+1);
        int temp;
        scanf("%d",&temp);
        fprintf(fp,"%d ",temp);
    }
    fclose(fp);
    fp=fopen("int_file.txt","r");
    fp1=fopen("even_file.txt","w");
    fp2=fopen("prime_file.txt","w");
    fp3=fopen("odd_file.txt","w");
    
    for (int i=0;i<n;i++) {
        int temp1;
        fscanf(fp,"%d ",&temp1);
        if (temp1%2==0) {
            
            fprintf(fp1,"%d ",temp1);
            
            
        }
        else if (isPrime(temp1)) {
            
            fprintf(fp2,"%d ",temp1);
            
        }
        else {
           
            fprintf(fp3,"%d ",temp1);
            
        }
    }
    
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fp=fopen("int_file.txt","r");
    fp1=fopen("even_file.txt","r");
    fp2=fopen("prime_file.txt","r");
    fp3=fopen("odd_file.txt","r");
    printf("Contents of int_file:");
    char c = fgetc(fp); 
    while (c != EOF) { 
        printf ("%c", c); 
        c = fgetc(fp); 
    } 
    
    
    
    printf("\n");
    printf("Contents of even_file:");
    
    c= fgetc(fp1); 
    while (c != EOF) { 
        printf ("%c", c); 
        c = fgetc(fp1); 
    } 
    
    printf("\n");
    printf("Contents of prime_file:");
    fp1=fopen("prime_file.txt","r");
    c = fgetc(fp2); 
    while (c != EOF) { 
        printf ("%c", c); 
        c = fgetc(fp2); 
    } 
    
    printf("\n");
    printf("Contents of odd_file:");
    fp1=fopen("odd_file.text","r");
    c = fgetc(fp3); 
    while (c != EOF) { 
        printf ("%c", c); 
        c = fgetc(fp3); 
    } 
     
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

}