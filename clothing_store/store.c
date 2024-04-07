#include <stdio.h>
#include "store.h"

void initializeInventory(Item inventory[], int size) {
    // You can add items and their prices here
    // For simplicity, let's hardcode some items
    Item items[] = {
        {"Shirt", 1500.0},
        {"Pants", 2000.0},
        {"Jacket", 2500.0}
    };
    for (int i = 0; i < size; i++) {
        inventory[i] = items[i];
    }
}

void displayInventory(Item inventory[], int size) {
    printf("Available Items:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - Rupees %.2f\n", i + 1, inventory[i].name, inventory[i].price);
    }
}

float calculateBill(Item inventory[], int size, int items[], int quantities[], int numItems) {
    float total = 0.0;
    for (int i = 0; i < numItems; i++) {
        int index = items[i] - 1;
        if (index >= 0 && index < size) {
            total += inventory[index].price * quantities[i];
        }
    }
    return total;
}
