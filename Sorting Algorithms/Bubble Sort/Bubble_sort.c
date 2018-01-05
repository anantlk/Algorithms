#include<stdio.h>
void swap(int a[20],int i,int j)
{
   a[i]=a[i]+a[j];
   a[j]=a[i]-a[j];
   a[i]=a[i]-a[j];
}
void bubble_sort(int a[20],int n)
{
   int i,j;
   for(i=0;i<n;i++)
   {
      for(j=0;j<n-i-1;j++)
      {
         if(a[j+1]<a[j])
         swap(a,j,j+1);
      }
   }
}
void main()
{
   int a[20],n,i;
   printf("Enter the number of terms:");
   scanf("%d",&n);
   printf("Enter the array:\n");
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
   bubble_sort(a,n);
   printf("The sorted array is:\n");
   for(i=0;i<n;i++)
      printf("%d ",a[i]);
   printf("\n");
}
