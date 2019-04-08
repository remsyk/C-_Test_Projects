
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>



void MainMenu();
void Login();
void ShowInbox(std::string username, std::ostream & sout);
void LoggedInMenu(std::string username);
void RegisterNewUser();
void DeleteUser();
std::string GetUserFile(std::string username);
std::string GetInboxFile(std::string username);
//truly could not figure out what GetLine needed to be used for, my code worked perfectly fine without it.
std::string GetLine(std::istream & sin);
bool DoesUserExist(std::string username);
int GetInboxCount(std::string username);
std::string FormatEmailString(std::string from, std::string to, std::string subject, std::string msg);
void SendEmail(std::string username);
std::string GetPassword(std::string username);

//@insert(main) -- don't modify
//@addRule(commentAll) -- don't modify
int main()
{
	MainMenu();
	return 0; // make sure your int main function returns an int
}
//@removeRule(commentAll) -- don't modify

void MainMenu()
{
	std::string input = "";
	int menuItem = 0;

	while (input != "99")
	{
		std::cout << " 1) Login" << "\n";
		std::cout << " 2) Register new user" << "\n";
		std::cout << " 3) Delete user" << "\n";
		std::cout << "99) Exit" << "\n";
		std::cout << "Selection: ";

		std::cin >> input;
		try
		{
			menuItem = stoi(input);
			switch (menuItem)
			{
			case 1:
				Login();
				break;
			case 2:
				RegisterNewUser();
				break;
			case 3:
				DeleteUser();
				break;
			}
		}
		catch (std::invalid_argument & ia)
		{
			std::cout << "Bad option!" << std::endl;
			std::cout << ia.what() << std::endl;
		}
	}
}

// Now you fill in the rest

void Login(){

	while (true){
		//initiate variables
		std::ifstream lin;
		std::string username;
		std::string pass;
		//info will be the user file info
		std::string info;
		std::cout << "Enter Username: ";
		std::cin >> username;
		//checks to see if user exists 
		if (DoesUserExist(GetUserFile(username).c_str()) == false){
			std::cout << "User does not exist!\n\n";
			break;
		}
		std::cout << "Enter Password: ";
		std::cin >> pass;	
		//compares user input to the password in file, will not accept uless password is 100% correct
		if (pass.compare(GetPassword(username))==0){
			//sends to logged in menu	
			LoggedInMenu(username);
				break;
			}
			else{
				std::cout << "Ivalid Password!" << std::endl;
				break;
			}
		lin.close();
		break;
	}
}

void RegisterNewUser(){
	while (true){
		//rout is register out
		std::ofstream rout;
		//iout is inbox out
		std::ofstream iout;
		std::string username;
		std::string pass;
		//chose to simply have first email created here
		std::string firstMessage;
		std::cout << "Enter Username: ";
		std::cin >> username;
		std::cout << "Enter Password: ";
		std::cin >> pass;
		//check if username length is correct
		if (username.length() < 3){
			std::cout << "Username must be at least 3 characters!" << "\n\n";
			break;
		}
		//checks to see if password length is correct
		if (pass.length() < 6){
			std::cout << "Password must be at least 6 characters!" << "\n\n";
			break;
		}

		if (DoesUserExist(GetUserFile(username).c_str())){
			std::cout << "User already exists!\n\n";
			break;
		}
		else{//if everything else is good then the code wil create user files
			rout.open(GetUserFile(username).c_str());
			iout.open(GetInboxFile(username).c_str());
			GetUserFile(username) = GetUserFile(username).c_str();
			rout << "username " << username << std::endl;
			rout << "password " << pass << std::endl;
			iout << "\n#email\n" << "mailservice\n" << username << "\n" << "Intro\n" << "Hello," << username << "! Welcome to our service\n";
			rout.close();
			iout.close();
			std::cout << "Accont Created!\n\n";
			break;
		}
		rout.close();
		iout.close();
	}
}

void DeleteUser(){
	while (true){
		std::string username;
		std::cout << "Input User To Delete: ";
		std::cin >> username;
		//makes sure user exists before deleting
		if (DoesUserExist(GetUserFile(username).c_str()) == false){
			std::cout << "User does not exist!\n\n";
			break;
		}
		//remove required a const char
		remove(GetInboxFile(username).c_str());
		remove(GetUserFile(username).c_str());
		std::cout << "User Deleted! \n\n";
		break;
	}
}

bool DoesUserExist(std::string username){
	std::ifstream file(username);
	return file.good();
}

