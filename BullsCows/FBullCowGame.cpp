#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRY = 8;	
	MyMaxTries = MAX_TRY;

	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;

	return;
}



int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTries() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGameValidity(FString)
{
	return false;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();

	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			if (Guess[i] == MyHiddenWord[i])
			{
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows;
				}

			}
		}
	}

	return BullCowCount;
}
