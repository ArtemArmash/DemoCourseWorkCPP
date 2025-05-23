#include "../include/Product.h"

Product::Product(const std::string& name, int quantity, const Date& supplyDate, double price)
    : name(name), quantity(quantity), supplyDate(supplyDate), price(price) {}

Product::Product(const std::string& name, int quantity, double price) 
    : name(name), quantity(quantity),  price(price) {}

Product::Product(const std::string& name, double price) 
    : name{ name }, price{ price } { }

const std::string& Product::getName() const { return name; }

int Product::getQuantity() const { return quantity; }

const Date& Product::getSupplyDate() const { return supplyDate; }

double Product::getPrice() const { return price; }
