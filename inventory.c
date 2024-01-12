#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "item.h"


// Define the structure for a single node in the inventory list
typedef struct Node {
    Item* item;
    struct Node* next;
} Node;

// Define the inventory list with head and tail pointers
typedef struct Inventory {
    Node* head;
    Node* tail;
} Inventory;

void addItem(Inventory* inventory, Item* item);

// Function to initialize the inventory list
void initializeInventory(Inventory* inventory) {
    // Open the file for reading
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    // Read items from the file and add them to the inventory list
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        if(strlen(line) == 0){
            break;
        }
        // Parse the line to extract item details
        char* token;
        Item* item = (Item*)malloc(sizeof(Item));

        // Extract item_id
        token = strtok(line, ",");
        item->item_id = atoi(token);

        // Extract item_name
        token = strtok(NULL, ",");
        item->item_name = strdup(token);

        // Extract item_price
        token = strtok(NULL, ",");
        item->item_price = atof(token);

        // Extract stock
        token = strtok(NULL, ",");
        item->stock = atoi(token);

        // Add the item to the inventory list
        addItem(inventory, item);
    }
    // Close the file
    fclose(file);
}


// Function to add an item to the inventory list
void addItem(Inventory* inventory, Item* item) {
    // Create a new node for the item
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = NULL;

    // If the inventory is empty, update both head and tail pointers
    if (inventory->head == NULL) {
        inventory->head = newNode;
        inventory->tail = newNode;
    } else {
        // Otherwise, add the new node to the end of the list
        inventory->tail->next = newNode;
        inventory->tail = newNode;
    }
}

// Function to get an item from the inventory list by item ID
Item* getItemById(Inventory* inventory, int item_id) {
    Node* current = inventory->head;

    // Iterate through the list to find the item
    while (current != NULL) {
        if (current->item->item_id == item_id) {
            return current->item;
        }
        current = current->next;
    }

    // Item not found
    return NULL;
}


// Function to display the items in the inventory list
void displayInventory(Inventory* inventory) {
    Node* current = inventory->head;

    printf("Inventory:\n");
    while (current != NULL) {
        printf("%d\t%s\t%.2f\t%d\n", current->item->item_id, current->item->item_name, current->item->item_price, current->item->stock);
        current = current->next;
    }
}

// Function to remove an item from the inventory list
void removeItem(Inventory* inventory, int item_id) {
    Node* current = inventory->head;
    Node* previous = NULL;

    // Iterate through the list to find the item
    while (current != NULL) {
        if (current->item->item_id == item_id) {
            // If the item is found at the head of the list
            if (previous == NULL) {
                inventory->head = current->next;
            } else {
                previous->next = current->next;
            }

            // If the item is found at the tail of the list
            if (current == inventory->tail) {
                inventory->tail = previous;
            }

            // Free the memory allocated for the item
            free(current->item);
            free(current);
            break;
        }

        previous = current;
        current = current->next;
    }

}


// Function to restock items in the inventory list
void restockItem(Inventory* inventory, int item_id, int quantity) {
    Node* current = inventory->head;

    // Iterate through the list to find the item
    while (current != NULL) {
        if (current->item->item_id == item_id) {
            // Update the quantity of the item
            current->item->stock += quantity;
            break;
        }
        current = current->next;
    }
}


// Function to save the inventory state to a CSV file
void saveInventoryState(Inventory* inventory) {
    // Open the file for writing
    FILE* file = fopen("data.csv", "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    Node* current = inventory->head;

    // Write each item in the inventory to the file
    while (current != NULL) {
        fprintf(file, "%d,%s,%.2f,%d\n", current->item->item_id, current->item->item_name, current->item->item_price, current->item->stock);
        current = current->next;
    }

    // Close the file
    fclose(file);
}

// Function to free the memory allocated for the inventory list
void freeInventory(Inventory* inventory) {
    Node* current = inventory->head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    inventory->head = NULL;
    inventory->tail = NULL;
}

