#include<stdio.h>

static int c=0,q=0;
int n_s,n_q;
struct list
{
   int data;
   struct list *next;
}*top=NULL,*front=NULL,*rear=NULL,*temp;
void push(struct list **top,int n)
{
   if(c==n_s)
   {
      printf("Overflow\n");
      return 0;
   }
   temp=malloc(sizeof(struct list));
   temp->data=n;
   temp->next=NULL;
   if(*top==NULL)
   {
      *top=temp;

   }
   else
   {
      temp->next=*top;
      *top=temp;
   }
   c++;
}
void pop(struct list **top)
{
   if(c==0)
   {
      printf("Underflow\n");
      return 0;
   }
   c--;
   (*top)=(*top)->next;
}
void display_s()
{
   if(top==NULL)
   {
      printf("Empty\n");
      return;
   }
   struct list *ptr;
   for(ptr=top;ptr!=NULL;ptr=ptr->next)
   {
      printf("%d ",ptr->data);
   }
   printf("\n");
}
int peak(struct list *top)
{
   return top->data;
}
void enqueue(struct list **front,struct list **rear,int n)
{
   if(q==n_q)
   {
      printf("Overflow!!\n");
      return 0;
   }
   temp=malloc(sizeof(struct list));
   temp->data=n;
   temp->next=NULL;
   if(*front==NULL && *rear==NULL)
   {
      *front=*rear=temp;
   }
   else
   {
      (*rear)->next=temp;
      *rear=(*rear)->next;
   }
   q++;
}
void dequeue(struct list **front,struct list **rear)
{
   if(*front==NULL)
   {
      printf("Underflow\n");
      return 0;
   }
   else if(*front==*rear)
   {
      q--;
      *front=*rear=NULL;
   }
   else
   {
      q--;
      *front=(*front)->next;
   }
}
void display_q()
{
   struct list *ptr;
   if(front==NULL)
   {
      printf("Empty\n");
      return ;
   }
   for(ptr=front;ptr!=rear->next;ptr=ptr->next)
   {
      printf("%d ",ptr->data);
   }
   printf("\n");
}
void main()
{
    int n;
    char ch1,ch2;
    printf("Enter the No. of elements of stack:");
    scanf("%d",&n_s);
    printf("Enter the No. of elements of queue:");
    scanf("%d",&n_q);
    while(1)
    {
        printf("Enter the choice:\n1.Stack\n  a.Push\n  b.Pop\n  c.Peak\n  d.Size\n  e.Display\n2.Queue\n  a.Enqueue\n  b.Dequeue\n  c.Size\n  d.Display\n3.Exit\n");
        scanf(" %c%c",&ch1,&ch2);
        if(ch1=='1')
        {
            if(ch2=='a')
            {
               printf("Enter the data:");
               scanf("%d",&n);
               push(&top,n);
            }
            else if(ch2=='b')
            {
               pop(&top);
            }
            else if(ch2=='c')
                {
                   int p;
                   p=peak(top);
                   printf("peak=%d\n",p);
                }
            else if(ch2=='d')
                {
                   printf("size=%d\n",c);
                }
            else if(ch2=='e')
            {
               display_s();
            }
        }
        else if(ch1=='2')
        {
            if(ch2=='a')
                {
                   printf("Enter the data:");
                   scanf("%d",&n);
                   enqueue(&front,&rear,n);
                }
            else if(ch2=='b')
                {
                  dequeue(&front,&rear);
                }
            else if(ch2=='c')
                {
                   printf("size=%d\n",q);
                }
            else if(ch2=='d')
            {
               display_q();
            }
        }
        else if(ch1=='3')
            break;
    }
    free(temp);
}
