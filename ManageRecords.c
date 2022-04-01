/*Name: Nina Jovic*/
/*UFID: 1447-7201*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
        char name[20];
        int age;
        struct record *left; 
        struct record *right;
    };
    struct record *starting_record = NULL;
    struct record *current_record=NULL;
    
    
void print_preorder(struct record *starting_record){
    
    if (starting_record)
    {
        print_preorder(starting_record->left);
        printf("%s %d\n",starting_record->name,starting_record->age);
        print_preorder(starting_record->right);
    }

}
    
struct record *insert(struct record *starting_record, char name[], int age){
    
struct record *y;
y=NULL;
struct record *x = starting_record;

while(x!=NULL){
    y=x;
    if(strcmp(name,x->name)<0){
      x=x->left;
    }
    else{
      x = x->right;
    }
}
if(y==NULL){
    starting_record=malloc(sizeof(struct record));
    strcpy((*starting_record).name,name);
    ((*starting_record)).age=age;
     return starting_record;
}

else if(strcmp(name,y->name)<0){
    y->left=malloc(sizeof(struct record));
    strcpy((*y->left).name,name);
    ((*y->left)).age=age;
    return y->left;
}
else{
    y->right=malloc(sizeof(struct record));
    strcpy((*y->right).name,name);
    ((*y->right)).age=age;
    return y->right;
            }
}


int BST_Search(char Name[], struct record  *current_record){

if (current_record==NULL){
return -1;
 }
if(strcmp(Name,current_record->name)==0){
return current_record->age;
}
else if(strcmp(Name,current_record->name)<0){
return BST_Search(Name, current_record->left) ;
}
else{
return BST_Search(Name, current_record->right);
}
}

int main(){
int c,k;
c=0;
k=1;
int op,age,age1;
char name[20],Name[20];

while(1){
printf("1: Insert\n2: Search\n3: Print all in sorted order\n4: Exit\n");
printf("Enter the required operation: ");
scanf("%d",&op);

if(op==1){
    printf("Enter name and the age: ");
   scanf("%s",name);
   scanf("%d",&age);
    if (c==0){
   starting_record = insert(starting_record,name,age);
   c++;
  
    }
   else {
   current_record=insert(starting_record,name,age);
   
   }
}

if(op==2){
    
     printf("Enter the name of the employee: ");
     scanf("%s",Name);
    
     age1=BST_Search(Name,starting_record);
  printf("Age is : %d\n",age1);
     
 } 

 if(op==3){
           print_preorder(starting_record);
            }
            
 if(op==4){
     printf("Bye Bye\n");
     break;
 }

 
}
return 0;
}