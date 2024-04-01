#include <stdio.h>
#include "store.h"

int main() {
    const int SIZE = 3; // Number of items in the store
    Item inventory[SIZE];
    initializeInventory(inventory, SIZE);

    displayInventory(inventory, SIZE);

    int numItems;
    printf("\nEnter the number of items you want to buy: ");
    scanf("%d", &numItems);

    int items[numItems];
    int quantities[numItems];

    printf("\nEnter the item numbers and quantities:\n");
    for (int i = 0; i < numItems; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i]);
        printf("Quantity: ");
        scanf("%d", &quantities[i]);
    }

    float total = calculateBill(inventory, SIZE, items, quantities, numItems);
    printf("\nTotal bill: $%.2f\n", total);

    return 0;
}
