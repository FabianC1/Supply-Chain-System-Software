#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

struct Customer {
    std::string name;
    int customer_id;
    bool has_purchased;
};

struct Order {
    int order_id;
    std::string product;
};

void displayMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Purchase a product\n";
    std::cout << "2. See orders\n";
    std::cout << "3. See customers who have purchased\n";
    std::cout << "4. Exit\n";
}

int main() {
    std::string games[] = {"GTA V", "GTA IV", "Rocket League", "FIFA 22", "Minecraft",
                           "Fortnite", "Call of Duty: Warzone", "Among Us", "Apex Legends",
                           "PUBG"};

    std::vector<Customer> customers;
    std::vector<Order> orders;

    int choice;
    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Available games:\n";
            for (int i = 0; i < 10; ++i) {
                std::cout << i + 1 << ". " << games[i] << "\n";
            }

            int game_choice;
            std::cout << "Enter the number of the game you want to buy (1-10): ";
            std::cin >> game_choice;

            if (game_choice >= 1 && game_choice <= 10) {
                std::string selected_game = games[game_choice - 1];
                char buy_choice;
                std::cout << "Do you want to buy " << selected_game << "? (y/n): ";
                std::cin >> buy_choice;

                if (buy_choice == 'y' || buy_choice == 'Y') {
                    
                    srand(time(0));
                    int order_id = rand() % 10000 + 1; // Random number between 1 and 10000
                    orders.push_back({order_id, selected_game});

                    std::string customer_name;
                    int customer_id;
                    bool customer_found = false;
                    std::cout << "Enter your name: ";
                    std::cin.ignore();
                    std::getline(std::cin, customer_name);

                    for (size_t i = 0; i < customers.size(); ++i) {
                        if (customers[i].name == customer_name) {
                            customer_found = true;
                            customers[i].has_purchased = true;
                            customer_id = customers[i].customer_id;
                            break;
                        }
                    }


                    if (!customer_found) {
                        customer_id = rand() % 1000 + 1; // Random number between 1 and 1000
                        customers.push_back({customer_name, customer_id, true});
                    }

                    std::cout << "You have purchased " << selected_game << ". Thank you!\n";
                    std::cout << "Your order ID is: " << order_id << std::endl;
                } else if (buy_choice == 'n' || buy_choice == 'N') {
                    std::cout << "You have chosen not to buy " << selected_game << ".\n";
                } else {
                    std::cout << "Invalid choice.\n";
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
                    if (customer.has_purchased) {
                        std::cout << "Customer ID: " << customer.customer_id << ", Name: " << customer.name << "\n";
                    }
                }
            }
        } else if (choice == 4) {
            std::cout << "Exiting...\n";
            break;
        } else {
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}
