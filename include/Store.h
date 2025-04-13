#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Product.h"
#include "Seller.h"

class Store {
private:
    std::string name;
    std::string type;
    std::string location;
    std::vector<Product> products;
    std::vector<Seller> sellers;

public:
    Store(const std::string& name, const std::string type, const std::string& location);
    
    std::string getName()const { return name; }
    std::string getLocation()const { return location; }

    void addProduct(const Product& product);
    void addSeller(const Seller& seller);
    void displayStoreInfo() const;
    void displayProductCatalog() const;
};
