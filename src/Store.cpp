#include "../include/Store.h"

Store::Store(const std::string& name, const std::string type, const std::string& location)
    : name(name), type{ type }, location(location) {}

void Store::addProduct(const Product& product) {
    products.push_back(product);
}

void Store::addSeller(const Seller& seller) {
    sellers.push_back(seller);
}

void Store::displayStoreInfo() const {
    std::cout << "Store Name: " << name << "\nLocation: " << location << std::endl;
}

void Store::displayProductCatalog() const
{
    if (products.empty()) {
        std::cout << "No products available in this store.\n";
    }
    else {
        std::cout << "Product catalog for " << name << ":\n";
        for (const auto& product : products) {
            std::cout << product.getName() << " - "
                << product.getQuantity() << " units, "
                << "$" << product.getPrice() << " each\n";
        }
    }
}
