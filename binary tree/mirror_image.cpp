#include<stdio.h>
#include<iostream>

using namespace std;
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
template <class T> class queue
{
   struct node
   {
      T data;
      struct node *next;
   }*front=NULL,*rear=NULL;
public:
   void push(T data)
   {
      struct node *temp;
      temp=new struct node;
      temp->data=data;
      temp->next=NULL;
      if(rear==NULL)
      {
         front=rear=temp;
      }
      else
      {
         rear->next=temp;
         rear=rear->next;
      }
   }
   void pop()
   {
      if(front==NULL)
         printf("Queue is empty!!\n");
      else if(front==rear)
         front=rear=NULL;
      else
         front=front->next;
   }
   T first()
   {
    return front->data;
   }
   void disp()
   {
      struct node *ptr;
      if(front==NULL && rear==NULL)
         cout<<"Empty!!\n";
      for(ptr=front;ptr!=NULL;ptr=ptr->next)
         cout<<(ptr->data)->data<<" ";
      cout<<"\n";
   }
};
struct tree* create(int n)
{
   struct tree *temp;
   temp=new struct tree;
   temp->data=n;
   temp->right=NULL;
   temp->left=NULL;
   return temp;
}
void insert(int n)
{
   struct list *temp;
   temp=new struct list;
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
void convert()
{
   queue <tree *> q;
   if(head==NULL)
   {
      root=NULL;
      return ;
   }
   root=create(head->data);
   head=head->next;
   q.push(root);
   while(head)
   {
      struct tree *parent=q.first();
      q.pop();
   struct tree *l=NULL,*r=NULL;
   l=create(head->data);
   q.push(l);
   head=head->next;
   if(head)
   {
      r=create(head->data);
      q.push(r);
      head=head->next;
   }
   parent->left=l;
   parent->right=r;
   }
}
void inorder(struct tree *t)
{
   if(root==NULL)
      cout<<"Tree is empty!!\n";
   else
   {
      if(t->left!=NULL)
         inorder(t->left);
      cout<<t->data<<"->";
      if(t->right!=NULL)
         inorder(t->right);
   }
}
void preorder(struct tree *t)
{
   if(root==NULL)
      cout<<"Tree ids empty\n";
   else
   {
      cout<<t->data<<"->";
      if(t->left!=NULL)
         preorder(t->left);
      if(t->right!=NULL)
         preorder(t->right);
   }
}
void postorder(struct tree *t)
{
   if(root==NULL)
      cout<<"The tree is empty!!\n";
   else
   {
      if(t->left!=NULL)
         postorder(t->left);
      if(t->right!=NULL)
         postorder(t->right);
      cout<<t->data<<"->";
   }
}
void mirror_preorder(struct tree *t)
{
   if(root==NULL)
      cout<<"The tree is empty!!\n";
   else
   {
      cout<<t->data<<"->";
      if(t->right!=NULL)
         mirror_preorder(t->right);
      if(t->left!=NULL)
         mirror_preorder(t->left);
   }
}
void mirror_postorder(struct tree *t)
{
   if(root==NULL)
      cout<"The tree is empty!!\n";
   else
   {
      if(t->right!=NULL)
         mirror_postorder(t->right);
      if(t->left!=NULL)
         mirror_postorder(t->left);
      cout<<t->data<<"->";
   }
}
void mirror_inorder(struct tree *t)
{
   if(root==NULL)
      cout<<"The tree is empty!!\n";
   else
   {
      if(t->right!=NULL)
         mirror_inorder(t->right);
      cout<<t->data<<"->";
      if(t->left!=NULL)
         mirror_inorder(t->left);
   }
}
int main()
{
   int ch;
   while(1)
   {
      cout<<"Enter the choice:\n1.Insert(-1 for stopping insertion)\n";
      cin>>ch;
      if(ch==1)
         {
            int n;
            cout<<"Enter the data:";
            cin>>n;
            insert(n);
         }
      else if(ch==-1)
         {
            break;
         }
      else
         cout<<"Wrong Option!!\n";
   }
   convert();
   cout<<"Enter the choice to display:\n1.Inorder\n2.Preorder\n3.Postorder\n";
   cin>>ch;
   if(ch==1)
   {
      inorder(root);
      cout<<"\n";
      cout<<"The mirror inorder is:\n";
      mirror_inorder(root);
   }
   else if(ch==2)
   {
      preorder(root);
      cout<<"\n";
      cout<<"The mirror preorder is:\n";
      mirror_preorder(root);
   }
   else if(ch==3)
   {
      postorder(root);
      cout<<"\n";
      cout<<"The mirror postorder is:\n";
      mirror_postorder(root);
   }
   return 0;
}

