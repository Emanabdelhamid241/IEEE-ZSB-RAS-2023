
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * multiply(char * num1, char * num2){
    int l1,l2;
    l1 = strlen(num1);
    l2 = strlen(num2);
    char* ans = (char*)calloc(l1+l2+1,sizeof(char));
    for(int i=0 ; i<l1 ; i++){
        for(int j=0 ; j<l2 ; j++){
            int k = i+j+1;
            int prod = (num1[i]-48) * (num2[j]-48);       //48 is a in ASCI code
            while(prod !=0){
                prod += ans[k];
                ans[k] = (prod)%10;
                prod = prod/10;
                k--;
            }
        }
    }
    int k=0;
    if(ans[0]==0) k=1;
    else k=0;

    for(int i=0 ; i<l1+l2 ; i++){
        ans[i] += '0';
    }
    if(ans[0]=='0') return ans+1;
    return ans;

}
