/*
 *
 * Transactions has a method for each different transaction
 * a user can complete. 
 *
 //Methods//
 *
 * login - checks that the username entered exists and, if so
 *		  sets the user global variable and returns the user
 *		  type. If not, it returns an error.
 * logout - logs current user out of the system and resets gv.
 * create - creates and saves a user account.
 * deleteFunc - deletes users and tickets and also updates the 
 *		   respective files to remove the user/ticket lines.
 * sell - sells/creates tickets to events and also updates the 
 *        tickets file on availability of tickets.
 * buy - buys tickets to events and also updates the 
 *       tickets file on availability of tickets.
 * refund - returns credit from buyer to seller and updates the
 *          user file.
 * addcredit - (functionality based on user type) adds credit to
 *             specified user and updates the user file as well.
 *
 //Global Variables//
 *
 * string dtf = daily transaction file line to be printed once
 *				the user has logged out.
 * string user = username of the user currently logged in.
 *
 */
#include <iostream>
#include <string>
#include <sstream>
#include "TransactionHelper.h"

using namespace std;

string dtf; //transaction line for daily transaction file
string user; //Name of user currently logged in

 
//Looks for username in user file. If found, it returns the
// user privilege level. If the user does not exist, it
// returns '00' instead. 
string login(string userName)
{
	string type = readType(userName);
	user = readUser(userName); // Sets global variable
	return type;
}

//Logs current user out of the system, prints DTF and resets global variables.
string logout(string transactions)
{
	//If no valid transactions were made, returns string of 0s for daily transaction file.
	if (transactions.empty())
	{
		transactions = "00 		      000000000";  
	}
	writeDTF(transactions);
	return "00";
}

//Creates and saves a user account.
string create()
{
	string C = "01 ";
	string DTF = "";
	string CTF = "";
	string username;
	string type;
	string credit;
	string space;
	string check;

	//string test = "XX_UUUUUUUUUUUUUUU_TT_CCCCCCCCC"; // test to check final tran file //test

	//cout << "Final tran file length should be: " << test.length() << endl; // test length //test

	cout << "\nEnter username: ";
	cin >> username;
	while (!(username.length() <= 15))  // check length of username not more the 15 charactor
	{
		cout << "\ninvalid username is too long";
		cout << "\nEnter username: ";
		cin >> username;
	}
	// Check username if exist or not 
	check = readUser(username); // username exist return 00
	while (check != "00")  // check username 
	{
		cout << "Username exist! try different one";
		cout << "\nEnter username: ";
		cin >> username;
		check = readUser(username);
	}

	for (unsigned int i = 0; i < 15 - username.length(); i++) // add spaces to the empty spots for username
	{
		space += " ";
	}
	DTF += space + username + " ";
	//cout << "DTF: " + DTF << endl; // test

	//---------------------------------------------------------------------- End of username
	cout << "Enter type: ";
	cin >> type;
	while (type != "AA" && type != "FS" && type != "BS" && type != "SS")
	{
		cout << "invalid type" << endl;
		cout << "Enter type: ";
		cin >> type;
	}
	DTF += type + " ";
	//cout << "DTF: " + DTF << endl; // test
	//---------------------------------------------------------------------- End of type
	cout << "Enter credit: ";
	cin >> credit;
	while (!(credit.length() <= 6)) // check length of credit not more the 999999
	{
		cout << "invalid credit exceeded the maximum" << endl;
		cout << "\nEnter credit: ";
		cin >> credit;
	}
	space = ""; // empty space
	for (unsigned int i = 0; i < 9 - credit.length(); i++) // add spaces to the empty spots for credit
	{
		space += "0";
	}
	DTF += space + credit;

	// THE FINAL FILES TRANSATIONS FOR DTF AND CTF
	CTF = DTF;
	//cout << "\nFinal User Account File: " << CTF << endl; //test
	DTF = C + DTF;
	//cout << "Final DTF: " << DTF << endl << endl; //test
	writeUserAccount(CTF);
	//cout << "Final CTF length is: " << CTF.length() << endl; // tesT
	//cout << "Final DTF length is: " << DTF.length() << endl; // test
	cout << "New user created" << endl;
	return DTF;
}

