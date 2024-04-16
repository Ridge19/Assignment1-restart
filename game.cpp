#include "game.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Game::Game()
{
    // TODO

}

Game::~Game()
{
    // TODO
    delete board;
    delete player;
}


void Game::start()
{
    //TODO
    Game::loadBoard();
    Game::initializePlayer();
    Game::play();
}

bool Game::loadBoard()
{
    //TODO
    const int ROWS = 10;
    const int COLS = 10;

    std::cout << "|" << " " << "|";
    for (int col = 0; col < COLS; col++) {
        std::cout << "" << col << "|";
    }
    std::cout << std::endl;

    for (int y = 0; y < ROWS; y++) {
        std::cout << "|" << y << "|";
        for (int x = 0; x < COLS; x++) {
            std::cout << "" << " " << "|";
        }
        std::cout << std::endl;
    }
    
    return false; // feel free to revise this line, depending on your implementation.
}

bool Game::initializePlayer()
{
    //TODO
    player = new Player();
    return true; // feel free to revise this line.
}

void Game::play()
{
    //TODO
}