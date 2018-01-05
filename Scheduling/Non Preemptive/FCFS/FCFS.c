#include<stdio.h>

struct process
{
   int pid,wait,ta,arr,dur;
};
void main()
{
   struct process e[10],temp;
   int i,n,time=0;
   float wait=0,ta=0;
   printf("Enter the Number of processes:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      printf("p[%d]:\n",i+1);
      printf("Id:");
      scanf("%d",&e[i].pid);
      printf("Burst Time:");
      scanf("%d",&e[i].dur);
      printf("Arrival:");
      scanf("%d",&e[i].arr);
   }
   int j;
   for(i=0;i<n;i++)
   {
      for(j=0;j<n-i-1;j++)
      {
         if(e[j].arr>e[j+1].arr)
         {
            temp=e[j];
            e[j]=e[j+1];
            e[j+1]=temp;
         }
      }
   }
   time=e[0].arr;
   printf("\n");
   for(i=0;i<n;i++)
   {
      time+=e[i].dur;
      e[i].wait=time-e[i].dur-e[i].arr;
      e[i].ta=time-e[i].arr;
      wait+=e[i].wait;
      ta+=e[i].ta;
      printf("p[%d]:\n",e[i].pid);
      printf("Waiting Time:%d\n",e[i].wait);
      printf("Turnaround time:%d\n",e[i].ta);
   }
   printf("\n\nAvergae Waiting time:%f",wait/n);
   printf("\nAverage Turnaround Time:%f",ta/n);
   printf("\n");
}