//Deletes users and tickets. Also updates user accounts file and ticket
// files. 
string deleteFunc()
{
	string D = "02 ";
	string DTF = "";
	string CTF = "";
	string choice;
	string userName;
	string confirm;
	string check;
	string space;
	string type;
	string credit;
	string sellerTicket;
	string eventTicket;
	cout << "\nEnter what you want to delete (user/ticket): ";
	cin >> choice;

	if (choice == "user")
	{
		cout << "\nEnter username: ";
		cin >> userName;
		// Check username if exist or not 
		check = readUser(userName); // username doesn't exist 
		while (check == "00")  // check username 
		{
			cout << "Username doesn't exist! try different one";
			cout << "\nEnter username: ";
			cin >> userName;
			check = readUser(userName);
		}
		for (unsigned int i = 0; i < 15 - userName.length(); i++) // add spaces to the empty spots for username
		{
			space += " ";
		}
		DTF += space + userName + " ";
		type = readType(userName);
		DTF += type + " ";
		space = ""; // empty space
		credit = readCredit(userName);
		for (unsigned int i = 0; i < 9 - credit.length(); i++) // add spaces to the empty spots for credit
		{
			space += "0";
		}
		DTF += space + credit;
		// check if you want to contiune or not
		cout << "Are you sure you want to delete?: ";
		cin >> confirm;
		if (confirm == "yes")
		{
			deleteUser(userName);
			// THE FINAL FILES TRANSATIONS FOR DTF AND CTF
			CTF = DTF;
			//cout << "\nUser Account File Deleted: " << CTF << endl; //test
			DTF = D + DTF;
			//cout << "Final DTF: " << DTF << endl << endl; //test
			cout << "User deleted\n" << endl;
			return DTF;
		}
		else if (confirm == "no")
		{
			// do nothing
			return " "; //must exit somehow
		}
		else
		{
			cout << "invalid input." << endl;
		}

	}
	else if (choice == "ticket"){
		cout << "Enter seller username: ";
		cin >> sellerTicket;
		cout << "Enter event title: ";
		cin >> eventTicket;
		check = readSellerEventTicket(sellerTicket, eventTicket);
		while (check == "00")
		{
			cout << "\nInvalid event: seller or event does not exist" << endl;
			cout << "Enter seller username: ";
			cin >> sellerTicket;
			cout << "Enter event title: ";
			cin >> eventTicket;
			check = readSellerEventTicket(sellerTicket, eventTicket);
		}
		for (unsigned int i = 0; i < 15 - userName.length(); i++) // add spaces to the empty spots for username
		{
			space += " ";
		}
		DTF += space + userName + " ";
		type = readType(userName);
		DTF += type + " ";
		space = ""; // empty space
		credit = readCredit(userName);
		for (unsigned int i = 0; i < 9 - credit.length(); i++) // add spaces to the empty spots for credit
		{
			space += "0";
		}
		DTF += space + credit;
		// check if you want to contiune or not
		cout << "Are you sure you want to delete?: ";
		cin >> confirm;
		if (confirm == "yes")
		{
			deleteTicket(check);
			DTF = D + DTF;
			cout << "Ticket deleted\n" << endl;
			return DTF;
		}
		else if (confirm == "no")
		{
			// do nothing
			return ""; //must exit somehow
		}
	}
	else
	{
		cout << "\ninvalid input.";
	}
}

//Sells tickets to events and also updates the tickets file on availability of tickets.
string sell(string userType)
{
	string C = "03 ";
	string DTF = "";
	string CTF = "";
	string space;
	string eName;
	float ePrice;
	int noTicket;
	string sPrice;
	string sTicketNo;

	if (userType.compare("AA") == 0 || userType.compare("SS") == 0 || userType.compare("FS") == 0)//check for the valid user
	{
		eName = getEventname();//gets the proper format of event name from user
		ePrice = getEventprice();//gets the proper format of price from user
		noTicket = getTicketNo();	// gets the proper format of ticket from user
		sTicketNo = std::to_string(noTicket);//convert to string from int
		sPrice = std::to_string(ePrice);//convert to string from float
		while (eName.size() < 19)
		{
			eName = " " + eName;
		}
		while (user.size() < 13) // add spaces to the empty spots for username
		{
			user = " " + user;
		}
		while (sTicketNo.size() < 3) // add 0s to the empty spots for ticket amount
		{
			sTicketNo = "0" + sTicketNo;
		}
		while (sPrice.size() < 6) // add 0s to the empty spots for ticket price
		{
			sPrice = "0" + sPrice;
		}
		CTF = eName + " " + user + " " + sTicketNo + " " + sPrice;//token for avaliable ticket file
		DTF = C + CTF;//token for daily transaction file
		writeTickets(CTF);//wriye in avaliable ticket file
		return DTF;
	}
	else
		cout << "Invalid user: access denied.";
}

