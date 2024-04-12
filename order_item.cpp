// order_item.cpp
#include "order_item.h"

order_item::order_item(int order_id, int customer_id, int product_id, int quantity, std::string status)
        : order_id(order_id), customer_id(customer_id), product_id(product_id), quantity(quantity), status(status) {}

void order_item::update_status(std::string new_status) {
    status = new_status;
}

std::string order_item::track_order_status() {
    return status;
}

int order_item::getOrderID() const {
    return order_id;
}

