#pragma once
#include <string>
#include "Date.h"

class Product {
public:
    std::string name;
    int quantity;
    Date supplyDate;  
    double price;

    Product(const std::string& name, int quantity, const Date& supplyDate, double price);

    const std::string& getName() const;
    int getQuantity() const;
    const Date& getSupplyDate() const;
    double getPrice() const;
};
