#include<stdio.h>
void swap(int a[20],int i,int j)
{
   int temp;
   temp=a[i];
   a[i]=a[j];
   a[j]=temp;
}
void selection_sort(int a[20],int n)
{
   int i,j,min;
   for(i=0;i<n;i++)
   {
      min=i;
      for(j=i+1;j<n;j++)
      {
         if(a[j]<=a[min])
            min=j;
      }
      swap(a,i,min);
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
   selection_sort(a,n);
   printf("The sorted array is:\n");
   for(i=0;i<n;i++)
      printf("%d ",a[i]);
   printf("\n");
}
