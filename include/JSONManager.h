#include <iostream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>
class JSONManager {
private:
    std::string filePath;
    nlohmann::json jsonData;

public:
    JSONManager(const std::string& filePath)
        : filePath(filePath) {}

    void loadData() {
       
        std::cout << "������������ ����� �� " << filePath << std::endl;
    }

    void writeData() {
        
        std::cout << "����� ����� � " << filePath << std::endl;
    }
};