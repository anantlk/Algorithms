#include<stdio.h>

struct node{
   int data;
   struct node *next;
}*head;
void add()
{
   struct node *np;
   int num;
   printf("Enter the number:");
   scanf("%d",&num);
   np=(struct node *)malloc((sizeof(struct node)));
   np->data=num;
   if(head==NULL)
   {
      printf("I am Null\n");
      head=np;
      head->next=NULL;
   }
   else
   {
      printf("I am Not Null");
      np->next=head;
      head=np;
   }
   free(np);
}
void display()
{
   while(head!=NULL)
   {
      printf("%d ",head->data);
      head=head->next;
   }
}
void main()
{
   int n;
   struct node *head=NULL;
   while(1)
   {
   printf("Enter the option:\n1.Add in the begining\n2.Display\n3.Exit\n");
   scanf("%d",&n);
   if(n==1)
      add();
   else if(n==2)
      display();
   else if(n==3)
      break;
   else
      printf("Wrong entry\n");
   }
}
