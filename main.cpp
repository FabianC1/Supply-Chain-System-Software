#include <iostream> // Include for input/output stream
#include <string> // Include for string manipulation
#include <vector> // Include for vector container
#include <cstdlib> // Include for standard library functions
#include <ctime> // Include for time-related functions
#include "customer_info.h" // Include for customer information class
#include "order_item.h" // Include for order item class
#include "product_item.h" // Include for product item class

// Struct to represent an order
struct Order {
    int order_id; // Order ID
    std::string product; // Product name
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
    // Array of game names
    std::string games[] = {"GTA V", "GTA IV", "Rocket League", "FIFA 22", "Minecraft",
                           "Fortnite", "Call of Duty: Warzone", "Among Us", "Apex Legends",
                           "PUBG"};

    // Initialize stock quantities for each game
    int stockQuantities[] = {100, 54, 18, 9, 24, 124, 107, 36, 45, 70};

    // Vectors to store customers, orders, and products
    std::vector<CustomerInfo> customers; // Vector to store customer information
    std::vector<order_item> orders; // Vector to store order items
    std::vector<product_item> products; // Vector to store product items

    // Initialize product items
    for (int i = 0; i < 10; ++i) {
        products.push_back(product_item(i + 1, games[i], "Description", stockQuantities[i]));
    }

    int choice; // Variable to store user's choice
    while (true) { // Loop for displaying the menu
        displayMenu(); // Display the menu
        std::cout << "Enter your choice: ";
        std::cin >> choice; // Read user's choice

        if (choice == 1) { // Purchase a product
            std::cout << "Available games:\n";
            for (int i = 0; i < 10; ++i) {
                std::cout << i + 1 << ". " << games[i] << " (Stock: " << products[i].getStockQuantity() << ")\n";
            }

            int game_choice; // Variable to store user's game choice
            std::cout << "Enter the number of the game you want to buy (1-10): ";
            std::cin >> game_choice; // Read user's game choice

            if (game_choice >= 1 && game_choice <= 10) { // Validate game choice
                std::string selected_game = games[game_choice - 1]; // Get selected game name

                if (products[game_choice - 1].getStockQuantity() > 0) { // Check if the selected game is in stock
                    char buy_choice; // Variable to store user's buy choice
                    std::cout << "Do you want to buy " << selected_game << "? (y/n): ";
                    std::cin >> buy_choice; // Read user's buy choice

                    if (buy_choice == 'y' || buy_choice == 'Y') { // If user wants to buy
                        srand(time(0)); // Seed for random number generation
                        int order_id = rand() % 10000 + 1; // Generate a random order ID between 1 and 10000

                        // Create an order_item object and add it to the orders vector
                        orders.push_back(order_item(order_id, customers.size() + 1, selected_game, "Pending"));

                        std::string customer_name; // Variable to store customer's name
                        std::cout << "Enter your name: ";
                        std::cin.ignore(); // Clear input buffer
                        std::getline(std::cin, customer_name); // Read customer's name

                        bool customer_found = false; // Flag to check if customer is found
                        for (size_t i = 0; i < customers.size(); ++i) { // Loop through existing customers
                            if (customers[i].GetName() == customer_name) { // If customer already exists
                                customer_found = true; // Set flag to true
                                break; // Exit loop
                            }
                        }

                        if (!customer_found) { // If customer is not found
                            customers.push_back(CustomerInfo(customers.size() + 1, customer_name)); // Add new customer
                        }

                        std::cout << "You have purchased " << selected_game << ". Thank you!\n";
                        std::cout << "Your order ID is: " << order_id << std::endl;

                        // Decrease stock quantity
                        products[game_choice - 1].removeStock(1);
                    } else if (buy_choice == 'n' || buy_choice == 'N') { // If user chooses not to buy
                        std::cout << "You have chosen not to buy " << selected_game << ".\n";
                    } else { // Invalid choice
                        std::cout << "Invalid choice.\n";
                    }
                } else { // If the selected game is out of stock
                    std::cout << "Sorry, " << selected_game << " is out of stock.\n";
                }
            } else { // Invalid game selection
                std::cout << "Invalid game selection.\n";
            }
        } else if (choice == 2) { // See orders
            if (orders.empty()) { // If no orders have been placed yet
                std::cout << "No orders have been placed yet.\n";
            } else { // If there are orders
                std::cout << "Orders:\n";
                for (const auto& order : orders) { // Loop through orders
                    std::cout << "Order ID: " << order.getOrderID() << ", Product: " << order.getProduct() << ", Status: " << order.track_order_status() << "\n";
                }
            }
        } else if (choice == 3) { // See customers who have purchased
            if (customers.empty()) { // If no customers have purchased anything yet
                std::cout << "No customers have purchased anything yet.\n";
            } else { // If there are customers who have purchased
                std::cout << "Customers who have purchased:\n";
                for (const auto& customer : customers) { // Loop through customers
                    std::cout << "Customer ID: " << customer.GetCustomerID() << ", Name: " << customer.GetName() << "\n";
                }
            }
        } else if (choice == 4) { // See stock
            std::cout << "Stock:\n";
            for (int i = 0; i < 10; ++i) { // Loop through products
                std::cout << i + 1 << ". " << games[i] << " (Stock: " << products[i].getStockQuantity() << ")\n";
            }
        } else if (choice == 5) { // Exit
            std::cout << "Exiting...\n";
            break; // Exit the loop
        } else { // Invalid choice
            std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }

    return 0; // Return 0 to indicate successful execution
}
