#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <Order.h>

class Buyer {
private:
    std::string name;
    int id;
    std::vector<Order> orders;

public:
    Buyer(const std::string& name, int id)
        : name(name), id(id) {}

    void addOrder(const Order& order) {
        orders.push_back(order);
    }

    void displayBuyerInfo() const {
        std::cout << "Покупець: " << name << "\nID: " << id << std::endl;
    }
};