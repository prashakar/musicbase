/*
 *
 * Transactions has a method for each different transaction
 * a user can complete.
 *
 //Methods//
 * readUser - reads in lines from username file and returns user name
 * readType - reads in lines from username file and returns user type
 * readCredit - reads in lines from username file and returns amount of user credit
 * readSellerEventTicket - reads in an event and returns seller
 * readEvent - reads the event name from available ticket file
 * readSellerName - reads the seller name from available ticket file
 * readTicketNo - reads the number of ticket from the aviable file
 * readPrice - reads the number of ticket from the aviable file
 * writeUserAccount - writes line to username file
 * writeTickets - writes line to ticket file
 * deleteTicket - deletes ticket/event line from availabletickets.txt
 * getEventName - gets the event name from the users
 * getEventPrice - gets the event pricefrom the users
 * getTicketNo - gets the number of ticket
 * getSellerName - gets the seller name
 * getTicketBuyNo - gets the number of ticket from the BS and FS user
 * getTicketNoFromAdmin - gets the number of ticket from the admin.
 * deleteUser - helper for deleteFunc. Deals with deleting users specifically.
 * writeDTF - writes to daily transaction file
 *
 //Global Variables//
 *
 * ifstream fr = file reader
 *
 * ofstream fw = file writer
 */
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm> //for remove_if

using namespace std;

ifstream fr; //file reader
ofstream fw; //file writer

//Reads in lines from username file and returns user name
string readUser(string name)
{
	string line;
	fr.open("UserAccounts.txt");
	if (fr.is_open())
	{
		while (getline(fr, line))
		{
			line = line.substr(0, 15); // get the position of username from tran file
			line.erase(remove_if(line.begin(), line.end(), isspace), line.end()); // remove space 
			if (line.compare(name) == 0)
			{
				fr.close();
				return line;
			}
		}
		fr.close();
		return "00"; // return 00 if user not found
	}
	return "0";
}

//Reads in lines from username file and returns user type
string readType(string name)
{
	string line;
	string user;
	string type;
	fr.open("UserAccounts.txt");
	if (fr.is_open()){
		while (getline(fr, line))
		{
			user = line.substr(0, 15); // get the position of username from tran file
			user.erase(remove_if(user.begin(), user.end(), isspace), user.end()); // remove space 
			if (user.compare(name) == 0) // if user exisit
			{
				type = line.substr(16, 2); // get the position of type from tran file
				type.erase(remove_if(type.begin(), type.end(), isspace), type.end()); // remove space 
				fr.close();
				return type;
			}
		}
		fr.close();
		return "00"; // return 00 if user not found
	}
	return "0";
}

//Reads in lines from username file and returns amount of user credit
string readCredit(string name)
{
	string line;
	string user;
	string credit;
	int fcredit;
	ostringstream convert; // to string
	fr.open("UserAccounts.txt");
	if (fr.is_open()){
		while (getline(fr, line))
		{
			user = line.substr(0, 15); // get the position of username from tran file
			user.erase(remove_if(user.begin(), user.end(), isspace), user.end()); // remove space 
			if (user.compare(name) == 0) // if user exisit
			{
				credit = line.substr(19, 9); // get the position of credit from tran file
				credit.erase(remove_if(credit.begin(), credit.end(), isspace), credit.end()); // remove 
				istringstream(credit) >> fcredit;
				convert << fcredit;
				credit = convert.str();
				fr.close();
				return credit;
			}
		}
		fr.close();
		return "00"; // return 00 if user not found
	}
	return "0";
}

//Reads in an event and returns seller
string readSellerEventTicket(string seller, string event)
{
	string line;
	string cSeller;
	string cEvent;
	fr.open("AvailableTickets.txt");
	if (fr.is_open())
	{
		while (getline(fr, line))
		{
			cEvent = line.substr(0, 19); // get the position from tran file
			cEvent.erase(remove_if(cEvent.begin(), cEvent.end(), isspace), cEvent.end()); // remove space 
			cSeller = line.substr(20, 13); // get the position from tran file
			cSeller.erase(remove_if(cSeller.begin(), cSeller.end(), isspace), cSeller.end()); // remove space 
			if ((cSeller.compare(seller) == 0) && (cEvent.compare(event) == 0))
			{
				fr.close();
				return line;
			}
		}
		fr.close();
		return "00"; // return 00 if user not found
	}
	return "0";
}

