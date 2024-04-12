// product_item.cpp
#include "product_item.h"

product_item::product_item(int productID, std::string name, std::string description, double price, int stockQuantity)
        : productID(productID), name(name), description(description), price(price), stockQuantity(stockQuantity) {}

void product_item::UpdateStock(int newQuantity) {
    stockQuantity = newQuantity;
}

void product_item::AddStock(int quantityToAdd) {
    stockQuantity += quantityToAdd;
}

void product_item::RemoveStock(int quantityToRemove) {
    if (quantityToRemove <= stockQuantity) {
        stockQuantity -= quantityToRemove;
    } else {
        // Handle insufficient stock
    }
}
