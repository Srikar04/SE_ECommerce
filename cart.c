#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cartItem {
    char itemName[100];
    int itemId;
    float price;
    int quantity;
    struct cartItem* next;
} cartItem;

typedef struct cart {
    struct cartItem* head;
} Cart;

void addItemToCart(Cart* cart, char* itemName, int itemId, float price, int quantity) {
    // Create a new cart item
    cartItem* newItem = (cartItem*)malloc(sizeof(cartItem));
    strcpy(newItem->itemName, itemName);
    newItem->itemId = itemId;
    newItem->price = price;
    newItem->quantity = quantity;
    newItem->next = NULL;

    if (cart->head == NULL) {
        cart->head = newItem;
    } else {
        cartItem* currentItem = cart->head;
        while (currentItem->next != NULL) {
            currentItem = currentItem->next;
        }
        currentItem->next = newItem;
    }
}

void displayCartItems(Cart* cart) {
    // Check if the cart is empty
    if (cart->head == NULL) {
        printf("Cart is empty.\n");
        return;
    }
    printf("Name\tID\tPrice\tQuantity\n");
    cartItem* currentItem = cart->head;
    while (currentItem != NULL) {
        printf("%s\t%d\t%.2f\t%d\n", currentItem->itemName, currentItem->itemId, currentItem->price, currentItem->quantity);
        currentItem = currentItem->next;
    }
}


void checkout(Cart* cart) {
    // Check if the cart is empty
    if (cart->head == NULL) {
        printf("Cart is empty.\n");
        return;
    }

    // Ask for user options
    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);

    char paymentOption[10];
    printf("Enter payment option (cash or card): ");
    scanf("%s", paymentOption);

    // Calculate final bill
    float totalBill = 0.0;
    cartItem* currentItem = cart->head;
    while (currentItem != NULL) {
        totalBill += (currentItem->price * currentItem->quantity);
        currentItem = currentItem->next;
        
    }
    // Calculate GST
    float gst = totalBill * 0.18;

    // Display final bill with GST
    printf("\n");
    printf("Customer Name: %s\n", name);
    printf("Payment Option: %s\n", paymentOption);
    printf("Total Bill: %.2f\n", totalBill);
    printf("GST: %.2f\n", gst);
    printf("Total Bill (including GST): %.2f\n", totalBill + gst);

    printf("\nPayment Done. Happy Shopping.\n");
}




