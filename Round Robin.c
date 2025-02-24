#include <stdio.h>

void roundRobinScheduling(int n, int bu[], int t) {
    int wa[10], tat[10], ct[10], temp = 0, max = 0;
    float awt = 0, att = 0;
    // Finding the maximum burst time
    for (int i = 0; i < n; i++) {
        ct[i] = bu[i];
        if (bu[i] > max) {
            max = bu[i];
        }
    }
    // Round Robin Scheduling
    for (int time = 0; time <= max; time += t) {
        for (int i = 0; i < n; i++) {
            if (bu[i] != 0) {
                if (bu[i] <= t) {
                    tat[i] = temp + bu[i];
                    temp += bu[i];
                    bu[i] = 0;
                } else {
                    bu[i] -= t;
                    temp += t;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        wa[i] = tat[i] - ct[i];
        att += tat[i];
        awt += wa[i];
    }
    printf("\nThe Average Turnaround Time is -- %.2f", att / n);
    printf("\nThe Average Waiting Time is -- %.2f", awt / n);
    printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");

    for (int i = 0; i < n; i++) {
        printf("\t%d \t %d \t\t %d \t\t %d \n", i + 1, ct[i], wa[i], tat[i]);
    }
}

int main() {
    int n, t;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bu[n]; 
    for (int i = 0; i < n; i++) {
        printf("\nEnter Burst Time for process %d: ", i + 1);
        scanf("%d", &bu[i]);
    }

    // Input time quantum
    printf("\nEnter the size of time slice: ");
    scanf("%d", &t);

    roundRobinScheduling(n, bu, t);

    return 0;
}


//output
Enter the number of processes: 4

Enter Burst Time for process 1: 24

Enter Burst Time for process 2: 8

Enter Burst Time for process 3: 12

Enter Burst Time for process 4: 6

Enter the size of time slice: 4

The Average Turnaround Time is -- 22.50
The Average Waiting Time is -- 8.25
    PROCESS  BURST TIME   WAITING TIME  TURNAROUND TIME
    1         24           8             24
    2         8            0             8
    3         12           4             16
    4         6            6             12
