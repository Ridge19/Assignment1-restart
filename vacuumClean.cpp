#include "game.h"
#include "helper.h"

#include <iostream>
#include <sstream>
#include <vector>


using std::string;
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

void Quit();

int main()
{
    /**
     * TODO: here's the main function. You can write the "main menu" loop/code
     * here or you can make separate functions - up to you.
     */

    while (true) {
        Game* game = new Game();
        std::string userInput;
        mainMenu();

        userInput = Helper::readInput();

        if (userInput == "1") {
            game->start(); //starts game (game.cpp)
            
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

void Quit() {
    cout << "Good bye!\n\n";
}