#include<stdio.h>

#define initial 1
#define waiting 2
#define visited 3

struct node
{
    int data;
}*nodes;
int *queue,front=-1,rear=-1,*state,n,**adj;
void insert(int v,int n)
{
    if(rear==n)
    {
        printf("Overflow\n");
    }
    else
    {
        if(rear==-1 && front==-1)
        {
            rear=front=0;
            queue[rear]=v;
        }
        else
        {
            rear++;
            queue[rear]=v;
        }
    }
}
int del()
{
    if(front==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        int k;
        if(front==rear)
        {
            k=queue[front];
            front=rear=-1;
        }
        else
        {
            k=queue[front];
            front++;
        }
        return k;
    }
}
void bfs(int v)
{
    insert(v,n);
    state[v]=waiting;
    int i;
    while(front!=-1)
    {
        v=del();
        printf("%d ",nodes[v].data);
        state[v]=visited;
        for(i=0; i<n; i++)
        {
            if(adj[v][i]==1 && state[i]==1)
            {
                insert(i,n);
                state[i]=waiting;
            }
        }
    }
}
void main()
{
    int i,x,y,j,c=0;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    queue=malloc(n*sizeof(int));
    nodes=malloc(n*sizeof(struct node));
    state=malloc(n*sizeof(int));
    adj=malloc(n*sizeof(int*));
    for(i=0; i<n; i++)
    {
        state[i]=initial;
        *(adj+i)=malloc(n*sizeof(int));
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            adj[i][j]=0;
        }
    }
    printf("Enter the Data for nodes:\n");
    for(i=0; i<n; i++)
    {
       printf("Node %d:\n",i+1);
        scanf("%d",&nodes[i].data);
    }
    printf("Enter the edges:(-1 -1 )for stop entering\n");
    while(1)
    {
        printf("Enter the edge %d:\n",c+1);
        printf("Node->");
        scanf("%d",&x);
        printf("Node->");
        scanf("%d",&y);
        if(x==-1 && y==-1)
            break;
        adj[x-1][y-1]=1;
        adj[y-1][x-1]=1;
        c++;
    }
    printf("\nAdjacency Matrix:\n\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    printf("\nOrder=\n");
    bfs(0);
    free(queue);
    free(nodes);
    free(state);
    free(adj);
}
