#include <stdio.h>

int main() {
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;

    printf("\nEnter the number of processes : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p[i] = i; 
        printf("Enter Burst Time for Process %d : ", i);
        scanf("%d", &bt[i]);
    }

    for(i = 0; i < n; i++) {
        for(k = i + 1; k < n; k++) {
            if(bt[i] > bt[k]) {
                //swap burst times
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
		// Swap process IDs
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }

    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];

    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1]; 
        tat[i] = tat[i - 1] + bt[i];   
        wtavg = wtavg + wt[i];        
        tatavg = tatavg + tat[i];     
    }
    printf("\n\t PROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME\n");
    for(i = 0; i < n; i++) {
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i] + 1, bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time : %f", wtavg / n);
    printf("\nAverage Turnaround Time : %f", tatavg / n);

    return 0;
}

//output
Enter the number of processes : 3
Enter Burst Time for Process 0 : 5
Enter Burst Time for Process 1 : 2
Enter Burst Time for Process 2 : 3

	 PROCESS 	 BURST TIME 	 WAITING TIME 	 TURNAROUND TIME

	 P2 		 2 		 0 		 2
	 P3 		 3 		 2 		 5
	 P1 		 5 		 5 		 10
Average Waiting Time : 2.333333
Average Turnaround Time : 5.666667
