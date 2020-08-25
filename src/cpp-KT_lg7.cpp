//============================================================================
// Name        : cpp-KT_lg7.cpp
// Author      : Tobias Gion <tgion>
// Version     :
// Copyright   : Your copyright notice
// Description : KT Übungsblatt LG7 - Fehlerbehebung
//============================================================================

#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::exception;
using std::cerr;

/// @brief	prints a string to stdout
///
/// @param	text string& to be printed
///
void print (string& text) {
	cout << text << endl;
}

/// @brief	prints an integer to stdout
///
/// @param	number itn& to be printed
///
void print (int& number) {
	cout << number << endl;
}

/// @brief	prints a float to stdout
///
/// @param	number float& to be printed
///
void print (float& number) {
	cout << number << endl;
}

/// @brief	checks if a string contains only numbers
///
/// @param	text string& string to check for numbers
/// @return	bool true if string is a number, otherwise false
///
bool isNumber(string& number) {
	for (int i = 0; i < number.length(); ++i) {
		if (isdigit(number[i]) == false) {
			return false;
		}
	}
	return true;
}

/// @brief	reads a number from stdin
///
/// @param	text string& print text to ask user for input
/// @return	integer read from stdin
///
bool readInt (string text, int& number) {
	cout << text;				// tell the user to input (given text)

	string userInput;
	cin >> userInput;			// save user input as string

	if (isNumber(userInput)) {		// check if user input is number
		number = stoi(userInput);	// if successfull return number
		return true;
	}
	else {
		throw std::invalid_argument("Sie haben keinen Integer eingegeben!");
		return false;
	}
}

int main() {

	//============================================================================
	// Aufgabe 1.1
	//============================================================================
	string myTestString = "Hello World!";

	//print (myTestString);

	//============================================================================
	// Aufgabe 1.2
	//============================================================================
	//int myTestInteger = 5;
	//float myTestFloat = 3.8f;

	//print (myTestInteger);
	//print (myTestFloat);

	//============================================================================
	// Aufgabe 2.1
	//============================================================================
	//readInt("Bitte geben Sie eine Integer ein: ");

	//============================================================================
	// Aufgabe 2.2
	//============================================================================
	int myAge;

/*	while ( !(readInt("Bitte geben Sie Ihr Alter ein: ", myAge)) ) {
		cerr << "Sie haben keine Zahl eingegeben!" << endl;
	}
*/


	while ( true ) {
		try {
			readInt("Bitte geben Sie Ihr Alter ein: ", myAge);
			break;
		}
		catch (exception &exc) {
			cerr << exc.what() << endl;
		}
	}

	switch (myAge) {
	case 1 ... 18:
		cout << "Servus Alter!" << endl;
		break;

	case 19 ... 65:
		cout << "Guten Morgen!" << endl;
		break;

	default:
		cout << "Guten Morgen alter Herr!" << endl;
		break;

	}

	return 0;
}



























