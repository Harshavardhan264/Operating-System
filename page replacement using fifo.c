#include <stdio.h>

int fifoPageReplacement(int pages[], int n, int f) {
    int frame[f], front = 0, count = 0, pageFaults = 0;

    for (int i = 0; i < f; i++)
        frame[i] = -1; 

    for (int i = 0; i < n; i++) {
        int found = 0;
        // Check if page is already in frame
        for (int j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        // If page is not found, replace using FIFO
        if (!found) {
            frame[front] = pages[i];
            front = (front + 1) % f; 
            pageFaults++;
        }
    }
    return pageFaults;
}

int main() {
    int n, f;

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    int pageFaults = fifoPageReplacement(pages, n, f);
    printf("\nTotal Page Faults using FIFO: %d\n", pageFaults);

    return 0;
}


//output
Enter the length of reference string: 12
Enter the reference string: 1 3 0 3 5 6 3 0 3 2 4 1
Enter the number of frames: 3

The number of Page Faults using FIFO are: 10
