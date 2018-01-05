#include<stdio.h>

int z=0;
void display(int n,int a[n])
{
   int i;
   for(i=0;i<n;i++)
   {
      printf("%d ",a[i]);
   }
   printf("\n");
}
void allcombinations(int n,int ele,int a[2*n])
{
   if(ele>n)
   {
      display(2*n,a);
      z=1;
      return;
   }
   int i;
   for(i=0;i<2*n;i++)
   {
      if((i+ele+1)<2*n && a[i]==0 && a[i+ele+1]==0)
      {
         a[i]=a[i+ele+1]=ele;
         allcombinations(n,ele+1,a);
         a[i]=a[i+ele+1]=0;
      }
   }
}
void main()
{
   int n;
   printf("Enter the number:");
   scanf("%d",&n);
   int a[2*n];
   int i;
   for(i=0;i<2*n;i++)
   {
      a[i]=0;
   }
   allcombinations(n,1,a);
   if(z==0)
      printf("No solution!!\n");
}
