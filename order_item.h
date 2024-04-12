#ifndef order_item_h
#define order_item_h

#include <string>

class order_item {
private:
    int order_id;
    int customer_id;
    int product_id;
    int quantity;
    std::string status;

public:
    order_item(int order_id, int customer_id, int product_id, int quantity, std::string status);
    void update_status(std::string new_status);
    std::string track_order_status();
    int getOrderID() const; // Getter function for order_id
};

#endif // order_item_h
