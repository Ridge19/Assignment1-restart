#include "game.h"
#include "helper.h"
#include "board.h"
#include "player.h"

#include <iostream>
#include <sstream>
#include <string>
#include <istream>
#include <vector>


using std::string;
using std::istringstream;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

void mainMenu();

void showStudentInformation(string name, string id, string email);

void gameMenu(); 

void Initalise();

void Quit();

int main()
{
    /**
     * TODO: here's the main function. You can write the "main menu" loop/code
     * here or you can make separate functions - up to you.
     */
        mainMenu();

    while (true) {
        // Game* game = new Game();
        std::string userInput;
        std::string gameInput;

        userInput = Helper::readInput();

        if (userInput == "1") {
            // game->start(); //starts game (game.cpp)
            gameMenu();
        } else if (userInput == "2") {
            showStudentInformation("Ridge Tagala", "s3934367", "s3934367@student.rmit.edu.au");
        } else if (userInput == "3") {
            Quit();
            return EXIT_SUCCESS;
        } else {
            cout << "error! invalid input" << endl;
            mainMenu();
        }
    }
}

void mainMenu() { //userInput  (REQ 1)
    cout << "\nWelcome to the Vaccum Cleaning Game!" << endl;
    cout << "------------------------" << endl;
    cout << "1. Play Game" << endl;
    cout << "2. Show Student Information" << endl;
    cout << "3. Quit" << endl;

    cout << "Please enter your choice: ";
    cout << endl;
}

void showStudentInformation(string name, string id, string email){
    // TODO
    cout << "------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Student ID: " << id << endl;
    cout << "Email: " << email << endl;
    cout << "------------------------\n" << endl;

    mainMenu();
}

