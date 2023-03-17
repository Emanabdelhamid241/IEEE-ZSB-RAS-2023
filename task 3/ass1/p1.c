#include <stdio.h>
#include <conio.h>
#include <string.h>

struct student{
    char *name[30];
    char *address[60];
    int *age[4];
    int *mark[4];
}student;

void addInfo(struct student* file[]);

int main(void){
    printf("\n\n");
    printf("\t***************************\n");
    addInfo(&student);

    return 0;
}

void addInfo(struct student* file[]){
    int i = 0;
    int otherCounter = 0;
    for(i = 0; i < 15; i++){
        printf("Enter the name of student %d: \n"),otherCounter+1;
        scanf("%s",&student.name[i]);
        printf("Enter the address of student %d: \n"),otherCounter+1;
        scanf("%s",&student.address[i]);
        printf("Enter the age of student %d: \n",otherCounter+1);
        scanf("%d",&student.age[i]);
        printf("Enter the mark of student %d: \n",otherCounter+1);
        scanf("%d",&student.mark[i]);
        printf("\t***************************\n");
        otherCounter++;
    }
    printf("\t***************************\n");
 
    }
