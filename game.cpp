#include "game.h"
#include "board.h"
#include "player.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Game::Game()
{
    // TODO
    playerRow = 0;
    playerCol = 0;

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
    // loadBoard();
    initializePlayer();
    play();
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
    Player player;
    player.position.y = 0;
    player.position.x = 0;
    // Player* vacuumClean = new Player();
    return true; // feel free to revise this line.
    // Game::play();
}

void Game::play()
{
    //TODO
    // Player* vacuumClean = new Player();
    // Board* board = new Board();
    Board board;
    Player player; 
    std::string UserMovement;

    
    // const int ROWS = 10;
    // const int COLS = 10;


    cout << "Enter command: ";
    // std::getline(std::cin, UserMovement);
    //     if (UserMovement.find(COMMAND_FORWARD_SHORTCUT) == 0) {
    //         cout << "Input recieved. moving player forward" << endl;
    //         board->movePlayerForward(player);
    //         player->getNextForwardPosition();
    //     }
    std::getline(std::cin, UserMovement);

    if (UserMovement.find(COMMAND_FORWARD_SHORTCUT) == 0) {
        PlayerMove moveResult = board.movePlayerForward(&player);

        if (moveResult == PLAYER_MOVED) {
            cout << "Player moving.." << endl;
            this->player->getNextForwardPosition();
            player.position.x++;
        } else if (moveResult == OUTSIDE_BOUNDS) {
            cout << "Error! player is on edge of board." << endl;
        } else if (moveResult == CELL_BLOCKED) {
            cout << "Error! cell infront of player is blocked." << endl;
        } else {
            cout << "Invalid input" << endl;
        }
    }





    //     for (int y = 0; y < ROWS; y++) {
    //     std::cout << LINE_OUTPUT << y << LINE_OUTPUT;
    //     for (int x = 0; x < COLS; x++) {
    //         if (player.position.y == y && player.position.x == x) {
    //             playerRow++;
    //             std::cout << "@" << LINE_OUTPUT;
    //         } else {
    //             std::cout << EMPTY_OUTPUT << LINE_OUTPUT;
    //         }
    //     }
    //     // Add newline character after each row
    //     std::cout << std::endl;
    // }
}