//Buys tickets to events and also updates the tickets file on availability of tickets.
string buy(string userType)
{
	if (userType.compare("AA") == 0 || userType.compare("BS") == 0 || userType.compare("FS") == 0)//check for the vaild user
	{
		string C = "04 ";
		string DTF = "";
		string CTF = "";
		string space;
		string eName;
		int ticketNo;
		float price;
		string confirmation;
		string eventTitle;
		string sellerName;
		string eventPrice;

		string findTicketNo;
		string findPrice;
		string checkEventtitle;
		string checkSellername;
		eventTitle = getEventname();//gets the proper format of event name from user
		sellerName = getSellerName();//gets the proper format of seller name from user
		if (userType.compare("AA") == 0)
		{
			//more privalge given to admin
			ticketNo = getTicketNoFromAdmin(userType);
		}
		else
		{
			ticketNo = getTicketBuyNo(userType);//gets the proper format of number of ticket from user
		}

		checkEventtitle = readEvent(eventTitle);//check if the event title is in file
		checkSellername = readSellerName(eventTitle);//check if sellername in the file

		if ((checkEventtitle != "00") && (checkSellername != "00"))//check if the seller name or event name id empty
		{
			findTicketNo = readTicketNo(eventTitle); //find the ticket avaible
			findPrice = readPrice(eventTitle);//find the ticket price
		}
		price = (float)atof(findPrice.c_str());//convert pric into float
		price = ticketNo*price;//calculate the total price
		cout << "The price for the ticket is $" + findPrice;
		cout << "/n";
		cout << "Total price $ %2f", price;
		cout << "Please confirm the purchase by selecting Yes and declined by No";
		cin >> confirmation;
		while (eName.size() < 19)
		{
			eName = " " + eName;
		}
		while (user.size() < 13) // add spaces to the empty spots for username
		{
			user = " " + user;
		}
		ostringstream convert; // stream used for the conversion
		convert << ticketNo; // insert the textual representation of 'Number' in the characters in the stream
		string ticketNum = convert.str();
		while (ticketNum.size() < 3) // add 0s to the empty spots for ticket amount
		{
			ticketNum = "0" + ticketNum;
		}
		convert << price; // insert the textual representation of 'Number' in the characters in the stream
		string strPrice = convert.str();
		while (strPrice.size() < 6) // add 0s to the empty spots for ticket price
		{
			strPrice = "0" + strPrice;
		}
		CTF = eName + " " + user + " " + ticketNum + " " + strPrice;//token for avaliable ticket file
		if (confirmation == "yes")//updating files
		{
			deleteTicket(CTF);//delete the ticket from the file
			int value = atoi(findTicketNo.c_str());
			value = value - ticketNo;
			while (eName.size() < 19)
			{
				eName = " " + eName;
			}
			while (user.size() < 13) // add spaces to the empty spots for username
			{
				user = " " + user;
			}
			convert << ticketNo; // insert the textual representation of 'Number' in the characters in the stream
			string ticketNum = convert.str();
			while (ticketNum.size() < 3) // add 0s to the empty spots for ticket amount
			{
				ticketNum = "0" + ticketNum;
			}
			convert << price; // insert the textual representation of 'Number' in the characters in the stream
			string strPrice = convert.str();
			while (strPrice.size() < 6) // add 0s to the empty spots for ticket price
			{
				strPrice = "0" + strPrice;
			}
			CTF = eName + " " + user + " " + ticketNum + " " + strPrice;;//token for avaliable ticket file
			DTF = C + CTF;//token for daily transaction file
			writeTickets(CTF);
			return DTF;

		}
		else if (confirmation == "no")
		{
			// do nothing
		}
		else
		{
			cout << "invalid input." << endl;
		}
	}
	else
		cout << "invalid user." << endl;
}

