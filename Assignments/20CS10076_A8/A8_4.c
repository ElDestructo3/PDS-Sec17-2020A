#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int N;
    char word[20];
    printf("Enter the number of words in list:");
    scanf("%d",&N);
    char** list = (char**) malloc(N*sizeof(char*));        
    for (int i=0;i<N;i++) {
        printf("Enter word %d:",i+1);
        scanf("%s",word);
        list[i]=(char*) malloc((strlen(word)+1)*sizeof(char));
        strcpy(list[i],word);
    }
    printf("List before sorting is:");
    for (int i=0;i<N;i++) {
        printf("%s,",list[i]);                                            //printing before sorting
        
    }
    printf("\n");
    for (int i=0;i<N-1;i++) {
        for (int j=0;j<N-1-i;j++) {
            if (strcmp(list[j],list[j+1])==1) {                            // swapping strings by alphabetical order using strcmp function
                char *temp;
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
    }
    printf("List after sorting is:");
    for (int i=0;i<N;i++) {
        printf("%s,",list[i]);                                              // printing after sorting
    }
    
    int freq_array[26]={0};
    for (int i=0;i<N;i++) {
        freq_array[list[i][0]-'a']++;                           // creating an array which carries information abt unique first characters of words and their frequency
    }
    int unique_first_char=0;
    for (int i=0;i<26;i++) {
        if (freq_array[i]>0) {
            unique_first_char++;
        } 
    }
    int final_freq_array[unique_first_char];
    int x=0;
    for (int i=0;i<26;i++) {                                                 // creating another array which removes all the 0s from the original array
        if (freq_array[i]!=0) {
            final_freq_array[x++]=freq_array[i];
        }
    }
    
    int k=0;
    char ***sorted=(char***) malloc(unique_first_char*sizeof(char**));       // first malloc based on number of unique first characters
    for (int i=0;i<unique_first_char;i++) {
        sorted[i]=(char**) malloc(final_freq_array[i]*sizeof(char*));        // second malloc based on number of words with same first character
        for (int j=0;j<final_freq_array[i];j++) {                            
            sorted[i][j]=(char*) malloc((strlen(list[k])+1)*sizeof(char));   // third malloc based on size of word
            strcpy(sorted[i][j],list[k]);
            k++;
        }
    }
    printf("\nFinal pattern is:\n");                              
    for (int i=0;i<unique_first_char;i++) {                                  // printing final pattern
        for (int j=0;j<final_freq_array[i];j++) {
            printf("%s,",sorted[i][j]);
        }
        printf("\n");
    }
                  
    for (int i=0;i<unique_first_char;i++) {                                // freeing 
        for (int j=0;j<final_freq_array[i];j++) {
            free(sorted[i][j]);
        }
        free(sorted[i]);
    }
    free(sorted);
    for (int i=0;i<N;i++) {
        free(list[i]);
    }
    free(list);
}