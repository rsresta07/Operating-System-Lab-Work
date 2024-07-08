#include <stdio.h>  
void main() {  
    int pageFaults = 0, frames, s, i, j, num;   
    printf("Enter the no. of Pages: ");
	scanf("%d",&num);
	int stream[num];
	printf("Enter the Page Number : ");
    for(i=0;i<num;i++)
        scanf("%d",&stream[i]);
    printf("Enter the no. of Frames : ");
    scanf("%d",&frames);
    printf(" Incoming \t ");
	for(i=0; i<frames; i++)
    	printf("Frame%d\t\t",i+1);  
    int temp[frames];  
    
    for(i=0; i<frames; i++) 
        temp[i] = -1;  
    for(i=0; i<num; i++) {  
        s = 0;   
        for(j=0; j<frames; j++) {  
            if(stream[i] == temp[j]) {  
                s++;  
                pageFaults--;  
            }  
        }  
        pageFaults++;  
        if((pageFaults <= frames) && (s == 0))
            temp[i] = stream[i];  
        else if(s == 0)  
            temp[(pageFaults - 1) % frames] = stream[i];  
        printf("\n %d\t\t",stream[i]);  
        
        for(j=0; j<frames; j++) {  
            if(temp[j] != -1)  
                printf(" %d\t\t\t", temp[j]);  
            else  
                printf(" - \t\t\t");  
        }  
    }  
    printf("\nTotal Page Faults: %d\n", pageFaults);  
    printf("\nTotal Page Hits : %d",num-pageFaults);
    getch(); 
}
