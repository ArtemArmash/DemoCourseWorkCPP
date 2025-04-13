#include "../include/Sale.h"

Sale::Sale(int id, Seller* seller, Buyer* buyer, const std::vector<Product>& products, const std::string& saleDate)
    : id(id), seller(seller), buyer(buyer), products(products), saleDate(saleDate) {
    calculateTotalPrice();
}

void Sale::calculateTotalPrice() {
    totalPrice = 0;
    for (const auto& product : products) {
        totalPrice += product.getPrice();
    }
}

double Sale::getTotalPrice() const {
    return totalPrice;
}
