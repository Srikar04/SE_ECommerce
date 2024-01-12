/**
 * Filename: cart.h
 * Author: Srikar
 * Date Created: 12-01-2024
 * Last Modified: 12-01-2024
 *
 * Description:
 * This is the header file for the cart module.
 * It contains all its function declarations and structure definitions
 */

#ifndef CART_H
#define CART_H

typedef struct cartItem {
    char itemName[100];
    int itemId;
    float price;
    int quantity;
    struct cartItem* next;
}cartItem;

typedef struct cart {
    struct cartItem* head;
}Cart;

//Methods
void addItemToCart(Cart* cart, char* itemName, int itemId, float price, int quantity);
void displayCartItems(Cart* cart);
void checkout(Cart* cart);

#endif