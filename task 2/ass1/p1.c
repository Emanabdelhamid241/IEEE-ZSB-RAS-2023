#include <stdio.h>

int main() {
  int x = 2;  
  int * p1 =&x ;
  char y = 'f'; 
  char * p2 = &y; 
  long z = 41; 
  long * p3 = &z; 
//   int* ptr = &myAge;  // A pointer variable, with the name ptr, that stores the address 

  // Output the memory address of int (4 byte)
  printf("%p\n", p1);
  p1++ ;
  printf("%p\n\n", p1);

  // Output the memory address of char (1 byte)
  printf("%p\n", p2);
  p2++ ;
  printf("%p\n\n", p2);

  // Output the memory address of long  (8 byte)
  printf("%p\n", p3);
  p3++ ;
  printf("%p\n\n", p3);

  return 0;
}
