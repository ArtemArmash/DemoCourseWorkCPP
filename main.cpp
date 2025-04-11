#include <iostream>
#include "Menu.h"
#include "Date.h"
#include <clocale>
int main() {
    setlocale(LC_ALL, "ukr");
    Menu menu;
    int choice;

    do {
        std::cout << "\n--- Меню ---\n";
        std::cout << "1. Добавить поставщика\n";
        std::cout << "2. Добавить товар к поставщику\n";
        std::cout << "3. Поиск поставщиков по товару и периоду\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите опцию: ";
        std::cin >> choice;

        std::cin.ignore(); // очищаем буфер

        switch (choice) {
        case 1: {
            std::string name, contact;
            std::cout << "Введите имя поставщика: ";
            std::getline(std::cin, name);
            std::cout << "Введите контактную информацию: ";
            std::getline(std::cin, contact);
            menu.addSupplier(name, contact);
            break;
        }

        case 2: {
            std::string supplierName, productName, dateStr;
            int quantity;
            double price;

            std::cout << "Введите имя поставщика: ";
            std::getline(std::cin, supplierName);
            std::cout << "Введите название товара: ";
            std::getline(std::cin, productName);
            std::cout << "Введите количество: ";
            std::cin >> quantity;
            std::cout << "Введите дату поставки (ГГГГ-ММ-ДД): ";
            std::cin >> dateStr;
            std::cout << "Введите цену товара: ";
            std::cin >> price;

            menu.addProductToSupplier(supplierName, productName, quantity, Date(dateStr), price);
            break;
        }

        case 3: {
            std::string productName, startDateStr, endDateStr;
            int minQuantity;

            std::cout << "Введите название товара: ";
            std::getline(std::cin >> std::ws, productName);
            std::cout << "Введите минимальное количество: ";
            std::cin >> minQuantity;
            std::cout << "Введите дату начала (ГГГГ-ММ-ДД): ";
            std::getline(std::cin >> std::ws, startDateStr);

            std::cout << "Введите дату окончания (ГГГГ-ММ-ДД): ";
            std::getline(std::cin >> std::ws, endDateStr);


            menu.querySuppliersForProduct(productName, minQuantity, Date(startDateStr), Date(endDateStr));
            break;
        }

        case 0:
            std::cout << "Выход из программы.\n";
            break;

        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }

    } while (choice != 0);

    return 0;
}
