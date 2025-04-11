#include <iostream>
#include "Menu.h"
#include "Date.h"
#include <clocale>
int main() {
    setlocale(LC_ALL, "ukr");
    Menu menu;
    int choice;

    do {
        std::cout << "\n--- ���� ---\n";
        std::cout << "1. �������� ����������\n";
        std::cout << "2. �������� ����� � ����������\n";
        std::cout << "3. ����� ����������� �� ������ � �������\n";
        std::cout << "0. �����\n";
        std::cout << "�������� �����: ";
        std::cin >> choice;

        std::cin.ignore(); // ������� �����

        switch (choice) {
        case 1: {
            std::string name, contact;
            std::cout << "������� ��� ����������: ";
            std::getline(std::cin, name);
            std::cout << "������� ���������� ����������: ";
            std::getline(std::cin, contact);
            menu.addSupplier(name, contact);
            break;
        }

        case 2: {
            std::string supplierName, productName, dateStr;
            int quantity;
            double price;

            std::cout << "������� ��� ����������: ";
            std::getline(std::cin, supplierName);
            std::cout << "������� �������� ������: ";
            std::getline(std::cin, productName);
            std::cout << "������� ����������: ";
            std::cin >> quantity;
            std::cout << "������� ���� �������� (����-��-��): ";
            std::cin >> dateStr;
            std::cout << "������� ���� ������: ";
            std::cin >> price;

            menu.addProductToSupplier(supplierName, productName, quantity, Date(dateStr), price);
            break;
        }

        case 3: {
            std::string productName, startDateStr, endDateStr;
            int minQuantity;

            std::cout << "������� �������� ������: ";
            std::getline(std::cin >> std::ws, productName);
            std::cout << "������� ����������� ����������: ";
            std::cin >> minQuantity;
            std::cout << "������� ���� ������ (����-��-��): ";
            std::getline(std::cin >> std::ws, startDateStr);

            std::cout << "������� ���� ��������� (����-��-��): ";
            std::getline(std::cin >> std::ws, endDateStr);


            menu.querySuppliersForProduct(productName, minQuantity, Date(startDateStr), Date(endDateStr));
            break;
        }

        case 0:
            std::cout << "����� �� ���������.\n";
            break;

        default:
            std::cout << "�������� �����. ���������� �����.\n";
        }

    } while (choice != 0);

    return 0;
}
