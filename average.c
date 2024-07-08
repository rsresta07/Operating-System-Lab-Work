#include<stdio.h>

void main() {
	int i, s=0, n;
	float ave=0;
	printf("enter no of items: ");
	scanf("%d",&n);
	int arr[n];
	printf("enter the input: ");
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++) {
		s=s+arr[i];
	}
	ave = (float)s/n;
	printf("The Sum = %d\n",s);
	printf("The average = %f",ave);
}
