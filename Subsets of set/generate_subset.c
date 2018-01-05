#include<stdio.h>

static int c=0;
void bin(int n,int b[4],int num)
{
   int i;
   c=0;
   for(i=num-1;i>=0;i--)
   {
      b[i]=n%2;
      if(b[i]==1)
         c++;
      n=n/2;
   }
}
void main()
{
   int a[20],b[20],**z,i,k=0,j;
   int n;
   printf("Enter the number of terms:");
   scanf("%d",&n);
   z=malloc(((int)pow(2,n)-1)*sizeof(int*));
   printf("Enter the set:");
   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
   for(i=0;i<n;i++)
   {
      b[i]=0;
   }
   b[i-1]=1;
   for(i=1;i<(int)pow(2,n);i++)
   {
      bin(i,b,n);
      k=0;
      *(z+i-1)=malloc(c*(sizeof(int)));
      for(j=0;j<n;j++)
      {
         if(b[j]==1)
         {
            z[i-1][k++]=a[j];
         }
      }
      for(j=0;j<k;j++)
      {
         printf("%d ",z[i-1][j]);
      }
      printf("\n");
   }
   free(z);
}
