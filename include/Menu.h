#pragma once
#include <vector>
#include <string>
#include "Supplier.h"
#include "Date.h"

class Menu {
private:
    std::vector<Supplier> suppliers;

public:
    void addSupplier(const std::string& name, const std::string& contactInfo);

    void addProductToSupplier(const std::string& supplierName, const std::string& productName,
        int quantity, const Date& supplyDate, double price);

    void querySuppliersForProduct(const std::string& productName, int minQuantity,
        const Date& startDate, const Date& endDate);
};
