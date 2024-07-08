#include<stdio.h>

void main() {
	int n=2, i, total_tat, total_wt, ave_tat, ave_wt;
	int bt[n], ct[n], tat[n], wt[n];
	int at[]={0,0,0};
	int p[]={1,2,3};
	//input the burst time
	printf("Enter the burst time: ");
	for(i=0; i<3; i++) {
		scanf("%d",&bt[i]);
	}
    //calculation
    ct[-1]=0; tat[0]=0; wt[-1]=0; total_tat=0; total_wt=0; bt[-1]=0;
    printf("\tProcess   Arrival time   Burst time   Completion time   TurnAround time   Waiting time\n");
    for(i=0; i<3; i++) {
		wt[i]=bt[i-1]+wt[i-1];
		tat[i]=wt[i]+bt[i];
		total_tat = total_tat + tat[i];
		total_wt = total_wt + wt[i];
		ct[i]=ct[i-1]+bt[i];
		printf("\tP%d        %d              %d            %d                 %d                 %d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	ave_tat = total_tat/3;
	ave_wt = total_wt/3;
	printf("Average Turn Around Time = %d",total_tat);
	printf("Average Waiting Time = %d",total_wt);
}
