#include<stdio.h>
#include"display.c"

static int c=0;
int check(int **a,int row,int col,int n)
{
   int i,j;
   for(j=col-1;j>=0;j--)
   {
      if(a[row][j]==1)
      {
         return 0;
      }
   }
   i=row-1;
   j=col-1;
   while(i>=0 && j>=0)
   {
      if(a[i][j]==1)
         return 0;
      i--;
      j--;
   }
   i=row+1;
   j=col-1;
   while(i<n && j>=0)
   {
      if(a[i][j]==1)
         return 0;
      i++;
      j--;
   }
   return 1;
}
int backtrack(int **a,int col,int n)
{
   if(col==n)
      {
         c++;
         display(a,n,c);
         return 1;
      }
   int i;
   for(i=0;i<n;i++)
   {
      if(check(a,i,col,n))
      {
         a[i][col]=1;
         backtrack(a,col+1,n);
         a[i][col]=0;
      }
   }
   return 0;
}
int main()
{
   int n,i,j;
   printf("Enter the number of queens:");
   scanf("%d",&n);
   int **a;
   a=malloc(sizeof(int*)*n);
   for(i=0;i<n;i++)
   *(a+i)=malloc(sizeof(int)*n);
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
         a[i][j]=0;
      }
   }
   if(n<=0 || n==1 || n==2 || n==3)
      printf("No solution\n");
   else
   backtrack(a,0,n);
   free(a);
}
