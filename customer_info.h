// customer_info.h
#ifndef customer_info_h
#define customer_info_h

#include <string>

class customer_info {
private:
    int customerID;
    std::string name;
    std::string email;
    std::string address;
    std::string phone;

public:
    // Default constructor
    customer_info() : customerID(0), name(""), email(""), address(""), phone("") {}

    customer_info(int customerID, std::string name, std::string email, std::string address, std::string phone);
    void UpdateContactInfo(std::string newInfo);
};

#endif /* customer_info_h */
