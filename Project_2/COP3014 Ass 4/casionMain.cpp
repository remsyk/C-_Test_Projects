#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <stdio.h> 

char selection = 'c';
// Provided for you
void displayMenu();

//////////////////////////////////////////////
// Functionality you need to provide				//
//////////////////////////////////////////////
// basic casino functionality
void seedRand(int seed){
	srand(time(NULL));
}
void printMoney(double money){
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	std::cout << "$"<<money;
}
void printWallet(double wallet){
	std::cout << "Wallet: ";
	printMoney(wallet);

}
void payMoney(double & wallet, double amount){
	wallet = wallet - amount;
	std::cout << "You paid ";
	printMoney(amount);
}
void winMoney(double & wallet, double amount){
	wallet = wallet + amount;
	std::cout << "You just won ";
	printMoney(amount);
}
int getRandomNumber (int max){
	int num= rand() % max;
	return num;
}
// games
void playFlipTheCoin(double & wallet){
	char choice;
	char choiceh='h';
	char choiceH='H';
	choiceH = choiceh;
	char choicet = 't';
	char choiceT = 'T';
	choiceT = choicet;
	int flip;
	bool reset = false;
	std::cout << "\n"<<"Welcome to the flip-a-coin game!"<<"\n";
	payMoney(wallet, .5);
	std::cout << "\n";
	flip = getRandomNumber(2);
	
	while (reset ==false){
		//std::cout <<"H0/T1:"<< flip<<"\n";
		std::cout << "Guess (H)eads or (T)ails: ";
		std::cin >> choice;
		

		if (choice==choiceh && flip == 0){
			std::cout << "The coin landed on heads" << "\n";
			std::cout << "You guessed heads...right!" << "\n";
			winMoney(wallet, 1);
			std::cout << "\n\n";
			printWallet(wallet);
			reset = true;
			selection = 'c';
		}
		else if (choice==choiceh && flip == 1){
			std::cout << "The coin landed on tails" << "\n";
			std::cout << "You guessed heads...wrong!! Haha!" << "\n";
			std::cout << "\n\n";
			printWallet(wallet);
			reset = true;
			selection = 'c';
		}
		else if (choice==choicet && flip == 1){
			std::cout << "The coin landed on tails" << "\n";
			std::cout << "You guessed tails...right!" << "\n";
			winMoney(wallet, 1);
			std::cout << "\n\n";
			printWallet(wallet);
			reset = true;
			selection = 'c';
		}
		else if (choice==choicet && flip == 0){
			std::cout << "The coin landed on heads" << "\n";
			std::cout << "You guessed tails...wrong!! Haha!" << "\n";
			std::cout << "\n";
			printWallet(wallet);
			reset = true;
			selection = 'c';
		}
		else{
			std::cout << "\n" << "Invalid Entry" << "\n";
			continue;
		}
	}
}
void playGuessTheNumber(double & wallet){
	int guess;
	int secretNum;
	int tries=0;
	bool reset = false; 
	std::cout <<"\n"<<"Welcome to guess the number!"<<"\n";
	payMoney(wallet, 1);
	std::cout << "\n";
	std::cout << "I have my secret number" << "\n";
	std::cout << "You get 10 guesses" << "\n";
	
	seedRand(time(NULL));
	secretNum = getRandomNumber(100);
	//std::cout << "secrectNum:" << secretNum << "\n";
	
	while (reset == false){

		for (int i = 1; i <= 10; i++){
			tries++;
			std::cout << "What do you guess" << "(" << tries << ")" << "?";
			std::cin >> guess;

			if (secretNum > guess && tries != 10){
				std::cout << "My number is higher" << "\n";
			}
			else if (secretNum < guess && tries != 10){
				std::cout << "My number is lower" << "\n";
			}
			else if (guess == secretNum){
				std::cout << "Congratulation!" << "\n";
				winMoney(wallet, 2);
				std::cout << "\n\n";
				break;
				//reset = true;
			}
			reset = true;
		}
	}
		if (tries == 10||reset ==true){
			std::cout << "\n";
			printWallet(wallet);
			selection = 'c';
		}
}

///////////////////////////////////////////END
//////////////////////////////////////////////

int main()
{
	// You need money to spend on the games
	double wallet = 20.00;

	//int reset = 0;
	// Here is where you should begin writing your code.
	// The first thing you need to do is call seedRand.
	// After that, create your loop. Inside of your loop,
	//  call my displayMenu function and act on the user's
	//  input.
	// Write some code here
	// Make sure to support uppercase and lowercase options
	
	
	do{
		if (selection=='c'){
			displayMenu();
			std::cout << "Selection (F,G,X): ";
			std::cin >> selection;
		
			switch (selection){	
			case'f':playFlipTheCoin(wallet);
				std::cout << "\n\n";
				break;
			case'F': playFlipTheCoin(wallet);
				std::cout << "\n\n";
				break;
			case'g': playGuessTheNumber(wallet);
				std::cout << "\n\n";
				//return selection;
				break;
			case'G': playGuessTheNumber(wallet);
				//return selection;
				std::cout << "\n\n";
				break;
			case'x': goto exit_loop;;
			case'X': goto exit_loop;;
			default:std::cout << "\n" << "Invalid selection" << "\n";
				selection = 'c';
				break;
			}
		}
	
	} while (true);

exit_loop:;
	

	// Here's courtesy code to stop the window from closing.
	std::cout << "Press ENTER to continue";
	std::cin.ignore();
	std::cin.get();
}

void displayMenu()
{
	const int nameWidth = 20;
	const int priceWidth = 8;

	std::cout << "Welcome to Bob's Casino" << "\n";
	std::cout << "What game do you want to play?" << "\n";
	std::cout << std::setw(nameWidth) << std::left << "Name";
	std::cout << std::setw(priceWidth) << std::left << "Price";
	std::cout << "Odds" << "\n";

	// Print flip the coin details
	std::cout << std::setw(nameWidth) << std::left << "(F)lip-the-Coin";
	std::cout << std::setw(priceWidth) << std::left << "$0.50";
	std::cout << "2/1" << "\n";

	// Print guess the number details
	std::cout << std::setw(nameWidth) << std::left << "(G)uess-the-Number";
	std::cout << std::setw(priceWidth) << std::left << "$1.00";
	std::cout << "2/1" << "\n";

	// Print exit details
	std::cout << "E(x)it" << "\n";
}