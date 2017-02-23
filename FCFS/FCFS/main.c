//
//  main.c
//  FCFS
//
//  Created by Abhishek Lomsh on 23/02/17.
//  Copyright © 2017 AbhishekLomsh. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int burstTime[20],waitingTime[20],turnAroundTime[20],numberOfJobs;
    printf("\nPlease enter number of jobs to be executed: ");
    scanf("%d", &numberOfJobs);
    printf("Please enter burst time of jobs to be executed\n");
    for(int i=0;i<numberOfJobs;i++){
        printf("JOB[%d]: ",i);
        scanf("%d",&burstTime[i]);
    }
    for(int i=0;i<numberOfJobs;i++){
        waitingTime[i]=0;
    }

    for(int i=0;i<numberOfJobs;i++){
        waitingTime[i] = burstTime[i] + waitingTime[i];
    }
    
    for(int i=0;i<numberOfJobs;i++){
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
    }
    printf("Serial Number\t\tBurst-Time\t\tWaiting-Time\t\tTurn Around Time\n");
    for(int i=0;i<numberOfJobs;i++){
        printf("%d\t\t\t\t\t%d\t\t\t\t%d\t\t\t\t\t\t\t%d\n",i+1,burstTime[i],waitingTime[i],turnAroundTime[i]);
    }
    return 0;
}
