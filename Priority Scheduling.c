#include <stdio.h>

int main() {
    int p[20], bt[20], pri[20], wt[20], tat[20], n, i, k, temp;
    float wtavg = 0, tatavg = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        p[i] = i;  
        printf("Enter the Burst Time & Priority of Process %d: ", i);
        scanf("%d %d", &bt[i], &pri[i]);
    }

    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
            if (pri[i] > pri[k]) {
                // Swap process indices
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;

                // Swap burst time
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                // Swap priority
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;
            }
        }
    }

    wt[0] = 0;  
    tat[0] = bt[0];  
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1]; 
        tat[i] = tat[i - 1] + bt[i]; 
    }

    for (i = 0; i < n; i++) {
        wtavg += wt[i];
        tatavg += tat[i];
    }
    printf("\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i] + 1, pri[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f", tatavg / n);

    return 0;
}
//output
Enter the number of processes: 3
Enter the Burst Time & Priority of Process 0: 6 2
Enter the Burst Time & Priority of Process 1: 8 1
Enter the Burst Time & Priority of Process 2: 7 3

PROCESS    PRIORITY    BURST TIME    WAITING TIME    TURNAROUND TIME
1           1           8             0               8
2           2           6             8               14
3           3           7             14              21

Average Waiting Time: 7.33
Average Turnaround Time: 14.33
