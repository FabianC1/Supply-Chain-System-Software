#ifndef order_item_h
#define order_item_h

#include <string>
#include <vector> // Include for vector container

// Forward declaration of struct Order
struct Order;

class order_item {
private:
    int order_id; // Order ID
    int customer_id; // Customer ID associated with the order
    std::string product; // Name of the product in the order

public:
    std::string status; // Status of the order (e.g., Pending, Shipped, Delivered)

    order_item(int order_id, int customer_id, std::string product, std::string status); // Constructor
    void update_status(std::string new_status); // Function to update the status of the order
    std::string track_order_status() const; // Function to track the current status of the order
    int getOrderID() const; // Getter function to retrieve the order ID
    std::string getProduct() const; // Getter function to retrieve the product associated with the order
};

// Struct to represent an order
struct Order {
    int order_id; // Order ID
    std::string product; // Product name
    std::string status; // Status of the order (e.g., Pending, Shipped, Delivered)
};

// Function to update order status
void updateOrderStatus(std::vector<order_item>& orders, int orderID);

#endif // order_item_h
