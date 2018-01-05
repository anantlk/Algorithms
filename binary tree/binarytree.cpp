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
void display()
{
   struct list *ptr;
   if(head==NULL)
      cout<<"Empty!!\n";
   for(ptr=head;ptr!=NULL;ptr=ptr->next)
      cout<<ptr->data<<"->";
   cout<<"\n";
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
      q.disp();
      struct tree *parent=q.first();
      q.disp();
      cout<<"parent="<<parent->data<<"\n";
      q.pop();
      q.disp();
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
int main()
{
   int ch;
   while(1)
   {
      cout<<"Enter the choice:\n1.Insert\n2.Inorder\n3.Exit\n4.Display\n";
      cin>>ch;
      if(ch==1)
         {
            int n;
            cout<<"Enter the data:";
            cin>>n;
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
         cout<<"Wrong Option!!\n";
   }
   convert();
   inorder(root);
   cout<<"\n";
   return 0;
}
