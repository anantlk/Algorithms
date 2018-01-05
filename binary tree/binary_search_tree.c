#include<stdio.h>

struct node
{
   int data;
   struct node *left;
   struct node *right;
}*root=NULL,*temp,*parent;
void search(struct node *t)
{
   if(temp->data<t->data && t->left!=NULL)
      search(t->left);
   else if(temp->data<=t->data && t->left==NULL)
      t->left=temp;
   else if(temp->data>t->data && t->right!=NULL)
      search(t->right);
   else if(temp->data>t->data && t->right==NULL)
      t->right=temp;
}
void insert()
{
   int n;
   printf("Enter data:");
   scanf("%d",&n);
   temp=malloc(sizeof(struct node));
   temp->left=NULL;
   temp->right=NULL;
   temp->data=n;
   if(root==NULL)
   {
      root=temp;
   }
   else
   {
      search(root);
   }
}
void inorder(struct node *t)
{
   if(root==NULL)
      printf("Empty!!\n");
   else
   {
      if(t->left!=NULL)
      inorder(t->left);
      printf("%d->",t->data);
      if(t->right!=NULL)
      inorder(t->right);
   }
}
void postorder(struct node *t)
{
   if(root==NULL)
      printf("Empty!!\n");
   else
   {
      if(t->left!=NULL)
         postorder(t->left);
      if(t->right!=NULL)
         postorder(t->right);
      printf("%d->",t->data);
   }
}
void preorder(struct node *t)
{
   if(root==NULL)
      printf("Empty!!\n");
   else
   {
      printf("%d->",t->data);
      if(t->left!=NULL)
         preorder(t->left);
      if(t->right!=NULL)
         preorder(t->right);
   }
}
struct node* maxvalue(struct node *t)
{
   if(t->right!=NULL)
    t= maxvalue(t->right);
   return t;
};
struct node* del(struct node *t,int n)
{
   if(root==NULL)
      printf("The tree is empty!!\n");
   else
   {
      if(t==NULL)
         printf("Element not found!!\n");
      else if(n<t->data)
      {
         t->left=del(t->left,n);
      }
      else if(n>t->data)
      {
         t->right=del(t->right,n);
      }
      else
      {
         if(t->left==NULL)
            {
               temp=t->right;
               free(t);
               return temp;
            }
         else if(t->right==NULL)
         {
            temp=t->left;
            free(t);
            return temp;
         }
         else
         {
            temp=maxvalue(t->left);
            t->data=temp->data;
            t->left=del(t->left,temp->data);
         }
      }
   }
   return t;
}
void main()
{
   int ch;
   while(1)
   {
      printf("Enter the choice:\n1.Insert\n2.Display in inorder\n3.Display in postorder\n4.Display in preorder\n5.Delete\n6.Exit\n");
      scanf("%d",&ch);
      if(ch==1)
         insert();
      else if(ch==2)
        {
         inorder(root);
         printf("\n");
        }
      else if(ch==3)
        {
           postorder(root);
           printf("\n");
        }
      else if(ch==4)
      {
         preorder(root);
         printf("\n");
      }
      else if(ch==5)
         {
            int num;
            printf("Enter the data to be deleted:");
            scanf("%d",&num);
            root=del(root,num);
         }
      else if(ch==6)
         break;
      else
         printf("Wrong Option!!\n");
   }
}
