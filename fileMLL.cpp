#include "headerMLL.h"

void createList(myList &data) {
    data.first = NULL;
    data.last = NULL;
}

// part of warehouse

warehouse newDataWarehouse(string warehouseName, string ID) {
    warehouse elemen;

    elemen.warehouseName = warehouseName;
    elemen.ID = ID;
    return elemen;
}

void newElmentWarehouse(warehouse info, adrWarehouse &W) {
    W = new elmWarehouse();
    W->info = info;
    W->next = NULL;
    W->firstInventory = NULL;
}

void insertLastWarehouse(myList &data, adrWarehouse W) {
    if (data.first == NULL) {
        data.first = W;
        data.last = W;
    } else {
        adrWarehouse P = data.first;

        while (P->next != NULL) {
            P = P->next;
        }
        P->next = W;
        data.last = W;
    }
}

void deleteFirstWarehouse(myList &data, adrWarehouse &W) {
    if (data.first == NULL) {
        cout << "List is empty" << endl;
    } else if (data.first->next == data.first) {
        W = data.first;
        data.first = NULL;
        data.last = NULL;
    } else {
        W = data.first;
        data.first = W->next;
        data.last->next = data.first;
    }
}

void deleteAfterWarehouse(myList &data, adrWarehouse &W) {
    if (data.first == NULL) {
        cout << "List is empty" << endl;
    } else if (data.first->next == data.first) {
        cout << "List contains only 1 element" << endl;
    } else {
        adrWarehouse prec = data.first;

        while (prec->next != W) {
            prec = prec->next;
        }
        prec->next = W->next;
        if (W == data.last) {
            data.last = prec;
        }
    }
}

void deleteLastWarehouse(myList &data, adrWarehouse &W) {
    if (data.first == NULL) {
        cout << "List is empty" << endl;
    } else if (data.first->next == data.first) {
        W = data.first;
        data.first = NULL;
        data.last = NULL;
    } else {
        adrWarehouse WNext = data.first;

        while (WNext->next->next != data.first) {
            WNext = WNext->next;
        }
        W = WNext->next;
        WNext->next = data.first;
        data.last = WNext;
    }
}

