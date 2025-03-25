#include <stdio.h>

int main() {
    int i, j, n, bu[10], wa[10], tat[10], t, ct[10], remaining;
    float awt = 0, att = 0, temp = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    remaining = n; 
    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &bu[i]);
        ct[i] = bu[i]; 
    }

    printf("Enter the time slice: ");
    scanf("%d", &t);
    while (remaining > 0) {
        for (i = 0; i < n; i++) {
            if (bu[i] > 0) {
                if (bu[i] <= t) { 
                    tat[i] = temp + bu[i]; 
                    temp += bu[i];
                    bu[i] = 0; 
                    remaining--; 
                } else {
                    bu[i] -= t; 
                    temp += t;
                }
            }
        }
    }

    // Calculate Waiting Time
    for (i = 0; i < n; i++) {
        wa[i] = tat[i] - ct[i];
        att += tat[i];
        awt += wa[i];
    }

    // Display Results
    printf("\nThe Average Turnaround Time is: %.2f", att / n);
    printf("\nThe Average Waiting Time is: %.2f", awt / n);

    printf("\n\nPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, ct[i], wa[i], tat[i]);

    return 0;
}

//output
Enter the number of processes: 3
Enter Burst Time for process 1: 2
Enter Burst Time for process 2: 6
Enter Burst Time for process 3: 3
Enter the time slice: 2

The Average Turnaround Time is: 7.33
The Average Waiting Time is: 3.67

PROCESS	 BURST TIME 	 WAITING TIME	TURNAROUND TIME
1		    2		               0		     2
2		    6	                   5		     11
3		    3		               6		     9
