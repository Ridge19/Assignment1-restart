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
    // delete board;
    // delete player;
}

void quitGame() {
    cout << "quitting" << endl;
    return;
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
    board->display(player);
    const int ROWS = 10;
    const int COLS = 10;

    std::cout << "|" << " " << "|";
    for (int col = 0; COLS < COLS; col++) {
        std::cout << "" << COLS << "|";
    }
    std::cout << std::endl;

    for (int y = 0; y < ROWS; y++) {
        std::cout << "|" << y << "|";
        playerRow++;
        for (int x = 0; x < COLS; x++) {
            std::cout << "" << " " << "|";
            playerCol++;
            
        }
        std::cout << std::endl;
    }
    return true; // feel free to revise this line, depending on your implementation.
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
    Position position;
    std::string UserMovement;

    
    // const int ROWS = 10;
    // const int COLS = 10;

    cout << "<x>,<y>,<direction>" << endl;
    cout << "\tx: horizontal position of the vacuum cleaner in the room (between 0 and 9)" << endl;
    cout << "\ty: veritcal position of the vacuum cleaner in the room (between 0 and 9)" << endl;
    cout << "\tdirection: direction of the vacuum cleaner's movement (north, east, south, west)" << endl;
    cout << "forward (or f)" << endl;
    cout << "turn_left (or l)" << endl;
    cout << "turn_right (or r)" << endl;
    cout << "quit" << endl; 

    std::getline(std::cin, UserMovement);
    #define ROWS 10
    #define COLS 10
    
    if (UserMovement.find(COMMAND_FORWARD_SHORTCUT) == 0) {
        PlayerMove moveResult = board.movePlayerForward(&player);

        if (moveResult == PLAYER_MOVED) {
            cout << "Player moving.." << endl;
            loadBoard();
            player.getNextForwardPosition();
            player.updatePosition(position);
        } else {
            cout << "Invalid input" << endl;
        }
    }
    else if (UserMovement.find(COMMAND_TURN_LEFT_SHORTCUT) == 0) {
        cout << "turning left" << endl;
        loadBoard();
        player.getNextForwardPosition();
        player.updatePosition(position);
        if (player.direction == Direction::NORTH) {
            cout << DIRECTION_ARROW_OUTPUT_NORTH;
        } else if (player.direction == Direction::SOUTH) {
            cout << DIRECTION_ARROW_OUTPUT_SOUTH; 
        } else if (player.direction == Direction::EAST) {
            cout << DIRECTION_ARROW_OUTPUT_EAST;
        } else if (player.direction == Direction::WEST) {
            cout << DIRECTION_ARROW_OUTPUT_WEST;
        }
        player.updatePosition(position);
        player.displayDirection();
    } else if (UserMovement.find(COMMAND_TURN_RIGHT_SHORTCUT) == 0) {
        cout << "turning right" << endl;
        loadBoard();
        player.getNextForwardPosition();
        player.updatePosition(position);
        if (player.direction == Direction::NORTH) {
            cout << DIRECTION_ARROW_OUTPUT_NORTH;
        } else if (player.direction == Direction::SOUTH) {
            cout << DIRECTION_ARROW_OUTPUT_SOUTH; 
        } else if (player.direction == Direction::EAST) {
            cout << DIRECTION_ARROW_OUTPUT_EAST;
        } else if (player.direction == Direction::WEST) {
            cout << DIRECTION_ARROW_OUTPUT_WEST;
        }
        player.updatePosition(position);
        player.displayDirection();
    } 
}

