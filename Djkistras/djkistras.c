#include<stdio.h>

#define inf 1000
void djkistras(int cost[20][20],int n,int count)
{
   int next,min,i,j,distance[20],start;
   int pred[20];
   static int  visited[20];
   printf("Enter the source:");
   scanf("%d",&start);
   for(i=0;i<n;i++)
   {
      pred[i]=start-1;
      distance[i]=cost[start-1][i];
   }
   visited[start-1]=1;
   int c=1;
   while(c<n-1)
   {
      min=inf;
      for(i=0;i<n;i++)
      {
         if(distance[i]<min && visited[i]==0)
         {
            min=distance[i];
            next=i;
         }
      }
      visited[next]=1;
      for(i=0;i<n;i++)
      {
         if(min+cost[next][i]<distance[i])
         {
            distance[i]=min+cost[next][i];
            pred[i]=next;
         }
      }
      c++;
   }
   printf("The paths for all the vertices are:\n");
   for(i=0;i<n;i++)
   {
      j=i;
      printf("The path for the node %d:\n",i);
      while(j!=start-1)
      {
         printf("%d<-",j);
         j=pred[j];
      }
      printf("%d\n",start-1);
      printf("distance=%d\n",distance[i]);
      printf("\n");
   }
}
void main()
{
   int n,edges[20][2],wt[20],i,j,count;
   static int adj[10][10],cost[20][20];
   printf("Enter the number of nodes:");
   scanf("%d",&n);
   printf("Enter the number edges:");
   scanf("%d",&count);
   printf("Enter the edges:\n");
   i=0;
   while(i<count)
   {
      printf("Enter edge %d:\n",i+1);
      printf("Node 1->");
      scanf("%d",&edges[i][0]);
      printf("Node 2->");
      scanf("%d",&edges[i][1]);
      printf("Enter the weight:");
      scanf("%d",&wt[i]);
      i++;
   }
   for(j=0;j<count;j++)
   {
      adj[edges[j][0]-1][edges[j][1]-1]=wt[j];
      adj[edges[j][1]-1][edges[j][0]-1]=wt[j];
   }
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
       if(i!=j)
         {
          if(adj[i][j]==0)
             cost[i][j]=inf;
          else
            cost[i][j]=adj[i][j];
         }
      }
   }
   /*for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
         printf("%d ",cost[i][j]);
      }
      printf("\n");*/
      djkistras(cost,n,count);

}
