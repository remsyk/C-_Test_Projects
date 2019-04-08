#include <iostream>
#include <ostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <stdio.h>

bool GetInputFileStream(std::ifstream * fin, std::string filename);
void GetOutputFileStream(std::ofstream * fout, std::string filename);
void SetGetPointer(std::istream & fin, int location);
void SetPutPointer(std::ostream & fout, int location);
void AnalyzeFile(std::istream & cin,
	int & numUsed,
	int & numNew,
	double & newTotalPrice,
	double & newTotalMileage,
	double & usedTotalPrice,
	double & usedTotalMileage);
void PrintLine(std::ostream & sout, std::string s);
void PrintNew(std::istream & fin, std::ostream & fout);
void PrintUsed(std::istream & fin, std::ostream & fout);
void PrintStatistics(std::ostream & rout,
	int numUsed,
	int numNew,
	double newTotalPrice,
	double newTotalMileage,
	double usedTotalPrice,
	double usedTotalMileage);
std::string FormatCarInfo(std::string year,
	std::string make,
	std::string model,
	double price,
	double mileage);
int main()
{
	// You will need to put the provided cars.txt into
	// the working directory of this program
	std::ifstream fin;
	std::string filename = "cars.txt";
	std::ofstream fout;
	std::string filename2 = "newFile.txt";
	std::ifstream sin;
	std::string filename3 = "numbers.txt";
	std::ofstream tout;
	std::string filename4 = "setPutExample.txt";
	std::ofstream pout;
	std::string filename5 = "stats.txt";
	std::ofstream lout;
	std::string filename6 = "output.txt";
	std::ofstream sout;
	std::string filename7 = "printLineExample.txt";
	std::ifstream gin;
	std::string filename8 = "cars.txt";


	bool isOpen = GetInputFileStream(&fin, filename);
	if (isOpen == false)
	{
		std::cout << "Couldn't find file " << filename << "!" << std::endl;
		std::cout << "Couldn't find file " << filename2 << "!" << std::endl;
		std::cout << "Couldn't find file " << filename3 << "!" << std::endl;
		std::cout << "Couldn't find file " << filename4 << "!" << std::endl;
		std::cout << "Couldn't find file " << filename5 << "!" << std::endl;
		std::cout << "Couldn't find file " << filename6 << "!" << std::endl;
		std::cout << "Couldn't find file " << filename7 << "!" << std::endl;
	}
	else
	{
		std::cout << "Successfully Loaded..." << filename << std::endl;
		std::cout << "Successfully Loaded..." << filename3 << std::endl;
		// Now work on tests to make sure the rest of your functions work properly

		GetOutputFileStream(&fout, filename2);
		fout << "This is my new file!\n";
		fout << "This is on a new line!";
		std::cout << "Successfully Edited..." << filename << std::endl;
		fout.close();

		GetInputFileStream(&sin, filename3);
		std::cout << "Reading(x2)..." << filename3 << std::endl;
		int number = 0;
		sin >> number;
		SetGetPointer(sin, 0);
		while (sin >> number){
			std::cout << "Read: " << number << std::endl;
		}
		sin.clear();
		sin.seekg(0, sin.beg);
		while (sin >> number){
			std::cout << "Read: " << number << std::endl;
		}
		sin.close();

		GetOutputFileStream(&tout, filename4);
		tout << "abcdefghijklmnopqrstuvwxyz";
		SetPutPointer(tout, 0);
		tout << "ABCDEFGHIJKLMN";
		std::cout << "Successfully Edited..." << filename4 << std::endl;
		tout.close();

		GetOutputFileStream(&pout, filename5);
		double newTotalPrice = 33000;
		double newTotalMileage = 250;
		double usedTotalPrice = 700;
		double usedTotalMileage = 254000;
		int numUsed = 1;
		int numNew = 2;
		PrintStatistics(std::cout, numUsed, numNew, newTotalPrice, newTotalMileage, usedTotalPrice, usedTotalMileage);
		SetPutPointer(pout, 0);
		PrintStatistics(pout, numUsed, numNew, newTotalPrice, newTotalMileage, usedTotalPrice, usedTotalMileage);
		pout.close();

		GetInputFileStream(&gin, filename8);
		newTotalPrice = 0;
		newTotalMileage = 0;
		usedTotalPrice = 0;
		usedTotalMileage = 0;
		numUsed = 0;
		numNew = 0;
		AnalyzeFile(gin, numUsed, numNew, newTotalPrice, newTotalMileage, usedTotalPrice, usedTotalMileage);
		PrintStatistics(std::cout, numUsed, numNew, newTotalPrice, newTotalMileage, usedTotalPrice, usedTotalMileage);


		GetOutputFileStream(&sout, filename7);
		std::stringstream ss;
		std::string s = "My output string!";
		PrintLine(std::cout, s);
		PrintLine(ss, s);
		std::cout << "SS: " << ss.str();
		PrintLine(sout, s);
		sout.close();

		GetInputFileStream(&fin, filename);
		PrintNew(gin, std::cout);
		std::stringstream ssout;
		PrintNew(gin, ssout);
		PrintLine(std::cout, "SS: " + ssout.str());


		GetInputFileStream(&fin, filename);
		PrintUsed(fin, std::cout);
		std::stringstream ssout2;
		PrintUsed(fin, ssout2);
		PrintLine(std::cout, "SS: " + ssout2.str());

		/*
		std::string year;
		std::string make;
		std::string model;
		double price;
		double mileage;
		std::string category;
		GetInputFileStream(&fin, filename);
		while (fin >> year &&fin >> make &&fin >> model &&fin >> price &&fin >> mileage &&fin >> category){
		std::string s = FormatCarInfo(year, make, model, price, mileage);
		}
		*/
		std::cout << "Press ENTER to continue";
		std::cin.get();
		return 0;
	}
}

