#include "board.h"

#include <iostream>

using std::cout;
using std::endl;

using std::vector;

#define ROWS 10
#define COLS 10

const vector<vector<Cell>> Board::BOARD_1 =
{
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

const vector<vector<Cell>> Board::BOARD_2 =
{
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

Board::Board()
{
    // TODO
    Board::BOARD_1[ROWS][COLS];
    Board::BOARD_2[ROWS][COLS];

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
}

Board::~Board()
{
    // TODO
    // delete board;
}

void Board::load(int boardId)
{
    // TODO
    if (boardId == 1) {
        std::cout << LINE_OUTPUT << EMPTY_OUTPUT << LINE_OUTPUT;
            for (int col = 0; col < COLS; col++) {
                std::cout << col << LINE_OUTPUT;
            }
            std::cout << std::endl;

        for (int y = 0; y < ROWS; y++) {
            std::cout << LINE_OUTPUT << y << LINE_OUTPUT;
            for (int x = 0; x < COLS; x++) {
                if (Board::BOARD_1[y][x] == 1) {
                    std::cout << BLOCKED_OUTPUT << LINE_OUTPUT;
                }
                if (Board::BOARD_1[y][x] == 0) {
                    std::cout << EMPTY_OUTPUT << LINE_OUTPUT;
                }
            }
            std::cout << std::endl;
        }
    } else if (boardId == 2) {
        std::cout << LINE_OUTPUT << EMPTY_OUTPUT << LINE_OUTPUT;
            for (int col = 0; col < COLS; col++) {
                std::cout << col << LINE_OUTPUT;
            }
            std::cout << std::endl;

        for (int y = 0; y < ROWS; y++) {
            std::cout << LINE_OUTPUT << y << LINE_OUTPUT;
            for (int x = 0; x < COLS; x++) {
                if (Board::BOARD_2[y][x] == 1) {
                    std::cout << BLOCKED_OUTPUT << LINE_OUTPUT;
                }
                if (Board::BOARD_2[y][x] == 0) {
                    std::cout << EMPTY_OUTPUT << LINE_OUTPUT;
                }
            }
            std::cout << std::endl;
        }
    }
    else {
        Helper::printInvalidInput();
    }
}

bool Board::placePlayer(Position position)
{
    // TODO
    if (position.x >= 0 && position.x < COLS && position.y >= 0 && position.y < ROWS) {
        if (Board::BOARD_1[position.y][position.x] == BLOCKED) {
            cout << "cell blocked! cannot place player" << endl;
            cout << endl;
            return false;
        } else {
            Player* player = new Player();
            player->position.x = position.x;
            player->position.y = position.y;
            cout << "Player placed in coordinates " << position.x << ", " << position.y << endl;
            Board::display(player);
            return true;
        }

    } else {
        cout << "Error - invalid coordinates for board 1" << endl;
        return false;
    }

    if (position.x >= 0 && position.x < COLS && position.y >= 0 && position.y < ROWS) {
        if (Board::BOARD_2[position.y][position.x] == BLOCKED) {
            cout << "cell blocked! cannot place player" << endl;
            return false;
        } else {
            Player* player = new Player();
            player->position.x = position.x;
            player->position.y = position.y;
            std::string directionStr;

            if (player->direction == Direction::NORTH) {
            directionStr = "North";
            } else if (player->direction == Direction::SOUTH) {
            directionStr = "South";
            } else if (player->direction == Direction::EAST) {
            directionStr = "East";
            } else if (player->direction == Direction::WEST) {
            directionStr = "West";
            } else {
            // Handle unexpected direction value (optional)
            }

            cout << "Player placed in coordinates " << position.x << ", " << position.y << ", " << directionStr << endl;
            // cout << "Player placed in coordinates " << position.x << ", " << position.y << endl;
            Board::display(player);
            return true;
        }
    } else {
        cout << "Error - invalid coordinates for board 2" << endl;
        return false;
    }
    return false; // feel free to revise this line, depending on your implementation.
}

PlayerMove Board::movePlayerForward(Player* player)
{
    // TODO
    // Check for out-of-bounds before moving
    if (player->position.y == 0) {
        std::cout << "Player is already at the top edge of the board!" << std::endl;
        return OUTSIDE_BOUNDS;
    }
    if (player->position.y == 0) {
        cout << "player is already at that coordinate!" << endl;
        return OUTSIDE_BOUNDS;
    } 
    if ((player->position.y) + player->position.x) {
        player->position.y--; // Move player forward (decrement y-coordinate)
        return PLAYER_MOVED;
    } else {
        std::cout << "Cell in front of player is blocked." << std::endl;
        return CELL_BLOCKED;
    }
    return CELL_BLOCKED;
}

void Board::display(Player* player)
{
    // TODO
    int boardNum = 1;

    if (player == nullptr) {
        return;
    }

    if (boardNum == 1) {
        //board 1
        std::cout << "|" << " " << "|";
        for (int col = 0; col < COLS; col++) {
            std::cout << "" << col << "|";
        }
        std::cout << std::endl;

        for (int y = 0; y < ROWS; y++) {
            std::cout << LINE_OUTPUT << y << LINE_OUTPUT;
            for (int x = 0; x < COLS; x++) {
                if (player->position.x == x && player->position.y == y) {
                    cout << "@|";
                }
                if (Board::BOARD_1[y][x] == 1) {
                    std::cout << BLOCKED_OUTPUT << LINE_OUTPUT;
                }
                if (Board::BOARD_1[y][x] == 0) {
                    std::cout << EMPTY_OUTPUT << LINE_OUTPUT;
                }
            }
            std::cout << std::endl;
        }
    } else if (boardNum == 2) {
        //board 2
        std::cout << LINE_OUTPUT << EMPTY_OUTPUT << LINE_OUTPUT;
        for (int col = 0; col < COLS; col++) {
            std::cout << "" << col << LINE_OUTPUT;
        }
        std::cout << std::endl;

        for (int y = 0; y < ROWS; y++) {
            std::cout << LINE_OUTPUT << y << LINE_OUTPUT;
            for (int x = 0; x < COLS; x++) {
                if (player->position.x == x && player->position.y == y) {
                    std::cout << "@|";
                }
                if (Board::BOARD_2[y][x] == 1) {
                    std::cout << EMPTY_OUTPUT << BLOCKED_OUTPUT;
                }
                if (Board::BOARD_2[y][x] == 0) {
                    std::cout << EMPTY_OUTPUT << BLOCKED_OUTPUT;
                }
            }
            std::cout << std::endl;
        }   
    } else {
        cout << "invalid board! does not exist" << endl;
    }
}


// else if (player->position.x > COLS && player->position.y > ROWS) {
//         cout << "Error! outside of board bounds!" << endl;
//         return OUTSIDE_BOUNDS;
