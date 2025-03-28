#include <stdio.h>

int lruPageReplacement(int pages[], int n, int f) {
    int frame[f], lastUsed[f], pageFaults = 0;

    for (int i = 0; i < f; i++) {
        frame[i] = -1;
        lastUsed[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                lastUsed[j] = i;
                break;
            }
        }
        if (!found) {
            int lruIndex = 0;
            for (int j = 1; j < f; j++) {
                if (lastUsed[j] < lastUsed[lruIndex])
                    lruIndex = j;
            }
            frame[lruIndex] = pages[i];
            lastUsed[lruIndex] = i;
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

    printf("\nTotal Page Faults using LRU: %d\n", lruPageReplacement(pages, n, f));

    return 0;
}
