#include<stdio.h>

struct process
{
   int ta,wait,rt,arr,dur,pid,priority;
};
void main()
{
   struct process e[10];
   int i,sum=0,remain=0,n,time,min;
   float avg_wait,avg_ta,wait=0,ta=0;
   printf("Enter the number of processes:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      printf("p[%d]\n",i+1);
      printf("Id:");
      scanf("%d",&e[i].pid);
      printf("Burst Time:");
      scanf("%d",&e[i].dur);
      printf("Arrival:");
      scanf("%d",&e[i].arr);
      printf("Priority:");
      scanf("%d",&e[i].priority);
      e[i].rt=e[i].dur;
      sum+=e[i].dur;
      printf("\n");
   }
   printf("\n");
   for(time=0;time<=sum;)
   {
    min=9;
    e[min].rt=1000;
    for(i=0;i<n;i++)
    {
       if(e[i].rt>0 && e[i].arr<=time && e[i].priority<e[min].priority)
       {
          min=i;
       }
    }
    e[min].rt--;
    time++;
    if(e[min].rt==0)
    {
       e[min].wait=time-e[min].dur-e[min].arr;
       e[min].ta=time-e[min].arr;
       wait+=e[min].wait;
       ta+=e[min].ta;
       printf("p[%d]\n",e[min].pid);
       printf("Wait time:%d\n",e[min].wait);
       printf("Turnaround Time:%d\n",e[min].ta);
    }
   }
   printf("\n\nAverage waiting Time:%f\n",wait/n);
   printf("Average Turnaround Time:%f\n",ta/n);
}
