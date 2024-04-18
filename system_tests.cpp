#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "customer_info.h"
#include "file_read.h"
#include "order_item.h"
#include "product_item.h"

TEST_CASE("CustomerInfo class test") {
    CustomerInfo customer(1, "John Doe");

    SECTION("Getters return correct values") {
        REQUIRE(customer.GetCustomerID() == 1);
        REQUIRE(customer.GetName() == "John Doe");
    }

    SECTION("UpdateName updates the name correctly") {
        customer.UpdateName("Jane Smith");
        REQUIRE(customer.GetName() == "Jane Smith");
    }
}

TEST_CASE("readGamesFromTXT function test") {
    std::vector<Game> games = readGamesFromTXT("games.txt");

    SECTION("Correct number of games read from file") {
        REQUIRE(games.size() == 20);
    }
    SECTION("Correct game information is read") {
        // Update the expected game names and other details based on the content of your file
        REQUIRE(games[0].name == "Call of Duty: Modern Warfare");
        REQUIRE(games[0].stockQuantity == 1);
        REQUIRE(games[0].price == Approx(59.99));

        REQUIRE(games[1].name == "FIFA 22");
        REQUIRE(games[1].stockQuantity == 20);
        REQUIRE(games[1].price == Approx(49.99));
    }
}

TEST_CASE("OrderItem class test") {
    order_item order(1, 1, "Product1", "Order Placed");

    SECTION("Getters return correct values") {
        REQUIRE(order.getOrderID() == 1);
        REQUIRE(order.getProduct() == "Product1");
        REQUIRE(order.track_order_status() == "Order Placed");
    }

    SECTION("UpdateStatus updates the status correctly") {
        order.update_status("Dispatched");
        REQUIRE(order.track_order_status() == "Dispatched");
    }
}

TEST_CASE("ProductItem class test") {
    product_item product(1, "Game1", "Description", 10, 29.99);

    SECTION("Getters return correct values") {
        REQUIRE(product.getProductID() == 1);
        REQUIRE(product.getName() == "Game1");
        REQUIRE(product.getDescription() == "Description");
        REQUIRE(product.getStockQuantity() == 10);
        REQUIRE(product.getPrice() == Approx(29.99));
    }

    SECTION("UpdateStock updates stock quantity correctly") {
        product.updateStock(15);
        REQUIRE(product.getStockQuantity() == 15);
    }

    SECTION("AddStock increases stock quantity correctly") {
        product.addStock(5);
        REQUIRE(product.getStockQuantity() == 15);
    }

    SECTION("RemoveStock decreases stock quantity correctly") {
        product.removeStock(5);
        REQUIRE(product.getStockQuantity() == 5);
    }
}

TEST_CASE("updateOrderStatus function test") {
    std::vector<Order> orders;
    orders.push_back(Order{1, "Product1", "Order Placed"});
    orders.push_back(Order{2, "Product2", "Order Placed"});
    orders.push_back(Order{3, "Product3", "Order Placed"});

    SECTION("Order status is updated correctly") {
        // Update the order status to 'Packaging' for all orders
        updateOrderStatus(orders, 1);
        updateOrderStatus(orders, 2);
        updateOrderStatus(orders, 3);
        // Verify that the status is updated as expected
        REQUIRE(orders[0].status == "Packaging");
        REQUIRE(orders[1].status == "Packaging");
        REQUIRE(orders[2].status == "Packaging");
    }

    SECTION("Order is removed if status is 'Delivered'") {
        // Update the status of the first order to 'Delivered'
        orders[0].status = "Delivered";
        // Remove the delivered order
        orders.erase(std::remove_if(orders.begin(), orders.end(),
            [](const Order& order) { return order.status == "Delivered"; }),
            orders.end());
        // Verify that only one order is removed
        REQUIRE(orders.size() == 2);
    }
}

TEST_CASE("displayMenu function test") {
    // Redirect cout to a stringstream to capture the output
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    // Call the function
    displayMenu();

    // Restore cout
    std::cout.rdbuf(oldCout);

    // Check the output
    std::string expectedOutput = "-------------------------------------\n";
    expectedOutput += "Menu:\n";
    expectedOutput += "1. Purchase a product\n";
    expectedOutput += "2. See orders & tracking status\n";
    expectedOutput += "3. See customers who have purchased\n";
    expectedOutput += "4. See stock\n";
    expectedOutput += "5. Change order status\n";
    expectedOutput += "6. Cancel an existing order\n";
    expectedOutput += "7. Exit\n";
    expectedOutput += "-------------------------------------\n";
    REQUIRE(output.str() == expectedOutput);
}

TEST_CASE("displayGames function test") {
    // Redirect cout to a stringstream to capture the output
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    // Create a vector of games for testing
    std::vector<Game> games;
    games.push_back(Game{"Game1", 10, 29.99});
    games.push_back(Game{"Game2", 5, 39.99});

    // Call the function
    displayGames(games);

    // Restore cout
    std::cout.rdbuf(oldCout);

    // Define the expected output without trailing whitespace after the price
    std::string expectedOutput = "|-----------------------------------------------------------------------------------------|\n"
                                 "|                Game Name                   | Stock Quantity |            Price          |\n"
                                 "|-----------------------------------------------------------------------------------------|\n"
                                 "| Game1    | 10             | £29.99                    |\n"
                                 "| Game2    | 5              | £39.99                    |\n"
                                 "|-----------------------------------------------------------------------------------------|\n";

    // Verify that the output matches the expected output
    REQUIRE(output.str() == expectedOutput);
}

TEST_CASE("getIntegerInput function test") {
    // Redirect cin to a stringstream to provide input
    std::stringstream input("42\n");
    std::streambuf* oldCin = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    // Call the function
    int result = getIntegerInput();

    // Restore cin
    std::cin.rdbuf(oldCin);

    // Check the result
    REQUIRE(result == 42);
}
