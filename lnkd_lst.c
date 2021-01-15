#include<stdio.h>
#include<stdlib.h>
//node
struct node
{
    int data;
    struct node *link;
};

struct node *head=NULL;

struct node* inst_at_begin(); //function prototype
void inst_at_end(struct node *head);
void inst_at_pos(struct node *head);
struct node* del_at_begin(struct node *head);
struct node* del_at_end(struct node *head);
void del_at_pos(struct node **head);
void print_data(struct node *head);

int main()
{
  //variable declaration
  int val, option,f=1;
  int insert,delete;

    while(f!=0)
    {
      //menu
      printf("\n****MAIN MENU****");
      printf("\n1.INSERT");
      printf("\n2.DELETE");
      printf("\n3.DISPLAY");
      printf("\n4.EXIT");
      printf("\n*********************");
      printf("\n\nEnter your option");
      scanf("%d",&option);
      switch(option)
      {
        case 1:
              //sub menu insert
              printf("\n****INSERT****\n");
              printf("\n1.INSERT AT FRONT\n");
              printf("\n2.INSERT AT END\n");
              printf("\n3.INSERT AT RANDOM POSITION\n");
              printf("\n Enter your option\n");
              scanf("%d",&insert);
                  switch(insert)
                  {
                    case 1:
                            head=inst_at_begin();
                            break;
                    case 2:
                            inst_at_end(head);
                            break;
                    case 3:
                            inst_at_pos(head);
                            break;
                    default: printf("\nEnter correct option!");
                  }

              break;
        case 2:
            //sub menu delete
            printf("\n****DELETE****");
            printf("\n1.DELETE AT FRONT");
            printf("\n2.DELETE AT END");
            printf("\n3.DELETE AT RANDOM POSITION");
            printf("\n Enter your option");
            scanf("%d",&delete);
                switch(delete)
                {
                  case 1:
                          del_at_begin(head);
                          break;
                  case 2:
                          del_at_end(head);
                           break;
                  case 3:
                          del_at_pos(&head);
                          break;
                  default: printf("\nEnter correct option!");
                }
              break;
        case 3:
           //display
          print_data(head);
          break;
        case 4: f=0;
                break;

        default:  printf("\n Enter correct choice..");
      }
    }
    return 0;
}


//fuction to insert at beginning
struct node* inst_at_begin()
{
  int d;
  printf("\nEnter Data");
  scanf("%d",&d);
  
  //creating a node
  struct node *ptr =(struct node *)malloc(sizeof(struct node*));
  ptr->data = d;
  ptr->link = NULL;
//updating link part of node
  ptr->link=head;
  head=ptr;
  return head;
}

//function to insert at end
void inst_at_end(struct node *head)
{
  int data;
  printf("Enter Data");
  scanf("%d",&data);
  struct node *ptr,*temp;
  ptr=head;
  temp=(struct node*)malloc(sizeof(struct node *));

  temp->data=data;
  temp->link=NULL;

  while(ptr->link!=NULL)
  {
    ptr=ptr->link; //updating value of ptr
  }
  ptr->link=temp;
}

//function to insert at any position
void inst_at_pos(struct node *head)
{
  int pos,data;
  printf("\nEnter position");
  scanf("%d",&pos);
  printf("\nEnter Data");
  scanf("%d",&data);

  struct node *ptr = head;
  struct node *ptr2 = (struct node *)malloc(sizeof(struct node*));
  ptr2->data=data;
  ptr2->link=NULL;
  pos --;
  while(pos!=0)
  {
    ptr=ptr->link;
    pos--;
  }
  ptr2->link=ptr->link;
  ptr->link=ptr2;
}

//functon to delte first node
struct node* del_at_begin(struct node *head)
{
  if(head==NULL)
  {
    printf("\nList is already empty!");
  }
  else
  {
    struct node *temp=head;
    head=head->link;
    free(temp);
  }
  return head;
}

//function to delete last node
struct node* del_at_end(struct node *head)
{
  if(head==NULL)
  {
    printf("\nlist is already empty");
  }
  else if (head->link==NULL)  //Check if one node
  {
    free(head);
    head=NULL;
  }
  else
  {
      struct node *temp=head;
      struct node *temp2=head;
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

//fuction to delete node at any position
void del_at_pos(struct node **head)
{
  int pos;
  printf("\nEnter the position you want to delete");
  scanf("%d",&pos);
  struct node *curr=*head;
  struct node *prev=*head;
  if(*head=NULL)
    {
      printf("list is  already empty!");
    }
  else if(pos==1)
    {
      *head=curr->link;
      free(curr);
      curr=NULL;
    }
  else
  {
      while(pos!=1)
      {
        prev=curr;
        curr=curr->link;
        pos--;
      }
      prev->link=curr->link;
      free(curr);
      curr=NULL;
  }
}
//function to display linked list
void print_data(struct node* head)
{
  if(head==NULL)
  {
    printf("Linked List is Empty");
  }
  else
  {
    struct node *ptr =NULL; //pointer for traversing
    ptr=head;
    while(ptr!=NULL)
    {
      printf("%d",ptr->data);
      ptr=ptr->link;
    }
  }
}
