#include<stdio.h>
main() {
	int n, c=0, c1, d, f, i, j, k=0, r, t;
	printf("Enter the no. of Pages: ");
	scanf("%d",&n); 
	int p[n], q[n], b[n], c2[n];
	printf("Enter the Page Number : ");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    printf("Enter the no. of Frames : ");
    scanf("%d",&f);
	q[k]=p[k];
	for(i=0; i<f; i++)
    	printf("\tFrame%d\t",i+1);  
	printf("\n\t%d\n",q[k]);
	c++;
	k++;
	for(i=1;i<n;i++) {
    	c1=0;
    	for(j=0;j<f;j++) {
            if(p[i]!=q[j])
            c1++;
        }
        if(c1==f) {
            c++;
            if(k<f) {
                q[k]=p[i];
                k++;
                for(j=0;j<k;j++)
                	printf("\t%d",q[j]);
                printf("\n");
            }
            else {
            	for(r=0;r<f;r++) {
                    c2[r]=0;
                    for(j=i-1;j<n;j--) {
                        if(q[r]!=p[j])
                            c2[r]++;
                        else
                            break;
                    }
                }
                for(r=0;r<f;r++)
                    b[r]=c2[r];
                for(r=0;r<f;r++) {
                    for(j=r;j<f;j++) {
                        if(b[r]<b[j]) {
                            t=b[r];
                            b[r]=b[j];
                            b[j]=t;
                        }
                    }
                }
                for(r=0;r<f;r++) {
                    if(c2[r]==b[0])
                    	q[r]=p[i];
                    printf("\t%d",q[r]);
                }
                printf("\n");
            }
        }
	}
	printf("\nThe no of page faults = %d",c);
	printf("\nThe no of page hits = %d",n-c);
}

