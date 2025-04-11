#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Buyer.h"
#include "Product.h"
class Order {
private:
    int id;
    Buyer buyer;
    std::vector<Product> products;
    double totalPrice;
    std::string orderDate;

public:
    Order(int id, const Buyer& buyer, const std::vector<Product>& products, const std::string& orderDate)
        : id(id), buyer(buyer), products(products), orderDate(orderDate) {
        calculateTotalPrice();
    }

    void calculateTotalPrice() {
        totalPrice = 0;
        for (const auto& product : products) {
            totalPrice += product.getPrice();
        }
    }

    double getTotalPrice() const {
        return totalPrice;
    }
};