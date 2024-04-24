#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"

int main() {
    // Login functionality
    char username[50];
    char password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (checkLogin(username, password)) {
        printf("Login successful!\n");

        const int SIZE = 4; // Number of items in the store
        Item **inventory = malloc(SIZE * sizeof(Item *));
        initializeInventory(inventory, SIZE);

        displayInventory(inventory, SIZE);

        int numItems;
        printf("\nEnter the number of items you want to buy: ");
        scanf("%d", &numItems);

        int *items = malloc(numItems * sizeof(int));
        int *quantities = malloc(numItems * sizeof(int));

        printf("\nEnter the item numbers and quantities:\n");
        for (int i = 0; i < numItems; i++) {
            printf("Item %d: ", i + 1);
            scanf("%d", &items[i]);
            printf("Quantity: ");
            scanf("%d", &quantities[i]);
        }

        float total = calculateBill(inventory, SIZE, items, quantities, numItems);
        printf("\nTotal bill: Rupees %.2f\n", total);

        // Free dynamically allocated memory
        for (int i = 0; i < SIZE; i++) {
            free(inventory[i]->name);
            free(inventory[i]);
        }
        free(inventory);
        free(items);
        free(quantities);
    } else {
        printf("Login failed. Invalid username or password.\n");
    }

    return 0;
}
