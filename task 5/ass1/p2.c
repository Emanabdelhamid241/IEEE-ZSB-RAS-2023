#include <stdio.h>
#include <stdlib.h>

int main()
{


	// This pointer will hold the
	// base address of the block created
	int* ptr;
	int n, i;

	// Get the number of elements for the array
	printf("Enter number of elements:");
	scanf("%d",&n);
	printf("Entered number of elements: %d\n", n);

	// Dynamically allocate memory using malloc()
	ptr = (int*)malloc(n * sizeof(int));

	// Check if the memory has been successfully
	// allocated by malloc or not
	if (ptr == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {

		// Memory has been successfully allocated
		printf("Memory successfully allocated using malloc.\n");

		// Get the elements of the array
		for (i = 0; i < n; ++i) {
			ptr[i] = i + 1;
		}

		// Print the elements of the array
		printf("The elements of the array are: ");
		for (i = 0; i < n; ++i) {
			printf("%d, ", ptr[i]);
		}
			printf("\n");

		free(ptr);

	}

	// This pointer will hold the
	// base address of the block created
	int* ptr1;
	int k, j;

	// Get the number of elements for the array
	k = 1000;
	// this larg number with limited  memory space will do over in stack and over in heap
	printf("Enter number of elements: %d\n", k);

	// Dynamically allocate memory using calloc()
	ptr1 = (int*)calloc(k, sizeof(int));

	// Check if the memory has been successfully
	// allocated by malloc or not
	if (ptr1 == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {

		// Memory has been successfully allocated
		printf("Memory successfully allocated using calloc.\n");

		// Get the elements of the array
		for (j = 0; j < k; ++j) {
			ptr1[j] = j + 1;
		}

		// Print the elements of the array
		printf("The elements of the array are: ");
		for (j = 0; j < k; ++j) {
			printf("%d, ", ptr1[j]);
		}

		free(ptr1);
	}

	return 0;
}
