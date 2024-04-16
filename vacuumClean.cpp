#include "game.h"
#include "helper.h"

#include <iostream>
#include <sstream>
#include <istream>
#include <vector>


using std::string;
using std::istringstream;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

void showStudentInformation(string name, string id, string email){
    // TODO
    cout << "------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Student ID: " << id << endl;
    cout << "Email: " << email << endl;
    cout << "------------------------\n" << endl;
}

void mainMenu();

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
        Game* game = new Game();
        std::string userInput;
        std::string gameInput;

        userInput = Helper::readInput();

        if (userInput == "1") {
            game->start(); //starts game (game.cpp)
            gameMenu();
        } else if (userInput == "2") {
            showStudentInformation("Ridge Tagala", "s3934367", "s3934367@student.rmit.edu.au");
        } else if (userInput == "3") {
            Quit();
            return EXIT_SUCCESS;
        } else {
            cout << "error! invalid input" << endl;
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

    while (true) {
        std::string gameInput;
        Board* board = new Board();
        cout << endl;
        gameInput = Helper::readInput();

            if (gameInput.find(COMMAND_LOAD) == 0) {
            std::istringstream iss(gameInput.substr(strlen(COMMAND_LOAD) + 1));
            int boardNum;

            if (iss >> boardNum) {
                if (boardNum == 1) {
                    cout << "loading board 1" << endl;
                    board->load(1);
                    Initalise();
                } else if (boardNum == 2) {
                    cout << "loading board 2" << endl;
                    board->load(2);
                    Initalise();
                } else {
                    cout << "error! cannot load board" << endl;
                }
            } else {
                cout << "error! invalid board number - doesnt exist" << endl;
            }
        } else {
            cout << "Invalid command input! try again." << endl;
            gameMenu();
        }
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