#include <stdio.h>
#include <conio.h>

int main()
{
int Max[10][10], need[10][10], allocation[10][10], available[10], completed[10], safeSequence[10];
int p, r, i, j, process, count;
count = 0;

printf("Enter the number of processes : ");
scanf("%d", &p);

for(i = 0; i< p; i++)
 completed[i] = 0;

printf("\nEnter the number of resources : ");
scanf("%d", &r);

printf("\nEnter the MAX Matrix for each process : \n");
for(i = 0; i < p; i++)
{
 printf("For process %d : ", i + 1);
 for(j = 0; j < r; j++)
  scanf("%d", &Max[i][j]);
}

printf("\n\nEnter the ALLOCATION for each process : \n");
for(i = 0; i < p; i++)
{
 printf("For process %d : ",i + 1);
 for(j = 0; j < r; j++)
  scanf("%d", &allocation[i][j]); 
}

printf("\n\nEnter the AVAILABLE Resources : ");
for(i = 0; i < r; i++)
  scanf("%d", &available[i]); 


 for(i = 0; i < p; i++)
  for(j = 0; j < r; j++)
   need[i][j] = Max[i][j] - allocation[i][j];
  
do
{
 printf("\n Max matrix:\tALLOCATION matrix:\n");
 for(i = 0; i < p; i++)
 {
  for( j = 0; j < r; j++)
   printf("%d  ", Max[i][j]);
  printf("\t\t");
  for( j = 0; j < r; j++)
   printf("%d  ", allocation[i][j]);
  printf("\n");
 }

 process = -1;

 for(i = 0; i < p; i++)
 {
  if(completed[i] == 0)
  {
   process = i ;
   for(j = 0; j < r; j++)
   {
    if(available[j] < need[i][j])
    {
     process = -1;
     break;
    }
   }
  }
  if(process != -1)
   break;
 }

 if(process != -1)
 {
  printf("\nProcess %d runs to completion!", process + 1);
  safeSequence[count] = process + 1;
  count++;
  for(j = 0; j < r; j++)
  {
   available[j] += allocation[process][j];
   allocation[process][j] = 0;
   Max[process][j] = 0;
   completed[process] = 1;
  }
 }
}while(count != p && process != -1);

if(count == p)
{
 printf("\nThe system is in a SAFE state!!\n");
 printf("Safe Sequence : < ");
 for( i = 0; i < p; i++)
   printf("%d  ", safeSequence[i]);
 printf(">\n");
}
else
 printf("\nThe system is in an UNSAFE state!!");
getch();
}
