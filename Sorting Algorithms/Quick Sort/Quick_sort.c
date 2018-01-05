#include<stdio.h>
void swap(int a[20],int l,int r)
{
   int temp;
   temp=a[l];
   a[l]=a[r];
   a[r]=temp;
}
void display(int a[20],int n)
{
   int i;
   printf("\n");
   for(i=0;i<n;i++)
      printf("%d ",a[i]);
   printf("\n");
}
int partition(int a[20],int left,int right,int pivot,int n)
{
   int l,r;
   l=left;
   r=right-1;
   while(1)
   {
      while(a[l]<=pivot && l<right)
      {
         l++;
      }
      while(r>=left && a[r]>=pivot)
      {
         r--;
      }
      if(l>=r)
         break;
      swap(a,l,r);
   }
   swap(a,l,right);
   return l;
}
void quicksort(int a[20],int left,int right,int n)
{
   if(right-left<=0)
      return ;
   int pivot,part_point,i;
   pivot=a[right];
   part_point=partition(a,left,right,pivot,n);
   quicksort(a,left,part_point-1,n);
   quicksort(a,part_point+1,right,n);
}
void main()
{
   int n,a[20],i;
   printf("Enter the number of terms:");
   scanf("%d",&n);
   printf("Enter the array:\n");
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
   quicksort(a,0,n-1,n);
   printf("The sorted array is:\n");
   display(a,n);
}
