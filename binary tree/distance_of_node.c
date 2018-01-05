#include<stdio.h>
int pow(int n,int exp)
{
   int p=1;
   int i;
   for(i=1;i<=exp;i++)
   {
      p=p*n;
   }
   return p;
}
int log(int n,int r)
{
   return (n>=r)?1+log(n/r,r):0;
}
void main()
{
   int n,val,dist,a[50];
   printf("Enter the number of node:");
   scanf("%d",&n);
   int i;
   printf("enter the array:");
   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
   printf("Enter the distance from the root:");
   scanf("%d",&dist);
   val=log(n,2);
   for(i=pow(2,dist)-1;i<n;i++)
      printf("%d ",a[i]);
}
