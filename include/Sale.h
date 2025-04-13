#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Buyer.h"
#include "Product.h"

class Seller;

class Sale {
private:
    int id;
    Seller* seller;
    Buyer* buyer;
    std::vector<Product> products;
    double totalPrice;
    std::string saleDate;

public:
    Sale(int id, Seller* seller, Buyer* buyer, const std::vector<Product>& products, const std::string& saleDate);

    void calculateTotalPrice();
    double getTotalPrice() const;
};
