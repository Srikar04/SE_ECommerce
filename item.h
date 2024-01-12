#ifndef ITEM_H
#define ITEM_H

typedef struct item{
    int item_id;
    char* item_name;
    double item_price;
    int stock;
}Item;

//functions
Item createItem(int itemId,char* name,double Price,int stock);

#endif