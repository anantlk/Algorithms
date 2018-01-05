#include<stdio.h>
void heapify(int a[20],int len,int i)
{
   int left,right,smallest,temp;
   left=2*i+1;
   right=2*i+2;
   if(left<=len-1 && a[left]<a[i])
      smallest=2*i+1;
   else
      smallest=i;
   if(right<=len-1 && a[right]<a[smallest])
   {
      smallest=2*i+2;
   }
   if(smallest!=i)
   {
      temp=a[smallest];
      a[smallest]=a[i];
      a[i]=temp;
      heapify(a,len,smallest);
   }
}
void buildheap(int a[20],int len)
{
   int i;
   for(i=len/2-1;i>=0;i--)
   {
      heapify(a,len,i);
   }
}
void heapsort(int a[20],int n)
{
   buildheap(a,n);
   int j,i,len=n,temp;
   for(i=len-1;i>=0;i--)
   {
      temp=a[0];
      a[0]=a[i];
      a[i]=temp;
      n--;
      heapify(a,n,0);
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
   heapsort(a,n);
   printf("The sorted array is:\n");
   for(i=0;i<n;i++)
   {
      printf("%d ",a[i]);
   }
}
