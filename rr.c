#include<stdio.h>  
#include<conio.h>  
  
void main() {  
    // initlialize the variable name  
    int i, n, sum=0, count=0, y, quant, wt, tat, ttat, twt;
    float avg_wt, avg_tat;  
    printf(" Total number of process: ");  
    scanf("%d", &n);  
    int at[n], bt[n], temp[n];  
    y = n; // Assign the number of process to variable y  
  
// Use for loop to enter the details of the process like Arrival time and the Burst Time  
	for(i=0; i<n; i++) {  
		printf(" Arrival and Burst time of P%d : ", i+1);  
		scanf("%d %d", &at[i], &bt[i]);  
		temp[i] = bt[i]; // store the burst time in temp array  
	}  
	// Accept the Time qunat  
	printf(" Enter the Time Quantum: ");  
	scanf("%d", &quant);  
	// Display the process No, burst time, Turn Around Time and the waiting time  
	printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");  
	for(sum=0, i = 0; y!=0;) {  
		if(temp[i] <= quant && temp[i] > 0) { // define the conditions    
    		sum = sum + temp[i];  
    		temp[i] = 0;  
    		count=1;  
    	}     
    	else if(temp[i] > 0) {  
        	temp[i] = temp[i] - quant;  
        	sum = sum + quant;    
    	}  
    	if(temp[i]==0 && count==1) {  
        	y--; //decrement the process no.  
        	tat=sum-at[i];
        	wt=sum-at[i]-bt[i];
        	printf("\n P%d \t %d\t\t %d\t\t %d", i+1, bt[i], tat, wt);  
        	twt = twt+sum-at[i]-bt[i];  
        	ttat = ttat+sum-at[i];  
        	count =0;     
    	}  
    	if(i==n-1)
        	i=0;  
    	else if(at[i+1]<=sum) 
        	i++;  
    	else  
        	i=0;  
	}  
	// represents the average waiting time and Turn Around time  
	avg_wt = (float)twt/n;  
	avg_tat = (float)ttat/n;  
	printf("\n Average WT: %.2f", avg_wt);  
	printf("\n Average TAT: %.2f", avg_tat);  
	getch();  
}  