//Returns credit from buyer to seller and updates the user file.
string refund()
{
	int amount;
	string buyerName;
	string sellerName;

	cout << "Enter the buyer's username: ";
	cin >> buyerName;
	string checkBuyer = readUser(buyerName);

	while (checkBuyer == "00")
	{
		cout << "Username not valid!" << endl;
		cout << "Try Again: ";
		cin >> buyerName;
		checkBuyer = readUser(buyerName);
	}

	cout << "Enter the seller's username: ";
	cin >> sellerName;
	string checkSeller = readUser(sellerName);

	while (checkSeller == "00")
	{
		cout << "Username not valid!" << endl;
		cout << "Try Again: ";
		cin >> sellerName;
		checkSeller = readUser(sellerName);
	}

	cout << "Enter amount to credit: ";
	cin >> amount;

	string buyerCreditS = readCredit(buyerName);
	int buyerCredit;
	istringstream(buyerCreditS) >> buyerCredit;

	while (buyerCredit < amount)
	{
		cout << "Amount entered exceeds buyer's account balance: " << endl;
		cout << "Try Again: ";
		cin >> amount;
		buyerCreditS = readCredit(buyerName);
		int buyerCredit;
		istringstream(buyerCreditS) >> buyerCredit;
	}

	string sellerCreditS = readCredit(sellerName);
	int sellerCredit;
	istringstream(sellerCreditS) >> sellerCredit;

	buyerCredit = buyerCredit - amount;
	sellerCredit = sellerCredit + amount;

	string buyerCreditS2; // string which will contain the result
	ostringstream convert; // stream used for the conversion
	convert << buyerCredit; // insert the textual representation of 'Number' in the characters in the stream
	buyerCreditS2 = convert.str();
	while (buyerCreditS2.size() < 9)
	{
		buyerCreditS2 = "0" + buyerCreditS2;
	}

	string sellerCreditS2; // string which will contain the result
	ostringstream convert1; // stream used for the conversion
	convert1 << sellerCredit; // insert the textual representation of 'Number' in the characters in the stream
	sellerCreditS2 = convert1.str();
	while (sellerCreditS2.size() < 9)
	{
		sellerCreditS2 = "0" + sellerCreditS2;
	}
	//cout << buyerCredit << endl << sellerCredit << endl;

	string deleteTHISBUYER;
	deleteTHISBUYER = buyerName;

	string buyerType = readType(buyerName);
	string sellerType = readType(sellerName);

	while (buyerName.size() < 15)
	{
		buyerName = " " + buyerName;
	}

	string deleteTHISSELLER;
	deleteTHISSELLER = sellerName;

	while (sellerName.size() < 15)
	{
		sellerName = " " + sellerName;
	}

	string amountString; // string which will contain the result
	ostringstream convert2; // stream used for the conversion
	convert2 << amount; // insert the textual representation of 'Number' in the characters in the stream
	amountString = convert2.str();
	while (amountString.size() < 9)
	{
		amountString = "0" + amountString;
	}

	string DTF = "05 " + buyerName + " " + sellerName + " " + amountString;
	cout << "DTF: " << DTF << endl;

	string UserAccounts1 = buyerName + " " + buyerType + " " + buyerCreditS2;
	deleteUser(deleteTHISBUYER);
	writeUserAccount(UserAccounts1);

	string UserAccounts2 = sellerName + " " + sellerType + " " + sellerCreditS2;
	deleteUser(deleteTHISSELLER);
	writeUserAccount(UserAccounts2);

	return DTF;
	//---------------------------------------------------------------------- End of refund
}

//If user is and amin, adds credit to specified user and updates the user file.
// If user is not an admin, adds credit to user's account and updates the user file.
string addCredit(string type)
{
	//string type = readType(userName);

	int amount;
	cout << "Enter amount you would like to add: " << endl;
	cin >> amount;

	if (type == "AA")
	{
		string addToUser;
		cout << "Enter account you would like to add credit to: " << endl;
		cin >> addToUser;
		string user = readUser(addToUser);
		while (user == "00")
		{
			cout << "Invalid user account" << endl;
			cout << "Try again: " << endl;
			cin >> addToUser;
			user = readUser(addToUser);
		}

		int balance;
		string balanceS = readCredit(addToUser);
		istringstream(balanceS) >> balance;
		int newBalance = balance + amount;
		string newBalanceS;
		ostringstream convert; // stream used for the conversion
		convert << newBalance; // insert the textual representation of 'Number' in the characters in the stream
		newBalanceS = convert.str();
		string userType = readType(addToUser);

		string deleteTHISUSER;
		deleteTHISUSER = addToUser;

		while (addToUser.size() < 15)
		{
			addToUser = " " + addToUser;
		}

		while (newBalanceS.size() < 9)
		{
			newBalanceS = "0" + newBalanceS;
		}

		string DTF = "06 " + addToUser + " " + userType + " " + newBalanceS;
		//cout << DTF << " AA" << endl;
		string UserAccounts = addToUser + " " + userType + " " + newBalanceS;
		deleteUser(deleteTHISUSER);
		writeUserAccount(UserAccounts);
		cout << "The credit was successfully added to the account.\n";
		return DTF;
	}
	else
	{
		int balance;
		string balanceS = readCredit(user);
		istringstream(balanceS) >> balance;
		int newBalance = balance + amount;

		string newBalanceS;
		ostringstream convert; // stream used for the conversion
		convert << newBalance; // insert the textual representation of 'Number' in the characters in the stream
		newBalanceS = convert.str();

		string userType = readType(user);

		string deleteTHISUSER;
		deleteTHISUSER = user;

		while (user.size() < 15)
		{
			user = " " + user;
		}

		while (newBalanceS.size() < 9)
		{
			newBalanceS = "0" + newBalanceS;
		}

		string DTF = "06 " + user + " " + userType + " " + newBalanceS;
		//cout << DTF << " NON AA" << endl;
		string UserAccounts = user + " " + userType + " " + newBalanceS;
		deleteUser(deleteTHISUSER);
		writeUserAccount(UserAccounts);
		cout << "The credit was successfully added to the account.\n";
		return DTF;
	}
}