//Readss the event name from available ticket file
string readEvent(string eventTitle)
{
	string line;
	fr.open("AvailableTickets.txt");
	if (fr.is_open()){
		while (fr.good())
		{
			getline(fr, line);
			line = line.substr(0, 25); // get the position of event from the available ticket file
			line.erase(remove_if(line.begin(), line.end(), isspace), line.end()); // remove space 
			if (line.compare(eventTitle) == 0)
			{
				fr.close();
				return line;
			}
		}
		fr.close();
		return "00"; // return 00 if user not found
	}
	return "0";
}

//Reads the seller name from available ticket file
string readSellerName(string eventTitle)
{
	string line;
	string user;
	string type;
	fr.open("AvailableTickets.txt");
	if (fr.is_open()){
		while (fr.good())
		{
			getline(fr, line);
			user = line.substr(0, 25); // get the position of event name from the available file
			user.erase(remove_if(user.begin(), user.end(), isspace), user.end()); // remove space 
			if (user.compare(eventTitle) == 0) // if event exist
			{
				type = line.substr(25, 40); // get the position of type from avaiable text file
				type.erase(remove_if(type.begin(), type.end(), isspace), type.end()); // remove space 
				fr.close();
				return type;
			}
		}
		fr.close();
		return "00"; // return 00 if user not found
	}
	return "0";
}

//Reads the number of ticket from the aviable file
string readTicketNo(string eventTitle)
{
	string line;
	string user;
	string type;
	fr.open("AvailableTickets.txt");
	if (fr.is_open()){
		while (fr.good())
		{
			getline(fr, line);
			user = line.substr(0, 25); // get the position of event name
			user.erase(remove_if(user.begin(), user.end(), isspace), user.end()); // remove space 
			if (user.compare(eventTitle) == 0) // if event name exisit
			{
				type = line.substr(40, 43); // get the position of type from tran file
				type.erase(remove_if(type.begin(), type.end(), isspace), type.end()); // remove space 
				fr.close();
				return type;
			}
		}
		fr.close();
		return "00"; // return 00 if user not found
	}
	return "0";
}

//Reads the number of ticket from the aviable file
string readPrice(string eventTitle)
{
	string line;
	string user;
	string type;
	fr.open("AvailableTickets.txt");
	if (fr.is_open()){
		while (fr.good())
		{
			getline(fr, line);
			user = line.substr(0, 25); // get the position of event name from file
			replace(user.begin(), user.end(), '_', ' '); // replace the '_'to empty space
			user.erase(remove_if(user.begin(), user.end(), isspace), user.end()); // remove space 
			if (user.compare(eventTitle) == 0) // if event name exisit
			{
				type = line.substr(43, 49); // get the position of type from the file
				type.erase(remove_if(type.begin(), type.end(), isspace), type.end()); // remove space 
				fr.close();
				return type;
			}
		}
		fr.close();
		return "00"; // return 00 if user not found
	}
	return "0";
}

//Writes user info to username file
bool writeUserAccount(string write)
{
	fr.open("UserAccounts.txt"); // check if empty only
	fw.open("UserAccounts.txt", ios_base::app);
	if (!(fr.peek() == std::ifstream::traits_type::eof()))
	{
		fw << "\n";
	}
	fw << write;
	fr.close();
	fw.close();
	return 0;
}

//Writes ticket info to ticket file
bool writeTickets(string write)
{

	fr.open("AvailableTickets.txt"); // check if empty only
	fw.open("AvailableTickets.txt", ios_base::app);
	if (!(fr.peek() == std::ifstream::traits_type::eof()))
	{
		fw << "\n";
	}
	fw << write;
	fr.close();
	fw.close();
	return 0;
}