void LoggedInMenu(std::string username){
	std::ifstream iin;
	std::string inbox;
	int loginMenu = 0;
	std::string loginInput = "";
	//setup for mailbox menu, user can select between choices
	std::cout <<"\n"<< username << " Succesful Login"<<std::endl;
	while (loginInput != "99"){
		std::cout << "1) Inbox[" << GetInboxCount(username)<< "]" << std::endl;
		std::cout << "2 Send Email" << std::endl;
		std::cout << "99) Logout" << std::endl;
		std::cout << "Selection: ";
		std::cin >> loginInput;

		try{
			//simple switch statement for the user choices, used the try catch for invalid entries
			loginMenu = stoi(loginInput);
			switch (loginMenu)
			{
			case 1:
				ShowInbox(username, std::cout);
				break;
			case 2:
				SendEmail(username);
				break;
			}
		}
		catch (std::invalid_argument & ia)
		{
			std::cout << "Bad option!" << std::endl;
			std::cout << ia.what() << std::endl;
		}
	}
	iin.close();
}

std::string GetUserFile(std::string username){
	//simlly takes the username and appends .txt to it
	username += ".txt";
	return username;
}

std::string GetInboxFile(std::string username){
	//simply takes user name and appens -inbox.txt and returns the change
	username += "-inbox"".txt";
	return username;
}

std::string GetPassword(std::string username){
	std::ifstream pin;
	std::string pass;
	pin.open(GetUserFile(username));
	//for loop break up the file by spaces to different lines and the pass words is always going to be the 4th line
	for (int i = 0; i < 4; i++){
		pin >> pass;
		}
	return pass;
	pin.close();
}

int GetInboxCount(std::string username){
	std::ifstream gin;
	std::string inbox;
	int emails = 0;
	gin.open(GetInboxFile(username));
	//while not at end of file
	while (!gin.eof()){
		//get file in put and direct to inbox string
		getline(gin, inbox);
		//loop through string length
		for (int i= 0; i < inbox.length(); i++){
			//find all # symbols and count them
			if (inbox.at(i) == '#'){
				emails++;
			}
		}
	}
	return emails;
	gin.close();
}

std::string FormatEmailString(std::string from, std::string to, std::string subject, std::string msg){
	std::stringstream buffer;
	buffer << "=============================" << std::endl;
	buffer << "From: " << from << std::endl;
	buffer << "To: " << to << std::endl;
	buffer << "Subject: " << subject << std::endl;
	buffer << "Message: " << msg << std::endl;
	buffer << "=============================" << std::endl;
	std::string s= buffer.str();
	return s;

}

void ShowInbox(std::string username, std::ostream & sout){
	std::ifstream sin;
	sin.open(GetInboxFile(username));
	std::string inbox;
	std::string from;
	std::string to;
	std::string subject;
	std::string message;
	std::string email;
	int counter = 0;
	//runs through email folder to sort files
	while (counter < GetInboxCount(username)){
		counter++;
		//for loop is very format specific
		for (int i = 0; i < 6; i++){
			getline(sin, inbox, '\n');
			if (i == 1){
				email = inbox;
			}
			if (i == 2){
				from = inbox;
			}
			if (i == 3){
				to = inbox;
			}
			if (i == 4){
				subject = inbox;
			}
			if (i == 5){
				message = inbox;
			}
		}
		sout << FormatEmailString(from, username, subject, message);
	}
}

void SendEmail(std::string username){
	while (true){
		//set up variables
		std::ofstream sout;
		std::string to;
		std::string subject;
		std::string message;
		int emailMenu = 0;
	redo:;// this is where the user can come back to for edits
		std::cout << "\nFrom: " << username << "\n";
		std::cout << "To:";
		//not sure why 2 getline functions but they both work and allow for spaces in user input
		std::getline(std::cin, to);
		std::getline(std::cin, to);
		std::cout << "Subject: ";
		std::getline(std::cin, subject);
		std::cout << "Message: ";
		//accepts spaces in user input, found it necessary when typing messages
		std::getline(std::cin, message);
		
		//since there was no way to go back and edit live, i figured running through the code again was the next best thing
		//prompts user if they want to send or edit, if they want to edit, it stars over
		std::cout << "[1]Send | [2] Edit" << std::endl;
		std::cin >> emailMenu;
		if (emailMenu == 1){
			//when they are ready to send they press one and this opens and appends recipients inbox file
			sout.open(GetInboxFile(to), std::ios::app);
			sout << "\n#email\n" << username << "\n" << to << "\n" << subject << "\n" << message <<std::endl;
			break;
		}
		else if (emailMenu == 2){
			goto redo;
		}
		sout.close();
	}
}


