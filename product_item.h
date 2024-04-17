// product_item.h
#ifndef PRODUCT_ITEM_H
#define PRODUCT_ITEM_H

#include <string>
#include <vector>

class product_item {
private:
    int productID;          // Product ID
    std::string name;       // Product name
    std::string description;    // Product description
    int stockQuantity;      // Stock quantity
    double price;

public:
    product_item(); // Default constructor
    product_item(int productID, std::string name, std::string description, int stockQuantity, double price);

    // Getter functions
    int getProductID() const { return productID; } // Retrieve product ID
    std::string getName() const { return name; } // Retrieve product name
    std::string getDescription() const { return description; } // Retrieve product description
    int getStockQuantity() const { return stockQuantity; } // Retrieve stock quantity
    double getPrice() const { return price; }

    // Setter functions
    void setProductID(int id) { productID = id; } // Set product ID
    void setName(const std::string& n) { name = n; } // Set product name
    void setDescription(const std::string& desc) { description = desc; } // Set product description
    void setStockQuantity(int quantity) { stockQuantity = quantity; } // Set stock quantity
    void setPrice(double price) { this->price = price; }


    // Additional member functions for managing stock
    void updateStock(int newQuantity);     // Update stock quantity
    void addStock(int quantityToAdd);      // Add stock
    void removeStock(int quantityToRemove);    // Remove stock
    product_item(std::string basicString, int i, std::string basicString1);

    auto getPrice();
};

#endif // PRODUCT_ITEM_H
