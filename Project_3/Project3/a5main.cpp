// [A5main]
// [Scott Blair]
// [10/16/16]
// [1]
// [Description]

// THIS CODE COMPILES AS IS - I RECOMMEND SAVING YOUR PROGRESS REGULARLY.
// EVEN IF YOU DO NOT COMPLETE A FUNCTION BEFORE TURNING IT IN IT WILL
//  STILL COMPILE. IF YOU COMPLETE 99% OF THE FUNCTIONALITY AND THEN
//  CREATE AN ERROR THAT WON'T COMPILE YOU WILL GET A 0% GRADE.

#include <iostream>



// Function Prototypes

// ancillary functions
void SeedRand(int x);

// Array testing
void InitializeArray(int a[], int arraySize);
void PrintArray(int a[], int arraySize);
bool Contains(int a[], int arraySize, int testVal);
void BubbleSort(int a[], int arraySize);
int SumArray(int a[], int arraySize);
int Largest(int a[], int arraySize);
int Smallest(int a[], int arraySize);
double Average(int a[], int arraySize);
void ReverseArray(int a[], int arraySize);

// multi-dimensional arrays
void InitializeTemperatures(int ma[][2], int xSize);
void PrintArray(int ma[][2], int xSize);

//[BEGIN MAIN] // DO NOT REMOVE THIS LINE
int main()
{
	// This entire main() function will be deleted
	// during the assessment and replaced with
	// another main() function that tests your code.

	// Develop code here to test your functions
	// You may use std::cout in any tests you develop
	// DO NOT put std::cout statements in any of the
	// provided function skeletons unless specificaly asked for

	// Here is a quick array to get you started.
	// This size may change!
	// Make sure your functions work for any array size.
	const int ARRAY_SIZE = 10;
	int a[ARRAY_SIZE];

	const int xSize = 10;
	int ma[xSize][2];

	int x;
	std::cout << "Enter Seed Vaue: ";
	std::cin >> x;
	SeedRand(x);
	// Start here
	// Call your functions and test their output
	// Here is an example
	// Only call this ONCE


	InitializeArray(a, ARRAY_SIZE);
	std::cout << "Initial Array=";
	PrintArray(a, ARRAY_SIZE);
	std::cout << "\n";

	bool isInThere = false;
	isInThere = Contains(a, ARRAY_SIZE, 20);
	std::cout << "Contains(20)? = " << std::boolalpha << isInThere << "\n";
	isInThere = Contains(a, ARRAY_SIZE, 5);
	std::cout << "Contains(5)? = " << std::boolalpha << isInThere << "\n";
	isInThere = Contains(a, ARRAY_SIZE, 10);
	std::cout << "Contains(10)? = " << std::boolalpha << isInThere << "\n";
	isInThere = Contains(a, ARRAY_SIZE, 50);
	std::cout << "Contains(50)? = " << std::boolalpha << isInThere << "\n";
	isInThere = Contains(a, ARRAY_SIZE, 44);
	std::cout << "Contains(44)? = " << std::boolalpha << isInThere << "\n";
	isInThere = Contains(a, ARRAY_SIZE, 97);
	std::cout << "Contains(97)? = " << std::boolalpha << isInThere << "\n";
	isInThere = Contains(a, ARRAY_SIZE, 71);
	std::cout << "Contains(71)? = " << std::boolalpha << isInThere << "\n";
	isInThere = Contains(a, ARRAY_SIZE, 46);
	std::cout << "Contains(46)? = " << std::boolalpha << isInThere << "\n";
	isInThere = Contains(a, ARRAY_SIZE, 9);
	std::cout << "Contains(9)? = " << std::boolalpha << isInThere << "\n";
	isInThere = Contains(a, ARRAY_SIZE, 88);
	std::cout << "Contains(88)? = " << std::boolalpha << isInThere << "\n";

	std::cout << "Sorting..." << "\n";
	BubbleSort(a, ARRAY_SIZE);
	std::cout << "End Array=";
	PrintArray(a, ARRAY_SIZE);
	std::cout << "\n";

	std::cout << "Sum=" << SumArray(a, ARRAY_SIZE) << "\n";
	std::cout << "Largest=" << Largest(a, ARRAY_SIZE) << "\n";
	std::cout << "Smallest=" << Smallest(a, ARRAY_SIZE) << "\n";
	std::cout << "Average=" << Average(a, ARRAY_SIZE) << "\n";
	std::cout << "Reversed=";
	ReverseArray(a, ARRAY_SIZE);
	std::cout << "\n";

	std::cout << "Initializing temperatures...\n";
	InitializeTemperatures(ma, ARRAY_SIZE);
	std::cout << "Temperatures=";
	PrintArray(ma, ARRAY_SIZE); // see below
	std::cout << "\n";
	std::cout << "Temperatures(F,C)=";
	PrintArray(ma, ARRAY_SIZE);
	std::cout << "\n\n";

	// Did it work?
	// Did not work upon initial compile without my code, did not print array.

	std::cout << "Press ENTER";
	std::cin.ignore();
	std::cin.get();
	return 0;
}
//[END MAIN] // DO NOT REMOVE THIS LINE



