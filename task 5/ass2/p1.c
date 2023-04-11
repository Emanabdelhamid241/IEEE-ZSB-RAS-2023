#include <stdio.h>
#include <stdlib.h>

int main() {
    int *time1;
    int i;
// allocate space in memory
    time1 = (int*) malloc(3*sizeof(int));
// get time form user
    printf("Insert the time as intger by intger to prtint as hh:mm:ss: ");
    for(i=0;i<3; ++i)
       scanf("%d", &time1[i]);
// print the time
    printf("The time is: ");
		for (i = 0; i < 3; ++i) {
			printf("%d:", time1[i]);
		}
			printf("\b\n");
// free the space
    free(time1);

    return 0;
}