#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
/* Function to print total bins used */
void printBins(int binsUsed) {
    printf("Total bins used: %d\n", binsUsed);
}
/* ================= FIRST FIT ================= */
void firstFit(int items[], int n, int capacity) {
    int remaining[MAX];
    int binsUsed = 0;
    memset(remaining, 0, sizeof(remaining));
    for (int i = 0; i < n; i++) {
        int placed = 0;
        for (int j = 0; j < binsUsed; j++) {
            if (remaining[j] >= items[i]) {
                remaining[j] -= items[i];
                placed = 1;
                break;
            }
        }
        if (!placed) {
            remaining[binsUsed] = capacity - items[i];
            binsUsed++;
        }
    }
    printBins(binsUsed);
}
/* Comparator for sorting in decreasing order */
int compareDescending(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return y - x;
}
/* ================= FIRST FIT DECREASING ================= */
void firstFitDecreasing(int items[], int n, int capacity) {
    int sorted[MAX];
    for (int i = 0; i < n; i++)
        sorted[i] = items[i];
    qsort(sorted, n, sizeof(int), compareDescending);

    printf("\n--- First Fit Decreasing ---\n");
    firstFit(sorted, n, capacity);
}
/* ================= BEST FIT ================= */
void bestFit(int items[], int n, int capacity) {
    int remaining[MAX];
    int binsUsed = 0;
    memset(remaining, 0, sizeof(remaining));

    for (int i = 0; i < n; i++) {
        int bestIndex = -1;
        int minSpaceLeft = capacity + 1;

        for (int j = 0; j < binsUsed; j++) {
            if (remaining[j] >= items[i]) {
                int spaceLeft = remaining[j] - items[i];
                if (spaceLeft < minSpaceLeft) {
                    minSpaceLeft = spaceLeft;
                    bestIndex = j;
                }
            }
        }
        if (bestIndex != -1) {
            remaining[bestIndex] -= items[i];
        } else {
            remaining[binsUsed] = capacity - items[i];
            binsUsed++;
        }
    }
    printf("\n--- Best Fit ---\n");
    printBins(binsUsed);
}
/* ================= MAIN FUNCTION ================= */
int main() {
    int n, capacity;
    int items[MAX];
    printf("Enter number of items: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("Invalid number of items.\n");
        return 1;
    }
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);
    printf("Enter item weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i]);
    }
    printf("\n--- First Fit ---\n");
    firstFit(items, n, capacity);
    firstFitDecreasing(items, n, capacity);
    bestFit(items, n, capacity);
    return 0;
}
