// Arrays and pointers: 
// to count a total  number of duplicate elements in an  array. 
#include <stdio.h>
int main()
{
//Initialize array     
int arr[] = {1, 2, 3, 4, 2, 7, 8, 8, 3};
//Calculate length of array arr    
int length = sizeof(arr)/sizeof(arr[0]);
printf("Duplicate elements in given array:\n");
//Searches for duplicate element    
for(int i = 0; i < length; i++) {
  for(int j=i+1;j<length;j++){
if(arr[i]== arr[j])
printf("%d\n",arr[j]);
}
}
return 0;
}


// //to print all  unique elements in an array. 

#include <stdio.h>
int main()
{
    int arr1[100], n,c=0;
    int i, j, k;
       printf("\n\nPrint all unique elements of an array:\n");
       printf("------------------------------------------\n"); 
       printf("Input the number of elements to be stored in the array: ");
       scanf("%d",&n);
       printf("Input %d elements in the array :\n",n);
       for(i=0;i<n;i++)
            {
       printf("element - %d : ",i+1);
       scanf("%d",&arr1[i]);
     }
    printf("\nThe unique elements found in the array are: \n");
    for(i=0; i<n; i++)
    {
        c=0;
        for(j=0,k=n; j<k+1; j++)
        {
            /*Increment the counter when the seaarch value is duplicate.*/
            if (i!=j)
            {
         if(arr1[i]==arr1[j])
              {
                 c++;
               }
             }
        }
       if(c==0)
        {
          printf("%d ",arr1[i]);
        }
    }
       printf("\n\n");
}


// //defines a function taking array as input argument and count the frequency of each element  of an array. 

#include <stdio.h>
int main()

{
//Initialize array     
int arr[]={1, 2, 8, 3, 2, 2, 2, 5, 1};
//Calculate length of array arr    
int len=sizeof(arr)/sizeof(arr[0]);
//Array fr will store frequencies of element    
int fr[len];
int visited = -1;
for(int i=0;i<len;i++){
  int c = 1;
  for(int j=i+1; j < len; j++){
    if(arr[i]==arr[j]){
      c++;
//To avoid counting same element again    
       fr[j]=visited;
}
}
if(fr[i]!=visited)
  fr[i] =c;
}
//Displays the frequency of each element present in array    
printf("---------------------\n");
printf("Element | Frequency\n");
printf("---------------------\n");

for(int i=0;i<len;i++){
  if(fr[i] !=visited){

printf("   %d",arr[i]);
printf("   |    ");
printf("%d\n",fr[i]);
}
}
printf("---------------------\n");
return 0;
}


// // to add  numbers using call by reference.

#include <stdio.h>
long addTwoNumbers(long *, long *);
 
int main()
{
   long f, s, sum;
   printf("\n\n Pointer : Add two numbers using call by reference:\n"); 
   printf("-------------------------------------------------------\n");   
   printf(" Input the first number : ");
   scanf("%ld", &f);
   printf(" Input the second  number : ");
   scanf("%ld", &s);   
   sum = addTwoNumbers(&f, &s);
   printf(" The sum of %ld and %ld  is %ld\n\n", f, s, sum);
   return 0;
}
long addTwoNumbers(long *n1, long *n2) 
{
   long sum;
   sum = *n1 + *n2;
   return sum;
}