#include <stdio.h>

int main() {
    int blockSize[10], processSize[10], blockAllocated[10];
    int i, j, blocks, processes;

    printf("Enter number of memory blocks: ");
    scanf("%d", &blocks);
    printf("Enter size of each block:\n");
    for (i = 0; i < blocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &processes);
    printf("Enter size of each process:\n");
    for (i = 0; i < processes; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
        blockAllocated[i] = -1;
    }

    for (i = 0; i < processes; i++) {
        int bestIdx = -1;
        for (j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            blockAllocated[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock Allocated\n");
    for (i = 0; i < processes; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (blockAllocated[i] != -1)
            printf("%d\n", blockAllocated[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}

//output
Enter number of memory blocks: 5
Enter size of each block:
Block 1: 100
Block 2: 500
Block 3: 200
Block 4: 300
Block 5: 600

Enter number of processes: 4
Enter size of each process:
Process 1: 212
Process 2: 417
Process 3: 112
Process 4: 426

Process No.	Process Size	Block Allocated
1		212		4
2		417		2
3		112		3
4		426		5
