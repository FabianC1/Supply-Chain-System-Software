#include "order_item.h"
#include <iostream>
#include <algorithm> // Include for remove_if

#include <iomanip> // Include for setw()
#include <limits> // Include for numeric_limits

void updateOrderStatus(std::vector<Order>& orders, int orderID) {
    bool found = false;

    for (auto& order : orders) {
        if (order.order_id == orderID) {
            found = true;
            // Update the order status
            if (order.status == "Order Placed") {
                order.status = "Packaging";
            } else if (order.status == "Packaging") {
                order.status = "Dispatched from factory";
            } else if (order.status == "Dispatched from factory") {
                order.status = "Out for delivery";
            } else if (order.status == "Out for delivery") {
                order.status = "Delivered";
            } else {
                std::cout << "Order is already delivered.\n";
                return;
            }
            std::cout << "Order status updated to " << order.status << ".\n";
            // Remove the order if it has been delivered
            if (order.status == "Delivered") {
                orders.erase(std::remove_if(orders.begin(), orders.end(), [&](const Order& o) {
                    return o.order_id == orderID;
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

void displayMenu() {
    std::cout << "-------------------------------------\n";
    std::cout << "Menu:\n";
    std::cout << "1. Purchase a product\n";
    std::cout << "2. See orders & tracking status\n";
    std::cout << "3. See customers who have purchased\n";
    std::cout << "4. See stock\n";
    std::cout << "5. Change order status\n";
    std::cout << "6. Cancel an existing order\n";
    std::cout << "7. Exit\n";
    std::cout << "-------------------------------------\n";
}

void displayGames(const std::vector<Game>& games) {
    int maxGameNameLength = 0;
    for (const auto& game : games) {
        maxGameNameLength = std::max(maxGameNameLength, static_cast<int>(game.name.length()));
    }

    std::cout << "|-----------------------------------------------------------------------------------------|\n";
    std::cout << "|                Game Name                   | Stock Quantity |            Price          |\n";
    std::cout << "|-----------------------------------------------------------------------------------------|\n";
    for (const auto& game : games) {
        std::cout << "| " << std::setw(maxGameNameLength + 4) << std::left << game.name
                  << "| " << std::setw(15) << std::left << game.stockQuantity
                  << "| £" << std::fixed << std::setprecision(2) << std::setw(25) << std::left << game.price << "|\n";
    }
    std::cout << "|-----------------------------------------------------------------------------------------|\n";
}

int getIntegerInput() {
    int input;
    while (!(std::cin >> input)) {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
    return input;
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
