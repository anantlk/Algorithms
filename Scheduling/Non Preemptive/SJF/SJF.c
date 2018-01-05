#include<stdio.h>

struct process
{
   int pid,wait,ta,arr,dur,status;
};
void main()
{
   struct process e[10],temp;
   int i,n,time=0,sum=0;
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
      sum+=e[i].dur;
      e[i].status=0;
   }
   sum+=e[0].arr;
   int j,min=9;
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
   e[min].dur=1000;
   for(;time<sum;)
   {
      min=9;
      for(i=0;i<n;i++)
      {
         if(e[i].arr<=time && e[i].status!=1 && e[i].dur<e[min].dur)
         {
            min=i;
         }
      }
      e[min].status=1;
      time+=e[min].dur;
      e[min].wait=time-e[min].dur-e[min].arr;
      e[min].ta=time-e[min].arr;
      wait+=e[min].wait;
      ta+=e[min].ta;
      printf("p[%d]:\n",e[min].pid);
      printf("Waiting Time:%d\n",e[min].wait);
      printf("Turnaround time:%d\n",e[min].ta);
   }
   printf("\n\nAvergae Waiting time:%f",wait/n);
   printf("\nAverage Turnaround Time:%f",ta/n);
   printf("\n");
}

