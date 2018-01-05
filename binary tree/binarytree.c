#include<stdio.h>
struct list
{
   int data;
   struct list *next;
}*head=NULL;
struct tree
{
   int data;
   struct tree *left,*right;
}*root=NULL;
struct tree* create(int n)
{
   struct tree *temp;
   temp=malloc(sizeof(struct tree));
   temp->data=n;
   temp->right=NULL;
   temp->left=NULL;
   return temp;
}
void insert(int n)
{
   struct list *temp;
   temp=malloc(sizeof(struct list));
   temp->next=NULL;
   temp->data=n;
   if(head==NULL)
   {
      head=temp;
   }
   else
   {
      struct list *ptr;
      for(ptr=head;ptr->next!=NULL;ptr=ptr->next);
      ptr->next=temp;
   }
}
void display()
{
   struct list *ptr;
   if(head==NULL)
      printf("Empty!!\n");
   for(ptr=head;ptr!=NULL;ptr=ptr->next)
      printf("%d ",ptr->data);
   printf("\n");
}
void convert()
{
   struct tree *parent;
   struct list *ptr1=head,*ptr2=head;
   if(head==NULL)
   {
      root=NULL;
      return ;
   }
   root=create(head->data);
   parent=root;
   ptr1=ptr1->next;
   ptr2=ptr2->next;
   while(ptr2)
   {
   struct tree *l=NULL,*r=NULL;
   l=create(ptr2->data);
   ptr2=ptr2->next;
   if(ptr2)
   {
      r=create(ptr2->data);
      ptr2=ptr2->next;
   }
   parent->left=l;
   parent->right=r;
   parent=create(ptr1->data);
   ptr1=ptr1->next;
   }
}
void inorder(struct tree *t)
{
   if(root==NULL)
      printf("Tree is empty!!\n");
   else
   {
      if(t->left!=NULL)
         inorder(t->left);
      printf("%d->",t->data);
      if(t->right!=NULL)
         inorder(t->right);
   }
}
void main()
{
   int ch;
   while(1)
   {
      printf("Enter the choice:\n1.Insert\n2.Inorder\n3.Exit\n4.Display\n");
      scanf("%d",&ch);
      if(ch==1)
         {
            int n;
            printf("Enter the data:");
            scanf("%d",&n);
            insert(n);
         }
      else if(ch==2)
         {
            ;
         }
      else if(ch==3)
         break;
      else if(ch==4)
            display();
      else
         printf("Wrong Option!!\n");
   }
   convert();
   inorder(root);
   printf("\n");
}
