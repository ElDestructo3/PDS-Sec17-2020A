#include <stdio.h>

typedef struct student {
    int roll_no;
    char name[20];
    int age;
    int marks[3];
} record ;


int main() {
    int N;
    FILE *ftotal, *fpass, *ffail;
    ftotal=fopen("stud_rec_file.txt","w");
    int pass_mark= 0.4*300;

    printf("Enter the number of student records to be entered:");
    scanf("%d",&N);
    record records[N];
    for (int i=0;i<N;i++) {
        
        fprintf(ftotal,"Student record %d\n",i+1);
        printf("Enter details for student %d.\n",i+1);

        printf("Enter roll number:");
        scanf("%d",&records[i].roll_no);
        fprintf(ftotal,"Roll number=%d\n",records[i].roll_no);

        printf("Enter age:");
        scanf("%d",&records[i].age);
        fprintf(ftotal,"Age=%d\n",records[i].age);
        
        printf("Enter name:");
        scanf("%s",records[i].name);
        fprintf(ftotal,"Name=%s\n",records[i].name);

        printf("Enter the marks in three tests separated by a space:");
        scanf("%d %d %d",&records[i].marks[0],&records[i].marks[1],&records[i].marks[2]);
        fprintf(ftotal,"Marks obtained in the 3 tests: %d,%d,%d\n\n",records[i].marks[0],records[i].marks[1],records[i].marks[2]);
        
        
    }
    fclose(ftotal);

    fpass=fopen("pass_file.txt","w");
    ffail=fopen("fail_file.txt","w");

    for (int i=0;i<N;i++) {
        int temp_total=records[i].marks[0]+records[i].marks[1]+records[i].marks[2];
        if (temp_total>=pass_mark) {
            fprintf(fpass,"Student record %d\n",i+1);
            fprintf(fpass,"Roll number=%d\n",records[i].roll_no);
            fprintf(fpass,"Age=%d\n",records[i].age);
            fprintf(fpass,"Name=%s\n",records[i].name);
            fprintf(fpass,"Marks obtained in the 3 tests: %d,%d,%d\n\n",records[i].marks[0],records[i].marks[1],records[i].marks[2]);
        }
        else {
            fprintf(ffail,"Student record %d\n",i+1);
            fprintf(ffail,"Roll number=%d\n",records[i].roll_no);
            fprintf(ffail,"Age=%d\n",records[i].age);
            fprintf(ffail,"Name=%s\n",records[i].name);
            fprintf(ffail,"Marks obtained in the 3 tests: %d,%d,%d\n\n",records[i].marks[0],records[i].marks[1],records[i].marks[2]);
        }

    }
    fclose(fpass);
    fclose(ffail);
    char c;

    ftotal=fopen("stud_rec_file.txt","r");
    printf("Contents of the stud_rec_file:\n");
    c =fgetc(ftotal);
    while(c!=EOF) {
        printf("%c",c);
        c=fgetc(ftotal);
    }
    fclose(ftotal);

    fpass=fopen("pass_file.txt","r");
    printf("Contents of the pass_file:\n");
    c =fgetc(fpass);
    while(c!=EOF) {
        printf("%c",c);
        c=fgetc(fpass);
    }
    fclose(fpass);

    ffail=fopen("fail_file.txt","r");
    printf("Contents of the fail_file:\n");
    c =fgetc(ffail);
    while(c!=EOF) {
        printf("%c",c);
        c=fgetc(ffail);
    }
    fclose(ffail);
    


}