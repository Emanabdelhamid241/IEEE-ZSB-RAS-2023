#include <stdio.h>
// define function to add
#define Add(a,b) a+b
// define function to subtract
#define Sub(a,b) a-b
// define to if
#define op
void main (){
    // int x,y;
    // scanf("%d,%d",&x,&y);
    #ifdef op
    int z=Add(2,3);
    int k=Sub(2,3);
    #endif
    printf("%d\n%d",z,k);
}