#include<stdio.h>

static int top=-1,stack[10];
void push(int n)
{
   if(top==6)
   {
      printf("Overflow!!\n");
      return 0;
   }
   if(top==-1)
   {
      top=0;
      stack[top]=n;
   }
   else
   {
      top=top+1;
      stack[top]=n;
   }
}
void pop()
{
   top=top-1;
}
void display()
{
   int i;
   printf("\nstack=\n");
   for(i=0;i<=top;i++)
   {
      printf("%d ",stack[i]);
   }
   printf("\n");
}
void DFS(int adj[6][6])
{
   push(0);
   int f=1;
   static int visited[6];
   visited[0]=1;
   printf("0 ");
   while(top!=-1)
   {
      f=0;
      int i=0;
      while(i<6)
      {
         if(adj[stack[top]][i]==1 && visited[i]==0)
         {
            // display();
            visited[i]=1;
            printf("%d ",i);
            push(i);
            i=0;
         }
         i++;
      }
      pop();
   }
}
void main()
{
   int adj[6][6]={{0,1,1,0,0,1},{1,0,0,0,0,0},{1,0,0,1,1,1},{0,0,1,0,1,0},{0,0,1,1,0,0},{1,0,1,0,0,0}};
   DFS(adj);
}
