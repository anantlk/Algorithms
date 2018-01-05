#include<stdio.h>

void display(int n,int a[n])
{
   int i;
   for(i=0;i<n;i++)
   {
      printf("%d ",a[i]);
   }
   printf("\n");
}
void Combinational_Sum(int a[4],int set[10],int c,int sum,int s,int i)
{
   //display(c,set);
   if(sum==s)
   {
      display(c,set);
      return;
   }
   if(sum>s)
   {
      return;
   }
   for(;i<4;i++)
   {
      set[c]=a[i];
      Combinational_Sum(a,set,c+1,sum+set[c],s,i);
   }
}
void main()
{
   int a[4]={2,4,6,8},s=8,set[10];
   Combinational_Sum(a,set,0,0,s,0);
}
