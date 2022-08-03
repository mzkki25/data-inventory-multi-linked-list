#include <iostream>
#include "headerMLL.h"

using namespace std;

int main() {
    myList data;
    adrWarehouse W;
    adrInventory I;
    string ID, code;
    int changeStock, moreThanX;

    createList(data);
    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                addDataWarehouse(data, W);
                cout << endl;
                break;
            case 2:
                addDataInventory(data, W, I);
                cout << endl;
                break;
            case 3:
                showAll(data);
                cout << endl;
                break;
            case 4:
                cout << "Input ID: ";
                cin >> ID;
                findAndShowWarehouse(data, ID);
                cout << endl;
                break;
            case 5:
                cout << "Input ID  : ";
                cin >> ID;
                cout << "Input Code: ";
                cin >> code;
                findAndShowInventory(data, ID, code);
                cout << endl;
                break;
            case 6:
                cout << "Input ID: ";
                cin >> ID;
                deleteWarehouse(data, ID);
                cout << endl;
                break;
            case 7:
                cout << "Input ID  : ";
                cin >> ID;
                cout << "Input Code: ";
                cin >> code;
                deleteInventory(data, W, I, ID, code);
                cout << endl;
                break;
            case 8:
                cout << "Count of Warehouse        : " << countOfWarehouse(data) << endl;
                cout << endl;
                break;
            case 9:
                cout << "Count of Inventory in Data: " << countOfInventory(data) << endl;
                cout << endl;
                break;
            case 10:
                cout << "Input ID: ";
                cin >> ID;
                I = maxStock(data, ID);
                if (I == NULL) {
                    cout << "Data not found" << endl;
                } else {
                    cout << "Inventory Name: " << I->info.inventoryName << endl;
                    cout << "Code          : " << I->info.code << endl;
                    cout << "Price         : " << upgradePrice(data, W, I) << endl;
                    cout << "Stock         : " << I->info.stock << endl;
                    cout << "====================================================" << endl;
                    cout << endl;
                }
                cout << endl;
                break;
            case 11:
                cout << "Input ID                                : ";
                cin >> ID;
                cout << "Count of Price of Inventory in Warehouse: " << countOfPrice(data, ID) << endl;
                cout << endl;
                break;
            case 12:
                cout << "Input ID                                : ";
                cin >> ID;
                cout << "Count of Stock of Inventory in Warehouse: " << countOfStock(data, ID) << endl;
                cout << endl;
                break;
            case 13:
                cout << "Input ID      : ";
                cin >> ID;
                cout << "Input Code    : ";
                cin >> code;
                cout << "Input Quantity: ";
                cin >> changeStock;
                takeStock(data, ID, code, changeStock);
                cout << endl;
                break;
            case 14:
                cout << "Input ID      : ";
                cin >> ID;
                cout << "Input Code    : ";
                cin >> code;
                cout << "Input Quantity: ";
                cin >> changeStock;
                addStock(data, ID, code, changeStock);
                cout << endl;
                break;
            case 15:
                cout << "Input ID   : ";
                cin >> ID;
                cout << "Input Price: ";
                cin >> moreThanX;
                findAndShowInventoryWithPriceMoreThanX(data, ID, moreThanX);
                cout << endl;
                break;
            case 16:
                cout << "Input ID   : ";
                cin >> ID;
                cout << "Input Stock: ";
                cin >> moreThanX;
                findAndShowInventoryWithStockMoreThanX(data, ID, moreThanX);
                cout << endl;
                break;
            case 17:
                cout << "Input ID: ";
                cin >> ID;
                cout << "Count of Inventory in Warehouse: " << countTheNumOfInventory(data, ID) << endl;
                cout << endl;
                break;
            default:
                cout << "End input" << endl;
                cout << endl;
                break;
        }
    } while (choice != 0);
    return 0;
}
