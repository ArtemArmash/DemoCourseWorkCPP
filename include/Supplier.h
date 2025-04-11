#pragma once
#include <string>
#include <vector>
#include "Product.h"

class Supplier {
private:
    std::string name;
    std::string contactInfo;
    std::vector<Product> suppliedProducts;

public:
    Supplier(const std::string& name, const std::string& contactInfo);

    void addSuppliedProduct(const Product& product);

    const std::string& getName() const;
    const std::vector<Product>& getSuppliedProducts() const;
};
