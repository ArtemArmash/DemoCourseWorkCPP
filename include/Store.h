#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Product.h"
#include "Seller.h"
class Store {
private:
    std::string name;
    std::string location;
    std::vector<Product> products;
    std::vector<Seller> sellers;

public:
    Store(const std::string& name, const std::string& location)
        : name(name), location(location) {}

    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void addSeller(const Seller& seller) {
        sellers.push_back(seller);
    }

    void displayStoreInfo() const {
        std::cout << "�������: " << name << "\n������������: " << location << std::endl;
    }
};