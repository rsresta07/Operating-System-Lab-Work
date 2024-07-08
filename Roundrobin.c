//Program to implement round robin
#include<stdio.h>
#include<conio.h>
#define max 30
void main(){
	int i,n,j,bt[max], rem_bt[max],wt[max], tat[max],qt,count=0,temp,sq=0;
	float awt=0,atat=0;
	printf("Enter the number of process : ");
	scanf("%d",&n);
	printf("Enter the burst time : ");
	for(i=0;i<n;i++){
		scanf("%d",&bt[i]);
		rem_bt[i]=bt[i];
	} 
	printf("Enter the quantum time : ");
	scanf("%d",&qt);
	while(1){
	
	for(i=0,count=0;i<n;i++){
		temp=qt;
		if(rem_bt[i]==0){
			count++;
			continue;
		}
		if(rem_bt[i]>qt){
			rem_bt[i]=rem_bt[i]-qt;
			
		}else 	if(rem_bt[i]>=0){
			temp=rem_bt[i];
			rem_bt[i]=0;
		}
		sq=sq+temp;
		tat[i]=sq;
		
	}
	if(n==count)
	break;
	}
	printf("process\t BurstTime\t TurnAroundTime\t WaitingTime\n");
	for(i=0;i<n;i++){
	wt[i]=tat[i]-bt[i];
	awt+=wt[i];
	atat+=tat[i];
	printf("\n%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],tat[i],wt[i]);
}
	printf("The Total Waiting Time is %f \n",awt);
	printf("The Total TurnAround Time is %f \n",atat);
	awt=awt/n;
	atat=atat/n;
	printf("The Average Waiting Time is %f \n",awt);
	printf("The Average TurnAround Time is %f",atat);
	getch();
}
