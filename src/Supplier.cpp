#include "Supplier.h"

Supplier::Supplier(const std::string& name, const std::string& contactInfo)
    : name(name), contactInfo(contactInfo) {}

void Supplier::addSuppliedProduct(const Product& product) {
    suppliedProducts.push_back(product);
}

const std::vector<Product>& Supplier::getSuppliedProducts() const {
    return suppliedProducts;
}

const std::string& Supplier::getName() const {
    return name;
}
