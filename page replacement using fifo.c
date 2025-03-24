#include <stdio.h>

int main() {
    int i, j, k, f, pf = 0, count = 0, n;
    int rs[25], m[10];

    printf("\nEnter the length of reference string: ");
    scanf("%d", &n);

    printf("\nEnter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    printf("\nEnter the number of frames: ");
    scanf("%d", &f);
    for (i = 0; i < f; i++)
        m[i] = -1;

    printf("\nThe Page Replacement Process is:\n");

    for (i = 0; i < n; i++) {
        for (k = 0; k < f; k++) {
            if (m[k] == rs[i])
                break;
        }

        if (k == f) {
            m[count++] = rs[i];
            pf++; // Increment page fault count
        }

        for (j = 0; j < f; j++)
            printf("\t%d", m[j]);

        if (k == f)
            printf("\tPF No. %d", pf);

        printf("\n");

        if (count == f)
            count = 0;
    }

    printf("\nThe number of Page Faults using FIFO are: %d\n", pf);

    return 0;
}


//output
Enter the length of reference string: 12
Enter the reference string: 1 3 0 3 5 6 3 0 3 2 4 1
Enter the number of frames: 3

The number of Page Faults using FIFO are: 10
