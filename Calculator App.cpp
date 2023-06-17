/* You'll write a calculator app that prompts for the user for the result of an operation. It'll tell the user if they got it right or if the messed up big time!

Your program will randomly generate integers between 0 and 199 and carry out  random operations (addition, subtraction, multiplication) on on these two random integers. The program will then ask the user for the result of the operation on the random numbers.

The user will type their answer on the terminal and your program will tell them whether they got it right or not. This program will reuse the technique we saw in fortune teller to give the user a chance to run the program again without having to re-run it, until the user decides for the program to end. Below is a sample run of the program. Note : We have left out the integer division operation because it can be confusing in this exercise.

Please give this your best shot. If you are still stuck after REALLY trying, you can check our reference solution. Questions for this assignment

What does the source code for your solution look like ? */


#include <iostream>
#include <cstdlib>
#include <ctime>

int generateRandomNumber() {
    return std::rand() % 200; // Generate a random number between 0 and 199
}

int performOperation(int num1, int num2, char operation) {
    switch (operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        default:
            std::cout << "Invalid operation: " << operation << std::endl;
            return 0;
    }
}

bool checkAnswer(int result, int userAnswer) {
    return result == userAnswer;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Seed the random number generator

    char playAgain;
    do {
        int num1 = generateRandomNumber();
        int num2 = generateRandomNumber();

        char operation;
        int result;
        do {
            switch (std::rand() % 3) {
                case 0:
                    operation = '+';
                    result = performOperation(num1, num2, operation);
                    break;
                case 1:
                    operation = '-';
                    result = performOperation(num1, num2, operation);
                    break;
                case 2:
                    operation = '*';
                    result = performOperation(num1, num2, operation);
                    break;
            }
        } while (result < 0); // Ensure the result is not negative

        int userAnswer;
        std::cout << "What is the result of " << num1 << " " << operation << " " << num2 << "? ";
        std::cin >> userAnswer;

        if (checkAnswer(result, userAnswer)) {
            std::cout << "Correct! You got it right." << std::endl;
        } else {
            std::cout << "Oops! Wrong answer. The correct answer is " << result << "." << std::endl;
        }

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
