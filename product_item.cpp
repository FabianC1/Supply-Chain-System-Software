// product_item.cpp
#include "product_item.h"

// Default constructor
product_item::product_item() : productID(0), name(""), description(""), stockQuantity(0) {}

// Parameterized constructor
product_item::product_item(int productID, std::string name, std::string description, int stockQuantity)
        : productID(productID), name(name), description(description), stockQuantity(stockQuantity) {}

// Function to update the stock quantity
void product_item::updateStock(int newQuantity) {
    stockQuantity = newQuantity; // Update the stock quantity
}

// Function to add stock
void product_item::addStock(int quantityToAdd) {
    stockQuantity += quantityToAdd; // Add stock
}

// Function to remove stock
void product_item::removeStock(int quantityToRemove) {
    if (quantityToRemove <= stockQuantity) {
        stockQuantity -= quantityToRemove; // Remove stock
    } else {
        // Handle insufficient stock
    }
}
