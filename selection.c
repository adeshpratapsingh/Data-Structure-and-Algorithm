// selection code in c programming language 
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX];
int rear1=-1;
int front1=-1;
int rear2=MAX;
int front2=MAX;

void enQueue(int val)
{ 
 if(rear1==rear2-1) 
 {
 printf("Queue is full!!Insertion is not possible!!!\n");
 return;
 }
 else 
 {
 if(rear1==-1)
 {
 front1=rear1=0;
 } 
 else 
 {
 rear1++;
 }
 queue[rear1]=val;
 }
}
int deQueue()
{
 if(front1==-1)
 {
 printf("Queue is empty!!Deletion is not possible!!!\n");
 return -1;
 } 
 else
 { 
 int ele=queue[front1];
 if(rear1==front1)
 {
 rear1=front1=-1;
 }
 else
 {
 front1++;
 }
 return ele;
 }
}
void display1()
{int i ;
 if(rear1==-1 && front1==-1)
 {
 printf(" ");
 return;
 }
 printf("\nQueue elements:  ");
 for(i=front1;i<=rear1;i++)
 {
 printf("%d\t",queue[i]);
 }

}
void inject(int val)
{
 if(rear1==rear2-1) 
 {
 printf("Queue is full!!Insertion is not possible!!!\n");
 return;
 }
 else 
 {
 if(rear2==MAX)
 {
 rear2=front2=MAX-1;
 } 
 else 
 {
 rear2--;
 }
 queue[rear2]=val;
 }
}
int eject()
{
 if(front2==MAX)
 {
 printf("Queue is empty!!Deletion is not possible!!!\n");
 return -1;
 } 
 else
 { 
 int ele=queue[front2];
 if(rear2==front2)
 {
 rear2=front2=MAX;
 }
 else
 {
 front2--;
 }
 return ele;
 }
}
void display2()
{ int i;
 if(rear2==MAX && front2==MAX)
 {
 printf(" ");
 return;
 }
 for(i=front2;i>=rear2;i--)
 {
 printf("%d\t",queue[i]);
 }
 printf("\n");
}

int main()
{
 int choice,value1,value2,element1,element2,n,i;
 printf("**MENU**\n");
 printf("1.Insert an element from the beginning\n2.Delete an element from the beginning\n3.Display Queue1\n4.Insert an element from the ending\n5.Delete an element from the ending\n6.EXIT\n");
                 

 
 while(1)
 { 
 printf("\nEnter your choice:\n");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
    printf("Enter the number of elements to be inserted : ");
        scanf("%d",&n);
        printf("Enter your data:\n");
        i=0;
        while(i<n){
          scanf("%d",&value1);
          enQueue(value1);
          i++;
        }   
 break;
 case 2:element1=deQueue();
 if(element1!=-1)
 {
 printf("The deleted element is:%d\n",element1); 
 }
 break;
 case 3:
 if(rear2==MAX && front2==MAX && rear1==-1 && front1==-1)
 {
 printf("Queue is empty!!!");
 }
 display1();
 display2();
 break;
 case 4: printf("Enter the number of elements to be inserted : ");
        scanf("%d",&n);
        printf("Enter your data:\n");
        i=0;
        while(i<n){
    scanf("%d",&value2);
        inject(value2); 
          i++;
        }   
 break;
 case 5:element2=eject();
 if(element2!=-1)
 {
 printf("The deleted element is:%d\n",element2); 
 }
 break;
 case 6:printf("Exiting....");
 exit(0);
 break;
 default:printf("Wrong choice!!Please enter a valid number!!!\n");
 }
 }
 return 0;
}
