#include <iostream>

// Function Prototypes=========================================================
// Do NOT change the signature of these function prototypes.
// If you do, your code will not compile with my altered main() function
// I suggest that you copy the prototypes below and then fill them in.
// ----------------------------------------------------------------------------
// Read in a line of text INCLUDING SPACES into a string.
// You may assume that the input will NOT exceed the maxLength available.
// Keep in mind that cin stops reading at a whitespace. See page 318.
void ReadString(char * c, int maxLength);

// Get the length of the string and store it in length
// Hint: How does C++ terminate a string? Look for that character!
void GetStringLength(char * c, int length);

// PrintString - Just print the string in forward order using cout
void PrintString(char * const c);

// PrintStringBackwards - Print the string in reverse order using cout
void PrintStringBackwards(char * const c);

// Search the string for the test character. Return -1 if not found
int FindIndexOfCharacter(char * c, char testVal);

// Return a pointer to the character at the index given
char * GetValueAtIndex(char * const c, int index);

// Return the ascii integer value of the character at requested index
int GetIntegerValueOfIndex(char * c, int index);

// Print the hexadecimal value of the character at the requested index
void PrintHexValueAtIndex(char * c, int index);

// Make the entire string uppercase
void MakeUpperCase(char * c);

// Make the entire string lowercase
void MakeLowerCase(char * c);

// ============================================================================

//[BEGIN MAIN] -- Don't delete this line
int main()
{
	// Use these variables to test.
	// SIZE could change so make sure your code works with different sizes.
	const int SIZE = 80;
	char ca[SIZE];
	char * pc = ca;
	int fPrints = 0;
	int bPrints = 0;
	int lengthChecks = 0;
	char test = 0;

	// Your code below
	// =========================
	/*
	int choice = 0;
	switch (choice) {
	case 1: std::cout << "[1] Test ReadString";
	case 2: std::cout << "[2] Test GetStringLength";
	case 3: std::cout << "[3] Test PrintString";
	case 4: std::cout << "[4] Test PrintStringBackwards";
	case 5: std::cout << "[5] Test FindIndexofCharacter";
	case 6: std::cout << "[6] Test GetValueAtIndex";
	case 7: std::cout << "[7] Test MakeUpperCase";
	case 8: std::cout << "[8] Test MakeLowerCase";
	case 9: std::cout << "[9] Test GetIntergerValueOfIndex";
	case 10: std::cout << "[10] Test PrintHexValueAtIndex";
	case 99: std::cout << "Quit";
	}
	*/
	
	ReadString(ca, SIZE);
	GetStringLength(pc, lengthChecks);
	PrintString(pc);
	PrintStringBackwards(pc);
	//FindIndexOfCharacter(pc, test);
	MakeUpperCase(pc);

	// =========================
	// Your code above

	std::cout << "Press ENTER";
	std::cin.get();
	return 0;
}
//[END MAIN] -- Don't delete this line

void ReadString(char * c, int maxLength)
{
	std::cout << "Enter a string less than " << maxLength << " characters." << std::endl;
	// Your code here
	// ==============================
	std::cin.getline (c,maxLength);
	// ==============================
}

void GetStringLength(char * c, int length)
{ 
	for (int i = 1; i > 1; i++){
		length += 1;
	}
	std::cout << "Length [" << length << "]:" << strlen(c) << std::endl;;
}

void PrintString(char * const c){
	std::cout << c << std::endl;
}

void PrintStringBackwards(char * const c){
	for (int i = strlen(c) - 1; i >= 0; i--){
		std::cout << c[i];
	}
	std::cout<<std::endl;
	
}

int FindIndexOfCharacter(char * c, char testVal){

	std::cout << "Input Test Value: ";
	std::cin >> testVal;
	char * index = NULL;
	index= strchr(c, testVal);
	int x = strlen(c); 
	
	for (int i = 0; i < x; i++){
		if (index != NULL){
			std::cout << testVal << " Index " << index << std::endl;
		}
		else{
			std::cout << testVal << " Index -1" << std::endl;
		}
	}
	return 0;
}

void MakeUpperCase(char * c){
	int x = strlen(c);
	for (int i = 0; i < x; i++){
		c[i] = toupper(c[i]);
		std::cout << c;

	}
	std::cout << std::endl;
}
// You need to provide the rest of the functions
// See Function Prototypes at the top.