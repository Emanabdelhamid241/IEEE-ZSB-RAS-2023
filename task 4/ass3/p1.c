 /*
     * C program to accept N numbers and arrange them in an ascending order
     */
 
    #include <stdio.h>
    #define op A
    #define op2 D
    void ascending(){
     int i, j, a, n, number[99];
        printf("Enter the value of N \n");
        scanf("%d", &n);
        printf("Enter the numbers \n");
        for (i = 0; i < n; i++)
            scanf("%d", &number[i]);
        for (i = 0; i < n; i++) 
        {
            for (j = i + 1; j < n; j++)
            {
                if (number[i] > number[j]) 
                {
                    a =  number[i];
                    number[i] = number[j];
                    number[j] = a;
                }
            }
        }
        printf("The numbers arranged in ascending order are given below \n");
        for (i = 0; i < n; i++)
            printf("%d\n", number[i]);
            }
    void descending(){
        /*
    * C program to accept a set of numbers and arrange them
    * in a descending order
    */
 
 
        int number[30];
 
        int i, j, a, n;
        printf("Enter the value of N\n");
        scanf("%d", &n);
 
        printf("Enter the numbers \n");
        for (i = 0; i < n; ++i)
	        scanf("%d", &number[i]);
 
        /*  sorting begins ... */
 
        for (i = 0; i < n; ++i) 
        {
            for (j = i + 1; j < n; ++j) 
            {
                if (number[i] < number[j]) 
                {
                    a = number[i];
                    number[i] = number[j];
                    number[j] = a;
                }
            }
        }
 
        printf("The numbers arranged in descending order are given below\n");
 
        for (i = 0; i < n; ++i) 
        {
            printf("%d\n", number[i]);
        }
 
    }
   
    void main()
    {
        char p ;
        printf("enter the type of sort\n");
        printf("D if you want Descending order\n");
        printf("A if you want  Ascending  order\n");
        scanf("%c",&p);
        #ifdef op
          ascending();
        #elif op2
          descending();
        #endif
        // switch(p){
        //     case 'D':
        //     descending();
        //     break;
        //     case 'A':
        //     ascending();
            
        // }
 
 
    }