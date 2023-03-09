#include <stdio.h>
void encrypt(FILE *orig,FILE *encry,int m) {
    
    
    char ch=fgetc(orig);
    while(ch!=EOF){
        if ((ch!=32)||(ch!='\n')) {
            
            printf("%c",ch+m);
            fputc(ch+m,encry);
        }
        else {
            fputc(ch,encry);
        }
        ch=fgetc(orig);
        
    }
    
    
}
void decrypt(FILE *orig,FILE *decry,int m) {
    
    
    char ch=fgetc(orig);
    while(ch!=EOF){
        if ((ch!=32)||(ch!='\n')) {
            
            
            fputc(ch-m,decry);
        }
        else {
            fputc(ch,decry);
        }
        ch=fgetc(orig);
        
    }
    
    
}

int main() {
    FILE *fp,*encry,*decry;
    int m,n;
    printf("Enter the key for encryption:");
    scanf("%d",&m);
    printf("Enter the key for decryption:");
    scanf("%d",&n);
    
    fp=fopen("rough.c","r");
    encry=fopen("encrypt.txt","w");
    printf("Original file is:\n");
    char c=fgetc(fp);
    while(c!=EOF) {
        printf("%c",c);
        c=fgetc(fp);
    } 
    
    
    encrypt(fp,encry,m);
    fclose(fp);
    fclose(encry);
    encry=fopen("encrypt.txt","r");
     printf("File after encryption is :\n");
    c=fgetc(encry);
    while(c!=EOF) {
        printf("%c",c);
        c=fgetc(encry);
    } 
    
    
    decry=fopen("decrypt.txt","w");
    decrypt(encry,decry,n);
    fclose(encry);
    fclose(decry);
    decry=fopen("decrypt.txt","r");
    
    printf("File after decryption is :\n");
    c=fgetc(decry);
    while(c!=EOF) {
        printf("%c",c);
        c=fgetc(decry);
    } 
    fclose(decry);

    
}