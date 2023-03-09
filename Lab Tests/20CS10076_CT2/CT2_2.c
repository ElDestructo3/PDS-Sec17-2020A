#include <stdio.h>
struct point {
    int x;
    int y;
};
struct set {
    struct point arr[20];
};
struct set temp1;
struct set read_s(int n) {
    static struct set s;
    for (int i=0;i<n;i++) {
        printf("Enter x-coordinate:");
        scanf("%d",&s.arr[i].x);
        printf("Enter y-coordinate:");
        scanf("%d",&s.arr[i].y);
    }
    temp1=s;
    return s;
}

void print_s(struct set s,int n) {
    for (int i=0;i<n;i++) {
        printf("(%d,%d),",s.arr[i].x,s.arr[i].y);
    }
}
struct set add_s(struct set s1, struct set s2, int x, int y, int* z) {
    int i=0;
    for (i=0;i<x;i++) {
        temp1.arr[i]=s1.arr[i];

    }
    for (i=0;i<y;i++) {
        temp1.arr[i+x]=s2.arr[i];
        
    }
    *z=x+y;
    return temp1;
}
struct set temp2;
struct set subtract_s(struct set s1, struct set s2, int x, int y, int* z) {
    int count=0;
    
    for (int i=0;i<x;i++) {
        int flag=1;
        for (int j=0;j<y;j++) {
            if ((s1.arr[i].x==s2.arr[j].x)&&(s1.arr[i].y==s2.arr[j].y)) {
                flag=0;
                break;
            }
            
        }
        if (flag==1) {
            temp2.arr[count++]=s1.arr[i];
        }
    }
    *z=count;
    return temp2;

}
struct set intersection_s(struct set s1, struct set s2, int x, int y, int* z) {
    struct set s_temp=subtract_s(s1,s2,x,y,z);
    struct set s_final=subtract_s(s1,s_temp,x,y,z);
    return s_final;
}
struct set union_s(struct set s1, struct set s2, int x, int y, int* z) {
    struct set s_temp1=add_s(s1,s2,x,y,z);
    struct set s_temp2=intersection_s(s1,s2,x,y,z);
    struct set s_temp3=subtract_s(s_temp1,s_temp2,x,y,z);
    struct set s_final=add_s(s_temp3,s_temp2,x,y,z);
    return s_final;
}
int main() {
    struct set a1,a2,add,subtract,intersection,set_union;
    int n1,n2;
    printf("Enter number of elements for first set:");
    scanf("%d",&n1);

    read_s(n1);
    a1=temp1;
    printf("The first set is:");
    print_s(a1,n1);
    printf("\nEnter number of elements for second set:");
    scanf("%d",&n2);
    read_s(n2);
    a2=temp1;
    printf("The second set is:");
    print_s(a2,n2);
    int a=0;
    int* p;
    p=&a;
    add=add_s(a1,a2,n1,n2,p);
    printf("\n The set when added is :");
    print_s(add,*p);
    subtract=subtract_s(a1,a2,n1,n2,p);
    printf("\n The set when subtarcted is :");
    print_s(add,*p);

}