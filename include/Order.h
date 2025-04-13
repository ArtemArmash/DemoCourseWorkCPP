#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Product.h"

class Buyer;

class Order {
private:
    int id;
    Buyer* buyer;
    std::vector<Product> products;
    double totalPrice;
    std::string orderDate;

public:
    Order() = default;
    Order(int id, Buyer* buyer, const std::vector<Product>& products, const std::string& orderDate);

    static int generateOrderId();

    void calculateTotalPrice();
    double getTotalPrice() const;

    bool containsProduct(const std::string& productName, int minQuantity = 1) const;
    bool isInDateRange(const std::string& startDate, const std::string& endDate) const;
};
