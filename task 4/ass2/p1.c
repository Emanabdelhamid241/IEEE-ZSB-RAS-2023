#include <stdio.h>
enum operator {
    add = '+', 
    sub = '-', 
    mult = '*', 
    divi = '/', 
    anding = '&',
    oring ='|',
    noti ='!'
};
int main(void)
{
    enum operator oper;
    int a, b;
    char op;

    printf("enter  [ +, -, *, /, &, |, ! ] :\n");
    scanf("%c", &op);
    printf("enter 2 integer\n");
    scanf("%d%d", &a, &b);
    switch(op) {
        case add:
            printf("%d + %d = %d\n", a, b, a+b);
            break;
        case sub:
            printf("%d - %d = %d\n", a, b, a-b);
            break;
        case mult:
            printf("%d * %d = %d\n", a, b, a*b);
            break;
        case divi:
            printf("%d / %d = %d\n", a, b, a/b);
            break;
        case anding:
            printf("%d & %d = %d\n", a, b, a&b);
            break;
        case oring:
            printf("%d | %d = %d\n", a, b, a|b);
            break;
        case noti:
            printf("%d !  = %d\n", a,!a);
            printf("%d ! = %d\n",  b, !b);
            break;
    }
    printf ("the size is :%ld",sizeof(oper));

    return 0;
}