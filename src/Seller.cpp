#include "../include/Seller.h"

Seller::Seller(const std::string& name, int id, double salary)
    : name(name), id(id), salary(salary) {}

void Seller::addSale(const Sale& sale) {
    sales.push_back(sale);
}

double Seller::totalSales() const {
    double total = 0;
    for (const auto& sale : sales) {
        total += sale.getTotalPrice();
    }
    return total;
}
