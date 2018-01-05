#include<stdio.h>
#include<math.h>

static int z=0;
void display(int mat[9][9])
{
    int i,j,k,l;
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(mat[i][j]==0)
                printf("_ ");
            else
                printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
int row(int a[9][9],int n,int i)
{
    int j;
    for(j=0; j<9; j++)
    {
        if(a[i][j]==n)
            return 0;
    }
    return 1;
}
int col(int a[9][9],int n,int j)
{
    int i;
    for(i=0; i<9; i++)
    {
        if(a[i][j]==n)
            return 0;
    }
    return 1;
}
int segment(int a[9][9],int n,int i,int j)
{
    int k,l;
    for(k=3*(i/3); k<(3*(i/3))+3; k++)
    {
        for(l=3*(j/3); l<(3*(j/3))+3; l++)
        {
            if(a[k][l]==n)
            {
                return 0;
            }
        }
    }
    return 1;
}
void solve(int mat[9][9],int a[9],int j,int iter)
{
    int k,f=0,t;
    if(iter==9)
    {
       display(mat);
       printf("Exit to close:");
       scanf("%d",&t);
    }
    if(iter==7)
      z=1;
    if(j>8)
    {
        j=0;
        iter++;
    }
    if(z==1)
    display(mat);
    if(mat[iter][j]==0)
    {
        for(k=0; k<9; k++)
        {
            if(row(mat,a[k],iter) && col(mat,a[k],j) && segment(mat,a[k],iter,j))
            {
                f=1;
                mat[iter][j]=a[k];
                solve(mat,a,j+1,iter);
                mat[iter][j]=0;
                f=0;
            }
        }
        if(f==0)
            return ;
    }
    else
    {
        solve(mat,a,j+1,iter);
    }
}
void main()
{
    int a[9]= {1,2,3,4,5,6,7,8,9};
    int mat[9][9]={{0,0,0,1,0,5,0,6,8},
        {0,0,0,0,0,0,7,0,1},
        {9,0,1,0,0,0,0,3,0},
        {0,0,7,0,2,6,0,0,0},
        {5,0,0,0,0,0,0,0,3},
        {0,0,0,8,7,0,4,0,0},
        {0,3,0,0,0,0,8,0,5},
        {1,0,5,0,0,0,0,0,0},
        {7,9,0,4,0,1,0,0,0}},i,j,k,l;
    printf("Enter the puzzle:\n");
    /*for(i=0;i<9;i++)
    {
       for(j=0;j<9;j++)
       {
          scanf("%d",&mat[i][j]);
       }
    }*/
    display(mat);
    printf("\n");
    solve(mat,a,0,0);
    //display(mat);
}
