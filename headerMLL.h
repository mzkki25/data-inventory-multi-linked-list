#ifndef HEADERMLL_H_INCLUDED
#define HEADERMLL_H_INCLUDED

#include <iostream>
using namespace std;

struct warehouse {
    string warehouseName;
    string ID;
};

struct inventory {
    string inventoryName;
    string code;
    float price;
    int stock;
};

typedef struct elmWarehouse *adrWarehouse;
typedef struct elmInventory *adrInventory;

struct elmWarehouse {
    warehouse info;
    adrWarehouse next;
    adrInventory firstInventory;
    adrInventory lastInventory;
};

struct elmInventory {
    inventory info;
    adrInventory next;
};

struct myList {
    adrWarehouse first;
    adrWarehouse last;
};

void createList(myList &data);

// part of warehouse
warehouse newDataWarehouse(string warehouseName, string ID);
void newElmentWarehouse(warehouse info, adrWarehouse &W);
void insertLastWarehouse(myList &data, adrWarehouse W);
void deleteFirstWarehouse(myList &data, adrWarehouse &W);
void deleteAfterWarehouse(myList &data, adrWarehouse &W);
void deleteLastWarehouse(myList &data, adrWarehouse &W);
adrWarehouse findElmentWarehouse(myList data, string ID);
void deleteWarehouse(myList &data, string ID);

// part of inventory
inventory newDataInventory(string inventoryName, string code, float price, int stock);
void newElmentInventory(inventory info, adrInventory &I);
void insertLastInventory(adrWarehouse W, adrInventory &I);
void deleteFirstInventory(adrWarehouse W, adrInventory &I);
void deleteAfterInventory(adrWarehouse W, adrInventory &I);
void deleteLastInventory(adrWarehouse W, adrInventory &I);
adrInventory findElmentInventory(adrWarehouse W, string code);
void deleteInventory(myList &data, adrWarehouse W, adrInventory I, string ID, string code);

// part of update the inventory
float upgradePrice(myList data, adrWarehouse W, adrInventory I);
void takeStock(myList &data, string ID, string code, int stock);
void addStock(myList &data, string ID, string code, int stock);

// part of count of datatype
int countOfWarehouse(myList data);
int countOfInventory(myList data);
int countOfStock(myList data, string ID);
int countOfPrice(myList data, string ID);
adrInventory maxStock(myList data, string ID);
int countTheNumOfInventory(myList data, string ID);

// part of add data
void addDataWarehouse(myList &data, adrWarehouse W);
void addDataInventory(myList &data, adrWarehouse W, adrInventory I);

// part of print data
void showAll(myList data);
void findAndShowWarehouse(myList data, string ID);
void findAndShowInventory(myList data, string ID, string code);
void findAndShowInventoryWithPriceMoreThanX(myList data, string ID, int X);
void findAndShowInventoryWithStockMoreThanX(myList data, string ID, int X);

// part of execution
int menu();

#endif // HEADERMLL_H_INCLUDED
