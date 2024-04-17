#ifndef FILE_READ_H
#define FILE_READ_H

#include <string>
#include <vector>

// Struct to represent a game
struct Game {
    std::string name;
    int stockQuantity;
    double price;
};

// Declaration of readGamesFromTXT function
std::vector<Game> readGamesFromTXT(const std::string &filename);

#endif // FILE_READ_H