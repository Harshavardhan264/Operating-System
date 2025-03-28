#include <stdio.h>

int optimalPageReplacement(int pages[], int n, int f) {
    int frame[f], pageFaults = 0;

    for (int i = 0; i < f; i++)
        frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            if (i < f) {
                frame[i] = pages[i];
            } else {
                int farthest = -1, replaceIndex = -1;
                for (int j = 0; j < f; j++) {
                    int k;
                    for (k = i + 1; k < n; k++) {
                        if (frame[j] == pages[k])
                            break;
                    }
                    if (k > farthest) {
                        farthest = k;
                        replaceIndex = j;
                    }
                }
                frame[replaceIndex] = pages[i];
            }
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

    printf("\nTotal Page Faults using Optimal: %d\n", optimalPageReplacement(pages, n, f));

    return 0;
}
