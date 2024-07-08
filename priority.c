/*
 * C program to implement priority scheduling premeeptive
 */
 
#include <stdio.h>
 
//Function to swap two variables
void swap(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main() {
    int n, i, j;
    printf("Enter Number of Processes: ");
    scanf("%d",&n);
 
    // b is array for burst time, p for priority and index for process id
    int b[n],p[n],pid[n];
    for(i=0;i<n;i++) {
        printf("Burst Time and Priority Value for P%d: ",i+1);
        scanf("%d %d",&b[i],&p[i]);
        pid[i]=i+1;
    }
    for(i=0;i<n;i++) {
        int a=p[i],m=i;
 		//Finding out highest priority element and placing it at its desired position
        for(j=i;j<n;j++) {
            if(p[j] < a) {
                a=p[j];
                m=j;
            }
        }
        //Swapping processes
        swap(&p[i], &p[m]);
        swap(&b[i], &b[m]);
        swap(&pid[i],&pid[m]);
    }

    printf("\nPid    Burst Time     Wait Time      TurnAround Time\n");
    int wt[i], tat[i],ttat=0,twt=0;
    float atat, awt;
    wt[-1]=0,b[-1]=0;
    for(i=0;i<n;i++) {
    	wt[i]=b[i-1]+wt[i-1];
    	tat[i]=wt[i]+b[i];
        printf("P%d   %d       %d    %d\n",pid[i],b[i],wt[i],tat[i]);
        ttat=ttat+tat[i];
        twt=twt+wt[i];
    }
    atat=(float)ttat/n;
    awt=(float)twt/n;
    printf("\n Average WT = %.2f \n Average TAT = %.2f",awt,atat);
    return 0;
}
