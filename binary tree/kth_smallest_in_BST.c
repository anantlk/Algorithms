#include<stdio.h>

struct tree
{
   int data;
   struct tree *left,*right;
}*root=NULL,*temp;
int count =0,k,tot=0;
void search(struct tree *t)
{
   if(temp->data<t->data && t->left!=NULL)
      search(t->left);
   else if(temp->data <=t->data && t->left==NULL)
      t->left=temp;
   else if(temp->data>t->data && t->right!=NULL)
      search(t->right);
   else if(temp->data>=t->data && t->right==NULL)
      t->right=temp;
}
void insert()
{
   int n;
   printf("Enter the data:");
   scanf("%d",&n);
   temp=malloc(sizeof(struct tree));
   temp->data=n;
   temp->left=NULL;
   temp->right=NULL;
   if(root==NULL)
   {
      root=temp;
   }
   else
   {
      search(root);
   }
}
void kth(struct tree *t)
{
   if(root==NULL)
      printf("The tree is empty!!\n");
   else
   {
      if(t->left!=NULL)
      kth(t->left);
      count+=1;
      if(count==k)
        {
         printf("The %d smallest element in the BST is :%d\n",k,t->data);
         exit(0);
        }
      if(t->right!=NULL)
         kth(t->right);
   }
}
void inorder(struct tree *t)
{
   if(root==NULL)
      printf("The tree is empty!!\n");
   else
   {
      if(t->left!=NULL)
         inorder(t->left);
      printf("%d->",t->data);
      if(t->right!=NULL)
         inorder(t->right);
   }
}
int main()
{
   int ch;
   while(1)
   {
      printf("Entee the choice:\n1.Insert\n2.Stop insertion\n");
      scanf("%d",&ch);
      if(ch==1)
      {
         insert(root);
         tot+=1;
      }
      if(ch==2)
         break;
   }
   printf("Enter the value of k:");
   scanf("%d",&k);
   if(k<=tot)
   {
      printf("\n");
      inorder(root);
      printf("\n\n");
      kth(root);
   }
   else
      printf("The size exceeds the number of nodes!!\n");
}
