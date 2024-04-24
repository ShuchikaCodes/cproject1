#ifndef STORENEW_H
#define STORENEW_H

// Struct to represent an item in the store
typedef struct {
    char *name;
    float price;
} Item;

// Function to initialize the inventory
void initializeInventory(Item **inventory, int size);

// Function to display the available items
void displayInventory(Item **inventory, int size);

// Function to calculate the total bill
float calculateBill(Item **inventory, int size, int *items, int *quantities, int numItems);

// Function to check login credentials
int checkLogin(const char *username, const char *password);

#endif
