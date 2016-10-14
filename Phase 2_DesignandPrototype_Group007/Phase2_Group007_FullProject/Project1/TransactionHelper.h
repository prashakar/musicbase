/*
 * HEADER FILE FOR TRANSACTIONHELPER.CPP
 */
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Reads in lines from username file and returns user name
string readUser(string name);
//Reads in lines from username file and returns user type
string readType(string name);
//Reads in lines from username file and returns amount of user credit
string readCredit(string name);
//Reads in an event and returns seller
string readSellerEventTicket(string seller, string event);
//Reads the event name from available ticket file
string readEvent(string eventTitle);
//Reads the seller name from available ticket file
string readSellerName(string eventTitle);
//Reads the number of ticket from the aviable file
string readTicketNo(string eventTitle);
//Reads the number of ticket from the aviable file
string readPrice(string eventTitle);
//Writes line to username file
bool writeUserAccount(string write);
//Writes line to ticket file
bool writeTickets(string eventName);
//Deletes ticket/event line from availabletickets.txt
void deleteTicket(string ticket);
//Gets the event name from the users
string getEventname();
//Gets the event pricefrom the users
float getEventprice();
//Gets the number of ticket
int getTicketNo();
//Gets the seller name 
string getSellerName();
//Gets the number of ticket from the BS and FS user
int getTicketBuyNo(string userType);
//Gets the number of ticket from the admin.
int getTicketNoFromAdmin(string userType);
//Helper for deleteFunc. Deals with deleting users specifically.
void deleteUser(string name);
//Writes to daily transaction file 
void writeDTF(string write);