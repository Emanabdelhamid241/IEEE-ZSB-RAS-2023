#include <stdio.h>
// by macros 
#define z()    sizeof(int)
// by inline function   
int f(){
    return sizeof(int);
}
int main(){
    f();
    z();
    printf("%d\n%ld",f(),z());

    return 0;
}
// the difference between them is time macros is fast because it replace the line in main 
// but the inline function oprate it in stack
// the best case in this function is macros