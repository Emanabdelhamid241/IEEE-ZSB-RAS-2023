
#include <stdio.h>
typedef struct  date {
    int day;
    int month;
    int year;
}date;
int main() {
    date d1;
    printf("please enter first date:\n");
    scanf("%d  %d  %d",&d1.day ,&d1.month ,&d1.year);
    date d2;
    printf("please enter second date:\n");
    scanf("%d  %d  %d",&d2.day ,&d2.month ,&d2.year);
    if(d1.day==d2.day && d1.month==d2.month && d1.year==d2.year ){
        printf("Dates are equal");
    }
    else
       printf("Dates are not equal");

    return 0;
}
