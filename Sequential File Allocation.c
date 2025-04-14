#include <stdio.h>
#include <stdbool.h>

#define MAX_BLOCKS 50

int main() {
    int memory[MAX_BLOCKS] = {0};
    int n, i, start, length;

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter starting block and length of file %d: ", i + 1);
        scanf("%d%d", &start, &length);

        bool canAllocate = true;

        if (start < 0 || start + length > MAX_BLOCKS) {
            printf("File %d cannot be allocated. Out of memory bounds.\n", i + 1);
            continue;
        }
        for (int j = start; j < start + length; j++) {
            if (memory[j] == 1) {
                canAllocate = false;
                break;
            }
        }

        if (canAllocate) {
            for (int j = start; j < start + length; j++) {
                memory[j] = 1;
            }
            printf("File %d allocated from block %d to %d\n", i + 1, start, start + length - 1);
        } else {
            printf("File %d cannot be allocated. Blocks already in use.\n", i + 1);
        }
    }

    printf("\nMemory Block Status:\n");
    for (i = 0; i < MAX_BLOCKS; i++) {
        printf("Block %2d: %s\n", i, memory[i] ? "Allocated" : "Free");
    }

    return 0;
}



//output
Enter number of files: 3

Enter starting block and length of file 1: 5 4
Enter starting block and length of file 2: 10 3
Enter starting block and length of file 3: 7 3

File 1 allocated from block 5 to 8
File 2 allocated from block 10 to 12
File 3 cannot be allocated. Blocks already in use.

Memory Block Status:
Block  0: Free
Block  1: Free
Block  2: Free
Block  3: Free
Block  4: Free
Block  5: Allocated
Block  6: Allocated
Block  7: Allocated
Block  8: Allocated
Block  9: Free
Block 10: Allocated
Block 11: Allocated
Block 12: Allocated
Block 13: Free
...
Block 49: Free
