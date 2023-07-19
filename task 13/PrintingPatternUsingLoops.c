#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);
    int s= 2 * n - 1;
        int arr[s][s];

        int inital= 0,finall= s- 1;
      // Complete the code to print the pattern.
    while(n!=0){
      for(int i=inital;i<=finall;i++){
          for (int j=inital;j<=finall;j++){
              if((i==inital)||(i==finall)||(j==inital)||(j==finall))
               arr[i][j]=n;
          }
      }
           inital++;
           finall--;
            n--;
}
 for (int i = 0; i < s; i++)
    {
for (int j = 0; j < s; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
