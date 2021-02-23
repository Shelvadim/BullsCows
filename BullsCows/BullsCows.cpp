// BullsCows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();

bool AskToPlayAgain();

string GetGuess();

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
    constexpr int WORD_LENGTH = 5;
    cout << "Wellcome to Bulls and Cows, a fun word game.\n";
    cout << "Can you guess the " << WORD_LENGTH;
    cout << " letter isogram I am thinking off?\n";
    cout << endl;
    return;
}

void PlayGame()
{
    constexpr int NUMBER_OF_TURN = 5;
    for (int i = 0; i < NUMBER_OF_TURN; i++) {
        string Guess = GetGuess();
        cout << "You guess is: " << Guess << "\n";
        cout << endl;
    }

}


string GetGuess()
{
    // get a guesse from the player
    string Guess = "";
    cout << "What is your guess: ";
    getline(cin, Guess);    
    return Guess;
}

bool AskToPlayAgain() 
{
    cout << "Do you want to play again y/n: ";
    string Responce = "";
    getline(cin, Responce);
   
    cout << endl;
    return (Responce[0] == 'y') || (Responce[0] == 'Y');
}