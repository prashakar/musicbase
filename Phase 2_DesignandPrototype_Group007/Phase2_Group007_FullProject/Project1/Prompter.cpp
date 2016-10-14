/*
 *
 * Prompter is the user-end of this program.
 * It takes care of most user input and calls each
 * transaction from the Transactions class. It also does 
 * most of the basic validation from the start except for 
 * requirements-focused validation.
 *
 */
#include <iostream>
#include <string>
#include "Transactions.h"

using namespace std;

int main()
{
	string cmd, userName, userType, transactions;

	cout << "Please enter a command:";
	cin >> cmd;

	if (cmd.compare("login") == 0)
	{
		cout << "Enter username:";
		cin >> userName;
		//cout << userName; //test
		userType = login(userName); // login() username exists and is valid, etc and returns user type
		if (!(userType.compare("00") == 0))
		{
			cout << userType; //test
			cout << "Login accepted.\n";
			while (!(cmd.compare("logout") == 0))
			{
				cout << "Please enter a command:\n";
				cin >> cmd;
				if (cmd == "create")
				{
					cout << "create\n";
					cout << "-----------------------------------------------------------------------\n";
					transactions += create() + "\n";
				}
				else if (cmd == "delete")
				{
					cout << "delete\n";
					cout << "-----------------------------------------------------------------------\n";
					transactions += deleteFunc() + "\n";
				}
				else if (cmd == "sell")
				{
					cout << "sell\n";
					cout << "-----------------------------------------------------------------------\n";
					transactions += sell(userType) + "\n";
				}
				else if (cmd == "buy")
				{
					cout << "buy\n";
					cout << "-----------------------------------------------------------------------\n";
					transactions += buy(userType) + "\n";
				}
				else if (cmd == "refund")
				{
					cout << "refund\n";
					cout << "-----------------------------------------------------------------------\n";
					transactions += refund() + "\n";
				}
				else if (cmd == "addcredit")
				{
					cout << "addcredit\n";
					cout << "-----------------------------------------------------------------------\n";
					transactions += addCredit(userType) + "\n";
				}
				else if (cmd == "logout")
				{
					cout << "Logout accepted.\nSession terminated." << endl;
					logout(transactions);
					return 0;
				}
				else 
				{
					cout << "invalid input\n";
				}
			}
	}
		else
		{
			cout << "That user does not exist.";
		}
	}
	else
	{
		cout << cmd + " invalid (please login first).";
	}
}