// The function prototypes are provided above
// Copy them here, remove the semicolons at the end
// Add braces, and fill in the functionality

bool GetInputFileStream(std::ifstream * fin, std::string filename){
	fin->open(filename, std::ifstream::in);
	return true;
}

void GetOutputFileStream(std::ofstream * fout, std::string filename){
	fout->open(filename, std::ifstream::out);
}

void SetGetPointer(std::istream & sin, int location){
	sin.seekg(0, sin.end);
	location = sin.tellg();
	sin.seekg(0, sin.beg);
}

void SetPutPointer(std::ostream & tout, int location){
	tout.seekp(location);
}

void PrintStatistics(std::ostream & rout, int numUsed, int numNew, double newTotalPrice, double newTotalMileage, double usedTotalPrice, double usedTotalMileage){
	using std::setw;
	rout << setw(10) << "Category|" << setw(10) << "Number|" << setw(10) << "Total Price|" << setw(10) << "Total Milage|" << '\n' <<
		setw(10) << "New|" << setw(10) << numNew << "|" << setw(10) << newTotalPrice << "|" << setw(10) << newTotalMileage << "|\n" <<
		setw(10) << "Used|" << setw(10) << numUsed << "|" << setw(10) << usedTotalPrice << "|" << setw(10) << usedTotalMileage << "|\n";

}


void AnalyzeFile(std::istream &gin, int & numUsed, int & numNew, double & newTotalPrice, double & newTotalMileage, double & usedTotalPrice, double & usedTotalMileage){
	std::string line;
	//std::string numbers = "0123456789";

	while (getline(gin, line, ' ')){
		/*
		std::size_t pos = line.find_first_of(numbers.c_str());

		if (pos >= 4){
		line.clear();
		}

		int arr[15];
		int r;
		std::istringstream(line) >> r;
		std::cout << r << std::endl;

		for (int i = 0; i <= 15; i++){
		arr[i] = r;
		std::cout << arr[i] << std::endl;
		}
		*/
		if (line.find("new", 0) != std::string::npos){
			numNew++;
		}
		if (line.find("used", 0) != std::string::npos){
			numUsed++;
		}
	}
}


void PrintLine(std::ostream & sout, std::string s){
	sout << s << std::endl;
}

void PrintNew(std::istream & gin, std::ostream & fout){
	std::string line;
	while (getline(gin, line)){
		if (line.find("new", 0) != std::string::npos){
			fout << line << std::endl;

		}
	}
}

void PrintUsed(std::istream & fin, std::ostream & fout){
	std::string line;
	while (getline(fin, line)){
		if (line.find("used") != std::string::npos){
			fout << line << std::endl;
		}
	}
}
/*
std::string FormatCarInfo(std::string year, std::string make, std::string model, double price, double mileage){
std::stringstream buffer;
using std::setw;
buffer<< setw(10) << year << setw(10) << make << setw(10) << model << setw(10) << price << setw(10) << mileage << std::endl;
std::string line = buffer.str();
return line;
}
*/