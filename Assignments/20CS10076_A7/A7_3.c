#include <stdio.h>
struct students {
    int roll;
    char name[20];
    int marks[3];
    int total_marks;
};
void swap(struct students *x, struct students  *y)
{
    struct student *s= x;
    x=y;
    y=s;

}
void input_records(struct students* s) {
    printf("Enter details about the student.\n");
    
    printf("Enter roll:");
    scanf("%d",&(s->roll));
    printf("Enter 1st mark :");
    scanf("%d",&(s->marks[0]));
    printf("Enter 2nd mark:");
    scanf("%d",&(s->marks[1]));
    printf("Enter 3rd mark:");
    scanf("%d",&(s->marks[2]));
    printf("Enter name:");
    scanf("%s",s->name);
    

    

}

void total_marks(struct students* s) {
    s->total_marks=s->marks[0]+s->marks[1]+s->marks[2];
}
void print_record(struct students* s,int n) {
    printf("Students[%d]=%d    %s    %d %d %d    %d",n,s->roll,s->name,s->marks[0],s->marks[1],s->marks[2],s->total_marks);
}
void sort(struct students* record[]) {
    if (record[0]->total_marks> record[1]->total_marks) {
        swap(record[0],record[1]);
    }
    if (record[1]->total_marks> record[2]->total_marks) {
        swap(record[1],record[2]);
    }
    if (record[0]->total_marks> record[1]->total_marks) {
        swap(record[0],record[1]);
    }
}
int main() {
    int n;
    
    printf("Enter number of students:"); 
    scanf("%d",&n);
    struct students* records[n];
    for (int i=0;i<n;i++) {
        input_records(records[i]);
    }
    for (int i=0;i<n;i++) {
        total_marks(records[i]);
    }
    // before sorting
    for (int i=0;i<n;i++) {
        print_record(records[i],i);
    }
    sort(records[]);
    // after sorting
    for (int i=0;i<n;i++) {
        print_record(records[i],i);
    }


    
}