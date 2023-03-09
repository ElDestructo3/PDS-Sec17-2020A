#include <stdio.h>

int main()
{
int code,num1,num2,num3;

char c;

printf("Enter character:\n");
scanf("%c",&c);
code=c;
// printf("%d",code); i used this for finding ascii codes of a, A and 0 and used these for getting ascii ranges for code
if ((96 <= code)&& (code<= 122)) {
    printf("\nYou entered a letter.");

}
else if ((65<=code) && (code<=90)) {
    printf("\nYou entered a letter.");

}
else if ((48<=code) &&(code<=57)) {
    printf("\nYou entered a number.");

}
else {
    printf("\nYou entered a special character.");


}







}
