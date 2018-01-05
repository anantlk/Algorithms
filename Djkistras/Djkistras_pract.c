#include<stdio.h>
#define inf 10000

void djkistras(int n,int adj[n*n][n*n],int cost[n*n][n*n],int q,int source[q],int desti[q])
{
   int c=0,distance[n*n],i,j,visited[n*n],pred[n*n];
   int k;
   for(k=0;k<q;k++)
   {
      c=0;
   for(i=0;i<n*n;i++)
   {
      distance[i]=cost[source[k]][i];
      visited[i]=0;
      pred[i]=source[k];
   }
   int min,next;
   visited[source[k]]=1;
   while(c<n*n-1)
   {
      min=inf;
      for(i=0;i<n*n;i++)
      {
         if(distance[i]<=min && visited[i]!=1)
         {
            min=distance[i];
            next=i;
         }
      }
      visited[next]=1;
      for(i=0;i<n*n;i++)
      {
         if(visited[i]!=1 && (min+cost[next][i]<=distance[i]))
         {
            distance[i]=min+cost[next][i];
            pred[i]=next;
         }
      }
      c++;
   }
   if(distance[desti[k]==inf)
      printf("impossible\n");
   else
      printf("%d\n",distance[desti[k]]);
   }
   return ;
}
void main()
{
   int n,m,q,i,j;
   scanf("%d %d %d",&n,&m,&q);
   int adj[n*n][n*n],cost[n*n][n*n],source[q],desti[q];
   for(i=0;i<n*n;i++)
   {
      for(j=0;j<n*n;j++)
      {
         adj[i][j]=0;
      }
   }
   int x,y,z,w;
   for(i=0;i<n-1;i++)
   {
      scanf("%d %d",&x,&y);
      for(j=0;j<n;j++)
      {
         adj[x-1+j*n][y - 1+ j*n]=1;
         adj[y-1 + j*n][x-1+j*n]=1;
      }
   }
   for(i=0;i<m;i++)
   {
      scanf("%d %d %d %d",&x,&y,&w,&z);
      adj[x-1+(y-1)*n][w-1 + (z-1)*n]=1;
      adj[w-1+(z-1)*n][x-1+(y-1)*n]=1;
   }
   for(i=0;i<q;i++)
   {
      scanf("%d %d %d %d",&x,&y,&w,&z);
      source[i]=x-1+(y-1)*n;
      desti[i]=w-1+(z-1)*n;
   }
   for(i=0;i<n*n;i++)
   {
      for(j=0;j<n*n;j++)
      {
         if(i!=j)
         {
            if(adj[i][j]==0)
            {
               cost[i][j]=inf;
            }
            else
               cost[i][j]=1;
         }
         else
         {
            cost[i][j]=0;
         }
      }
   }
   //display(n,cost);
   djkistras(n,adj,cost,q,source,desti);
   //display(n,adj);
}
