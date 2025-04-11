#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Buyer.h"
#include "Product.h"
#include "Seller.h"
class Sale {
private:
    int id;
    Seller seller;
    Buyer buyer;
    std::vector<Product> products;
    double totalPrice;
    std::string saleDate;

public:
    Sale(int id, const Seller& seller, const Buyer& buyer, const std::vector<Product>& products, const std::string& saleDate)
        : id(id), seller(seller), buyer(buyer), products(products), saleDate(saleDate) {
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