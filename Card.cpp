#include <iostream>
#include <string>
#include <Windows.h>
#include "Card.h"

using namespace std;

HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);		//needed for color and cursor control

//Places cursor for showCard function
void placeCursorClass(HANDLE screen, int row, int col){
	COORD position;
	position.Y = row;
	position.X = col;
	SetConsoleCursorPosition(screen, position);
}

//Sets the numeric value of the cards 1-14. 11 = Jack, 12 = Queen, 13 = King, 14 = Ace
void Card::setValue(int v)
{
	value = v;
}

//Sets the suit number. 3 = Hearts, 4 = Diamonds, 5 = Clubs, 6 = Spades
void Card::setSuit(int s)
{
	suit = s;
}

//Checks if the value is above 10 and sets it to 10 or 11 for the variable actualValue. Ace check in function in main
void Card::setActualValue()
{
	int m;

	if (value < 11)
	{
		m = value;
	}
	else if (value = 14)
	{
		m = 11;
	}
	else
	{
		m = 10;
	}
	actualValue = m;
}

//Shows value
int Card::getValue()
{
	return value;
}

//Shows actualValue
int Card::getActualValue()
{
	return actualValue;
}

//Shows suit
int Card::getSuit()
{
	return suit;
}

//Displays card to screen. Takes 2 arguments to place on specific location
void Card::showCard(int row, int col)			//3 = Hearts, 4 = Diamonds, 5 = Clubs, 6 = Spades
{
	string convertedValue, convertedSuit;
	convertedSuit = suit;

	if (value == 1)
	{
		convertedValue = "1";
	}
	else if (value == 2)
	{
		convertedValue = "2";
	}
	else if (value == 3)
	{
		convertedValue = "3";
	}
	else if (value == 4)
	{
		convertedValue = "4";
	}
	else if (value == 5)
	{
		convertedValue = "5";
	}
	else if (value == 6)
	{
		convertedValue = "6";
	}
	else if (value == 7)
	{
		convertedValue = "7";
	}
	else if (value == 8)
	{
		convertedValue = "8";
	}
	else if (value == 9)
	{
		convertedValue = "9";
	}
	else if (value == 10)
	{
		convertedValue = "10";
	}
	else if (value == 11)
	{
		convertedValue = "J";
	}
	else if (value == 12)
	{
		convertedValue = "Q";
	}
	else if (value == 13)
	{
		convertedValue = "K";
	}
	else
	{
		convertedValue = "A";
	}
	placeCursorClass(screen, row, col);
	cout << "------" << endl;
	placeCursorClass(screen, row + 1, col);
	if (convertedValue != "10")
	{
		cout << "|" << convertedValue << "   |" << endl;
	}
	else
	{
		cout << "|" << convertedValue << "  |" << endl;
	}
	placeCursorClass(screen, row + 2, col);
	cout << "|" << convertedSuit <<"   |" << endl;
	placeCursorClass(screen, row + 3, col);
	cout << "|    |" << endl;
	placeCursorClass(screen, row + 4, col);
	cout << "|   " << convertedSuit << "|" << endl;
	placeCursorClass(screen, row + 5, col);
	if (convertedValue != "10")
	{
		cout << "|   " << convertedValue << "|" << endl;
	}
	else
	{
		cout << "|  " << convertedValue << "|" << endl;
	}
	placeCursorClass(screen, row + 6, col);
	cout << "------" << endl;
}					

