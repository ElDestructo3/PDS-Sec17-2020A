#include <stdio.h>
#include <conio.h>

void enter_string() {
    char input[1000]={0};
    static int count=0;
    char c;
    c=getch();
    if (c=='\n') {
        printf("%s",input);
    
        return;
    }
    else {
        input[count++]=c;
        
        enter_string();
    }


}
void delete(char a[],char b[],char c) {
    int j=0;
    int i=0;
    while(a[i]!='\0') {
        if (a[i]!=c) {
            b[j++]=a[i];
            i++;
            
        }
        else {
            i++;
        }

        
    }
}

int main() {
    /* enter_string(); */
    char input[1000];
    printf("Enter input string:");
    scanf("%s",input);
    char output[1000]={0};
    printf("Enter character to be deleted:");
    char a;
    scanf(" %c",&a);
    delete(input,output,a);
    printf("%s",output); 
    
    
}