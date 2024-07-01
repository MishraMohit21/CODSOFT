#include <iostream>
#include <random>


int main()
{

    std::random_device rd;
    std::mt19937 generator(rd());

    int choice, limit, guess;
    std::cout << "Welcome to the Number Guess Game\n";
    std::cout << "Please select the difficulty:\n";

    std::cout << "1) Easy(Num <= 10)\n2) Moderate(Num <= 100)\n3) Hard(Num <= 500)\nChoice: ";

    while (true)
    {
        std::cin >> choice;
        if (choice > 0 && choice < 4){
            break;
        }
        else {
            std::cout << "The entered choice is not correct. Please reenter the choice\n";
        }
    }

    switch (choice)
    {
        case 1:
            limit = 10;
            break;
        case 2:
            limit = 100;
            break;
        case 3:
            limit = 500;
            break;
        default:
            break;
    }

    std::uniform_int_distribution<int> distribution(1, limit);

    int randNum = distribution(generator);
    // std::cout << randNum << std::endl;
    std::cout << "Now,\nGuess a number: ";
    while (true)
    {
        std::cin >> guess;
        if (guess == randNum)
        {
            std::cout << "Yes, The Number you guessed is correct\n";
            break;
        }
        else if (guess < randNum)
        {
            std::cout << "No, The Number you guessed is too low\nGuess Again: ";
        }
        else if (guess > randNum)
        {
            std::cout << "No, The Number you guessed is too high\nGuess Again: ";
        }
    }

    return 0;

}