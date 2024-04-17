#include "order_item.h"

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
