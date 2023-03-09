#include <stdio.h>
int compare(char s1[],char s2[],int a,int b) {
    
    while((s1[a]!='\0')&&(s2[b]!='\0')){
        
        if (s1[a]!=s2[b]) {
            return 0;
        }
        a++;
        b++;
    }
    
    if (s2[b] != '\0') {
        return 0;
    }
    return 1;
}
char* find_replace (char *str, char *find, char *replace) {
    int len=0;
    int count=0;
    char edited[100]={0};
    while(str[len]!='\0') {
        len++;
    }
    int len1,len2=0;
    while(find[len1]!='\0') {
        len1++;
    }
    while(replace[len2]!='\0') {
        len2++;
    }
    
    for (int i=0;i<len;i++) {
        if (compare(str,find,i,0)) {
            for (int j=0;j<len2;j++) {
                edited[count++]=replace[j];
                i+=len1-1;
            }
        }
        else {
            edited[count++]=str[i];
        }
    }
    edited[count]='\0';
    for (int i=0;i<count;i++) {
        str[i]=edited[i];
    }
    return str;

}
void getstring(char *s) {
    gets(s);
    printf("Input string s=is:%s\n",s);
}

int main() {
    char s[100],find[100],replace[100];
    printf("Enter main string:");
    getstring(s);
    printf("Enter string to be found:");
    getstring(find);
    printf("Enter string to be replaced with:");
    getstring(replace); 
    
    char* edited=find_replace(s,find,replace);
    printf("%s",edited); 
   // printf("%d",compare("abxxyz","xx",2,0));
    
    
}