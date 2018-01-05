#include<stdio.h>

void display(int a[10],int n)
{
   int i;
   printf("\n");
   for(i=0;i<n;i++)
      printf("%d ",a[i]);
   printf("\n");
}
void shell_sort(int a[10],int n)
{
   int gap,i,j,temp;
   for(gap=n/2;gap>=1;gap=gap/2)
   {
      for(i=gap;i<n;i++)
      {
         temp=a[i];
         j=i-gap;
         while(j>=0 && a[j]>temp)
         {
            a[j+gap]=a[j];
            j=j-gap;
         }
         a[j+gap]=temp;
      }
   }
}
void main()
{
   int n,a[10],i;
   printf("Enter the number of terms:");
   scanf("%d",&n);
   printf("Enter the array:");
   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
   shell_sort(a,n);
   printf("The sorted array:");
   display(a,n);
}
