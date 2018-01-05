#include<stdio.h>

struct process
{
   int arr,dur,wait,ta,rt,pid;
   int status;
};
void main()
{
   struct process e[10];
   int n,i,rr,remain=0,time=0;
   float wait=0,ta=0,avg_ta=0,avg_wait=0;
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
      printf("\n");
      e[i].rt=e[i].dur;
      e[i].status=0;
   }
   printf("\n");
   printf("Enter the Time Slice:");
   scanf("%d",&rr);
   while(remain!=n)
   {
      for(i=0;i<n;i++)
      {
         if(e[i].arr<=time && e[i].rt>0)
         {
            if(e[i].rt>=rr)
            {
            e[i].rt-=rr;
            time+=rr;
            }
            else
            {
               time+=e[i].rt;
               e[i].rt=0;
            }
         }
         if(e[i].rt==0 && e[i].status==0)
         {
            e[i].status=1;
            remain++;
            e[i].wait=time-e[i].dur-e[i].arr;
            e[i].ta=time-e[i].arr;
            wait+=e[i].wait;
            ta+=e[i].ta;
            printf("p[%d]:\n",e[i].pid);
            printf("Waiting Time:%d\n",e[i].wait);
            printf("TurnAround Time:%d\n",e[i].ta);
         }
      }
   }
   avg_wait=wait/n;
   avg_ta=ta/n;
   printf("\n\nAverage Waiting Time:%f",avg_wait);
   printf("\nAvergae Turnaround Time:%f\n",avg_ta);
}
