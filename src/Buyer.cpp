#include "../include/Buyer.h"

Buyer::Buyer(const std::string& name, const std::string& email)
    : name(name), email(email) {}

std::string Buyer::getEmail() const {
    return email;
}

void Buyer::displayBuyerInfo() const {
    std::cout << "Name: " << name << "\nEmail: " << email << std::endl;
}

bool Buyer::hasRelevantOrder(const std::string& productName, const std::string& startDate,
    const std::string& endDate, int minQuantity) const {
    for (const auto& order : orders) {
        if (order.containsProduct(productName, minQuantity) || order.isInDateRange(startDate, endDate)) {
            return true;
        }
    }
    return false;
}

void Buyer::addOrder(const Order& order) {
    orders.push_back(order);
}
