#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"

void initializeInventory(Item **inventory, int size) {
    // You can add items and their prices here
    // For simplicity, let's hardcode some items
    Item items[] = {
        {"Shirt", 1500.0},
        {"Pants", 2000.0},
        {"Jacket", 2500.0},
        {"Sweater", 2000.0}

    };

    for (int i = 0; i < size; i++) {
        inventory[i] = malloc(sizeof(Item));
        inventory[i]->name = malloc((strlen(items[i].name) + 1) * sizeof(char));
        strcpy(inventory[i]->name, items[i].name);
        inventory[i]->price = items[i].price;
    }
}

void displayInventory(Item **inventory, int size) {
    printf("Available Items:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - Rupees %.2f\n", i + 1, inventory[i]->name, inventory[i]->price);
    }
}

float calculateBill(Item **inventory, int size, int *items, int *quantities, int numItems) {
    float total = 0.0;
    for (int i = 0; i < numItems; i++) {
        int index = items[i] - 1;
        if (index >= 0 && index < size) {
            total += inventory[index]->price * quantities[i];
        }
    }
    return total;
}

int checkLogin(const char *username, const char *password) {
    // Read from config file to check username and password
    FILE *fp = fopen("config.txt", "r");
    if (fp == NULL) {
        perror("Error opening config file");
        return 0;
    }

    char user[50];
    char pass[50];
    while (fscanf(fp, "%s %s", user, pass) != EOF) {
        if (strcmp(username, user) == 0 && strcmp(password, pass) == 0) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}
