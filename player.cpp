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
}

void Player::turnDirection(TurnDirection turnDirection)
{
    //TODO
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
