#include <iostream>
#include <iomanip>

// if / else 3.6 page 73
// while 3.7 page 78
// sentinels 3.9 page 84
// iomanip 3.9 page 91
// increment / decrement 3.12 page 97
// for-loop 4.3 page 118
// do-while 4.5 page 126
// Switch 4.6 page 128
// break / continue 4.7 page 135
// Logical Operators 4.8 page 137

int main()
{
	int quoteNumber = 1;
	bool customerHappy = false; // are they happy with car?
	int carSelection = 0; // used to capture selected car
	double carCost = 0; // car cost alone
	double upgradeCost = 0; // upgrade cost alone
	double totalCost = 0; // car plus upgrades cost

	// You are going to DOOO something until the customer has
	// selected a car and is happy
	do
	{
		// if(true) will ALWAYS be activated
		// TODO: Make this loop run if we haven't selected a car <<DONE!>>
		// yet - get the customer to select one
		// if carSelection == 0, then they haven't picked a car yet (hint hint)
		if (carSelection==0)
		{
			std::cout << "Welcome to Bob's used car lot and chop shop!" << "\n";
			std::cout << "As you can see we have quite a few to choose from!" << "\n";
			std::cout << "Which one would you like?:" << "\n";
			std::cout << "[1] 2005 Vokswagen Beetle ($8,000)" << "\n";
			std::cout << "[2] 2008 Pontiac G6 ($8,581)" << "\n";
			std::cout << "[3] 2004 Chevy S-10 ($10,500)" << "\n";
			std::cout << "[4] 2016 Jeep Patriot ($15,209)" << "\n";
			std::cout << "[5] 2012 Jeep Wrangler Sport ($24,390)" << "\n";
			std::cout << "Which car would you like?: ";
			std::cin >> carSelection;
			std::cout << "\n";

						
			// TODO: If the user makes a bad selection, tell them <<DONE!>>
			// TODO: Else, set the carCost and move on to upgrades <<DONE!>>
			// ----------------------------------------------
			// Put your code in here! --> hint: use a switch
			
				switch (carSelection){
				case 1: std::cout << "2005 Vokswagen Beetle";
					carCost = 8000;
					break;
				case 2: std::cout << "2008 Pontiac G6";
					carCost = 8581;
					break;
				case 3: std::cout << "2004 Chevy S-10"; 
					carCost = 10500;
					break;
				case 4: std::cout << "2016 Jeep Patriot";
					carCost = 15209;
					break;
				case 5: std::cout << "2012 Jeep Wrangler Sport";
					carCost = 24390;
					break;
				default: std::cout << "Invalid Car Selection" << "\n";
					 carSelection=0;
				}
			// ----------------------------------------------
			// switch(carSelection)...
			// ----------------------------------------------

			// This newline will create a space between menus
			std::cout << "\n";
		}
		else // Otherwise try to sell them some upgrades!
		{
			int upgradeSelection = 0; // The users menu choice
			int engineLevel = 0; // the upgrade level of engine (0-5 only)
			  
			// while(true) will NEVER stop running
			// TODO: Make this while loop exit based on user input <<DONE!>>
			while (true)
			{
				/////////////////////////////////////////////////////
				// TODO: Calculate the engine upgrade costs here <<DONE!>>
				/////////////////////////////////////////////////////
				// Upgrades are $100 per level plus the cost of lower upgrades
			
					switch (upgradeSelection){
						// Example: Level 1 upgrade is $100
						// Example: Level 2 upgrade is $100 + $200 = $300
						// Example: Level 3 upgrade is $100 + $200 + $300 = $600
						// etc etc etc etc etc etc etc etc etc etc etc etc etc...
						// Hint: You might find a for-loop helpful for accumulating an amount
						//upgradeCost = 0;

						//////////////////////////////////////////////////////
						// Put your code below each of the comments marked
						// for each upgrade type
						//////////////////////////////////////////////////////
						// Calculate upgrade cost for engine
						// i.e. Put code here for engine...
					case -1:
						if (engineLevel <=5 && engineLevel >0){
							upgradeCost = upgradeCost - (engineLevel * 100);
							engineLevel--;
						}
						break;
					case +1:
						if (engineLevel <5 && engineLevel>=0){
							engineLevel++;
							upgradeCost = upgradeCost + (engineLevel * 100);
						}
						break;
					case 2: 
						engineLevel = 0;
						upgradeCost = 0;
						break;
					case 3:
						carSelection = 0;
						engineLevel = 0;
						upgradeCost = 0;
						goto exit_loop;
						break;
					case 4: 
						customerHappy = true;
						goto exit_loop;
						break;
					default:
						if (upgradeSelection > 4){
							std::cout << "Invalid Selection" << "\n";
						}
						break;
				}
					
				//////////////////////////////////////////////////////
				// TODO: Make the quote lines below print to look like money <<Done!>>
				// Example 3.45234 should be --> 3.45
				// Think about iomanip
				// ---------------------------------------
				// Put some code in here
				// ---------------------------------------
					std::cout << std::fixed;
					std::cout << std::setprecision(2);	
				// ---------------------------------------
				// ============================================================
				// Don't mess with these lines ================================
				// ============================================================
				std::cout << "{" << quoteNumber++ << "} "; // Don't touch me
				std::cout << " Car($" << carCost << ")"; // Don't touch me
				std::cout << " E(" << engineLevel << ")"; // Don't touch me
				// Don't touch the following line -- HOWEVER, you should put
				// something in the space ABOVE to make this line print like money
				std::cout << " Upgrades($" << upgradeCost << ")" << std::endl; // Don't touch me
				// ============================================================

				// Leave this menu the way it is
				std::cout << "Do you want to upgrade your car?\n";
				std::cout << "[-/+1] Downgrade / Upgrade Engine\n";
				std::cout << "[   2] Clear all upgrades\n";
				std::cout << "[   3] Reset car\n";
				std::cout << "[   4] Buy Car!!!\n";
				std::cout << "What would you like to do?: ";
				std::cin >> upgradeSelection; // can be positive or negative

				// TODO: Now operate on the user's selection <<DONE!>>
				// TODO: If the user makes a bad selection, tell them <<DONE!>>
				// -----------------------------------------------------------
				// Put your code in here! --> hint: what did you do last time?
				// -----------------------------------------------------------

					// Refer to line 131-135

				// -----------------------------------------------------------


				// This newline will create a space between menus
				std::cout << "\n";
			}
		}
	exit_loop:;
		// Once again, a while(true) loop will never exit
		// TODO: Make this loop exit when a car is selected and the customer is happy <<DONE!>>
		
	} while (customerHappy != true);

	/////////////////////////////////////////////////
	// Do not modify these lines
	/////////////////////////////////////////////////
	totalCost = carCost + upgradeCost; // Don't touch me
	std::cout << "Bill: Car($" << carCost << ")"; // Don't touch me
	std::cout << " Upgrades($" << upgradeCost << ")"; // Don't touch me
	std::cout << " Total ($" << totalCost << ")\n"; // Don't touch me
	/////////////////////////////////////////////////

	// these will stop the window from closing
	std::cout << "Press ENTER to continue";
	std::cin.ignore();
	std::cin.get();
}