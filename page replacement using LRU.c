#include <stdio.h>

int findLRU(int time[], int frames) {
    int min = time[0], pos = 0;
    for (int i = 1; i < frames; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int f, n, pageFaults = 0;
    
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    
    int rs[n], m[f], time[f];

    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    for (int i = 0; i < f; i++)
        m[i] = -1;  

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                found = 1;
                time[j] = i; 
                break;
            }
        }

        if (!found) {
            if (i < f) {
                m[i] = rs[i];
                time[i] = i;
            } else {
                int pos = findLRU(time, f);
                m[pos] = rs[i];
                time[pos] = i;
            }
            pageFaults++;
        }
    }

    printf("\nTotal Page Faults using LRU: %d\n", pageFaults);
    return 0;
}

//output
Enter the number of frames: 3
Enter the number of pages: 14
Enter the reference string: 7 0 1 2 0 3 0 4 2 3 0 3 2 3

Total Page Faults using LRU: 9
