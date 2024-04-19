#include "getRandomQuestion.h"
#include "json/json.h" 
#include "json/json-forwards.h"
#include <fstream>
#include <string>

std::string getRandomQuestion(int x) // x equals inputed number when asked for what test to take
{
	if (x == 1)
	{
        srand((unsigned)time(0));

        // use ifstream to get file pointer in "file"
        std::ifstream file("APlus.json");
        Json::Value root;
        Json::Reader reader;

        // use reader to parse json
        reader.parse(file, root);

        // get random question from file and put into "randomQuestion"
        int numQuestions = root.size();
        int randomIndex = rand() % numQuestions;
        std::string randomQuestion = root[randomIndex]["question"].asString();

        return randomQuestion;

	}
    else if (x == 2)
    {
        srand((unsigned)time(0));

        // use ifstream to get file pointer in "file"
        std::ifstream file("NetPlus.json");
        Json::Value root;
        Json::Reader reader;

        // use reader to parse json
        reader.parse(file, root);

        // get random question from file and put into "randomQuestion"
        int numQuestions = root.size();
        int randomIndex = rand() % numQuestions;
        std::string randomQuestion = root[randomIndex]["question"].asString();

        return randomQuestion;
    }
    else if (x == 3)
    {
        srand((unsigned)time(0));

        // use ifstream to get file pointer in "file"
        std::ifstream file("foo.json");
        Json::Value root;
        Json::Reader reader;

        // use reader to parse json
        reader.parse(file, root);

        // get random question from file and put into "randomQuestion"
        int numQuestions = root.size();
        int randomIndex = rand() % numQuestions;
        std::string randomQuestion = root[randomIndex]["question"].asString();

        return randomQuestion;
    }
}