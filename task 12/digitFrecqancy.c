#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char s[100];
    int c=0;
    char ch='0';
    scanf("%[^\n]", s);
    int len = strlen(s);
    for(int j;j<=9;j++){
    for(int i=0;i<=len; i++){
        if(s[i]==ch){
            c++;
        }
    }
    printf("%d",c);
    c=0;
    ch++;
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
