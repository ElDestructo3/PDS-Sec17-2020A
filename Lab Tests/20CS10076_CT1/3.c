#include <stdio.h>

int main() {
    char str[1000];
    printf("Enter a string:");
    gets(str);
    int length=0;
    while(str[length]!='\0') {
        length++;
    }
    
    for (int count=0;count<length;count++) {
        for (int i=0;i<length-count;i++) {
            for (int k=0;k<=count;k++) {
                printf("%c",str[length-1-i-k]);
            
            }    
            for (int j=0;j<length-count;j++) {
                printf(" ");
        
        
            }
        } 
        printf("\n");
    }
    
    




}