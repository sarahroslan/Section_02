#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() {Reset();}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() const { return bIsGameWon; }

void FBullCowGame::Reset()
{	
	constexpr int32 MAX_TRIES = 8;
	const Fstring HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bIsGameWon = false;
	return;
}



EGuessStatus FBullCowGame::CheckGuessValidity(Fstring Guess) const
{
	if (!IsIsogram(Guess)) // If guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (Guess.length() != GetHiddenWordLength()) // If guess length is wrong
	{
		return EGuessStatus::Wrong_Length; 
	}
	else if (false) // If guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase; 
	}
	else// otherwise
	{
		return EGuessStatus::OK; 
	}

}
// receives a VALID guess, increments tries and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(Fstring Guess)
{

	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); //assuming same length as guess
	// loop through all the letters in the hidden word
	
	for (int32 i = 0; i < WordLength; i++) {
		// compare letters against the guess
		for (int32 j = 0; j < WordLength; j++) {
			// if they match then
			if (Guess[i] == MyHiddenWord[j]) {
				// increment Bulls if they're in the same place
				if (i == j) {
					BullCowCount.Bulls++;
				}
				// increment Cows if not
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) 
	{
		bIsGameWon = true;
	}
	else 
	{
		bIsGameWon = false;
	}
	return BullCowCount;

	
}

bool FBullCowGame::IsIsogram(Fstring) const
{	
	//in a loop
		//run through word letter by letter
			//if letter is seen
				//is not isogram
			//else
				//add the letter to the map as seen

	return true;
}


