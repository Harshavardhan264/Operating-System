#include<stdio.h>
int main(){
	int bt[20],wt[20],tt[20],i,n;
	float avgwt,avgtt;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter Burst Time for process %d : ",i+1);
		scanf("%d",&bt[i]);
	}
	wt[0]=avgwt=0;
	tt[0]=avgtt=bt[0];
	for(i=1;i<n;i++){
		wt[i]=wt[i-1]+bt[i-1];
		tt[i]=tt[i-1]+bt[i];
		avgwt=avgwt+wt[i];
		avgtt=avgtt+tt[i];
	}
	printf("\tPROCESS \t BURST TIME \t WAITING TIME \t TURN AROUND TIME\n");
	for(i=0;i<n;i++)	
	   printf("\n\t P%d \t\t %d \t\t %d \t\t %d ",i+1,bt[i],wt[i],tt[i]);
	printf("\nAverage Waiting Time : %f",avgwt/n);
	printf("\nAverage Turnaroud Time : %f\n",avgtt/n);
}

//output
Enter the number of processes : 5
Enter Burst Time for process 1 : 3
Enter Burst Time for process 2 : 6
Enter Burst Time for process 3 : 1
Enter Burst Time for process 4 : 7
Enter Burst Time for process 5 : 2
	PROCESS 	 BURST TIME 	 WAITING TIME 	 TURN AROUND TIME

	 P1 		 3 		 0 		 3 
	 P2 		 6 		 3 		 9 
	 P3 		 1 		 9 		 10 
	 P4 		 7 		 10 		 17 
	 P5 		 2 		 17 		 19 
Average Waiting Time : 7.800000
Average Turnaroud Time : 11.600000
