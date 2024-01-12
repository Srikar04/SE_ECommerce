/**
 * Filename: inventory.h
 * Author: Srikar
 * Date Created: 12-01-2024
 * Last Modified: 12-01-2024
 *
 * Description:
 * This is the header file for the inventory module. 
 * It contains all its function declarations and structure definitions
 */
#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"

typedef struct Node {
    Item* item;
    struct Node* next;
} Node;

typedef struct Inventory {
    Node* head;
    Node* tail;
} Inventory;

void initializeInventory(Inventory* inventory);
void addItem(Inventory* inventory, Item* item);
void displayInventory(Inventory* inventory);
void saveInventoryState(Inventory* inventory);
void restockItem(Inventory* inventory, int item_id, int quantity);
void freeInventory(Inventory* inventory);
void removeItem(Inventory* inventory, int item_id);
Item* getItemById(Inventory* inventory, int item_id);

#endif