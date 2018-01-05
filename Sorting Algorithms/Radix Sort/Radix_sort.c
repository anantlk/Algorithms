#include<stdio.h>

void display(int a[20],int n)
{
   int i;
   printf("\n");
   for(i=0;i<n;i++)
   {
      printf("%d ",a[i]);
   }
   printf("\n");
}
int max(int a[20],int n)
{
   int i,max=0;
   for(i=0;i<n;i++)
   {
      if(a[i]>=max)
         max=a[i];
   }
   return max;
}
void radix_sort(int a[20],int n)
{
   int exp=1,m,i,j,c[10],b[20];
   m=max(a,n);
   while(m/exp>0)
   {
      for(i=0;i<10;i++)
         c[i]=0;
      for(i=0;i<n;i++)
      {
         c[(a[i]/exp)%10]++;
      }
      for(i=1;i<10;i++)
      {
         c[i]+=c[i-1];
      }
      for(i=n-1;i>=0;i--)
      {
         b[--c[(a[i]/exp)%10]]=a[i];
      }
      for(i=0;i<n;i++)
      {
         a[i]=b[i];
      }
      exp*=10;
   }
}
void main()
{
   int n,a[20],i;
   printf("Enter the number of terms:");
   scanf("%d",&n);
   printf("Enter the array:\n");
   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
   radix_sort(a,n);
   printf("The array in sorted order is:\n");
   display(a,n);
}
