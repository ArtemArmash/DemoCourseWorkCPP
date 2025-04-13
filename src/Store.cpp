#include "../include/Store.h"

Store::Store(const std::string& name, const std::string& location)
    : name(name), location(location) {}

void Store::addProduct(const Product& product) {
    products.push_back(product);
}

void Store::addSeller(const Seller& seller) {
    sellers.push_back(seller);
}

void Store::displayStoreInfo() const {
    std::cout << "Store Name: " << name << "\nLocation: " << location << std::endl;
}
