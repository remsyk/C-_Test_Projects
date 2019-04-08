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

int index = 0;

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
	char test = 'r';
	int selection = 0;
	bool reset = false;
	
	// Your code below
	// =========================
	do {
		if (selection == 0){
			std::cout << "[1] Test ReadString" << std::endl;
			std::cout << "[2] Test GetStringLength" << std::endl;
			std::cout << "[3] Test PrintString" << std::endl;
			std::cout << "[4] Test PrintStringBackwards" << std::endl;
			std::cout << "[5] Test FindIndexofCharacter" << std::endl;
			std::cout << "[6] Test GetValueAtIndex" << std::endl;
			std::cout << "[7] Test GetIntegerValueOfIndex" << std::endl;
			std::cout << "[8] Test PrintHexValueAtIndex" << std::endl;
			std::cout << "[9] Test MakeUpperCase" << std::endl;
			std::cout << "[10] Test MakeLowerCase" << std::endl;
			std::cout << "Selction: ";
			std::cin >> selection;
			std::cin.ignore();
		
			switch (selection) {
			case 1:
				ReadString(pc, SIZE);
				selection = 0;
				break;
			case 2:
				GetStringLength(pc, lengthChecks);
				selection = 0;
				break;
			case 3:
				PrintString(pc);
				selection = 0;
				break;
			case 4:
				PrintStringBackwards(pc);
				selection = 0;
				break;
			case 5:
				std::cout << "Input Test Value: ";
				std::cin >> test;
				FindIndexOfCharacter(pc, test);
				std::cout << test << " index " << index << std::endl;
				selection = 0;
				break;
			case 6:
				
				int index = 0;
				char oldChar = 'S';
				char newChar = 'R';
				char * cPtr;
				index = FindIndexOfCharacter(pc, oldChar);
				std::cout << oldChar << "-->" << newChar << "\n";
				cPtr = GetValueAtIndex(pc, index);
				*cPtr = newChar;				PrintString(pc);
				std::cout << std::endl;
				
				selection = 0;
				break;
			case 7:
				/*
				int x = strlen(pc);
				for (int i = 0; i < 10; ++i)
				{
					int i_ascii = GetIntegerValueOfIndex(pc, i);
					std::cout << pc[i] << "=" << i_ascii << std::endl;
				}				*/
				selection = 0;
				break;
			case 8:
				/*
				int x = strlen(pc);
				for (int i = 0; i < x; ++i)
				{
					std::cout << "HEX=";
					PrintHexValueAtIndex(pc, i);
					std::cout << std::endl;
				}				*/
				selection = 0;
				break;
			case 9:
				MakeUpperCase(pc);
				selection = 0;
				break;
			case 10:
				MakeLowerCase(pc);
				selection = 0;
				break;
			case 99: std::cout << "Quit";
				break;
				reset = true;
			default : selection =1;
			}
		}
	} while (reset == false);
	
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
	std::cin.getline(c, maxLength);
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
	std::cout << std::endl;

}

int FindIndexOfCharacter(char * c, char testVal){
	
	char * ptr = strchr(c, testVal);

	if (ptr){
		index = ptr - c+1;
		return index;
	}
	else{
		index = -1;
	}
	return index;
}

char * GetValueAtIndex(char * const c, int index){
	return &c[index];
}

void MakeUpperCase(char * c){
	int x = strlen(c);
	for (int i = 0; i < x; i++){
		c[i] = toupper(c[i]);
	}
	std::cout << c << std::endl;
}

void MakeLowerCase(char * c){
	int x = strlen(c);
	for (int i = 0; i < x; i++){
		c[i] = tolower(c[i]);
	}
	std::cout << c << std::endl;
}
// You need to provide the rest of the functions
// See Function Prototypes at the top.