#include<stdio.h>

struct value
{
    int data;
};
void dfs(int i,int *visited,int **adj_mat,int n,struct value *nodes)
{
    visited[i]=1;
    int j;
    printf("%d\n",nodes[i].data);
    for(j=0; j<n; j++)
    {
        if(visited[j]==0 && adj_mat[i][j]==1)
        {
            dfs(j,visited,adj_mat,n,nodes);
        }
    }
}
void main()
{
    int j,n,i,**edge,num,*visited;
    struct value *nodes;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    printf("Enter the nodes:\n");
    nodes=malloc(n*sizeof(struct value));
    visited=malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
        visited[i]=0;
        printf("node %d->",i+1);
        scanf("%d",&nodes[i].data);
    }
    printf("Enter the number of edges:");
    scanf("%d",&num);

    edge=malloc(num*sizeof(int));
    for(i=0; i<num; i++)
    {
        *(edge+i)=malloc(2*sizeof(int));
    }
    printf("Enter the edges(bidirectional):\n");
    for(i=0; i<num; i++)
    {
        printf("Edge %d:\n",i+1);
        scanf("%d",&edge[i][0]);
        scanf("%d",&edge[i][1]);
    }
    int **adj_mat;
    adj_mat=malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
        *(adj_mat+i)=malloc(n*sizeof(int));
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            adj_mat[i][j]=0;
        }
    }
    for(i=0; i<num; i++)
    {
        adj_mat[edge[i][0]-1][edge[i][1]-1]=1;
        adj_mat[edge[i][1]-1][edge[i][0]-1]=1;
    }
    printf("Adjacency Matrix:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",adj_mat[i][j]);
        }
        printf("\n");
    }
    dfs(0,visited,adj_mat,n,nodes);
}

