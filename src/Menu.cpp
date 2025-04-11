#include "Menu.h"
#include <iostream>

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
