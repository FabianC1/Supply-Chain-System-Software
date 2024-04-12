// product_item.h
#ifndef product_item_h
#define product_item_h

#include <string>

class product_item {
private:
    int productID;
    std::string name;
    std::string description;
    double price;
    int stockQuantity;

public:
    // Default constructor
    product_item() : productID(0), name(""), description(""), price(0.0), stockQuantity(0) {}

    product_item(int productID, std::string name, std::string description, double price, int stockQuantity);
    void UpdateStock(int newQuantity);
    void AddStock(int quantityToAdd);
    void RemoveStock(int quantityToRemove);
};

#endif /* product_item_h */
