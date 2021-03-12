// BullsCows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once

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
void PrintGameSummary();

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
    std::cout << "\n\nWellcome to Bulls and Cows, a fun word game.\n";
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLenght();
    std::cout << " letter isogram I am thinking off?\n";
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();
    
    int32 MaxTries = BCGame.GetMaxTries();
       
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTries()< MaxTries)
    {

        FText Guess = GetValidGuess();        

        FBullCowCount BullCowCount= BCGame.SubmitValidGuess(Guess);

        std::cout << "Bulls= " << BullCowCount.Bulls;
        std::cout << ". Cows= " << BullCowCount.Cows << "\n\n";
        
    }
    PrintGameSummary();

    return;
}


std::string GetValidGuess()
{
    FText Guess = "";
    EWordStatus Status = EWordStatus::Invalid;
    do 
    {
        // get a guesse from the player
        int32 CurrentTry = BCGame.GetCurrentTries();
        
        std::cout << "Try:" << CurrentTry << " off " << BCGame.GetMaxTries();
        std::cout << ". What is your guess: ";
        std::getline(std::cin, Guess);

        Status = BCGame.CheckGuessValidity(Guess);

        switch (Status)
        {
        case EWordStatus::Wrong_Length:
            std::cout << "Please enter a " << BCGame.GetHiddenWordLenght() << " letter word.\n\n";
            break;
        case EWordStatus::Not_Lowercase:
            std::cout << "Please enter lower case word.\n\n";
            break;
        case EWordStatus::Not_Isogram:
            std::cout << "Please enter a word without repiting letters.\n\n";
            break;
        default:
            break;
        }
        //std::cout << std::endl;
    } while (Status != EWordStatus::Ok); 
    return Guess;   
}

bool AskToPlayAgain() 
{
    std::cout << "Do you want to play again with the same hidden word y/n: ";
    FText Responce = "";
    std::getline(std::cin, Responce);
   
    std::cout << std::endl;
    return (Responce[0] == 'y') || (Responce[0] == 'Y');
}

void PrintGameSummary() 
{
    if (BCGame.IsGameWon())
    {
        std::cout << "WELL DONE YOU WON!!\n";
    }
    else 
    {
        std::cout << "Better luck next time.\n";
    }
}
