//============================================================================
// Name        : Lab1-3.cpp
// Author      : Leticia Herrera
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Lab 1-3 Up to Speed in C++
//============================================================================

#include <algorithm>
#include <iostream>
using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

//Defined a data structure to hold bid information together as a single unit of storage.
struct Bid {
	char title[20];
	double fund;
	int vehicleID;
	double bidAmount;
};

//Displays the bid values passed in data structure
/**
 * Display the bid information
 */
void displayBid(Bid bid) {
    cout << "Title: " << bid.title << endl;
    cout << "Fund: " << bid.fund << endl;
    cout << "Vehicle: " << bid.vehicleID << endl;
    cout << "Bid Amount: " << bid.bidAmount << endl;

    return;
}

//Stores input values in data structure
/**
 * Prompt user for bid information
 *
 * @return data structure containing the bid info
 */
Bid getBid() {
    Bid listBid;

    cout << "Enter title: ";
    cin.ignore();
    getline(cin, listBid.title);

    cout << "Enter fund: ";
    cin >> listBid.fund;

    cout << "Enter vehicle: ";
    cin.ignore();
    getline(cin, listBid.vehicleID);

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    listBid.bidAmount = strToDouble(strAmount, '$');

    return listBid;
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}


/**
 * The one and only main() method
 */
int main() {

    //Declares instance of data structure to hold bid information
	Bid theBid;

    //loops to display menu until exit chosen
    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter Bid" << endl;
        cout << "  2. Display Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        //Complete the method calls then test the program
        switch (choice) {
            case 1:
            	theBid = getBid();
                break;
            case 2:
                displayBid(theBid);
                break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
