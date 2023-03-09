#include <stdio.h> 

int main() {
    char input[1000]={0};
    char edited[1000]={0};
    printf("enter string:");
    gets(input);
    int j=0;
    int count=0;
    for (int i=0;i<1000;i++) {
        if ((input[i]=='a')&&(input[i+1]=='n')&&(input[i+2]==32)) {
            i=i+1;
            count++;
            continue;

        }
        else {
            edited[j]=input[i];
            j++;
        }
    }
     
    printf("%s\n",edited);
    printf("\nthe string 'an' was deleted %d times.",count);
   




}
