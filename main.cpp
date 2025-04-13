#include <iostream>
#include "include/Menu.h"
#include "include/Date.h"
#include <clocale>

int main() {
    setlocale(LC_ALL, "ukr");
    Menu menu;
    int choice;

    do {
        std::cout << "\n--- Menu ---\n";  // ����
        std::cout << "1. Add Supplier\n";  // ������ �������������
        std::cout << "2. Add Product to Supplier\n";  // ������ ����� �� �������������
        std::cout << "3. Search Suppliers by Product and Period\n";  // ����� ������������� �� ������� � �������
        std::cout << "4. Add Buyer\n";  // ������ �������
        std::cout << "5. Add Order for Buyer\n";  // ������ ���������� ��� �������
        std::cout << "6. Find Buyers by Product, Date, and Quantity\n";  // ������ �������� �� �������, ����� �� �������
        std::cout << "7. Create store point\n";
        std::cout << "8. Add Product to Store\n";
        std::cout << "9. Display Products in Store\n";;
        std::cout << "0. Exit\n";  // �����

        std::cout << "Choose an option: ";  // ������� �����
        std::cin >> choice;

        std::cin.ignore(); // ������� �����

        switch (choice) {
        case 1: {  // ������ �������������
            std::string name, contact;
            std::cout << "Enter supplier name: ";  // ������ ��'� �������������
            std::getline(std::cin, name);
            std::cout << "Enter contact information: ";  // ������ ��������� ����������
            std::getline(std::cin, contact);
            menu.addSupplier(name, contact);
            break;
        }

        case 2: {  // ������ ����� �� �������������
            std::string supplierName, productName, dateStr;
            int quantity;
            double price;

            std::cout << "Enter supplier name: ";  // ������ ��'� �������������
            std::getline(std::cin, supplierName);
            std::cout << "Enter product name: ";  // ������ ����� ������
            std::getline(std::cin, productName);
            std::cout << "Enter quantity: ";  // ������ �������
            std::cin >> quantity;
            std::cout << "Enter delivery date (YYYY-MM-DD): ";  // ������ ���� �������� (����-��-��)
            std::cin >> dateStr;
            std::cout << "Enter product price: ";  // ������ ���� ������
            std::cin >> price;

            menu.addProductToSupplier(supplierName, productName, quantity, Date(dateStr), price);
            break;
        }

        case 3: {  // ����� ������������� �� ������� � �������
            std::string productName, startDateStr, endDateStr;
            int minQuantity;

            std::cout << "Enter product name: ";  // ������ ����� ������
            std::getline(std::cin >> std::ws, productName);
            std::cout << "Enter minimum quantity: ";  // ������ �������� �������
            std::cin >> minQuantity;
            std::cout << "Enter start date (YYYY-MM-DD): ";  // ������ ���� ������� (����-��-��)
            std::getline(std::cin >> std::ws, startDateStr);

            std::cout << "Enter end date (YYYY-MM-DD): ";  // ������ ���� ��������� (����-��-��)
            std::getline(std::cin >> std::ws, endDateStr);

            menu.querySuppliersForProduct(productName, minQuantity, Date(startDateStr), Date(endDateStr));
            break;
        }
        case 4: {  // ������ �������
            std::string name, email;
            std::cout << "Enter buyer's name: ";  // ������ ��'� �������
            std::getline(std::cin, name);
            std::cout << "Enter buyer's email: ";  // ������ ���������� ����� �������
            std::getline(std::cin, email);

            Buyer newBuyer(name, email);
            menu.addBuyer(newBuyer);  // ������ ������� � ����

            break;
        }
        case 5: {  // ������ ���������� ��� �������
            std::string buyerEmail, productName;
            int quantity;
            double price;
            std::string orderDate;

            std::cout << "Enter buyer's email: ";  // ������ ���������� ����� �������
            std::getline(std::cin, buyerEmail);
            std::cout << "Enter product name: ";  // ������ ����� ������
            std::getline(std::cin, productName);
            std::cout << "Enter quantity: ";  // ������ �������
            std::cin >> quantity;
            std::cout << "Enter product price: ";  // ������ ���� ������
            std::cin >> price;
            std::cout << "Enter order date (YYYY-MM-DD): ";  // ������ ���� ���������� (����-��-��)
            std::cin >> orderDate;

            // Searching for the buyer by email
            Buyer* buyer = nullptr;
            for (auto& b : menu.getBuyers()) {
                if (b.getEmail() == buyerEmail) {
                    buyer = &b;
                    break;
                }
            }

            // If buyer is found, create order
            if (buyer != nullptr) {
                std::vector<Product> products;  // Create products
                products.push_back(Product(productName, price));  // Add product to vector

                // Generate unique order ID
                int orderId = Order::generateOrderId();

                // Create the order, passing all necessary parameters
                Order newOrder(orderId, buyer, products, orderDate);

                // Add the order to the buyer
                buyer->addOrder(newOrder);
            }
            else {
                std::cout << "Buyer with this email not found.\n";  // �������� � ����� ����������� ������ �� ���������.
            }

            break;
        }

        case 6: {  // ������ �������� �� �������, ����� �� �������
            std::string productName, startDateStr, endDateStr;
            int minQuantity;

            std::cout << "Enter product name: ";  // ������ ����� ������
            std::getline(std::cin >> std::ws, productName);
            std::cout << "Enter minimum quantity: ";  // ������ �������� �������
            std::cin >> minQuantity;
            std::cout << "Enter start date (YYYY-MM-DD): ";  // ������ ���� ������� (����-��-��)
            std::getline(std::cin >> std::ws, startDateStr);
            std::cout << "Enter end date (YYYY-MM-DD): ";  // ������ ���� ��������� (����-��-��)
            std::getline(std::cin >> std::ws, endDateStr);

            std::vector<Buyer> result = menu.getBuyersByProductAndDate(
                menu.getBuyers(), productName, startDateStr, endDateStr, minQuantity
            );

            std::cout << "\nBuyers matching the criteria:\n";  // �������, �� ���������� ��������
            for (const auto& buyer : result) {
                buyer.displayBuyerInfo();
                std::cout << "----------------------\n";
            }

            std::cout << "Total count: " << result.size() << "\n";  // �������� �������
            break;
        }
        case 7:
        {
            std::string nameStore, type, location;
            std::cout << "Enter name of Store: ";
            std::getline(std::cin, nameStore);
            std::cout << "Enter type (Department store, Shop, Booth, Kiosk): ";
            std::getline(std::cin, type);
            std::cout << "Enter location: ";
            std::getline(std::cin, location);

            Store store(nameStore, type, location);
            menu.addStore(store);

            break;
        }
        case 8:
        {
            std::string nameStore, productName;
            double price;
            int quantity;
            std::cout << "Enter name of Store: ";
            std::getline(std::cin, nameStore);
            std::cout << "Enter product name: ";  // ������ ����� ������
            std::getline(std::cin, productName);
            std::cout << "Enter quantity: ";  // ������ �������
            std::cin >> quantity;
            std::cout << "Enter product price: ";  // ������ ���� ������
            std::cin >> price;
            menu.addProductToStore(nameStore, productName, price, quantity);

            break;
        }
        case 9:
        {
            std::string nameStore;
            std::cout << "Enter name of Store: ";
            std::getline(std::cin, nameStore);

            menu.viewStoreProducts(nameStore);

            break;
        }
        case 0:
            std::cout << "Exiting program.\n";  // ����� � ��������
            break;

        default:
            std::cout << "Invalid choice. Try again.\n";  // ������� ����. ��������� �� ���
        }

    } while (choice != 0);

    return 0;
}
