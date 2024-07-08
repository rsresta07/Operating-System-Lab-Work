#include<stdio.h>

void main() {
	int num, i, total_tat, total_wt;
	printf("Enter the number of process: ");
	scanf("%d",&num);
	int p[num], at[num], bt[num], ct[num], tat[num], wt[num];
	//input the processes
	printf("Enter the processes: ");
	for(i=0; i<num; i++) {
		scanf("%d",&p[i]);
	}
	//input the arrival time
	printf("Enter the arrival time: ");
	for(i=0; i<num; i++) {
		scanf("%d",&at[i]);
	}
	//input the burst time
	printf("Enter the burst time: ");
	for(i=0; i<num; i++) {
		scanf("%d",&bt[i]);
	}

	/*for (i = 0; i < num; i++) {
        if (at[i + 1] < at[i]) 
			return 0;
	}*/

    //calculation
    ct[-1]=0; tat[0]=0; wt[0]=0; total_tat=0; total_wt=0;
    printf("\tProcess   Arrival time   Burst time   Completion time   TurnAround time   Waiting time\n");
    for(i=0; i<num; i++) {
		ct[i] = ct[i-1] + bt[i];
		tat[i] = ct[i] - at[i];
		wt[i] = tat[i] - bt[i];
		total_tat = total_tat + tat[i];
		total_wt = total_wt + wt[i];
		printf("\tP%d        %d              %d            %d                 %d                 %d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
}
