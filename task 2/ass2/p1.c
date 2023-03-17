#include <stdio.h>
// fun to increment an integer
// A normal function with an int parameter 
void fun(int a)
{
  printf("Enter an integer: ");
  scanf("%d", &a); 
	printf("Value of incremant a is %d\n", ++a);
	
}

int main()
{
	// fun_ptr is a pointer to function fun()
	void (*fun_ptr)(int) = &fun;

	//  fun() using fun_ptr
	(*fun_ptr)(10);
	return 0;
}
