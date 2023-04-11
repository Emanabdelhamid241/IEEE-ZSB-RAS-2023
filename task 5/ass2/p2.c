#include<stdio.h>
#include<string.h>
#include <stdlib.h>
// function to return the number of unique
// characters in str[]
int count_unique_char(char* str) {
 
 	int i,n, c = 0;
    printf("How many characters in the string? ");
    scanf("%d", &n);
	char *hash[10] = { 0 };

    str = (char*) malloc(n*sizeof(char));
    printf("Insert the string: ");
    scanf("%s", &hash);
    printf("the name you entered is:%s \n", hash);
	// reading each character of str[]
	for (i = 0; i < n; ++i) {
		// set the position corresponding 
		// to the ASCII value of str[i] in hash[] to 1
		hash[str[i]] = 1;
		
	}

	// counting number of unique characters
	// repeated elements are only counted once
	for (i = 0; i < n; ++i) {
		c += hash[i];
	}

	return c;
	free(hash);

}
int main() {
    char* hash;
	char str[10];
  if (*hash == '!!')
    return 0;
  else{
	printf("Number of Unique Characters in String: %d", count_unique_char(str));
	return 0;
}
}