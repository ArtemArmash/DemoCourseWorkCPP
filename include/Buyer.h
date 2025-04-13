#pragma once

#include <string>
#include <vector>
#include "Order.h"

class Buyer {
private:
    std::string name;
    std::string email;
    std::vector<Order> orders;

public:
    Buyer(const std::string& name, const std::string& email);

    std::string getEmail() const;
    void displayBuyerInfo() const;
    bool hasRelevantOrder(const std::string& productName, const std::string& startDate,
        const std::string& endDate, int minQuantity) const;
    void addOrder(const Order& order);
};
