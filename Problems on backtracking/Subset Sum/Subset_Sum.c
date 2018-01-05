#include<stdio.h>

void display(int n,int set[n])
{
   int i;
   for(i=0;i<n;i++)
   {
      printf("%d ",set[i]);
   }
   printf("\n");
}
void subset_sum(int a[5],int set[5],int s,int ite,int c,int sum)
{
   int i;
   if(sum==s)
   {
      display(c,set);
      return ;
   }
   if(sum>s)
      return;
   //display(c,set);
   for(i=ite;i<5;i++)
   {
      set[c]=a[i];
      subset_sum(a,set,s,i+1,c+1,sum+set[c]);
   }
}
void main()
{
   int a[5]={1,2,3,4,5},s=10,set[5];
   subset_sum(a,set,s,0,0,0);
}
