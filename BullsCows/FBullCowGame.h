#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus 
{
	Invalid,
	Ok,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};



class FBullCowGame {
public:

	FBullCowGame(); //constractor
	
	int32 GetMaxTries() const;
	int32 GetCurrentTries() const;
	int32 GetHiddenWordLenght() const;

	EWordStatus CheckGuessValidity(FString) const;
	bool IsGameWon() const;

	void Reset();
	

	FBullCowCount SubmitValidGuess(FString);

private:
	int32 MyCurrentTry;
	//int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};