/**
 * Filename: item.h
 * Author: Srikar
 * Date Created: 12-01-2024
 * Last Modified: 12-01-2024
 *
 * Description:
 * This is the header file for the item module. 
 * It contains all its function declarations and structure definitions
 */
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