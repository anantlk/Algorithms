#include<stdio.h>

void insertion_sort(int a[20],int n)
{
   int i,j,k;
   for(i=1;i<n;i++)
   {
      k=a[i];
      j=i-1;
      while(j>=0 && a[j]>=k)
      {
         a[j+1]=a[j];
         j--;
      }
      a[j+1]=k;
   }
}
void main()
{
   int n,a[20],i;
   printf("Enter the number of terms:");
   scanf("%d",&n);
   printf("Enter the array:\n");
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
   insertion_sort(a,n);
   printf("The sorted array is:\n");
   for(i=0;i<n;i++)
      printf("%d ",a[i]);
   printf("\n");
}
