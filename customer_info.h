#ifndef CUSTOMER_INFO_H
#define CUSTOMER_INFO_H

#include <string>

class CustomerInfo {
private:
    int customerID; // ID of the customer
    std::string name; // Name of the customer

public:
    // Constructor to initialize customer information
    CustomerInfo(int customerID, std::string name);

    // Method to update the customer's name
    void UpdateName(std::string newName); // Update the customer's name

    // Accessor method to retrieve the customer's ID
    int GetCustomerID() const; // Retrieve the customer's ID

    // Accessor method to retrieve the customer's name
    std::string GetName() const; // Retrieve the customer's name
};

#endif // CUSTOMER_INFO_H
