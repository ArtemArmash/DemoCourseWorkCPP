#include "../include/Menu.h"
#include <iostream>
#include <map>


void Menu::addSupplier(const std::string& name, const std::string& contactInfo) {
    suppliers.push_back(Supplier(name, contactInfo));
}

void Menu::addProductToSupplier(const std::string& supplierName, const std::string& productName,
    int quantity, const Date& supplyDate, double price) {
    for (auto& supplier : suppliers) {
        if (supplier.getName() == supplierName) {
            supplier.addSuppliedProduct(Product(productName, quantity, supplyDate, price));
            break;
        }
    }
}

void Menu::querySuppliersForProduct(const std::string& productName, int minQuantity,
    const Date& startDate, const Date& endDate) {
    int supplierCount = 0;

    std::cout << "Постачальники, які постачають продукцію: " << productName << " в зазначений період:\n";

    for (const auto& supplier : suppliers) {
        int totalQuantity = 0;
        bool isValidSupplier = false;


        for (const auto& product : supplier.getSuppliedProducts()) {
            if (product.getName() == productName &&
                product.getQuantity() >= minQuantity &&
                product.getSupplyDate() >= startDate &&
                product.getSupplyDate() <= endDate) {
                totalQuantity += product.getQuantity();
                isValidSupplier = true;
            }
        }

        if (isValidSupplier) {
            std::cout << "Постачальник: " << supplier.getName() << ", Загальна кількість: " << totalQuantity << "\n";
            supplierCount++;
        }
    }

    std::cout << "Всього постачальників: " << supplierCount << "\n";
}

std::vector<Buyer> Menu::getBuyersByProductAndDate(const std::vector<Buyer>& buyers, 
    const std::string& productName, const std::string& startDate, const std::string& endDate, int minQuantity)
{
    std::vector<Buyer>result;
    for (const auto& buyer : buyers) {
        if (buyer.hasRelevantOrder(productName, startDate, endDate, minQuantity)) {
            result.push_back(buyer);
        }
    }
    return result;
}

std::vector<Buyer>& Menu::getBuyers()
{
    return buyers;

}
void Menu::addBuyer(const Buyer& buyer) {
    buyers.push_back(buyer);
}
void Menu::addStore(const Store& store) {
    stores.push_back(store);
}
void Menu::addProductToStore(const std::string& nameStore, const std::string& productName, int quantity, double price)
{
    for (auto& store : stores) {
        if (store.getName() == nameStore) {
            store.addProduct(Product(productName, quantity, price));
        }
    }
}

void Menu::viewStoreProducts(const std::string& nameStore)
{
    for (auto& store : stores) {
        if (store.getName() == nameStore) {
            store.displayProductCatalog();
            return;
        }
    }
    std::cout << "Store with name " << nameStore << " not found.\n";
}



