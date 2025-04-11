#include "Date.h"

Date::Date() {
    std::memset(&date, 0, sizeof(date));
}

Date::Date(const std::string& dateStr) {
    std::istringstream ss(dateStr);
    ss >> std::get_time(&date, "%Y-%m-%d");
    if (ss.fail()) {
        throw std::invalid_argument("Неправильний формат");
    }
}

std::string Date::toString() const
{
    std::ostringstream oss;
    oss << std::put_time(&date, "%Y-%m-%d");
    return oss.str();
}

bool Date::operator<=(const Date& other) const {
    return std::difftime(std::mktime(const_cast<std::tm*>(&date)), std::mktime(const_cast<std::tm*>(&other.date))) <= 0;
}

bool Date::operator>=(const Date& other) const {
    return std::difftime(std::mktime(const_cast<std::tm*>(&date)), std::mktime(const_cast<std::tm*>(&other.date))) >= 0;
}

bool Date::operator==(const Date& other) const {
    return std::difftime(std::mktime(const_cast<std::tm*>(&date)), std::mktime(const_cast<std::tm*>(&other.date))) == 0;
}
