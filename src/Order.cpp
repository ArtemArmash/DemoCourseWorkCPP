#include "../include/Order.h"
#include "../include/Buyer.h"

Order::Order(int id, Buyer* buyer, const std::vector<Product>& products, const std::string& orderDate)
    : id(id), buyer(buyer), products(products), orderDate(orderDate) {
    calculateTotalPrice();
}

int Order::generateOrderId() {
    static int id = 0;
    return ++id;
}

void Order::calculateTotalPrice() {
    totalPrice = 0;
    for (const auto& product : products) {
        totalPrice += product.getPrice();
    }
}

double Order::getTotalPrice() const {
    return totalPrice;
}

bool Order::containsProduct(const std::string& productName, int minQuantity) const {
    int count = 0;
    for (const auto& product : products) {
        if (product.getName() == productName) {
            count++;
        }
    }
    return count >= minQuantity;
}

bool Order::isInDateRange(const std::string& startDate, const std::string& endDate) const {
    return orderDate >= startDate && orderDate <= endDate;
}