//Deletes ticket/event line from availabletickets.txt
void deleteTicket(string ticket)
{
	string deleteline;
	string cline;
	string line;
	string cuser;
	fr.open("AvailableTickets.txt");
	fw.open("temp.txt");
	//for deleteing line
	int count = 0;
	while (getline(fr, line))
	{
		if (line != ticket)
		{
			if (count == 0){
				fw << line;
				count++;
			}
			else{
				fw << "\n" << line;
			}
		}
	}
	fw.close();
	fr.close();
	remove("AvailableTickets.txt");
	rename("temp.txt", "AvailableTickets.txt");
}


//Gets the event name from the users
string getEventname()
{
	string eventName;
	cout << "Please enter the event name:";
	bool cEvent = true; //check string
	while (cEvent)
	{
		cin >> eventName;
		if (eventName.size() <= 25) cEvent = false;//check if it is 25 character
		else//error message
		{
			cout << "Invalid event: name should be 25 character or less.";
			cout << "Please try again:";
		}
	}
	return eventName;
}

//Gets the event price from the users
float getEventprice()
{
	float eventPrice;

	bool cPrice = true;
	while (cPrice)
	{
		cout << "Please enter the event ticket price:";
		cin.ignore();
		cin >> eventPrice;
		cout << "test";
		if (eventPrice >= 0 && eventPrice <= 999.99)//check for price format
		{
			cPrice = false;
		}

		else cout << "That value is invalid.";//error
	}
	return eventPrice;
}
//Gets the number of tickets
int getTicketNo()
{
	int noTicket;
	bool cTicket = true;
	while (cTicket)
	{
		cout << "Please enter the total number of tickets:";
		cin >> noTicket;
		if (noTicket <= 100) cTicket = false;
		else
		{
			cout << "Invalid event: name should be 25 characters or less.";

		}
	}
	return noTicket;
}
//Gets the seller name 
string getSellerName()
{
	string sellerName;
	cout << "Enter the seller's username: ";
	cin >> sellerName;
	string checkSeller = readUser(sellerName);
	while (checkSeller == "00")//check for valid user
	{
		cout << "Username not valid!" << endl;
		cout << "Try Again: ";
		cin >> sellerName;
		checkSeller = readUser(sellerName);
	}
	return sellerName;
}

//Gets the number of ticket from the BS and FS user
int getTicketBuyNo(string userType)
{
	int noTicket;
	bool cTicket = true;
	while (cTicket)
	{
		cout << "Please enter the number of tickets:";
		cin >> noTicket;
		if (noTicket <= 4) cTicket = false;//only let 4 ticket sale
		else
		{
			cout << "Invalid event: you must have a privileged account to buy more than 4 tickets.";
		}
	}
	return noTicket;

}

//Gets the number of tickets from the admin.
int getTicketNoFromAdmin(string userType)
{
	int noTicket;
	bool cTicket = true;
	while (cTicket)
	{
		cout << "Please enter the number of ticket";
		cin >> noTicket;
		if (noTicket <= 100) cTicket = false;//maxium ticket sale
		else
		{
			cout << "Invalid event: you must have a privileged account to buy more than 4 tickets.";
		}
	}
	return noTicket;

}

//Helper for deleteFunc. Deals with deleting users specifically.
void deleteUser(string name)
{
	string deleteline;
	string cline;
	string line;
	string cuser;
	ifstream fr2;
	fr2.open("UserAccounts.txt");
	fw.open("temp.txt");
	fr.open("UserAccounts.txt");
	if (fr.is_open()){
		while (fr.good())
		{
			getline(fr, cline);
			cuser = cline.substr(0, 15); // get the position of username from tran file
			cuser.erase(remove_if(cuser.begin(), cuser.end(), isspace), cuser.end()); // remove space 
			if (cuser.compare(name) == 0)
			{
				fr.close();
				deleteline = cline;
				goto jmp;
			}
		}
		fr.close();
	}
jmp:
	//for deleteing line
	int count = 0;
	while (getline(fr2, line))
	{
		if (line != deleteline)
		{
			if (count == 0){
				fw << line;
				count++;
			}
			else{
				fw << "\n" << line;
			}
		}
	}
	fw.close();
	fr2.close();
	remove("UserAccounts.txt");
	rename("temp.txt", "UserAccounts.txt");
}

//Writes to daily transaction file 
void writeDTF(string write)
{
	fw.open("dtfTest.txt");
	fw << write;
	fw.close();
}