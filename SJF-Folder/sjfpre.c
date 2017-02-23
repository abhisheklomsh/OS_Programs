#include<stdio.h>
int main()
{
  int time,burst_time[10],arrival_time[10],sum_burst_time=0,smallest,n,i;
  int sum_turnaround=0,sum_wait=0;
  printf("Enter no of processes : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Enter arrival time for process P[%d] : ",i+1);
    scanf("%d",&arrival_time[i]);
    printf("Enter burst time for process P[%d] : ",i+1);
    scanf("%d",&burst_time[i]);
    sum_burst_time+=burst_time[i];
  }
  burst_time[9]=9999;
  printf("\n\nProcess\t\tTurnaround Time\t\t Waiting Time\n");
  for(time=0;time<sum_burst_time;)
  {
    smallest=9;
    for(i=0;i<n;i++)
    {
      if(arrival_time[i]<=time && burst_time[i]>0 && burst_time[i]<burst_time[smallest])
        smallest=i;
    }
    if(smallest==9)
    {
      time++;
      continue;
    }
    printf("P[%d]\t\t\t%d\t\t\t%d\n",smallest+1,time+burst_time[smallest]-arrival_time[smallest],time-arrival_time[smallest]);
    sum_turnaround+=time+burst_time[smallest]-arrival_time[smallest];
    sum_wait+=time-arrival_time[smallest];
    time+=burst_time[smallest];
    burst_time[smallest]=0;
  }
  printf("\n\n average waiting time = %f",(float)sum_wait/n);
  printf("\n\n average turnaround time = %f\n",(float)sum_turnaround/n);
  return 0;
}