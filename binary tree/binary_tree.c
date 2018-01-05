#include<stdio.h>

struct list
{
   int data;
   struct list *next;
}*head=NULL;
struct tree
{
   int data;
   struct tree *left;
   struct tree *right;
}*root=NULL,*front=NULL;
struct tree* create(int data)
{
   struct tree *p;
   p=malloc(sizeof(struct tree));
   p->data=data;
   p->left=NULL;
   p->right=NULL;
   return p;
};
void insert(int n)
{
   struct list *temp;
   temp=malloc(sizeof(struct list));
   temp->data=n;
   temp->next=NULL;
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
void push(struct tree *t)
{
   struct tree *ptr;
   if(front==NULL)
   {
      front=t;
   }
   else
   {
      for(ptr=front;ptr->right!=NULL;ptr=ptr->right);
      ptr->right=t;
   }
}
void pop()
{
   front=front->right;
}
void convert()
{
   if(head==NULL)
   {
      root=NULL;
      return ;
   }
   root=create(head->data);
   push(root);
   head=head->next;
   while(head)
   {
      struct tree *parent;
      parent=front;
      pop();
      struct tree *l=NULL,*r=NULL;
      l=create(head->data);
      push(l);
      head=head->next;
      if(head)
      {
         r=create(head->data);
         push(r);
         head=head->next;
      }
      parent->left=l;
      parent->right=r;
   }
}
void add()
{
   struct list *ptr;
   for(ptr=head;ptr!=NULL;ptr=ptr->next)
      push(create(ptr->data));
}

void inorder(struct tree *t)
{
   if(root==NULL)
      printf("Tree is empty!!\n");
   else
   {
      //printf("tree=%d\n",t->data);
      if(t->left!=NULL)
         inorder(t->left);
      printf("%d->",t->data);
      if(t->right!=NULL)
         inorder(t->right);
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
void disp()
{
   struct tree *ptr;
   for(ptr=front;ptr!=NULL;ptr=ptr->right);
   printf("%d ",ptr->data);
   printf("\n");
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
            display();
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
   /*struct tree *ptr=root,*t;
   printf("%d->",ptr->data);
   ptr=root->left;
   printf("%d->",ptr->data);
   ptr=root->right;
   printf("%d->",ptr->data);
   t=root->left;
   ptr=t->left;
   printf("%d->",ptr->data);
   ptr=t->right;
   printf("%d->",ptr->data);*/
}
