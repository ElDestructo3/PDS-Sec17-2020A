#include <stdio.h>
void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 
int count=0;
void permute_string(char *str,int b,int c,char *strings[]) {
    
    int len=c+1;
    
    if (c==b) {
        
        strings[count++]=str;
        

    }
    else {
        for (int i=b;i<=c;i++) {

            
            swap((str+b),(str+i));
            permute_string(str,b+1,c,strings);
            swap((str+b),(str+i));
        
            
        
        }
    }
}
int valid_permute(char *str) {
    int len=0;    
    while(str[len]!='\0') {
        len++;
    }
    int temp=0;
    for (int i=0;i<len;i++) {
        if (str[len]=='(') {
            temp++;
        }
        else {
            temp--;
        }
        if (temp<0) {
            return 0;
        }
    }
    return 1;

}
int main() {
    int n;
    printf("Enter a value of n more than or equal to 1:");
    scanf("%d",&n);
    char * strings[1000];
    char main_string[2*n+1];
    for (int i=0;i<n;i++) {
        main_string[i]='(';
    }
    for (int i=0;i<n;i++) {
        main_string[i+n]=')';
    }
    main_string[2*n]='\0';
    
    permute_string(main_string,1,2*n-2,strings);
    int num_count=0;
    printf("Valid permutations are:");
    for (int i=0;i<count;i++) {
        if ( valid_permute(strings[i])) {
            printf("%d\n",strings[i]);
            num_count++;
        }
    } 
    printf("Number of valid permutations are :%d",num_count); 
    printf("%s",strings[1]);
      

}