// Implement all of the following functions
// DO NOT put any std::cout statements unless directly specified
// DO NOT change their signatures

void SeedRand(int x)
{
	srand(x);

}

void InitializeArray(int a[], int arraySize)
{
	// Develop an algorithm that inserts random numbers
	// between 1 and 100 into a[]
	// hint: use rand()

	for (int i = 0; i < arraySize; i++)	{
		a[i] = rand() % 100 + 1;
	}
}

void PrintArray(int a[], int arraySize)
{

	// print the array using cout
	// leave 1 space in-between each integer
	// Example: if the array holds { 1, 2, 3 }
	// This function should print: 1 2 3 
	// It is ok to have a dangling space at the end
	for (int i = 0; i < arraySize; ++i){
		std::cout << a[i] << ' ';
	}

}

bool Contains(int a[], int arraySize, int testVal)
{
	bool contains = false;
	// Develop a linear search algorithm that tests
	// whether the array contains testVal
	for (int i = 0; i < arraySize; i++){
		if (a[i] == testVal){
			contains = true;
		}
	}
	return contains;
}

void BubbleSort(int a[], int arraySize)
{
	// Develop an algorithm that performs the bubble sort
	for (int i = 0; i < arraySize; ++i)
		for (int j = 0; j < arraySize - i - 1; ++j)
			if (a[j] > a[j + 1])
			{
				int x = a[j];
				a[j] = a[j + 1];
				a[j + 1] = x;
			}
}

int SumArray(int a[], int arraySize)
{
	int sum = 0;
	// Develop an algorithm that sums the entire array
	// and RETURNS the result
	for (int i = 0; i < arraySize; i++){
		sum += a[i];
	}
	return sum;
}

int Largest(int a[], int arraySize)
{
	int largest = a[0];
	// Develop an algorithm to figure out the largest value
	for (int i = 1; i < arraySize; i++){
		if (a[i]>largest){
			largest = a[i];
		}
	}
	return largest;
}

int Smallest(int a[], int arraySize)
{
	int smallest = a[0];
	// Develop an algorithm to figure out the smallest value
	for (int i = 1; i < arraySize; i++){
		if (a[i] < smallest){
			smallest = a[i];
		}
	}
	return smallest;
}

double Average(int a[], int arraySize)
{
	double average = 0;
	// Develop an algorithm to figure out the average INCLUDING decimals
	// You might find your previous SumArray function useful
	for (int i = 0; i < arraySize; i++){
		average += a[i];
		average = average / arraySize;
	}
	return average;
}

void ReverseArray(int a[], int arraySize)
{
	// Develop an algorithm to flip the array backwards
	// You might need some temporary storage
	// I wonder if you could just copy the array into a new one
	// and then copy over the old values 1 by 1 from the back
	for (int i = arraySize - 1; i >= 0; i--){
		std::cout << a[i] << ' ';
	}
}

void InitializeTemperatures(int ma[][2], int xSize)
{
	// Develop an algorithm that inserts random numbers
	// between 1 and 100 into a[i][0]
	// hint: use rand()
	// These random numbers represent a temperature in Fahrenheit
	// Then, store the Celsius equivalents into a[i][1]

	for (int i = 0; i < xSize; i++)	{
		for (int n = 1; n < 2; n++){
			ma[i][2] = rand() % 100 + 1;
		}
	}
}

void PrintArray(int ma[][2], int xSize)
{
// print the multi-dimensional array using cout
// Each x-y pair should be printed like so: [x,y]
// All pairs should be printed on one line with no spaces
// Example: [x0,y0][x1,y1][x2,y2] ...

	for (int i = 0; i < xSize; i++)	{
		for (int n = 0; n < 2; n++){
			std::cout << ma[i][2];
		}
	}

}
