#include <stdio.h>
 struct test{
     int id  ;
     char name ;
     char class_id;
};
struct test1{
     char class_id;
     int id  ;
     char name ;
     
};
int main() {
    // in struct test >>>>4+1+1+2(wasted)=8
    printf("size of struct before swapping: %ld\n", sizeof(struct test));
    // in struct test1 >>>1+3(wasted)+4+1+3(wasted)=12
    printf("size of struct aftar swapping: %ld", sizeof(struct test1));
    return 0;
}