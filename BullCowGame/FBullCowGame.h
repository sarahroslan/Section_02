#pragma once
#include <string>

using Fstring = std::string;
using int32 = int;


//all value initialised to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
	
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
	
};

class FBullCowGame {
public:
	FBullCowGame(); //constructor
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(Fstring) const;
	bool IsIsogram() const;

	void Reset(); // 
	
	FBullCowCount SubmitValidGuess(Fstring);
	
//No need to think about this yet	
private:

	//see contructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	Fstring MyHiddenWord; 
	bool bIsGameWon;

	bool IsIsogram(Fstring) const;
	
};