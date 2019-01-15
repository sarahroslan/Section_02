/*This is the console executable that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic, see the FBullCowGame class.*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using Ftext = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
Ftext GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; //Instantiate a new game (make an instance of a new game)

// Entry point of our application
int main()
{	
	
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);
	return 0;
}

// Introduce the game
void PrintIntro() 
{
	std::cout << "\n\nWelcome to Bulls and Cows,a fun word game!\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n\n";
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//loop asking for guesses while the game is NOT won 
	//and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {

		{
			Ftext Guess = GetValidGuess();

			// Submit valid guess to the game and receive counts
			FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
			// Return number of bulls and cows
			std::cout << "Bulls = " << BullCowCount.Bulls;
			std::cout << ". Cows = " << BullCowCount.Cows;
			std::cout << std::endl;
		}

		// loop for the number of turns asking for guesses
		// TODO change from FOR to WHILE loop once we are validating tries

		std::cout << "You have " << MaxTries - BCGame.GetCurrentTry() + 1 ;
		std::cout << " out of " << MaxTries;
		std::cout << " tries";
		std::cout << std::endl;
	
	}
	PrintGameSummary();
	return;
}

// loop continuously until get a valid guess
Ftext GetValidGuess() 
{	
	Ftext Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << std::endl;
		std::cout << "Try " << CurrentTry << ". Please enter your guess.\n";
		
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;

		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter guess in lowercase.\n";
			break;
		default:
			//assume the guess is valid
			break;
		
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); //keep looping until we get no errors
		
	return Guess;

}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	Ftext Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
	std::cout << std::endl;

}
//TODO if game won or lost, don't print how many tries have left
void PrintGameSummary()
{
	
	if (BCGame.IsGameWon())
	{
		std::cout << "You Won!\n";
	}
	else  
	{
		std::cout << "Better luck next time!\n";
	}
	
}
