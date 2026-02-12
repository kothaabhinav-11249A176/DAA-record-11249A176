#include <stdio.h>

// Structure to store item details
struct Item {
    int profit;
    int weight;
    float ratio;
};

// Function to sort items based on profit/weight ratio (descending)
void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    int n, capacity;
    float totalProfit = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter profit and weight for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items by ratio
    sortItems(items, n);

    printf("\nItems selected:\n");

    for (int i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity) {
            // Take full item
            printf("Item with profit %d and weight %d taken fully\n",
                   items[i].profit, items[i].weight);
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            // Take fractional part
            float fraction = (float)capacity / items[i].weight;
            printf("Item with profit %d and weight %d taken partially\n",
                   items[i].profit, items[i].weight);
            totalProfit += items[i].profit * fraction;
            capacity = 0;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}
