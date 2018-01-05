#include<stdio.h>
#include<string.h>

int **mat,c=0;
int **mark;
int check_dir(int k,int j)
{
    int i;
   // printf("The matrix:\n");
    mat[c][0]=k;
    mat[c++][1]=j;
   /* for(i=0; i<c; i++)
    {
        printf("%d ",mat[i][0]);
        printf("%d ",mat[i][1]);
        printf("\n");
    }*/
    if(c<3)
        return 1;
    else
    {
        if((mat[c-1][0]-mat[c-2][0])==(mat[c-2][0]-mat[c-3][0]) && (mat[c-1][1]-mat[c-2][1])==(mat[c-2][1]-mat[c-3][1]))
        {
            //printf("dir same\n");
            return 1;
        }
        else
        {
            //printf("dir not same\n");
            return 0;
        }
    }
}
int find(int row,int col,char *str,char **a,int iter,int n)
{
    int i,j;
    if(iter==strlen(str))
        {
           printf("iter=strlen(str)\n");
           return 1;
        }
    if(check_dir(row,col))
    {
      // printf("Searching for character:%c\n",str[iter]);
        if(col+1<n && a[row][col+1]==str[iter] && mark[row][col+1]==0)
        {
            if(find(row,col+1,str,a,iter+1,n))
            {
                mark[row][col+1]=1;
                return 1;
            }
        }
        if(row-1>=0 && col+1<n &&a[row-1][col+1]==str[iter] && mark[row-1][col+1]==0)
        {
            if(find(row-1,col+1,str,a,iter+1,n))
            {
                mark[row-1][col+1]=1;
                return 1;
            }
        }
        if(row-1>=0 && a[row-1][col]==str[iter] && mark[row-1][col]==0)
        {
            if(find(row-1,col,str,a,iter+1,n))
            {
                mark[row-1][col]=1;
                return 1;
            }
        }
        if(row-1>=0 && col-1>=0 && a[row-1][col-1]==str[iter] && mark[row-1][col-1]==0)
        {
            if(find(row-1,col-1,str,a,iter+1,n))
            {
                mark[row-1][col-1]=1;
                return 1;
            }
        }
        if(col-1>=0 && a[row][col-1]==str[iter] && mark[row][col-1]==0)
        {
            if(find(row,col-1,str,a,iter+1,n))
            {
                mark[row][col-1]=1;
                return 1;
            }
        }
        if(row+1<n && col-1>=0 && a[row+1][col-1]==str[iter] && mark[row+1][col-1]==0)
        {
            if(find(row+1,col-1,str,a,iter+1,n))
            {
                mark[row+1][col-1]=1;
                return 1;
            }
        }
        if(row+1<n &&a[row+1][col]==str[iter] && mark[row+1][col]==0)
        {
            if(find(row+1,col,str,a,iter+1,n))
            {
                mark[row+1][col]=1;
                return 1;
            }
        }
        if(row+1<n && col+1<n && a[row+1][col+1]==str[iter] && mark[row+1][col+1]==0)
        {
            if(find(row+1,col+1,str,a,iter+1,n))
            {
                mark[row+1][col+1]=1;
                return 1;
            }
        }
        c--;
        mark[row][col]=0;
        return 0;
    }
    else
    {
       c--;
        return 0;
    }
}
int word(char *str,char **a,int n)
{
    int i,j,f=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            c=0;
            if(a[i][j]==str[0])
            {
               mark[i][j]=1;
                if(find(i,j,str,a,1,n))
                {
                   f=1;
                   printf("Found at:(%d,%d)\n",i,j);
                }
                printf("\n");
            }
        }
    }
    return f;
}
void main()
{
    int count=0,n,len;
    char **a,*str;
    int i,j;
    printf("Ente the dimension:");
    scanf("%d",&n);
    a=malloc(n*sizeof(char));
    for(i=0;i<n;i++)
    {
       *(a+i)=malloc(n*sizeof(char));
    }
    printf("Enter the matrix:\n");
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
       {
          scanf(" %c",&a[i][j]);
       }
    }
    printf("Enter the length of the word:");
    scanf("%d",&len);
    str=malloc(len*sizeof(char));
    printf("Enter the word to be found:");
    scanf("%s",str);
    printf("The matrix is:\n");
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
         {
            printf("%c ",a[i][j]);
         }
       printf("\n");
    }

    mark=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
       *(mark+i)=malloc(n*sizeof(int));
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            mark[i][j]=0;
        }
    }
    for(i=0;str[i]!='\0';i++)
    {
       count++;
    }
    mat=malloc(count*sizeof(int));
    for(i=0;i<count;i++)
    {
       mat[i]=malloc(2*sizeof(int));
    }
    if(!word(str,a,n))
      printf("Not found\n");
    free(a);
    free(mark);
    free(str);
    free(mat);
}
