#include<stdio.h>

void display(int a[20],int n)
{
   int i;
   for(i=0;i<n;i++)
   {
      printf("%d ",a[i]);
   }
   printf("\n");
}
void merge(int a[20],int l,int m,int r,int n)
{
   int i,j,k=0;
   i=l;
   j=m+1;
   int b[20];
   while(i<=m && j<=r)
   {
      if(a[i]<=a[j])
      {
         b[k++]=a[i];
         i++;
      }
      else
      {
        b[k++]=a[j];
        j++;
      }
   }
   while(i<=m)
   {
      b[k++]=a[i++];
   }
   while(j<=r)
   {
      b[k++]=a[j++];
   }
   int c=0;
   for(i=l;i<=r;i++)
   {
      a[i]=b[c++];
   }
}
void mergesort(int a[20],int left,int right,int n)
{
   int m;
   if(right==left)
      return;
   m=(left+right)/2;
   mergesort(a,left,m,n);
   mergesort(a,m+1,right,n);
   merge(a,left,m,right,n);
}
void main()
{
   int n,a[20],i;
   printf("Enter the number of terms:");
   scanf("%d",&n);
   printf("Enter the array:\n");
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
   mergesort(a,0,n-1,n);
   printf("The array in the sorted order is:\n");
   display(a,n);
}
