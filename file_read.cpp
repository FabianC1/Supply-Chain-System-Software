#include "file_read.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Function to read games from a TXT file
std::vector<Game> readGamesFromTXT(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Game> games;

    if (file.is_open()) {
        std::string line;

        // Read and discard the header line
        std::getline(file, line);

        while (std::getline(file, line)) {
            std::stringstream ss(line);

            std::string gameName;
            int stockQuantity;
            double price;
            char comma;

            std::getline(ss, gameName, ',');
            ss >> stockQuantity >> comma >> price;

            games.push_back({gameName, stockQuantity, price});
        }

        file.close();
    } else {
        std::cout << "Error opening file: " << filename << std::endl;
    }

    return games;
}