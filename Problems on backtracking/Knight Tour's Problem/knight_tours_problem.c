#include<stdio.h>

void display(int n,int move[n][n])
{
   int i,j;
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
         printf("%d ",move[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}
void solve(int n,int move[n][n],int visited[n][n],int mov,int i,int j)
{
   if(mov==n*n)
   {
      display(n,move);
      exit(0);
   }
   int x[8]={2,1,-1,-2,-2,-1,1,2},y[8]={1,2,2,1,-1,-2,-2,-1},m;
   //display(n,move);
   printf("%d\n",mov);
   for(m=0;m<8;m++)
   {
            if((i+x[m]<n && i+x[m]>=0) && (j+y[m]>=0 && j+y[m]<n) && visited[i+x[m]][j+y[m]]==0)
            {
               move[i+x[m]][j+y[m]]=mov;
               visited[i+x[m]][j+y[m]]=1;
               solve(n,move,visited,mov+1,i+x[m],j+y[m]);
               move[i+x[m]][j+y[m]]=0;
               visited[i+x[m]][j+y[m]]=0;
            }
   }
}
void main()
{
   int n;
   printf("Enter the order:");
   scanf("%d",&n);
   int r,c;
   printf("Enter the initial position:");
   scanf("%d %d",&r,&c);
   int move[n][n],i,j,visited[n][n];
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
         move[i][j]=0;
         visited[i][j]=0;
      }
   }
   visited[r][c]=1;
   solve(n,move,visited,1,r,c);
}
