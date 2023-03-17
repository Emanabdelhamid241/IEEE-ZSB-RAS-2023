#include <stdio.h>

int main() {
  int hex_x = 0x24122;  
  int *ptr = &hex_x ;
printf("%p\n", ptr);
// z= *ptr++ >>>>  z=*ptr , ptr =ptr+1 
*ptr++ ;
printf("%p\n", ptr);
// z= *++ptr >>>>  ptr=ptr +1  , z= *ptr
*++ptr ;
printf("%p\n", ptr);
// z= *++ptr >>>>  *ptr=*ptr +1  , z= *ptr
++*ptr ;
printf("%p\n", ptr);
  return 0;
}