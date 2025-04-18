#pragma once
#include <vector>
#include <string>
#include "Supplier.h"
#include "Date.h"
#include "Buyer.h"
#include "Order.h"
#include "Store.h"
class Menu {
private:
    std::vector<Supplier> suppliers;
    std::vector<Buyer>buyers;
    std::vector<Order>orders;
    std::vector<Store>stores;
public:
    void addSupplier(const std::string& name, const std::string& contactInfo);

    void addProductToSupplier(const std::string& supplierName, const std::string& productName,
        int quantity, const Date& supplyDate, double price);

    void querySuppliersForProduct(const std::string& productName, int minQuantity,
        const Date& startDate, const Date& endDate);
    ///////////////
    std::vector<Buyer> getBuyersByProductAndDate(const std::vector<Buyer>& buyers, const std::string& productName, 
        const std::string& startDate, const std::string& endDate, int minQuantity);

    std::vector<Buyer>& getBuyers();
    void addBuyer(const Buyer& buyer);

    void addStore(const Store& store);
    void addProductToStore(const std::string& nameStore, const std::string& productName,
        int quantity, double price);

    void viewStoreProducts(const std::string& nameStore);
    
    void printProductInfoInStore(Store& store, const std::string& productName);

    void getProdctInfoAllStores(const std::string& productName);
    void getProductInfoByStoreType(const std::string& productName, const std::string& storeType);
    void getProductInfoByStore(const std::string& productName, const std::string& storeId);

};