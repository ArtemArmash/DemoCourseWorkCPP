#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Store.h>
class Manager {
private:
    std::string name;
    int id;
    std::vector<Store> stores;

public:
    Manager(const std::string& name, int id)
        : name(name), id(id) {}

    void addStore(const Store& store) {
        stores.push_back(store);
    }

    void displayManagerInfo() const {
        std::cout << "Менеджер: " << name << "\nID: " << id << std::endl;
    }
};