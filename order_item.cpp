#include "order_item.h"
#include <iostream>
#include <algorithm> // Include for remove_if

// Implement updateOrderStatus function
void updateOrderStatus(std::vector<order_item>& orders, int orderID) {
    bool found = false;

    // Iterate through the orders vector
    for (auto& order : orders) {
        if (order.getOrderID() == orderID) {
            found = true;
            // Update the order status
            if (order.track_order_status() == "Order Placed") {
                order.update_status("Packaging");
            } else if (order.track_order_status() == "Packaging") {
                order.update_status("Dispatched from factory");
            } else if (order.track_order_status() == "Dispatched from factory") {
                order.update_status("Out for delivery");
            } else if (order.track_order_status() == "Out for delivery") {
                order.update_status("Delivered");
            } else {
                std::cout << "Order is already delivered.\n";
                return;
            }
            std::cout << "Order status updated to " << order.track_order_status() << ".\n";
            // Remove the order if it has been delivered
            if (order.track_order_status() == "Delivered") {
                orders.erase(std::remove_if(orders.begin(), orders.end(), [&](const order_item& o) {
                    return o.getOrderID() == orderID;
                }), orders.end());
                std::cout << "Order " << orderID << " has been completed and removed!\n";
            }
            break;
        }
    }

    if (!found) {
        std::cout << "Order with ID " << orderID << " not found." << std::endl;
    }
}


order_item::order_item(int order_id, int customer_id, std::string product, std::string status)
        : order_id(order_id), customer_id(customer_id), product(product), status(status) {}

void order_item::update_status(std::string new_status) {
    status = new_status;
}

std::string order_item::track_order_status() const {
    return status;
}

int order_item::getOrderID() const {
    return order_id;
}

std::string order_item::getProduct() const {
    return product;

}
