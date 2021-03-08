// BullsCows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
FText GetGuess();
FBullCowGame BCGame;

int main()
{    
    bool bReplay = false;
    do {        
        PrintIntro();
        PlayGame();
        bReplay = AskToPlayAgain();
    } while (bReplay);        
          
    return 0;
}


void PrintIntro() 
{
    // intro
    constexpr int32 WORD_LENGTH = 5;
    std::cout << "Wellcome to Bulls and Cows, a fun word game.\n";
    std::cout << "Can you guess the " << WORD_LENGTH;
    std::cout << " letter isogram I am thinking off?\n";
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();
    
    int32 MaxTries = BCGame.GetMaxTries();
    std::cout << MaxTries << std::endl;
   
    for (int32 i = 0; i < MaxTries; i++) {
        FText Guess = GetGuess();

       FBullCowCount BullCowCount= BCGame.SubmitGuess(Guess);

        std::cout << "Bulls= " << BullCowCount.Bulls;
        std::cout << ". Cows= " << BullCowCount.Cows << std::endl;
        std::cout << std::endl;
    }

}


std::string GetGuess()
{
    // get a guesse from the player
    int32 CurrentTry = BCGame.GetCurrentTries();
    FText Guess = "";
    std::cout <<"Try:" << CurrentTry << ". What is your guess: ";
    std::getline(std::cin, Guess);
    return Guess;
}

bool AskToPlayAgain() 
{
    std::cout << "Do you want to play again y/n: ";
    FText Responce = "";
    std::getline(std::cin, Responce);
   
    std::cout << std::endl;
    return (Responce[0] == 'y') || (Responce[0] == 'Y');
}