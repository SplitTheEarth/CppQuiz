#include "getRandomQuestion.h"
#include "json/json.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

#include <string>
// using namespace std;

int main()
{
    srand((unsigned)time(0));
    std::cout << "Press any key to begin...\n";

    _getch(); //wait for user input to continue
    system("cls"); // clear screen

    std::cout << "Select Category, \n 1) APlus \n 2) NetPlus \n 3) ... \n"; // REPLACE ... WITH OTHER CATEGORIES LATER!!!!!
    int x{};
    std::cin >> x;

    if (x == 1) // runs if APlus is selected
    {
        system("cls"); //clear screen

        getRandomQuestion(x);

    }
    else if (x == 2) // runs if NetPlus is selected
    {
        system("cls"); //clear screen

        getRandomQuestion(x);

    }
    else if (x == 3) // runs if ... is selected
    {
        system("cls"); //clear screen

        getRandomQuestion(x);

    }
}