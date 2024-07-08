#include<stdio.h>
#include<conio.h>

//Function to swap two variables
void swap(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

void main() {
	int n, i, j, tat, wt=0;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	int bt[n], prio[n],pid[n];
	
	for(i=0;i<n;i++) {
		printf("Burst Time and Priority of P%d : ",i+1);
		scanf("%d %d",&bt[i],&prio[i]);
		pid[i]=i+1;
	}
	
	for(i=0;i<n;i++) {
        int a=prio[i], m=i;
        //Finding out highest priority element and placing it at its desired position
        for(j=i;j<n;j++){
            if(prio[j]<a){
                a=prio[j];
                m=j;
            }
        }
        //Swapping processes
        swap(&prio[i], &prio[m]);
        swap(&bt[i], &bt[m]);
        swap(&pid[i], &pid[m]);
    }
    
    printf("Process Id   Priority   Burst Time   Wait Time   TurnAround Time\n");
    for(i=0;i<n;i++) {
    	tat =wt+bt[i];
        printf("P%2d         %2d         %2d           %2d          %2d\n",pid[i],prio[i],bt[i],wt,tat);
        wt += bt[i];
        ttat=ttat+tat;
        twt=twt+wt;
    }
    Avetat=
}
