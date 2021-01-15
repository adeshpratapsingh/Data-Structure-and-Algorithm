#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node* left;
    struct node* right;
};


struct node* newnode(int data);
struct node* insert(struct node* root,int data );
int main()
{   
    struct node* root=NULL; //to store address ofroot
    int option,data,f=1;
    while(f!=0)
    {
        printf("\n****BINARY SEARCH TREE****");
        printf("\n1.Insert");
        printf("\n2.Exit");
        printf("\n**************************");
        printf("\n Enter your option");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("Enter your data");
                scanf("%d",&data);
                insert(root,data);
                break;
            case 2:
                f=0;
                break;

        }

    }
}

struct node* newnode(int data)
{
    struct node* newnode =(struct node*)malloc(sizeof(struct node*));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
}

struct node* insert(struct node* root,int data)
{
    if(root==NULL)
    {
        root=newnode(data);
    }
    else if(data<root->data)
    {
        root->left=insert(root->left,data);    
    }
    else //data>root->data
    {
        root->right=insert(root->right,data);
    }
    return root;
}