#ifndef FILE_READ_H
#define FILE_READ_H

#include <string>

const int MAX_GAMES = 20; // Maximum number of games to read

// Struct to represent a game
struct Game {
    std::string name;
    int stockQuantity;
    double price;
};

// Function to read games from a TXT file
bool readGamesFromTXT(const std::string &filename, Game games[], int &numGames);

std::string getUserInputFilename();

#endif // FILE_READ_H
