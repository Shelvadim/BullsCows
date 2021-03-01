#pragma once
#include <string>


class FBullCowGame {
public:

	FBullCowGame(); //constractor
	
	int GetMaxTries() const;
	int GetCurrentTries() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGameValidity(std::string);



private:
	int MyCurrentTry;
	int MyMaxTries;
	

};