#include "customer_info.h"

// Constructor to initialize customer information
CustomerInfo::CustomerInfo(int customerID, std::string name)
        : customerID(customerID), name(name) {}

// Method to update the customer's name
void CustomerInfo::UpdateName(std::string newName) {
    name = newName; // Update the name
}

// Accessor method to retrieve the customer's ID
int CustomerInfo::GetCustomerID() const {
    return customerID;
}

// Accessor method to retrieve the customer's name
std::string CustomerInfo::GetName() const {
    return name;
}
