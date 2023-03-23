#include<stdio.h>
int main() {
typedef unsigned char u8 ;
typedef unsigned short int u16  ;
typedef unsigned long int  u32 ;
typedef signed char s8 ;
typedef signed short int s16  ;
typedef signed long int  s32 ;
typedef double f32  ;
typedef long double f64 ;

    printf("Size of u8: %d bytes\n", sizeof(u8));
    printf("Size of u16: %d bytes\n", sizeof(u16));
    printf("Size of u32: %d bytes\n", sizeof(u32));
    printf("Size of s8: %d byte\n", sizeof(s8));
    printf("Size of s16: %d bytes\n", sizeof(s16));
    printf("Size of s32: %d bytes\n", sizeof(s32));
    printf("Size of f32: %d bytes\n", sizeof(f32));
    printf("Size of f64: %d byte\n", sizeof(f64));
    return 0;
}