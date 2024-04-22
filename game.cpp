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

void quitGame() {
    return;
}


void Game::start()
{
    //TODO
    play();
}

bool Game::loadBoard()
{
    //TODO
    board->display(player);
    return true; // feel free to revise this line, depending on your implementation.
}

bool Game::initializePlayer()
{
    //TODO
    Player player;
    player.position.y = player.position.y;
    player.position.x = player.position.x;
    return true; // feel free to revise this line.
}

void Game::play()
{
    //TODO
    Board board;
    Player player; 
    Position position;
    std::string UserMovement;

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
    
    if (UserMovement.find(COMMAND_FORWARD_SHORTCUT) == 0) { //when user inputs f
        PlayerMove moveResult = board.movePlayerForward(&player);

        if (moveResult == PLAYER_MOVED) { //if player has moved (return PLAYER_MOVED)
            cout << "Player moving.." << endl;
            loadBoard();
            player.getNextForwardPosition();
            player.updatePosition(position);
        } else {
            cout << "Invalid input" << endl;
        }
    }
    else if (UserMovement.find(COMMAND_TURN_LEFT_SHORTCUT) == 0) { //if player has turned left 
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
    } else if (UserMovement.find(COMMAND_TURN_RIGHT_SHORTCUT) == 0) { //if player has turned right 
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
    } else if (UserMovement.find(COMMAND_QUIT) == 0) { //if user inputs "quit"
        return;
    } else {
        cout << "error! invalid input. try again." << endl;
        play();
    }
}

