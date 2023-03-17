#include <stdio.h>
typedef union database{

  struct shops {
    char name ;
    char location;
   };
  struct  product_info { 
    int id ; 
    float price ;
    float quantity; 
   };
  struct category  { 
    int id_g ;
    int products_num ;
    };
} database;
int main()
{
    // the size of database = the size of largest nested structs
    printf("size of union database: %ld\n", sizeof(database));
    printf("size of struct shops: %ld\n", sizeof(struct shops));
    printf("size of struct product_info: %ld\n", sizeof(struct product_info));
    printf("size of struct category: %ld\n", sizeof(struct category ));
    return 0;
}