bool initialised = false; 
void gameMenu() { //gameInput (REQ 1)
    cout << "You can use the following commands to play the game: \n" << endl;
    cout << "load <g>" << endl;
    cout << "\t" << "g: number of the game board to load" << endl;
    cout << "<x>,<y>,<direction>" << endl;
    cout << "\tx: horizontal position of the vacuum cleaner in the room (between 0 and 9)" << endl;
    cout << "\ty: veritcal position of the vacuum cleaner in the room (between 0 and 9)" << endl;
    cout << "\tdirection: direction of the vacuum cleaner's movement (north, east, south, west)" << endl;
    cout << "forward (or f)" << endl;
    cout << "turn_left (or l)" << endl;
    cout << "turn_right (or r)" << endl;
    cout << "quit" << endl; 

        std::string gameInput;
        Board* board = new Board();
        Player* player = new Player();
        Game* game = new Game();
        cout << endl;
        gameInput = Helper::readInput();

        if (gameInput.find(COMMAND_QUIT) == 0) { //if user inputs "quit", program terminates to main menu
            cout << "Quit" << endl;
            mainMenu();
            return;
        } else if (gameInput.find(COMMAND_LOAD) == 0) { //if user inputs load
            std::istringstream iss(gameInput.substr(strlen(COMMAND_LOAD) + 1));
            int boardNum;
            
            if (iss >> boardNum) {
                if (boardNum == 1) { //if user chooses board1
                
                    std::string gameInput;
                    cout << "loading board 1" << endl;
                    board->load(1); //loads board1
                    Initalise(); //shows menu
                    
                    int x;
                    int y;

                    std::getline(cin, gameInput);

                    std::stringstream ss(gameInput);
                    std::string token;

                    if (gameInput.find(COMMAND_QUIT) == 0) { //if user inputs "quit", program terminates to main menu
                        cout << "Quit" << endl;
                        mainMenu();
                        return;
                    }
                    

                    //x coordinate
                    if (std::getline(ss, token, ',')) {
            
                        x = std::stoi(token);
                        if (std::getline(ss, token, ',')) { //y coordinate
                            y = std::stoi(token);
                            cout << "Placing player in coordinates with direction" << endl;
                            player->displayDirection(); //gets direction
                            board->placePlayer(Position(x, y)); //places player in x/y coordinate inputted by user
                                                            
                            //----------- player movement commands (see game.cpp)
                            std::string UserMovement;
                            while (true) {

                                game->start();
                            }

                            if (player->direction == Direction::NORTH) { //player direction (NOT WORKING - COULDNT FIGURE OUT.)
                                    player->displayDirection();
                                    cout << (DIRECTION_ARROW_OUTPUT_NORTH) << endl;
                                    cout << "Player placed with direction: " << Direction::NORTH << endl;
                                } else if (player->direction == Direction::SOUTH) {
                                    player->displayDirection();
                                    cout << (DIRECTION_ARROW_OUTPUT_SOUTH) << endl;
                                    cout << "Player placed with direction: " << Direction::SOUTH << endl;
                                } else if (player->direction == Direction::EAST) {
                                    player->displayDirection();
                                    cout << (DIRECTION_ARROW_OUTPUT_EAST) << endl;
                                    cout << "Player placed with direction: " << Direction::EAST << endl;
                                } else if (player->direction == Direction::WEST) {
                                    player->displayDirection();
                                    cout << (DIRECTION_ARROW_OUTPUT_WEST) << endl;
                                    cout << "Player placed with direction: " << Direction::WEST << endl;
                                }
                            } else {
                                cout << "error: invalid y coordinate" << endl;
                            }
                    } else {
                        cout << "error: invalid x coordinate" << endl;
                        return;
                    }
                } else if (boardNum == 2) { //if user selected board2
                    std::string gameInput;
                    cout << "loading board 2" << endl;
                    board->load(2); //loads board2 
                    Initalise(); //shows menu
                    
                    int x;
                    int y;

                    std::getline(cin, gameInput);

                    std::stringstream ss(gameInput);
                    std::string token;
                    

                    //x coordinate
                    if (std::getline(ss, token, ',')) {
            
                        x = std::stoi(token);
                        if (std::getline(ss, token, ',')) { //y coordinate
                            y = std::stoi(token);
                            cout << "Placing player in coordinates with direction" << endl;
                            player->displayDirection();
                            board->placePlayer(Position(x, y));
                                                            
                            //----------- player movement commands 
                            std::string UserMovement;
                            while (true) {
                                game->start();
                            }
                            if (player->direction == Direction::NORTH) {
                                    player->displayDirection();
                                    cout << (DIRECTION_ARROW_OUTPUT_NORTH) << endl;
                                    cout << "Player placed with direction: " << Direction::NORTH << endl;
                                } else if (player->direction == Direction::SOUTH) {
                                    player->displayDirection();
                                    cout << (DIRECTION_ARROW_OUTPUT_SOUTH) << endl;
                                    cout << "Player placed with direction: " << Direction::SOUTH << endl;
                                } else if (player->direction == Direction::EAST) {
                                    player->displayDirection();
                                    cout << (DIRECTION_ARROW_OUTPUT_EAST) << endl;
                                    cout << "Player placed with direction: " << Direction::EAST << endl;
                                } else if (player->direction == Direction::WEST) {
                                    player->displayDirection();
                                    cout << (DIRECTION_ARROW_OUTPUT_WEST) << endl;
                                    cout << "Player placed with direction: " << Direction::WEST << endl;
                                }
                            } else {
                                cout << "error: invalid y coordinate" << endl;
                            }
                    } else {
                        cout << "error: invalid x coordinate" << endl;
                        return;
                    }
            } else {
                cout << "error! invalid board number - doesnt exist" << endl;

            }
        } else {
            cout << "Invalid command input! try again." << endl;
            gameMenu();
        }
    }
    if (!initialised) {
        cout << "error! invalid input. try again." << endl;
        gameMenu();
    }      
}

void Initalise() { 
    //REQ 3 Menu
    cout << "At this stage of the program, only three commands are acceptable: " << endl;
    cout << "load <g>" << endl;
    cout << "init <x>, <y>, <direction>" << endl;
    cout << "quit" << endl;
}

void Quit() {
    cout << "Good bye!\n\n";
}