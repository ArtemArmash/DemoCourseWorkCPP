#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <Sale.h>
class Seller {
private:
    std::string name;
    int id;
    double salary;
    std::vector<Sale> sales;

public:
    Seller(const std::string& name, int id, double salary)
        : name(name), id(id), salary(salary) {}

    void addSale(const Sale& sale) {
        sales.push_back(sale);
    }

    double totalSales() const {
        double total = 0;
        for (const auto& sale : sales) {
            total += sale.getTotalPrice();
        }
        return total;
    }
};