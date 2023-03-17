#include <stdio.h>
typedef struct named_info {
    char name[20];
    int age;
}info;
int main() {
    info info1;
    info *info_ptr = &info1; 
    printf("Enter your information:\n");
    printf("please enter your name:\n");
    scanf("%s",&info_ptr->name);
    printf("please enter your age:\n");
    scanf("%d",&info_ptr->age);
    printf("Displaying:\n");
    printf("name: %s\n" ,info_ptr->name);
    printf("age: %d\n" ,info_ptr->age);
    return 0;
}
