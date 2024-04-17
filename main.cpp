#include <iostream> // Include for input/output stream
#include <string> // Include for string manipulation
#include <vector> // Include for vector container
#include <cstdlib> // Include for standard library functions
#include <ctime> // Include for time-related functions
#include <fstream>
#include <sstream>

#include "customer_info.h" // Include for customer information class
#include "order_item.h" // Include for order item class
#include "product_item.h" // Include for product item class
#include "file_read.h"

// Struct to represent an order
struct Order {
    int order_id; // Order ID
    std::string product; // Product name
};
// Struct to represent a product item
struct ProductItem {
    std::string name;
    int stockQuantity;

    // Function to read game data from a text file
    static std::vector<ProductItem> readGameData(const std::string& filename) {
        std::vector<ProductItem> products;
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::stringstream ss(line);
                std::string name;
                int stockQuantity;
                char comma;
                if (std::getline(ss, name, ',') && ss >> stockQuantity >> comma) {
                    products.push_back({name, stockQuantity});
                }
            }
            file.close();
        } else {
            std::cerr << "Failed to open file: " << filename << std::endl;
        }
        return products;
    }
};

// Function to display the menu options
void displayMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Purchase a product\n";
    std::cout << "2. See orders\n";
    std::cout << "3. See customers who have purchased\n";
    std::cout << "4. See stock\n"; // Updated option to see stock
    std::cout << "5. Exit\n"; // Updated option to exit
}

int main() {
    // Read game data from file
    std::vector<ProductItem> products = ProductItem::readGameData("games.txt");

    std::vector<std::string> games;
    for (const auto& product : products) {
        games.push_back(product.name);
    }

    std::vector<Order> orders;
    std::vector<CustomerInfo> customers;

    int choice;
    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Available games:\n";
            for (int i = 0; i < 10; ++i) {
                std::cout << i + 1 << ". " << games[i] << " (Stock: " << products[i].stockQuantity << ")\n";
            }

            int game_choice;
            std::cout << "Enter the number of the game you want to buy (1-10): ";
            std::cin >> game_choice;

            if (game_choice >= 1 && game_choice <= 10) {
                std::string selected_game = games[game_choice - 1];

                if (products[game_choice - 1].stockQuantity > 0) {
                    char buy_choice;
                    std::cout << "Do you want to buy " << selected_game << "? (y/n): ";
                    std::cin >> buy_choice;

                    if (buy_choice == 'y' || buy_choice == 'Y') {
                        srand(time(0));
                        int order_id = rand() % 10000 + 1;
                        orders.push_back(Order{order_id, selected_game});

                        std::string customer_name;
                        std::cout << "Enter your name: ";
                        std::cin.ignore();
                        std::getline(std::cin, customer_name);

                        bool customer_found = false;
                        for (size_t i = 0; i < customers.size(); ++i) {
                            if (customers[i].GetName() == customer_name) {
                                customer_found = true;
                                break;
                            }
                        }

                        if (!customer_found) {
                            customers.push_back(CustomerInfo(customers.size() + 1, customer_name));
                        }

                        std::cout << "You have purchased " << selected_game << ". Thank you!\n";
                        std::cout << "Your order ID is: " << order_id << std::endl;

                        products[game_choice - 1].stockQuantity -= 1;
                    } else if (buy_choice == 'n' || buy_choice == 'N') {
                        std::cout << "You have chosen not to buy " << selected_game << ".\n";
                    } else {
                        std::cout << "Invalid choice.\n";
                    }
                } else {
                    std::cout << "Sorry, " << selected_game << " is out of stock.\n";
                }
            } else {
                std::cout << "Invalid game selection.\n";
            }
        } else if (choice == 2) {
            if (orders.empty()) {
                std::cout << "No orders have been placed yet.\n";
            } else {
                std::cout << "Orders:\n";
                for (const auto& order : orders) {
                    std::cout << "Order ID: " << order.order_id << ", Product: " << order.product << "\n";
                }
            }
        } else if (choice == 3) {
            if (customers.empty()) {
                std::cout << "No customers have purchased anything yet.\n";
            } else {
                std::cout << "Customers who have purchased:\n";
                for (const auto& customer : customers) {
                    std::cout << "Customer ID: " << customer.GetCustomerID() << ", Name: " << customer.GetName() << "\n";
                }
            }
        } else if (choice == 4) {
            std::cout << "Stock:\n";
            for (int i = 0; i < 10; ++i) {
                std::cout << i + 1 << ". " << games[i] << " (Stock: " << products[i].stockQuantity << ")\n";
            }
        } else if (choice == 5) {
            std::cout << "Exiting...\n";
            break;
        } else {
            std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}

