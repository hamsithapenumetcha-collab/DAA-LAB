#include <stdio.h>

struct Item {
    int id;
    double value;
    double weight;
    double ratio;
};

int main() {
    int n;
    double capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%lf", &capacity);
   
    struct Item items[n];

    printf("\nEnter value and weight for each item:\n");
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        printf("Item %d - Value: ", i + 1);
        scanf("%lf", &items[i].value);
        printf("Item %d - Weight: ", i + 1);
        scanf("%lf", &items[i].weight);
        
        items[i].ratio = items[i].value / items[i].weight;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    double total_value = 0.0;
    double current_weight = 0.0;

    printf("\nItems selected in the knapsack:\n");
    printf("ID\tTaken Weight\tValue Contribution\n");

    for (int i = 0; i < n; i++) {

        if (current_weight + items[i].weight <= capacity) {
            current_weight += items[i].weight;
            total_value += items[i].value;
            printf("%d\t%.2f\t\t%.2f\n", items[i].id, items[i].weight, items[i].value);
        } 
        
        else {
            double remaining_capacity = capacity - current_weight;
            double fractional_value = items[i].value * (remaining_capacity / items[i].weight);
            
            total_value += fractional_value;
            printf("%d\t%.2f (Fraction)\t%.2f\n", items[i].id, remaining_capacity, fractional_value);
            
            current_weight = capacity;
            break; 
        }
    }

    printf("\nMaximum total value earned: %.2f\n", total_value);

    return 0;
}
    