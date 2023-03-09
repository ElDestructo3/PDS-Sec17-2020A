#include <stdio.h>
#include <string.h>
struct date {
    int day;
    char month[4];
    int year;
};
struct PDS_LAB_ASSIGNMENT {
    struct date date;
    char topic[50];
    int ques_num;
    float marks;

};
// (d) function for returning index,marks for topic
int marks_assignment(char topic[], struct PDS_LAB_ASSIGNMENT record[],int size) {
    int index;
    for (int i=0;i<size;i++) {
        if (strcmp(topic,record[i].topic)==0) {
            index=i+1;
            
            return index;
        }

    }
}
// (e) function for assignment date
int index_assignment(struct PDS_LAB_ASSIGNMENT record[],int size,int day,char month[],int year) {
    int index_1;
    for (int i=0;i<size;i++) {
        if ((record[i].date.day==day)&&(record[i].date.year==year)&&(strcmp(record[i].date.month,month)==0)) {
            index_1=i+1;
            return index_1;
        }
    }
}


int main() {
    int n;
    printf("Enter number of records:");
    scanf("%d",&n);
   
    struct PDS_LAB_ASSIGNMENT records[n];
    for (int i=0;i<n;i++) {
        printf("Enter record %d\n",i+1);
        printf("Enter date of assignment\n");
        printf("Enter day (1-31):");
        scanf("%d",&records[i].date.day);
        printf("Enter month of assignment(in three letters-jan,feb,etc.):");
        scanf("%s",records[i].date.month);
        printf("Enter year of assignment:(2020/2021):");
        scanf("%d",&records[i].date.year);
        printf("Enter topic of assignment: (datatypes,arrays, functions , loops etc.)");
        scanf("%s",records[i].topic);
        printf("Enter number of questions in assignment:");
        scanf("%d",&records[i].ques_num);
        printf("Enter marks secured in asssignment:");
        scanf("%f",&records[i].marks);
    }
    // (a) average
    float sum=0,avg;
    for (int i=0;i<n;i++) {
        sum+=records[i].marks;
    }
    avg=(float) sum/n ;
    printf("Your average score is %f.\n",avg);
    // (b) topics where score>avg
    for (int i=0;i<n;i++) {
        if (records[i].marks>=avg) {
            printf("Your score is more than or equal to average score in %s.\n",records[i].topic);
        }
    }
    // (c) assignment with least number of questions
    int min=records[0].ques_num;
    int pos=0;
    for (int i=1;i<n;i++) {
        if (records[i].ques_num<min) {
            min=records[i].ques_num;
            pos=i;
        }   
    }
    printf("The assignment with least number of questions was held on %d %s %d.\n",records[pos].date.day,records[pos].date.month,records[pos].date.year);
    // calling function marks_assignment
    char final_topic[100];
    printf("Enter the topic for which marks are to be found:");
    scanf("%s",final_topic);
    int final_index=marks_assignment(final_topic, records,n);
    printf("The assignment index is %d and marks in the assignment is %f.\n",final_index,records[final_index-1].marks);
    // calling function for part (e)
    int final_day,final_year;
    char final_month[4];
    printf("Enter the day, month and year for assignment(Ex: 23 jan 2021):");
    printf("Enter day:");
    scanf("%d",&final_day);
    printf("Enter month:");
    scanf("%s",&final_month);
    printf("Enter year:");
    scanf("%d",&final_year);
    int final_index_1=index_assignment(records,n,final_day,final_month,final_year);
    printf("The assignment index is %d and marks in the assignment is %f.\n",final_index_1,records[final_index_1-1].marks);
    printf("The assignment was on the topic %s.It had %d questions.\n",records[final_index_1-1].topic,records[final_index_1-1].ques_num);


}
