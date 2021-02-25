#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* top =NULL;

struct node* push();
struct node* pop(struct node *top);
void display(struct node* top);
void peek(struct node *top);

int main()
{
  int val, option,f=1;
  while(f!=0)
  {
    printf("\n****MAIN MENU****");
    printf("\n1.PUSH");
    printf("\n2.POP");
    printf("\n3.PEEK");
    printf("\n4.DISPLAY");
    printf("\n5.EXIT");
    printf("\n*********************");
    printf("\n\nEnter your option");
    scanf("%d",&option);
    switch(option)
    {
      case 1:
            top=push();
            break;
      case 2:
            pop(top);
            break;
      case 3:
            peek(top);            
            break;
      case 4:
            display(top);
            break;
      case 5: f=0;
      		  break;
      default:  printf("\n Enter correct choice..");
    }
  }
}

struct node* push()
{
  int d;
  printf("\nEnter Data");
  scanf("%d",&d);
  
  //creating a node
  struct node *ptr =(struct node *)malloc(sizeof(struct node*));
  ptr->data = d;
  ptr->link = NULL;
//updating link part of node
  ptr->link=top;
  top=ptr;
  return top;
}

struct node* pop(struct node *top)
{
  if(top==NULL)
  {
    printf("Stack Underflow");
  }
  else if (top->link==NULL)  //Check if one node
  {
    int val = top->data;
    printf("The number poped is %d",val);
    free(top);
    top=NULL;
    
  }
  else
  {
      struct node *temp=top;
      struct node *temp2=top;
      while(temp->link!=NULL)
      {
        temp2=temp;
        temp=temp->link;
      }
      temp2->link=NULL;
      free(temp);
      temp=NULL;
  }
}

void peek(struct node *top)
{
  int d = top->data;
  printf("%d",d);
}
void display(struct node* top)
{
  if(top==NULL)
  {
    printf("Linked List is Empty");
  }
  else
  {
    struct node *ptr =NULL; //pointer for traversing
    ptr=top;
    while(ptr!=NULL)
    {
      printf("\n %d",ptr->data);
      ptr=ptr->link;
    }
  }
}