adrWarehouse findElmentWarehouse(myList data, string ID) {
    adrWarehouse P = data.first;

    while (P != NULL) {
        if (P->info.ID == ID) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void deleteWarehouse(myList &data, string ID) {
    adrWarehouse W = findElmentWarehouse(data, ID);

    if (W == NULL) {
        cout << "Data not found" << endl;
    } else if (W == data.first) {
        deleteFirstWarehouse(data, W);
    } else if (W == data.last) {
        deleteLastWarehouse(data, W);
    } else {
        deleteAfterWarehouse(data, W);
    }
}

// part of inventory

inventory newDataInventory(string inventoryName, string code, float price, int stock) {
    inventory elemen;

    elemen.inventoryName = inventoryName;
    elemen.code = code;
    elemen.price = price;
    elemen.stock = stock;
    return elemen;
}

void newElmentInventory(inventory info, adrInventory &I) {
    I = new elmInventory();
    I->info = info;
    I->next = NULL;
}

void insertLastInventory(adrWarehouse W, adrInventory &I) {
    if (W->firstInventory == NULL) {
        W->firstInventory = I;
        W->lastInventory = I;
    } else {
        adrInventory P = W->firstInventory;

        while (P->next != NULL) {
            P = P->next;
        }
        P->next = I;
        W->lastInventory = I;
    }
}

void deleteFirstInventory(adrWarehouse W, adrInventory &I) {
    if (W->firstInventory == NULL) {
        cout << "List is empty" << endl;
    } else if (W->firstInventory->next == W->firstInventory) {
        I = W->firstInventory;
        W->firstInventory = NULL;
        W->lastInventory = NULL;
    } else {
        I = W->firstInventory;
        W->firstInventory = I->next;
        W->lastInventory->next = W->firstInventory;
    }
}

void deleteAfterInventory(adrWarehouse W, adrInventory &I) {
    if (W->firstInventory == NULL) {
        cout << "List is empty" << endl;
    } else if (W->firstInventory->next == W->firstInventory) {
        cout << "List contains only 1 element" << endl;
    } else {
        adrInventory prec = W->firstInventory;

        while (prec->next != I) {
            prec = prec->next;
        }
        prec->next = I->next;
        if (I == W->lastInventory) {
            W->lastInventory = prec;
        }
    }
}

void deleteLastInventory(adrWarehouse W, adrInventory &I) {
    if (W->firstInventory == NULL) {
        cout << "List is empty" << endl;
    } else if (W->firstInventory->next == W->firstInventory) {
        I = W->firstInventory;
        W->firstInventory = NULL;
        W->lastInventory = NULL;
    } else {
        adrInventory WNext = W->firstInventory;

        while (WNext->next->next != W->firstInventory) {
            WNext = WNext->next;
        }
        I = WNext->next;
        WNext->next = W->firstInventory;
        W->lastInventory = WNext;
    }
}

adrInventory findElmentInventory(adrWarehouse W, string code) {
    adrInventory P = W->firstInventory;

    while (P != NULL) {
        if (P->info.code == code) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void deleteInventory(myList &data, adrWarehouse W, adrInventory I, string ID, string code) {
    W = findElmentWarehouse(data, ID);
    I = findElmentInventory(W, code);

    if (I == NULL) {
        cout << "Data not found" << endl;
    } else if (I == W->firstInventory) {
        deleteFirstInventory(W, I);
    } else if (I == W->lastInventory) {
        deleteLastInventory(W, I);
    } else {
        deleteAfterInventory(W, I);
    }
}

// part of update the inventory

float upgradePrice(myList data, adrWarehouse W, adrInventory I) {
    float result = I->info.price * I->info.stock;
    return result;
}

void takeStock(myList &data, string ID, string code, int stock) {
    adrWarehouse W = findElmentWarehouse(data, ID);
    adrInventory I = findElmentInventory(W, code);

    if (W != NULL) {
        if (I != NULL) {
            I->info.stock = I->info.stock - stock;
        } else {
            cout << "Data not found" << endl;
        }
    } else {
        cout << "Data not found" << endl;
    }
}

void addStock(myList &data, string ID, string code, int stock) {
    adrWarehouse W = findElmentWarehouse(data, ID);
    adrInventory I = findElmentInventory(W, code);

    if (W != NULL) {
        if (I != NULL) {
            I->info.stock = I->info.stock + stock;
        } else {
            cout << "Data not found" << endl;
        }
    } else {
        cout << "Data not found" << endl;
    }
}

// part of count of datatype

int countOfWarehouse(myList data) {
    int result = 0;
    adrWarehouse P = data.first;

    while (P != NULL) {
        result++;
        P = P->next;
    }
    return result;
}

int countOfInventory(myList data) {
    int result = 0;
    adrWarehouse W = data.first;

    while (W != NULL) {
        adrInventory I = W->firstInventory;

        while (I != NULL) {
            result++;
            I = I->next;
        }
        W = W->next;
    }
    return result;
}

int countOfStock(myList data, string ID) {
    int countStock = 0;
    adrWarehouse W = findElmentWarehouse(data, ID);

    if (W != NULL) {
        adrInventory I = W->firstInventory;

        while (I != NULL) {
            countStock += I->info.stock;
            I = I->next;
        }
    } else {
        cout << "Data not found" << endl;
    }
    return countStock;
}

int countOfPrice(myList data, string ID) {
    int countPrice = 0;
    adrWarehouse W = findElmentWarehouse(data, ID);

    if (W != NULL) {
        adrInventory I = W->firstInventory;

        while (I != NULL) {
            countPrice += upgradePrice(data, W, I);
            I = I->next;
        }
    } else {
        cout << "Data not found" << endl;
    }
    return countPrice;
}

adrInventory maxStock(myList data, string ID) {
    adrInventory maxPrice = NULL;
    adrWarehouse W = findElmentWarehouse(data, ID);

    if (W != NULL) {
        adrInventory I = W->firstInventory;

        int max = W->firstInventory->info.stock;
        while (I != NULL) {
            if (I->info.stock > max) {
                max = I->info.stock;
                maxPrice = I;
            }
            I = I->next;
        }
    }
    return maxPrice;
}

int countTheNumOfInventory(myList data, string ID) {
    int count = 0;
    adrWarehouse W = findElmentWarehouse(data, ID);

    if (W != NULL) {
        adrInventory I = W->firstInventory;

        while (I != NULL) {
            count++;
            I = I->next;
        }
    } else {
        cout << "Data not found" << endl;
    }
    return count;
}

// part of add data

void addDataWarehouse(myList &data, adrWarehouse W) {
    string ID, name;

    while (true) {
        cout << "Input ID / STOP        : ";
        cin >> ID;
        if (ID == "STOP") {
            break;
        }
        cout << "Input name of warehouse: ";
        cin >> name;
        cout << endl;
        newElmentWarehouse(newDataWarehouse(name, ID), W);
        insertLastWarehouse(data, W);
    }
}

void addDataInventory(myList &data, adrWarehouse W, adrInventory I) {
    string inventoryName, ID, code;
    float price;
    int stock;

    while (true) {
        cout << "Input ID of warehouse name: ";
        cin >> ID;
        if (ID == "STOP") {
            break;
        }
        W = findElmentWarehouse(data, ID);
        if (W != NULL) {
            cout << "Input code          : ";
            cin >> code;
            cout << "Input inventory name: ";
            cin >> inventoryName;
            cout << "Input price         : ";
            cin >> price;
            cout << "Input stock         : ";
            cin >> stock;
            cout << endl;
            newElmentInventory(newDataInventory(inventoryName, code, price, stock), I);
            insertLastInventory(W, I);
        } else {
            cout << "Data not found" << endl;
        }
    }
}

// part of print data

void showAll(myList data) {
    adrWarehouse W = data.first;

    while (W != NULL) {
        cout << "====================================================" << endl;
        cout << "ID            : " << W->info.ID << endl;
        cout << "Warehouse Name: " << W->info.warehouseName << endl;
        cout << "====================================================" << endl;
        adrInventory I = W->firstInventory;

        while (I != NULL) {
            cout << "Inventory Name: " << I->info.inventoryName << endl;
            cout << "Code          : " << I->info.code << endl;
            cout << "Price         : " << upgradePrice(data, W, I) << endl;
            cout << "Stock         : " << I->info.stock << endl;
            cout << "====================================================" << endl;
            I = I->next;
        }
        W = W->next;
    }
    cout << endl;
}

void findAndShowWarehouse(myList data, string ID) {
    adrWarehouse W = findElmentWarehouse(data, ID);

    if (W == NULL) {
        cout << "Data not found" << endl;
    } else {
        cout << "====================================================" << endl;
        cout << "ID            : " << W->info.ID << endl;
        cout << "Warehouse Name: " << W->info.warehouseName << endl;
        cout << "====================================================" << endl;
        adrInventory I = W->firstInventory;

        while (I != NULL) {
            cout << "Inventory Name: " << I->info.inventoryName << endl;
            cout << "Code          : " << I->info.code << endl;
            cout << "Price         : " << upgradePrice(data, W, I) << endl;
            cout << "Stock         : " << I->info.stock << endl;
            cout << "====================================================" << endl;
            I = I->next;
        }
    }
}

void findAndShowInventory(myList data, string ID, string code) {
    adrWarehouse W = findElmentWarehouse(data, ID);

    if (W == NULL) {
        cout << "Data not found" << endl;
    } else {
        adrInventory I = findElmentInventory(W, code);

        if (I == NULL) {
            cout << "Data not found" << endl;
        } else {
            cout << "====================================================" << endl;
            cout << "Inventory Name: " << I->info.inventoryName << endl;
            cout << "Code          : " << I->info.code << endl;
            cout << "Price         : " << upgradePrice(data, W, I) << endl;
            cout << "Stock         : " << I->info.stock << endl;
            cout << "====================================================" << endl;
            cout << endl;
        }
    }
}

void findAndShowInventoryWithPriceMoreThanX(myList data, string ID, int X) {
    adrWarehouse W = findElmentWarehouse(data, ID);

    if (W == NULL) {
        cout << "Data not found" << endl;
    } else {
        adrInventory I = W->firstInventory;

        while (I != NULL) {
            if (upgradePrice(data, W, I) > X) {
                cout << "====================================================" << endl;
                cout << "Inventory Name: " << I->info.inventoryName << endl;
                cout << "Code          : " << I->info.code << endl;
                cout << "Price         : " << upgradePrice(data, W, I) << endl;
                cout << "Stock         : " << I->info.stock << endl;
                cout << "====================================================" << endl;
                cout << endl;
            }
            I = I->next;
        }
    }
}

void findAndShowInventoryWithStockMoreThanX(myList data, string ID, int X) {
    adrWarehouse W = findElmentWarehouse(data, ID);

    if (W == NULL) {
        cout << "Data not found" << endl;
    } else {
        adrInventory I = W->firstInventory;

        while (I != NULL) {
            if (I->info.stock > X) {
                cout << "====================================================" << endl;
                cout << "Inventory Name: " << I->info.inventoryName << endl;
                cout << "Code          : " << I->info.code << endl;
                cout << "Price         : " << upgradePrice(data, W, I) << endl;
                cout << "Stock         : " << I->info.stock << endl;
                cout << "====================================================" << endl;
                cout << endl;
            }
            I = I->next;
        }
    }
}

void showAllInventory(myList data, string ID) {
    adrWarehouse W = findElmentWarehouse(data, ID);

    if (W == NULL) {
        cout << "Data not found" << endl;
    } else {
        adrInventory I = W->firstInventory;

        while (I != NULL) {
            cout << "====================================================" << endl;
            cout << "Inventory Name: " << I->info.inventoryName << endl;
            cout << "Code          : " << I->info.code << endl;
            cout << "Price         : " << upgradePrice(data, W, I) << endl;
            cout << "Stock         : " << I->info.stock << endl;
            cout << "====================================================" << endl;
            cout << endl;
            I = I->next;
        }
    }
}

// part of execution

int menu() {
    int choice;

    cout << "====================================================" << endl;
    cout << "1. Add Data in Warehouse" << endl;
    cout << "2. Add Data in Inventory of Warehouse" << endl;
    cout << "3. Show All Data of Warehouse" << endl;
    cout << "4. Find and Show Warehouse" << endl;
    cout << "5. Find and Show Inventory from Warehouse" << endl;
    cout << "6. Delete Warehouse" << endl;
    cout << "7. Delete Inventory from Warehouse" << endl;
    cout << "8. Count of Warehouse" << endl;
    cout << "9. Count of Inventory in Data" << endl;
    cout << "10. Max Stock of Inventory in Warehouse" << endl;
    cout << "11. Count of Price of Inventory in Warehouse" << endl;
    cout << "12. Count of Stock of Inventory in Warehouse" << endl;
    cout << "13. Take Stock of Inventory in Warehouse" << endl;
    cout << "14. Add Stock of Inventory in Warehouse" << endl;
    cout << "15. Show All Data Warehouse with Price More Than X" << endl;
    cout << "16. Show All Data Warehouse with Stock More Than X" << endl;
    cout << "17. Count of Inventory in Warehouse" << endl;
    cout << "0. Exit" << endl;
    cout << "====================================================" << endl;
    cout << "Input choice: ";
    cin >> choice;
    return choice;
}
