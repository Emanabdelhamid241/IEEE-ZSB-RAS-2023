#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    // int s[n];
    int sum=0;
    scanf("%d",&n);

    int *s = malloc(n*sizeof(int));

    for (int i=0;i<n;i++){
        scanf("%d",&s[i]);
        sum +=s[i];
    }
    printf("%d",sum);
    return 0;
    free(s);
}
