//#include "getRandomQuestion.h"
#include "json/json.h" 
#include "json/json-forwards.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <conio.h>


void custom_shuffle(std::vector<std::string>& v) 
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);
}

void getQuestion(const std::string& fileName)
{
    
    srand((unsigned)time(0));
    
    std::ifstream file(fileName);
    Json::Value root;
    Json::Reader reader;

    // use reader to parse json
    reader.parse(file, root);

    // get random question from file and put into "randomQuestion"
    int numQuestions = root.size();
    while (true) {
        // Generate a random index
        int randomIndex = rand() % root.size();

        // Retrieve the randomly selected question and its answers
        std::string randomQuestion = root[randomIndex]["question"].asString();
        std::vector<std::string> answers;
        std::string correctAnswer = root[randomIndex]["correct_answer"].asString();
        Json::Value jsonAnswers = root[randomIndex]["answers"];
        for (const auto& answer : jsonAnswers) {
            answers.push_back(answer.asString());
        }

        // Shuffle the answers randomly
        custom_shuffle(answers);

        // Print the random question
        std::cout << "Question: " << randomQuestion << std::endl;

        // Print the shuffled answers
        std::cout << "Possible Answers:" << std::endl;
        for (int i = 0; i < answers.size(); ++i) {
            std::cout << i + 1 << ". " << answers[i] << std::endl;
        }

        // Wait for user input to see the correct answer or quit
        std::cout << "Press any key for the correct answer, or 'q' to quit..." << std::endl;
        char userInput = _getch();
        if (userInput == 'q' || userInput == 'Q') {
            break;
        }

        // Print the correct answer
        std::cout << "Correct Answer: " << correctAnswer << std::endl;

        // Wait for user input to continue
        std::cout << "Press any key to continue..." << std::endl;
        _getch(); // Wait for a key press
        system("cls"); // Clear the console screen for the next question
    }
}

void getRandomQuestion(int x) // x equals inputed number when asked for what test to take
{
    std::string filenames[] = { "", "APlus.json", "NetPlus.json", "foo.json" }; // file names in an array
    if (x >= 1 && x <= 3) // if selected categories number is in array then run getQuestion
    {
        getQuestion(filenames[x]);
    }
    else
    {
        std::cout << "Invalid Input\n";
    }
}