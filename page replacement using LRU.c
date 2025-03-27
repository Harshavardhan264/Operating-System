#include <stdio.h>

int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for (i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frames, pages, i, j, pos, pageFaults = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    
    printf("Enter the number of pages: ");
    scanf("%d", &pages);
    
    int reference[pages], memory[frames], time[frames];
    
    printf("Enter the reference string: ");
    for (i = 0; i < pages; i++)
        scanf("%d", &reference[i]);

    for (i = 0; i < frames; i++)
        memory[i] = -1; // Initialize frames as empty

    printf("\nPage Replacement Process:\n");

    for (i = 0; i < pages; i++) {
        int found = 0;

        for (j = 0; j < frames; j++) {
            if (memory[j] == reference[i]) {
                found = 1;
                time[j] = i; // Update last used time
                break;
            }
        }

        if (!found) { // Page fault occurs
            if (i < frames) {
                memory[i] = reference[i];
                time[i] = i;
            } else {
                pos = findLRU(time, frames); // Find LRU page
                memory[pos] = reference[i];
                time[pos] = i;
            }
            pageFaults++;
        }

        // Print current frame state
        for (j = 0; j < frames; j++)
            printf("%d\t", memory[j] != -1 ? memory[j] : -1);
        
        if (!found)
            printf("Page Fault No. -- %d", pageFaults);
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}
