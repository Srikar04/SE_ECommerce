typedef struct item{
    int item_id;
    char* item_name;
    double item_price;
    int stock;
}Item;

Item createItem(int itemId,char* name,double Price,int stock){
    Item item;
    item.item_id = itemId;
    item.item_name = name;
    item.item_price = Price;
    item.stock = stock;
    return item;
}


