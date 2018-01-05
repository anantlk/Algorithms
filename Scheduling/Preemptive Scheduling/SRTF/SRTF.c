#include<stdio.h>

struct process
{
   int ta,wait,rt,arr,dur,pid;
};
void main()
{
   struct process e[10];
   int i,remain=0,n,time,min,endTime;
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
      e[i].rt=e[i].dur;
      printf("\n");
   }
   printf("\n");
   for(time=0;remain!=n;time++)
   {
    min=9;
    e[min].rt=1000;
    for(i=0;i<n;i++)
    {
       if(e[i].rt>0 && e[i].arr<=time && e[i].rt<e[min].rt)
       {
          min=i;
       }
    }
    e[min].rt--;
    endTime=time+1;
    if(e[min].rt==0)
    {
       remain++;
       e[min].wait=endTime-e[min].dur-e[min].arr;
       e[min].ta=endTime-e[min].arr;
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
