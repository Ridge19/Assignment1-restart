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
    cout << "game start function" << endl;
}

bool Game::loadBoard()
{
    //TODO
    return false; // feel free to revise this line, depending on your implementation.
}

bool Game::initializePlayer()
{
    //TODO
    return false; // feel free to revise this line.
}

void Game::play()
{
    //TODO
}