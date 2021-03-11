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
FText GetValidGuess();
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
    //constexpr int32 WORD_LENGTH = 5;
    std::cout << "Wellcome to Bulls and Cows, a fun word game.\n";
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLenght();
    std::cout << " letter isogram I am thinking off?\n";
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();
    
    int32 MaxTries = BCGame.GetMaxTries();
       
    for (int32 i = 1; i <=MaxTries; i++) {

        FText Guess = GetValidGuess();        

        FBullCowCount BullCowCount= BCGame.SubmitGuess(Guess);

        std::cout << "Bulls= " << BullCowCount.Bulls;
        std::cout << ". Cows= " << BullCowCount.Cows << "\n\n";
        
    }

}


std::string GetValidGuess()
{
    EWordStatus Status = EWordStatus::Invalid;
    do 
    {
        // get a guesse from the player
        int32 CurrentTry = BCGame.GetCurrentTries();
        FText Guess = "";
        std::cout << "Try:" << CurrentTry << ". What is your guess: ";
        std::getline(std::cin, Guess);

        Status = BCGame.CheckGuessValidity(Guess);

        switch (Status)
        {
        case EWordStatus::Wrong_Length:
            std::cout << "Please enter a " << BCGame.GetHiddenWordLenght() << " letter word.\n";
            break;
        case EWordStatus::Not_Lowercase:
            std::cout << "Please enter lower case word.\n";
            break;
        case EWordStatus::Not_Isogram:
            std::cout << "Please enter a word without repiting letters.\n";
            break;
        default:
            return Guess;
        }
        std::cout << std::endl;
    } while (Status==EWordStatus::Ok);
   
}

bool AskToPlayAgain() 
{
    std::cout << "Do you want to play again y/n: ";
    FText Responce = "";
    std::getline(std::cin, Responce);
   
    std::cout << std::endl;
    return (Responce[0] == 'y') || (Responce[0] == 'Y');
}