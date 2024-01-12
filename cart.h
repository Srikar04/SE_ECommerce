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