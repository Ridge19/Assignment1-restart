#include <iostream>
#include "player.h"

Position::Position()
{
    //TODO
    x = 0; 
    y = 0;
}


Position::Position(int x, int y)
{
    //TODO
    this->x = x;
    this->y = y;
}

Player::Player()
{
    //TODO
    this->position = position;
    this->direction = direction;
}

void Player::initialisePlayer(Position* position, Direction direction)
{
    //TODO
    // Position position;
    // Direction direction; 

}

void Player::turnDirection(TurnDirection turnDirection)
{
    //TODO
    if (turnDirection == 0) { //turning left 
        if (direction == NORTH) {
            direction = Direction::WEST;
        } else if (direction == Direction::WEST) {
            direction = Direction::SOUTH; 
        } else if (direction == Direction::SOUTH) {
            direction = Direction::EAST;
        } else if (direction == Direction::EAST) {
            direction = Direction::NORTH;
        }
    } else if (turnDirection == 1) { //turning right 
        if (direction == NORTH) {
            direction = Direction::EAST;
        } else if (direction == Direction::EAST) {
            direction = Direction::SOUTH; 
        } else if (direction == Direction::SOUTH) {
            direction = Direction::WEST;
        } else if (direction == Direction::WEST) {
            direction = Direction::NORTH;
        }
    }
}

Position Player::getNextForwardPosition()
{
    //TODO
    Position newPosition = this->position;
    if (direction == Direction::NORTH) {
        newPosition.y++;
    } else if (direction == Direction::SOUTH) {
        newPosition.y--;
    } else if (direction == Direction::EAST) {
        newPosition.x++;
    } else if (direction == Direction::WEST) {
        newPosition.x--;
    }
    return this->position;
}

void Player::updatePosition(Position position)
{
    //TODO
}

void Player::displayDirection()
{
    //TODO
    if (direction == Direction::NORTH) {
        std::cout << DIRECTION_ARROW_OUTPUT_NORTH;
    } else if (direction == Direction::SOUTH) {
        std::cout << DIRECTION_ARROW_OUTPUT_SOUTH;
    } else if (direction == Direction::EAST) {
        std::cout << DIRECTION_ARROW_OUTPUT_EAST;
    } else if (direction == Direction::WEST) {
        std::cout << DIRECTION_ARROW_OUTPUT_WEST;
    }
}
