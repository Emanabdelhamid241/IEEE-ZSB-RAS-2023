
#include <stdio.h>
#include <string.h>
int lengthOfLongestSubstring(char * s){

        int len,max_len = 0;
        int arr[200]={0};

        for(int i=0; s[i] !=0 ;i++){
            len=0;
    // Reset the array to all zeros.
           memset(arr ,0 ,sizeof(arr));

 // Iterate over the string, starting from the current character.
          for(int j=i; s[j] !=0;j++){

 /* If the current character has not been seen before, increment the length of
     the current substring and increment the count of the current character in the array.*/

    if (arr[s[j]]==0) {
        arr[s[j]]++;
        len++;
    }
    else{
        break;
    }
        }
        if(len >=max_len){
            max_len=len;
        }
}
return max_len;
}
int main(){
int *p = "abcabcbb";
int l= lengthOfLongestSubstring(p);
printf("%d",l);
    return 0;
}
