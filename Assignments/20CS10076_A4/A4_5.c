#include <stdio.h>

int main() {
    char key_string[100]={'0'};
    char test_string[100]={'0'};
    printf("Enter key string:");
    scanf("%s",key_string);
    printf("Enter test string:");
    scanf("%s",test_string);
    int length_key=0;
    int length_test=0;
    

    while(key_string[length_key]!='\0') {
        length_key++;
    }
    while(test_string[length_test]!='\0') {
        length_test++;
    }
    int flag=0;
    for (int i=0;i<length_key;i++) {
        int count_key=0;
        int count_test=0;
        for (int k=0;k<length_key;k++) {
            if ((key_string[k]==key_string[i])||(key_string[k]-key_string[i]=='c'-'C')||(key_string[k]-key_string[i]=='C'-'c')) {
                count_key++;
            }
        }
        for (int j=0;j<length_test;j++) {
            if ((key_string[j]==key_string[i])||(key_string[j]-key_string[i]=='c'-'C')||(key_string[j]-key_string[i]=='C'-'c')) {
                count_test++;
            }
        if (count_key<=count_test) {
            flag++;
        }
        }
        
    }
    if (flag==length_key) {
        printf("Key string is present in test string");
    }
    else {
        printf("Key string is not present in test string");
    }



}