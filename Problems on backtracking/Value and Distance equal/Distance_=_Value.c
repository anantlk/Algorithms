#include<stdio.h>
static int z=0;
void display(int n,int a[n])
{
   int i;
   for(i=0;i<n;i++)
   {
      printf("%d ",a[i]);
   }
   printf("\n");
}
void initial(int n,int a[2*n],int visited[n])
{
   int i;
   for(i=0;i<2*n;i++)
   {
      a[i]=0;
   }
   for(i=0;i<n;i++)
   {
      visited[i]=0;
   }
}
int check_comp(int n,int a[2*n])
{
   int i;
   for(i=0;i<2*n;i++)
   {
      if(a[i]==0)
         return 0;
   }
   return 1;
}
int check(int k,int pos,int n,int a[2*n])
{
   if(pos+k+1<2*n)
   {
      if(a[pos]==0 && a[pos+k+1]==0)
         return 1;
   }
   return 0;
}
void combination(int n,int pos,int a[2*n],int visited[n])
{
   if(check_comp(n,a)==1)
   {
      display(2*n,a);
      z=1;
      return ;
   }
   int i;
   //display(2*n,a);
   if(a[pos]==0)
   {
   for(i=1;i<=n;i++)
   {
      if(visited[i-1]==0 && check(i,pos,n,a))
      {
         visited[i-1]=1;
         a[pos]=a[pos+i+1]=i;
         combination(n,pos+1,a,visited);
         a[pos]=a[pos+i+1]=0;
         visited[i-1]=0;
      }
   }
   }
   else
   {
      combination(n,pos+1,a,visited);
   }
}
void main()
{
   int n;
   printf("Enter the number:");
   scanf("%d",&n);
   int i,a[2*n],d=n;
   int visited[n];
   initial(n,a,visited);
   combination(n,0,a,visited);
   if(z==0)
      printf("No solution!!\n");
}
