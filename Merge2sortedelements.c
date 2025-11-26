#include <stdio.h>

int main() {
    int A1[50], A2[50], A3[100];
    int n1, n2, i, j, k = 0, t;

    printf("Enter n1: ");
    scanf("%d", &n1);

    printf("Enter elements of A1: ");
    for(i = 0; i < n1; i++)
        scanf("%d", &A1[i]);

    printf("Enter n2: ");
    scanf("%d", &n2);

    printf("Enter elements of A2: ");
    for(i = 0; i < n2; i++)
        scanf("%d", &A2[i]);

    // Sort A1
    for(i = 0; i < n1; i++)
        for(j = i + 1; j < n1; j++)
            if(A1[i] > A1[j]) {
                t = A1[i];
                A1[i] = A1[j];
                A1[j] = t;
            }

    // Sort A2
    for(i = 0; i < n2; i++)
        for(j = i + 1; j < n2; j++)
            if(A2[i] > A2[j]) {
                t = A2[i];
                A2[i] = A2[j];
                A2[j] = t;
            }

    // Display individually sorted arrays
    printf("Sorted A1: ");
    for(i = 0; i < n1; i++) printf("%d ", A1[i]);

    printf("\nSorted A2: ");
    for(i = 0; i < n2; i++) printf("%d ", A2[i]);

    // Merge arrays
    for(i = 0; i < n1; i++) A3[k++] = A1[i];
    for(i = 0; i < n2; i++) A3[k++] = A2[i];

    // Sort merged array
    for(i = 0; i < k; i++)
        for(j = i + 1; j < k; j++)
            if(A3[i] > A3[j]) {
                t = A3[i];
                A3[i] = A3[j];
                A3[j] = t;
            }

    // Display merged + sorted array
    printf("\nMerged & Sorted Array: ");
    for(i = 0; i < k; i++) printf("%d ", A3[i]);

    return 0;
}
