//program to implement priority scheduling (non primtive) wothout arrival time
#include<stdio.h>
#include<conio.h>
#define max 50
int main(){
	int i,n,j,bt[max], wt[max], pr[max], tat[max], pos,t,p[max];
	float awt=0,atat=0;
	printf("Enter the number of process : ");
	scanf("%d",&n);
	printf("Enter the process number : ");
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	} 
	printf("Enter the burst time : ");
	for(i=0;i<n;i++){
		scanf("%d",&bt[i]);
	} 
	printf("Enter the priority of process : ");
	for(i=0;i<n;i++){
		scanf("%d",&pr[i]);
	} 
	for(i=0;i<n;i++){
		pos=i;
		for(j=i+1;j<n;j++){
			if(pr[j]<=pr[pos]){
				pos=j;
			}
		}
		t=pr[i];
		pr[i]=pr[pos];
		pr[pos]=t;
		
		t=bt[i];
		bt[i]=bt[pos];
		bt[pos]=t;
		
		t=p[i];
		p[i]=p[pos];	
		p[pos]=t;
		
	}
	wt[0]=0;
	printf("process\t BurstTime\t Priority\t WaitingTime\t TurnAroundTime\n");
	for(i=0;i<n;i++){
		wt[i]=0;
		tat[i]=0;
		
		for(j=0;j<i;j++){
			wt[i]+=bt[j];
			
		}
		tat[i]=wt[i]+bt[i];
		awt+=wt[i];
		atat+=tat[i];
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],pr[i],wt[i],tat[i]);
	}
	printf("The Total Waiting Time is %f \n",awt);
	printf("The Total TurnAround Time is %f \n",atat);
	awt=awt/n;
	atat=atat/n;
	printf("The Average Waiting Time is %f \n",awt);
	printf("The Average TurnAround Time is %f",atat);
	getch();
}
