#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    char *str;
    int l;
    int  max[l],i,n,j,k=0,count=0;
    // get maxmum of length of name from user
    printf("How many characters in the string? ");
    scanf("%d", &n);

    str = (char*) malloc(n*sizeof(char));
    // get name from user
    printf("Insert the string: ");
    scanf("%s", str);
    // print name of user
    printf("the name you entered is:%s ", str);
    // to get the frequency of the most repeated character
    l=strlen(str);
    for(i=0;i<l;i++)  
    {
    	max[i]=0;
    	count=1;
    	if(str[i])
    	{
		
 		  for(j=i+1;j<l;j++)  
	      {   
	    	
	        if(str[i]==str[j])
    	    {
                 count++;
                //  str[j]=str[i];
	     	}
	      }  
       }
	   max[i]=count;
	   if(count>=k)
	     k=count;
	   
 	}
//  	to print the most repeated character and its frequency
 	printf("\nthe most repeated character is : ");
 	for(j=0;j<l;j++)  
	    {
	    	
	        if(max[j]==k)
    	    {
	             printf(" '%c',",str[j]);
	     	}
	   }  
     
	printf("\b= %d times \n ",k);

    free(str);

    return 0;
}