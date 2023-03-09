#include <stdio.h>
char* enter_string() {
    static char string[100];
    int index=0;
    char c;
    printf("Enter string:");
    scanf("%c",&c);
    while (c!='\n') {
        string[index++]=c;
        scanf("%c",&c);
    }
    string[index]='\0';
    return string;
}

void print_string(char *a) {
    printf("Input string=%s\n",a);
}

void compute_vowel_consonant(char* string,int* vowels,int* consonants) {
    int len=0;
    
    while (string[len]!='\0') {
        if ((string[len]=='a')|| (string[len]=='e')|| (string[len]=='i')|| (string[len]=='o')|| (string[len]=='u')) {
            (*vowels)++;
            
        }
        else {
            (*consonants)++;
        }
        len++;
    }
}
void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 
void permute_string(char *str,int b,int c) {
    
    int len=c+1;
    
    if (c==b) {
        printf(" %s",str);
    }
    else {
        for (int i=b;i<=c;i++) {

            
            swap((str+b),(str+i));
            permute_string(str,b+1,c);
            swap((str+b),(str+i));
        
            
        
        }
    }
}


int main() {
    char *str=enter_string();
    int vowels=0;
    int consonants=0;
    int *p,*q;
    p=&vowels;
    q=&consonants;
    print_string(str);
    compute_vowel_consonant(str,p,q);
    printf("Number of vowels=%d,number of consonants=%d\n",vowels,consonants);
    int c=vowels+consonants-1;
    int b=0;
    printf("Permutations of entered string=");
    permute_string(str,b,c);
}