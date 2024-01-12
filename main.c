/**
 * Filename: main.c
 * Author: Srikar
 * Date Created: 12-01-2024
 * Last Modified: 12-01-2024
 *
 * Description:
 * This is the main file that is the start point of the project.
 *
 */

#include <stdio.h>
#include <stdlib.h>

//header files
#include "inventory.h"
#include "item.h"
#include "cart.h"
#include "report.h"

int main(){
    Inventory* inventory;
    inventory = (Inventory*)malloc(sizeof(Inventory));
    inventory->head = NULL;
    inventory->tail = NULL;
    initializeInventory(inventory);

    struct cart* cart = (struct cart*)malloc(sizeof(struct cart));
    cart->head = NULL;

    printf("\n-------------------------------------");
    printf("\n║                                    ║");
    printf("\n║         Welcome to our Store!      ║");
    printf("\n║          Let's go Shopping!        ║");
    printf("\n║                                    ║");
    printf("\n--------------------------------------\n");

    while(1){
        int mode;

        printf("Choose a mode:\n");
        printf("1. Customer\n");
        printf("2. Administrator\n");
        printf("3. Exit\n");

        printf("Your Option: ");
        scanf("%d", &mode);

        if(mode == 1){
            printf("Welcome Customer\n");
            int choice;
            while(1){
                printf("1. Display Items\n");
                printf("2. Add product to Cart\n");
                printf("3. Display Cart\n");
                printf("4. Checkout\n");
                printf("5. Exit to main menu\n");

                printf("Your Option: ");
                scanf("%d", &choice);

                if(choice == 1){
                    displayInventory(inventory);
                }else if(choice == 2){
                    int itemId;
                    int quantity;

                    printf("Enter Item ID: ");
                    scanf("%d", &itemId);

                    printf("Enter Quantity: ");
                    scanf("%d", &quantity);

                    Item* item = getItemById(inventory, itemId);
                    if(item != NULL && item->stock >= quantity){
                        addItemToCart(cart, item->item_name,item->item_id,quantity,item->item_price);
                        item->stock -= quantity;
                        printf("Item added to cart successfully!\n");
                    }else{
                        printf("Item not found or insufficient stock!\n");
                    }
                    saveInventoryState(inventory);
                }else if(choice == 3){
                    displayCartItems(cart);
                }else if(choice == 4){
                    checkout(cart);
                    free(cart);
                }else{
                    break;
                }
            }
        }else if(mode == 2){
            printf("Welcome Administrator\n");
            int choice;
            while(1){
                printf("1. Display All items\n");
                printf("2. Add new Item\n");
                printf("3. Restock Items\n");
                printf("4. Remove Items\n");
                printf("5. Generate Report\n");
                printf("6. Exit to main menu\n");

                printf("Your Option: ");
                scanf("%d", &choice);

                if(choice == 1){
                    displayInventory(inventory);
                }else if(choice == 2){
                    int itemId;
                    char name[100];
                    double price;
                    int stock;

                    printf("Enter Item ID: ");
                    scanf("%d", &itemId);

                    printf("Enter Item Name: ");
                    scanf("%s", name);

                    printf("Enter Item Price: ");
                    scanf("%lf", &price);

                    printf("Enter Stock: ");
                    scanf("%d", &stock);

                    Item new_item = createItem(itemId, name, price, stock);
                    addItem(inventory, &new_item);
                    saveInventoryState(inventory);
                }else if(choice == 3){
                    int itemId;
                    int amount;

                    printf("Enter Item ID: ");
                    scanf("%d", &itemId);

                    printf("Enter Amount: ");
                    scanf("%d", &amount);

                    restockItem(inventory,itemId, amount);
                    saveInventoryState(inventory);
                }else if(choice == 4){
                    int itemId;

                    printf("Enter ID of item to be removed: ");
                    scanf("%d", &itemId);

                    removeItem(inventory,itemId);
                    saveInventoryState(inventory);
                }else if(choice == 5){
                    printf("1.Show all transaction\n");
                    printf("2.Show transactions by name\n");
                    printf("3.Show transactions above a certain amount\n");
                    int num;
                    scanf("Your Option:%d",&num);
                    switch (num) {
                        case 1:
                            readReport();
                            break;
                        case 2:
                            char name[100];
                            printf("Enter name: ");
                            scanf("%s", name);
                            readReportByName(name);
                            break;
                        case 3:
                            double amount;
                            printf("Enter amount: ");
                            scanf("%lf", &amount);
                            readReportByAmount(amount);
                            break;
                        default:
                            printf("Invalid option\n");
                            break;
                    }
                }else {
                    break;
                }
            }
        }else{
            freeInventory(inventory);
            break;
        }
    }
}
