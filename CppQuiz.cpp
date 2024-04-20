#include "getRandomQuestion.h"
#include "json/json.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

#include <string>
// using namespace std;

//std::string getRandomQuestion(int x);

int main()
{
    srand((unsigned)time(0));
    std::cout << "Press any key to begin...\n";

    _getch(); //wait for user input to continue
    system("cls"); // clear screen

    std::cout << "Select Category, \n 1) APlus \n 2) NetPlus \n 3) ... \n"; // REPLACE ... WITH OTHER CATEGORIES LATER!!!!!
    int x{};
    std::cin >> x; // get category selection and put into x variable

    system("cls"); // clear screen
    getRandomQuestion(x);
}