#include <stdio.h>
#include <stdlib.h>
// A linked list node
typedef struct Node
{
int data;
char element;
struct Node *next;
}Node;
Node *head ;

// -----------------------------------------------
Node* Append(Node *head, int element){
	Node *new_node = NULL;

	new_node =(Node *) malloc(sizeof(Node));
    if (new_node == NULL){
		return NULL;
	}
	new_node->element = element ;
	new_node->next = NULL;
    if (head != NULL){
		Node *temp = head;
		while (temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new_node;
	}
    return new_node;
}
//----------------------------
int Length (Node *head){
	int len=1;
	if(head == NULL)
	  return 0;
	Node *temp = head;
	while (temp->next != NULL){
		len++;
		temp =temp->next;
	}
	return len;
}
// --------------------------------------------------
int Get_Element(Node *head, int node_number, char*element){
 if(head == NULL){ // linked list is empty
return 0;
 }

 if((node_number > Length(head)) || (node_number < 1)){
 return -1;
 }

 // this address points to 1st node
 Node *temp = head;
 int x = 1;
 while(x < node_number){
 // move temp to the next node
 temp = temp->next;
 x++;
 }
 *element = temp->element;
 return 1;
 }
 
// ----------------------------------------
int Delete_Node(Node *head, int node_number){
	// if linked list empty
	if(head== NULL){
	   return 0;}
// if linked list not empty
	if(node_number > Length(head) || node_number < 2)
	    return -1 ;
	
	// to delete any node in linked list
	Node *prev = head, *current;
	int x=1;
	while (x < node_number - 1){
		prev = prev->next ;
		x++;
	}
	 current = prev->next;
	prev->next = current->next;
	free(current);
	return 1;
}
// -----------------------------------------------------
int Insert (Node *head , int node_number, char element){
		// if linked list empty
	if(head== NULL)
	   return 0;
	   // if linked list not empty
	if((node_number > Length(head)) || (node_number <1)){
		return -1 ;
	}
	Node *prev = head, *current;
	int x =1;
	current =(Node *)malloc(sizeof(Node));
	// node is empty
	if (current == NULL){
		return 0;
	while (x<node_number){
			prev = prev->next;
			x++;
		}
		current->element =element;
		current->next =prev->next ;
		prev->next = current;
		return 1;
	}}
    // return new_node;
// -----------------------------------------------------
int main(){
	Node *ptr_head = NULL;
	int len=0 , x=0 ;
	char element;
	char *ptr_element = &element;
	ptr_head =Append(ptr_head, 's');
	Append(ptr_head, 's');
	Append(ptr_head, 's');
    Append(ptr_head, 's');
	Append(ptr_head, 's');
	Append(ptr_head, 's');
    printf("enter do you want to do\n");
    printf("if you want to add a node enter '+' :\n");
    printf("if you want to delete a node enter '-' :\n");
    printf("if you want to print linked list enter 'p' :\n");
    printf("if you want to stop enter 's' :\n");
    char mark;
    scanf("%c",&mark);
    switch (mark)
    {
    case 'p':
        len = Length (ptr_head);
	    for(x=1; x<= len; ++x){
		   Get_Element(ptr_head, x ,ptr_element);
		   printf("\n %d --> %c",x, *ptr_element);
	    }
	    printf("\n -----------------");

        break;
    case '-':
       Delete_Node(ptr_head, 5);
	   len = Length(ptr_head);
	   for(x=1; x<= len; ++x){
		  Get_Element(ptr_head, x ,ptr_element);
		  printf("\n %d --> %c",x, *ptr_element);
	    }
	    printf("\n -----------------");
        break;

    case '+':
	   Insert(ptr_head, 2, 'M');
       len = Length(ptr_head);
       for(x=1; x<= len; ++x){
          Get_Element(ptr_head, x, ptr_element);
           printf("\n %d --> %c", x, *ptr_element);
        }
        printf("\n ---------");
        break;

    case 's':
       break;
    }
	
	
	return 0;
}