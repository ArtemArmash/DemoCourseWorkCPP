#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Sale.h"  // Подключаем заголовочный файл Sale.h

class Seller {
private:
    std::string name;
    int id;
    double salary;
    std::vector<Sale> sales;

public:
    Seller(const std::string& name, int id, double salary);

    void addSale(const Sale& sale);
    double totalSales() const;


    // Геттеры для доступа к данным продавца
    std::string getName() const { return name; }
    int getId() const { return id; }
    double getSalary() const { return salary; }
};
