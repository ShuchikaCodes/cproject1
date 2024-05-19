#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"

void initializeInventory(Item **inventory, int size) {
    FILE *fp = fopen("inventory.txt", "r");
    if (fp == NULL) {
        perror("Error opening inventory file");
        exit(EXIT_FAILURE);
    }

    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), fp) && i < size) {
        char *name = strtok(line, ",");
        char *price_str = strtok(NULL, ",");
        float price = atof(price_str);

        inventory[i] = malloc(sizeof(Item));
        inventory[i]->name = malloc((strlen(name) + 1) * sizeof(char));
        strcpy(inventory[i]->name, name);
        inventory[i]->price = price;
        i++;
    }

    fclose(fp);
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

