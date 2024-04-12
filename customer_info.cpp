// customer_info.cpp
#include "customer_info.h"

customer_info::customer_info(int customerID, std::string name, std::string email, std::string address, std::string phone)
        : customerID(customerID), name(name), email(email), address(address), phone(phone) {}

void customer_info::UpdateContactInfo(std::string newInfo) {
    // Update the contact information
}
