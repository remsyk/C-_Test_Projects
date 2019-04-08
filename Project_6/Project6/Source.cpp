
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
		std::ifstream lin;
		std::string username;
		std::string pass;
		std::string info;
		std::cout << "Enter Username: ";
		std::cin >> username;
		if (DoesUserExist(GetUserFile(username).c_str()) == false){
			std::cout << "User does not exist!\n\n";
			break;
		}
		std::cout << "Enter Password: ";
		std::cin >> pass;
		lin.open(GetUserFile(username));
		std::cout<<GetPassword(username);
		int count=0;
		for (int i = 0; i < 5; i++){
			count = i;
				lin>> info;
			if (info.find(pass) != std::string::npos && pass != username){
			LoggedInMenu(username);
			break;
			}
			else if (count >= 4){
				std::cout << "Ivalid Password!" << std::endl;
				break;
			}
		}
		break;
	}
}
	
void RegisterNewUser(){
	while (true){
		std::ofstream rout;
		std::ofstream iout;
		std::string username;
		std::string pass;
		std::string firstMessage;
		std::cout << "Enter Username: ";
		std::cin >> username;
		std::cout << "Enter Password: ";
		std::cin >> pass;
		if (username.length() < 3){
			std::cout << "Username must be at least 3 characters!" << "\n\n";
			break;
		}
		if (pass.length() < 6){
			std::cout << "Password must be at least 6 characters!"<<"\n\n";
			break;
		}

		if (DoesUserExist(GetUserFile(username).c_str())){
			std::cout << "User already exists!\n\n";
			break;
		}
		else{
			rout.open(GetUserFile(username).c_str());
			iout.open(GetInboxFile(username).c_str());
			GetUserFile(username) = GetUserFile(username).c_str();
			rout << "username "<< username << std::endl;
			rout << "password "<<pass << std::endl;
			iout << "#email\n" << "mailservice\n" << username << "\n" << "Intro\n" << "Hello," << username << "! Welcome to our service\n";
			rout.close();
			iout.close();
			std::cout << "Accont Created!\n\n";
			break;
		}
	}
}

void DeleteUser(){
	while (true){
		std::string username;
		std::cout << "Input User To Delete: ";
		std::cin >> username;
		if (DoesUserExist(GetUserFile(username).c_str()) == false){
			std::cout << "User does not exist!\n\n";
			break;
		}
		remove(GetInboxFile(username).c_str());
		remove(GetUserFile(username).c_str());
		std::cout << "User Deleted! \n\n";
	}
}

bool DoesUserExist(std::string username){
	std::ifstream file(username);
	return file.good();
}

void LoggedInMenu(std::string username){
	std::ifstream iin;
	std::string info;
	iin.open(GetUserFile(username));
	int count = 0;
	for (int i = 0; i < 5; i++){
		count = i;
		iin >> info;
		if (info.find(GetInboxFile(username)) != std::string::npos){
			break;
		}
	}


		int loginMenu = 0;
		std::string loginInput = "";
		while (loginInput != "99"){
			std::cout << username << " Succesful Login" << std::endl;
			std::cout << "1) Inbox[" << "]" << std::endl;
			std::cout << "2 Send Email" << std::endl;
			std::cout << "99) Logout" << std::endl;
			std::cout << "Selection: ";
			std::cin >> loginInput;

			try{
				loginMenu = stoi(loginInput);
				switch (loginMenu)
				{
				case 1:
					std::cout << "Inbox" << std::endl;
					break;
				case 2:
					std::cout << "Send Email" << std::endl;
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

std::string GetUserFile(std::string username){
	username += ".txt";
	return username;
}

std::string GetInboxFile(std::string username){
	username +="-inbox"".txt";
	return username;
}

std::string GetPassword(std::string username){
	std::ifstream lin;
	std::string info;
	std::string pass ="12345678";
	std::size_t pos;
	lin. open(GetUserFile(username));
	for (int i=0; i<5;i++){
		lin >> info;
	}
	pos = info.find("password ");
	pass = info.substr(pos);
	return pass;
		
}


