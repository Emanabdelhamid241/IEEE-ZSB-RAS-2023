#include <stdio.h>
void main() {  
    int x,y,z;  
    int *p,*q,*r;  
    x=1;  
    y=2;  
    z=3;  
    p=&x;  
    q=&y;  
    r=&z;    
    // Print with labels the values of x, y, z, p, q, r, *p, *q, *r.
    printf("value of x is %d\n", x);
    printf("value of y is %d\n", y);
    printf("value of z is %d\n", z);
    printf("value of p is %d\n", p);
    printf("value of q is %d\n", q);
    printf("value of r is %d\n", r);
    printf("value of *p is %p\n", *p);
    printf("value of *q is %p\n", *q);
    printf("value of *r is %p\n", *r);

// Print the message: Swapping pointers.
    printf("Swapping pointers.");

// Execute the swap code: r = p; p = q; q = r;

    int w;  
    w=*r;  
    r=p;  
    p=q;  
    q=r;  

    // Print with labels the values of x, y, z, p, q, r, *p, *q, *r.
    printf("value of x is %d\n", x);
    printf("value of y is %d\n", y);
    printf("value of z is %d\n", z);
    printf("value of p is %d\n", p);
    printf("value of q is %d\n", q);
    printf("value of r is %d\n", r);
    printf("value of *p is %p\n", *p);
    printf("value of *q is %p\n", *q);
    printf("value of *r is %p\n", *r);


}//end main