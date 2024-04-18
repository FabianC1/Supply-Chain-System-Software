#include <iostream> // Include for input/output stream
#include <string> // Include for string manipulation
#include <vector> // Include for vector container
#include <cstdlib> // Include for standard library functions
#include <ctime> // Include for time-related functions
#include <iomanip> // Include for setw()
#include <fstream>
#include <sstream>
#include <limits> // Include for numeric_limits
#include <cctype> // Include for isdigit
#include <algorithm> // Include for remove_if

#include "customer_info.h" // Include for customer information class
#include "order_item.h" // Include for order item class
#include "product_item.h" // Include for product item class
#include "file_read.h"


// Function to display the menu options
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <games_file>" << std::endl;
        return 1;
    }

    std::string gamesFilename = argv[1];
    std::vector<Game> products = readGamesFromTXT(gamesFilename);

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
        choice = getIntegerInput();

        if (choice == 1) {
            std::cout << "Available games:\n";
            for (size_t i = 0; i < games.size(); ++i) {
                std::cout << i + 1 << ". " << games[i] << " (Stock: " << products[i].stockQuantity << ")\n";
            }

            int game_choice;
            std::cout << "Enter the number of the game you want to buy (1-" << games.size() << "): ";
            std::cin >> game_choice;

            if (game_choice >= 1 && game_choice <= static_cast<int>(games.size())) {
                std::string selected_game = games[game_choice - 1];

                if (products[game_choice - 1].stockQuantity > 0) {
                    char buy_choice;
                    std::cout << "-------------------------------------\n"; // Separator line
                    std::cout << "Do you want to buy " << selected_game << "? (y/n): ";
                    std::cin >> buy_choice;

                    if (buy_choice == 'y' || buy_choice == 'Y') {
                        srand(time(0));
                        int order_id = rand() % 10000 + 1;
                        orders.push_back(Order{order_id, selected_game, "Order Placed"});

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
                        int currentStock = products[game_choice - 1].stockQuantity;
                        products[game_choice - 1].stockQuantity = currentStock - 1;
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
                std::cout << "Enter the order ID to track status: ";
                int orderID;
                std::cin >> orderID;
                bool found = false;

                for (const auto& order : orders) {
                    if (order.order_id == orderID) {
                        found = true;
                        std::cout << "Order ID: " << order.order_id << ", Product: " << order.product << ", Status: " << order.status << std::endl;
                        break;
                    }
                }

                if (!found) {
                    std::cout << "Order with ID " << orderID << " not found." << std::endl;
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
            displayGames(products);
        } else if (choice == 5) {
            std::cout << "Enter the order ID to change status: ";
            int orderID;
            std::cin >> orderID;
            updateOrderStatus(orders, orderID);
        } else if (choice == 6) {
            if (orders.empty()) {
                std::cout << "No orders to cancel.\n";
            } else {
                std::cout << "Existing orders:\n";
                for (const auto& order : orders) {
                    std::cout << "Order ID: " << order.order_id << ", Product: " << order.product << ", Status: " << order.status << std::endl;
                }

                std::cout << "Enter the order ID to cancel: ";
                int orderID;
                std::cin >> orderID;

                auto it = std::find_if(orders.begin(), orders.end(), [&](const Order& order) {
                    return order.order_id == orderID;
                });

                if (it != orders.end()) {
                    orders.erase(it);
                    std::cout << "Order with ID " << orderID << " has been cancelled.\n";
                } else {
                    std::cout << "Order with ID " << orderID << " not found.\n";
                }
            }
        } else if (choice == 7) {
            std::cout << "Exiting the software...\n";
            break;
        } else {
            std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }
    return 0;
}
