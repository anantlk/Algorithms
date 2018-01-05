#include<stdio.h>

struct tree
{
   int data;
   struct tree *left;
   struct tree *right;
}*root=NULL;
struct tree* convert(int pre[7],int in[7],int l,int r,int index,int n)
{
   struct tree *temp=malloc(sizeof(struct tree));
   if(l>r || index==n)
      return NULL;
   if(temp)
   {
   temp->data=pre[index];
   if(l==r)
      return temp;
   int i;
   for(i=l;i<=r;i++)
   {
      if(pre[index]==in[i])
         break;
   }
      temp->left=convert(pre,in,l,i-1,index+1,n);
      temp->right=convert(pre,in,i+1,r,index+1,n);
   return temp;
   }
   return NULL;
}
void postorder(struct tree *t)
{
   if(t==NULL)
      {
         printf("hi");
         return ;
      }
   if(t->left!=NULL)
      postorder(t->left);
   if(t->right!=NULL)
      postorder(t->right);
   printf("%d ",t->data);
}
void main()
{
   int n=7,pre[7]={30,20,10,12,40,37,45};
   /*printf("Enter the number of nodes:");
   scanf("%d",&n);*/
   //pre=malloc(sizeof(int)*7);
   int i,in[7],j,temp;
   //in=malloc(7*sizeof(int));
   //printf("Enter the preorder traversal:\n");
   /*for(i=0;i<n;i++)
   {
      scanf("%d",&pre[i]);
   }*/
   for(i=0;i<n;i++)
   {
      in[i]=pre[i];
   }
   for(i=0;i<n;i++)
   {
      for(j=0;j<n-i-1;j++)
      {
         if(in[j+1]<in[j])
         {
            temp=in[j];
            in[j]=in[j+1];
            in[j+1]=temp;
         }
      }
   }
   root=convert(pre,in,0,n-1,0,n);
   //printf("root=%d\n",root->data);
   postorder(root);
   printf("\n");
   free(pre);
   free(in);
}
