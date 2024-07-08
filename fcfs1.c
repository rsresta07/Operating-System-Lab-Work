#include<stdio.h>

void main() {
	int num, i, total_tat, total_wt, ave_tat, ave_wt;
	printf("Enter the number of process: ");
	scanf("%d",&num);
	int p[num], at[num], bt[num], ct[num], tat[num], wt[num];
	
	//input the processes
	for(i=0; i<num; i++) {
		p[i]=i+1;
	}
	//input the arrival time
	for(i=0; i<num; i++) {
		at[i]=0;
	}
	//input the burst time
	printf("Enter the burst time: ");
	for(i=0; i<num; i++) {
		scanf("%d",&bt[i]);
	}

    //calculation
    ct[0]=0; tat[0]=0; wt[-1]=0; total_tat=0; total_wt=0; bt[-1]=0;
    printf("\tProcess   Arrival time   Burst time   Completion time   TurnAround time   Waiting time\n");
    for(i=0; i<num; i++) {
		wt[i]=bt[i-1]+wt[i-1];
		tat[i]=wt[i]+bt[i];
		total_tat = total_tat + tat[i];
		total_wt = total_wt + wt[i];
		ct[i]=ct[i-1]+bt[i];
		printf("\tP%d        %d              %d            %d                 %d                 %d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	ave_tat = total_tat/2;
	ave_wt = total_wt/2;
	printf("Average Turn Around Time = %d",total_tat);
	printf("Average Waiting Time = %d",total_wt);
}
