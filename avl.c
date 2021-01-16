#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* right;
    struct node* left;
    int height; //to check weather tree is balanced 
};
void preorder(struct node* root);
struct node* right_rotation(struct node* r);
struct node* left_rotation(struct node* r);
int getbalance(struct node* r);
int height(struct node * r);
int max(int a, int b);
struct node* new_node(int val);
struct node * insert(struct node* root,int val);


int main()
{
    struct node* root=NULL;
    int d,option,f=1;
    

    while(f!=0)
    {
        printf("\n1.INSERT");
        printf("\n2.PREORDER TRAVERSAL");
        printf("\n3.EXIT");
        printf("\nEnter your option!");
        scanf("%d",&option);
        switch (option)
        {
         case 1: printf("Enter data");
                 scanf("%d",&d);
                 root= insert(root,d);
                 break;
        case 2: printf("The preorder traversal is")
                preorder(root);
                break;
        case 3: f=0;
                break;
        default : printf("Enter correct option");
        }
    
    }
    return 0;
}

struct node * insert(struct node* root,int val)
{
    if(root==NULL)
      return new_node(val);
    
    if (val  < root->data)
    {
        root->left = insert(root->left,val);
    }
    else if (val > root->data)
    {
         root->right= insert(root->right,val);
    }

    else 
     return root;
   
    root->height = 1 + max(height(root->left),height(root->right));

    int balance = getbalance(root);

    //check for conditions

//condtion -> right rotation
    if (balance > 1 && val < root->left->data)
        {
         return right_rotation(root);
        }
     //condition -> left right rotation
     if (balance > 1 && val > root->left->data)
        {
         root->left = left_rotation(root->left);
         return right_rotation(root);
        }

     //condition -> left rotation 
     if (balance < -1 && val > root->right->data )
        {
         return left_rotation(root->right);
        }

     //condition -> right left
     if(balance <- 1 && val < root->right->data)
        {
         root->right = right_rotation(root->right);
         return left_rotation(root);
        }

     
     return root;
     
}

struct node* new_node(int val)
{
    struct node* new_node =NULL;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=val;
    new_node->right=NULL;
    new_node->left=NULL;
    new_node->height=1;
    return (new_node);
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

int height(struct node * r)
{
    if(r==NULL)    
        return 0;
    return r->height;  
}


int getbalance(struct node* r)
{
    if(r==NULL)
    
        return 0;
    
    return (height(r->left) - height(r->right));
   
}

struct node* right_rotation(struct node* r)
{
    struct node* a = r->left;
    struct node *y = a->right;
    a->right=r;
    r->left=y;

    a->height = 1 + max(height(a->left),height(a->right));
    r->height = 1 + max(height(a->left),height(a->right));
    return a;
}

struct node* left_rotation(struct node* r)
{
    struct node *a = r->right;
    struct node *y = a->left;
    a->left=r;
    r->right=y;

    a->height = 1 + max(height(a->left),height(a->right));
    r->height = 1 + max(height(a->left),height(a->right));
    return a;
}

void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf(" %d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}