#include<stdio.h>
#include<limits.h>

// Function to find the index of the page that will not be used for the longest time
int findOptimalPage(int pages[], int frames[], int currentIndex, int n, int k) {
    int farthest = currentIndex;
    int indexToReplace = -1;

    // For each frame, find the page that will be used farthest in the future
    for (int i = 0; i < k; i++) {
        int j;
        // Check for the page in the future reference string
        for (j = currentIndex; j < n; j++) {
            if (frames[i] == pages[j]) {
                break;
            }
        }

        // If the page is not found in the future, it will be replaced
        if (j == n) {
            return i;
        }

        // Track the farthest reference in the future
        if (j > farthest) {
            farthest = j;
            indexToReplace = i;
        }
    }

    return indexToReplace;
}

// Function to implement Optimal Page Replacement Algorithm
int getFault(int pages[], int frames[], int n, int k) {
    int count = 0;

    // Initialize frames with -1 (empty slots)
    for (int i = 0; i < k; i++) {
        frames[i] = -1;
    }

    // Loop through the reference string
    for (int i = 0; i < n; i++) {
        int avail = 0;
        
        // Check if the page is already in one of the frames
        for (int j = 0; j < k; j++) {
            if (frames[j] == pages[i]) {
                avail = 1;
                break;
            }
        }

        // If the page is not found, perform page replacement
        if (avail == 0) {
            // Find the optimal page to replace
            int replaceIndex = findOptimalPage(pages, frames, i + 1, n, k);
            frames[replaceIndex] = pages[i];
            count++;  // Increment page fault count
        }
    }

    return count;
}

int main() {
    int n, pages[50], frames[50], k;

    // Input the number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    // Input the page numbers
    printf("Enter the page numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Input the number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &k);

    // Calculate page faults using the Optimal page replacement algorithm
    int fault = getFault(pages, frames, n, k);

    // Output the number of page faults
    printf("Page faults are: %d\n", fault);

    return 0;
}
output:
Enter the number of pages: 14
Enter the page numbers: 7 0 1 2 0 3 0 4 2 3 0 3 2 3  
Enter the number of frames: 4
Page faults are: 6
