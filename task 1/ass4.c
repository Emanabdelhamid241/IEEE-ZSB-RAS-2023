// string
// to input a string and print it
#include <stdio.h>

int main()
{   
    // array to store string taken as input
    char color[20];
    
    // take user input
    printf("Enter your favourite color: ");
    scanf("%s", color);
    
    // printing the input value
    printf("Your favourite color is: %s.", color);
    
    return 0;
}


// //to separate the  individual characters from a string.
#include <stdio.h>
#include <string.h>
int main()
{
char string[]="characters";
//Displays individual characters from given string  
printf("Individual characters from given string:\n");
//Iterate through the string and display individual character  
for(int i=0;i<strlen(string);i++){
  printf("%c  ",string[i]);
}
return 0;
}




// to compare two  strings without using string library  functions.
#include<stdio.h>
int main() {
 char str1[30], str2[30];
 int i=0;
 printf("\nEnter two strings :");
 gets(str1);
 gets(str2);
 while (str1[i] == str2[i] && str1[i] != '\0')
    i++;
 if (str1[i] > str2[i])
   printf("str1 > str2");
 else if (str1[i] < str2[i])
      printf("str1 < str2");
 else
   printf("str1 = str2");
return (0);
}





// // copy one string to another string
#include<stdio.h>
#include<conio.h>
#include<string.h> 
int main() { 
char str1[20], 
str2[20]; 
printf("Enter the string: "); 
gets(str1); 
printf("\nString 1 = %s", str1); 
strcpy(str2, str1); 
printf("\nString 2 = %s", str2); 
getch(); 
return 0; 
}