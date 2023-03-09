#include <stdio.h>
#include <string.h>
void bubbleSort(int arr[], int n) { 
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
int num_vowels(char str[]) {
    int vowels=0;
    int len=strlen(str);
    for (int i=0;i<len;i++) {
        if ((str[i]='a')||(str[i]='e')||(str[i]='i')||(str[i]='o')||(str[i]='u')) {
            vowels++;
        }
    }
    return vowels;
}
int main() {
    FILE* fp;
    char str[1000];
    fp=fopen("file.txt","w");
    printf("Enter the contents to be entered into the file:");
    gets(str);
    fprintf(fp,"%s",str);
    fclose(fp);
    fopen("file.txt","r");
    char c=fgetc(fp);
    printf("The contents of the file are :\n");
    while (c!=EOF) {
        printf("%c",c);
        c=fgetc(fp);
    }
    fclose(fp);
    fopen("file.txt","r");
    char word[50];
    char words[1000][50];
    int count[1000];
    int isUnique,i;
    int max_len=0,max_pos=0,min_pos=0,min_len=1001,max_vowels=-1,min_vowels=51,min_vwlpos=0,max_vwlpos=0;

    
    int index=0;
    while (fscanf(fp, "%s", word) != EOF){
        strlwr(word);
        int len=strlen(word);
        
        if (ispunct(word[len-1])){
            word[len-1] = '\0';
        }
        isUnique = 1;
        for (i=0; ((i<index) && (isUnique)); i++){
        
            if (strcmp(words[i], word) == 0){
                isUnique = 0;
            }
        }

   
        if (isUnique){
   
            strcpy(words[index], word);
            count[index]++;
            index++;
        }
        else{
            count[i - 1]++;
        }
    }
    fclose(fp);
    for (int i=0;i<index;i++) {
        if (strlen(words[i])>max_len){
            max_len=strlen(words[i]);
            max_pos=i;
        }
        if (strlen(words[i])<min_len) {
            min_len=strlen(words[i]);
            min_pos=i;
        }
        if (num_vowels(words[i])>max_vowels){
            max_vowels=num_vowels(words[i]);
            max_vwlpos=i;
        }
        if (num_vowels(words[i])<min_vowels){
            min_vowels=num_vowels(words[i]);
            min_vwlpos=i;
        }
        
    }
    int max_freq=0;int max_freqpos=0;
    for (int i=0;i<index;i++) {
        if (count[i]>1) {
            printf("%s is repeated\n",words[i]);
        }
    }
    printf("Word with max length is %s\n",words[max_pos]);
    printf("Word with min length is %s\n",words[min_pos]);
    printf("Word with max number of vowels is %s\n",words[max_vwlpos]);
    printf("Word with min number of vowels is %s\n",words[min_vwlpos]);
    

}