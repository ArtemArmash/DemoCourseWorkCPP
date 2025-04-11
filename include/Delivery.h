#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Supplier.h>
#include <Product.h>
class Delivery {
private:
    int id;
    Supplier supplier;
    std::vector<Product> products;
    std::string deliveryDate;

public:
    Delivery(int id, const Supplier& supplier, const std::vector<Product>& products, const std::string& deliveryDate)
        : id(id), supplier(supplier), products(products), deliveryDate(deliveryDate) {}

    void addProductToDelivery(const Product& product) {
        products.push_back(product);
    }
};