#pragma once

#include <string>
#include <ctime>

class Date {
private:
    std::tm date;

public:
    Date();
    Date(const std::string& dateStr);

    std::string toString() const;
    bool operator<=(const Date& other) const;
    bool operator>=(const Date& other) const;
    bool operator==(const Date& other) const;
    std::tm getDate() const;
};
