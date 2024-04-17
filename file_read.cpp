#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

const int MAX_GAMES = 20; // Maximum number of games to read

// Struct to represent a game
struct Game {
    std::string name;
    int stockQuantity;
    double price;
};

// Function to read games from a TXT file
bool readGamesFromTXT(const std::string &filename, Game games[], int &numGames) {
    std::ifstream file(filename);
    if (file.is_open()) {
        int count = 0; // Variable to count the number of games read
        std::string line;

        // Discard the header line
        std::getline(file, line);

        while (file.good() && numGames < MAX_GAMES &&
               std::getline(file, line)) {
            std::stringstream ss(line);

            std::string gameName;
            int stockQuantity;
            double price;

            char comma; // to read and discard the commas
            std::getline(ss, gameName, ',');
            ss >> stockQuantity >> comma >> price;

            // Debug output
            std::cout << "Read from file: " << gameName << ", Stock: " << stockQuantity << ", Price: £" << price << std::endl;

            // Store the game in the array
            games[numGames++] = {gameName, stockQuantity, price};

            count++;
        }
        file.close();
        std::cout << "File successfully opened: " << filename << std::endl;
        return true;
    } else {
        std::cout << "Error opening file: " << filename << std::endl;
        return false;
    }
}

std::string getUserInputFilename() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;
    return filename;
}

