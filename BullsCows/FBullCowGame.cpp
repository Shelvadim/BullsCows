#include "FBullCowGame.h"


FBullCowGame::FBullCowGame()
{
	Reset();
}


void FBullCowGame::Reset()
{
	constexpr int MAX_TRY = 8;	
	MyMaxTries = MAX_TRY;

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

bool FBullCowGame::CheckGameValidity(std::string)
{
	return false;
}
