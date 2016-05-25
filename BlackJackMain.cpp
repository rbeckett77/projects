#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <Windows.h>
#include "Card.h"
using namespace std;

//Make table //done
//Make dealer cards //done
//Make player cards //done
//Make player able to "hit" //done
//Make player able to "stay" //done
//Make ability to lose //done
//MAke ability to win //done
//Make cards add up //done
//Make ability to "bust" //done
//Make ability for dealer to hit //done
//Make ability for dealer to stay at 17 and above //done
//Make ability to have dealer reveal after player stays //done
//Make display more appealing and easier to understand //done
//Add colors to cards
//Make ability for cards not to repeat
//Make input "Jason Proof"





//void setPlayerCards();
bool startMenu();
int money();
bool blackJackCheck(int, int);
char inGameMenu(HANDLE, bool);
void placeCursor(HANDLE, int, int);
void showBlank(HANDLE, int, int);
bool dealerReveal();
int cardAmountCheck(int, int, int, int, int, int);

int main()
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);		//needed for color and cursor control
	Card playerCard1, playerCard2, dealerCard1, dealerCard2;
	Card playerHit1, playerHit2, playerHit3;
	Card dealerHit1, dealerHit2, dealerHit3;
	bool start, quit;
	int bank;
	string playerName;
	srand(time(0));

	start = startMenu();
	if (start)
	{
		cout << "What is your name? ";
		cin >> playerName;
		bank = 100;
		do
		{
			
		int suit;
		int value;
		int bet;
		int playerTotal, dealerTotal;
		int dealerCheckCard1, dealerCheckCard2;
		int playerCheckCard1, playerCheckCard2;
		char choice;
		int hitCounter = 0, dealerHitCounter = 0;
		bool dealerReveal = false;
		bool playerTurn;
		bool dealerBlackJackCheck;
		bool playerBlackJackCheck;
		bool dealerWin, playerWin;
		bool hitCheck = false, doubleDownCheck = false;

// This sets all the values for the cards, still need to change it so you cant have copies of the same card
			value = rand() % 13 + 2;
			suit = rand() % 4 + 3;					//3 = Hearts, 4 = Diamonds, 5 = Clubs, 6 = Spades
			playerCard1.setSuit(suit);
			playerCard1.setValue(value);
			value = rand() % 13 + 2;
			suit = rand() % 4 + 3;
			playerCard2.setSuit(suit);
			playerCard2.setValue(value);
			value = rand() % 13 + 2;
			suit = rand() % 4 + 3;
			dealerCard1.setSuit(suit);
			dealerCard1.setValue(value);
			value = rand() % 13 + 2;
			suit = rand() % 4 + 3;
			dealerCard2.setSuit(suit);
			dealerCard2.setValue(value);
			value = rand() % 13 + 2;
			suit = rand() % 4 + 3;
			playerHit1.setSuit(suit);
			playerHit1.setValue(value);
			value = rand() % 13 + 2;
			suit = rand() % 4 + 3;
			playerHit2.setSuit(suit);
			playerHit2.setValue(value);
			value = rand() % 13 + 2;
			suit = rand() % 4 + 3;
			playerHit3.setSuit(suit);
			playerHit3.setValue(value);
			value = rand() % 13 + 2;
			suit = rand() % 4 + 3;
			dealerHit1.setSuit(suit);
			dealerHit1.setValue(value);
			value = rand() % 13 + 2;
			suit = rand() % 4 + 3;
			dealerHit2.setSuit(suit);
			dealerHit2.setValue(value);
			value = rand() % 13 + 2;
			suit = rand() % 4 + 3;
			dealerHit3.setSuit(suit);
			dealerHit3.setValue(value);

//This sets the actual values of the cards. Makes any card that has Jack-Ace a 10
			playerCard1.setActualValue();
			playerCard2.setActualValue();
			playerHit1.setActualValue();
			playerHit2.setActualValue();
			playerHit3.setActualValue();
			dealerCard1.setActualValue();
			dealerCard2.setActualValue();
			dealerHit1.setActualValue();
			dealerHit2.setActualValue();
			dealerHit3.setActualValue();

//This checks if the dealer or the player has a Black Jack
			dealerCheckCard1 = dealerCard1.getActualValue();
			dealerCheckCard2 = dealerCard2.getActualValue();
			dealerBlackJackCheck = blackJackCheck(dealerCheckCard1, dealerCheckCard2);
			playerCheckCard1 = playerCard1.getActualValue();
			playerCheckCard2 = playerCard2.getActualValue();
			playerBlackJackCheck = blackJackCheck(playerCheckCard1, playerCheckCard2);
			system("CLS");
			cout << "You have $" << bank << "." << endl;
			cout << "What would you like to bet? $";
			cin >> bet;
			system("CLS");
			do
			{
				if (dealerBlackJackCheck)
				{
					dealerReveal = true;
					dealerWin = true;
					playerWin = false;
					playerTurn = false;
				}
				if (playerBlackJackCheck)
				{
					dealerWin = false;
					playerWin = true;
					playerTurn = false;
				}
				placeCursor(screen, 0, 40);
				cout << "Chips: $" << bank << endl;
				placeCursor(screen, 1, 40);
				cout << "  Bet: $" << bet << endl;
				placeCursor(screen, 0, 0);
				cout << "	----Dealer----" << endl;
				//game display starts here
				if (dealerReveal)
				{
					dealerCard1.showCard(2, 0);
					dealerCard2.showCard(2, 7);
				}
				else
				{
					dealerCard1.showCard(2, 0);
					showBlank(screen, 2, 7);
				}
				
				placeCursor(screen, 9, 0);
				cout << "	----" << playerName << "----" << endl;
				playerCard1.showCard(10, 0);
				playerCard2.showCard(10, 7);
				if (dealerBlackJackCheck)
				{
					break;
				}
				if (playerBlackJackCheck)
				{
					break;
				}
				cout << endl << endl;
				playerTotal = cardAmountCheck(playerCard1.getActualValue(), playerCard2.getActualValue(), playerHit1.getActualValue(), playerHit2.getActualValue(), playerHit3.getActualValue(), hitCounter);
				cout << "You have " << playerTotal << endl;
				if (playerTotal > 21)
				{
					playerTurn = false;
					dealerWin = true;
					playerWin = false;
					break;
				}
				else
				{
					playerTurn = true;
				}
				choice = inGameMenu(screen, hitCheck);
				if (choice == 'A' || choice == 'a')
				{
					hitCheck = true;
					if (hitCounter == 0)
					{
						playerHit1.showCard(10, 14);
						hitCounter++;
					}
					else if (hitCounter == 1)
					{
						playerHit1.showCard(10, 14);
						playerHit2.showCard(10, 21);
						hitCounter++;
					}
					else
					{
						playerHit1.showCard(10, 14);
						playerHit2.showCard(10, 21);
						playerHit3.showCard(10, 28);
						hitCounter++;
					}
				}
				else if (choice == 'B' || choice == 'b')
				{
					cout << "You stay" << endl;
					dealerWin = false;
					playerWin = false;
					playerTurn = false;
				}
				else if (choice == 'C' || choice == 'c')
				{
					cout << "You double down" << endl;
					playerHit1.showCard(10, 14);
					dealerWin = false;
					playerWin = false;
					playerTurn = false;
				}
				else
				{
					cout << "Invalid choice" << endl;
					cout << "You stay" << endl;
					dealerWin = false;
					playerWin = false;
					playerTurn = false;
				}
			} while (playerTurn);
//Dealer's Turn
			dealerCard2.showCard(2, 7);
			if (dealerWin == false && playerWin == false)
			{
				dealerTotal = cardAmountCheck(dealerCard1.getActualValue(), dealerCard2.getActualValue(), dealerHit1.getActualValue(), dealerHit2.getActualValue(), dealerHit3.getActualValue(), dealerHitCounter);
				if (dealerTotal <= 16)
				{
					dealerHit1.showCard(2, 14);
					dealerHitCounter++;
				}
				dealerTotal = cardAmountCheck(dealerCard1.getActualValue(), dealerCard2.getActualValue(), dealerHit1.getActualValue(), dealerHit2.getActualValue(), dealerHit3.getActualValue(), dealerHitCounter);
				if (dealerTotal <= 16)
				{
					dealerHit1.showCard(2, 14);
					dealerHit2.showCard(2, 21);
					dealerHitCounter++;
				}
				dealerTotal = cardAmountCheck(dealerCard1.getActualValue(), dealerCard2.getActualValue(), dealerHit1.getActualValue(), dealerHit2.getActualValue(), dealerHit3.getActualValue(), dealerHitCounter);
				if (dealerTotal <= 16)
				{
					dealerHit1.showCard(2, 14);
					dealerHit2.showCard(2, 21);
					dealerHit3.showCard(2, 28);
					dealerHitCounter++;
				}	
				if (dealerTotal > 21)
				{
					dealerWin = false;
					playerWin = true;
				}
			}
			if (dealerWin == false && playerWin == false)
			{
				dealerTotal = cardAmountCheck(dealerCard1.getActualValue(), dealerCard2.getActualValue(), dealerHit1.getActualValue(), dealerHit2.getActualValue(), dealerHit3.getActualValue(), dealerHitCounter);
				playerTotal = cardAmountCheck(playerCard1.getActualValue(), playerCard2.getActualValue(), playerHit1.getActualValue(), playerHit2.getActualValue(), playerHit3.getActualValue(), hitCounter);
				if (dealerTotal > playerTotal)
				{
					dealerWin = true;
					playerWin = false;
				}
				else if (dealerTotal < playerTotal)
				{
					dealerWin = false;
					playerWin = true;
				}
				else
				{
					dealerWin = true;
					playerWin = true;
				}
			}
			char delayKey;
//Win Check
			placeCursor(screen, 20, 0);
			cout << "                                                    " << endl;
			dealerTotal = cardAmountCheck(dealerCard1.getActualValue(), dealerCard2.getActualValue(), dealerHit1.getActualValue(), dealerHit2.getActualValue(), dealerHit3.getActualValue(), dealerHitCounter);
			placeCursor(screen, 20, 0);
			cout << "Dealer has " << dealerTotal << endl;
			placeCursor(screen, 21, 0);
			/*cout << " " << endl;*/
			if (dealerWin == true && playerWin == false)
			{
				placeCursor(screen, 23, 0);
				cout << "Dealer Wins!" << endl;
				if (doubleDownCheck)
				{
					bank -= bet * 2;
				}
				else
				{
					bank -= bet;
				}
			}
			else if (playerWin == true && dealerWin == false)
			{
				placeCursor(screen, 23, 0);
				cout << "You Win!" << endl;
				if (doubleDownCheck)
				{
					bank += bet * 2;
				}
				else
				{
					bank += bet;
				}
			}
			else
			{
				placeCursor(screen, 23, 0);
				cout << "Push!" << endl;
			}
			cout << "Press any key then enter to continue: ";
			cin >> delayKey;
			system("CLS");
			
		} while (bank > 0);
	}
	else
	{
		cout << "Now exiting the program..." << endl;
		cin.get();
	}

	return 0;
}

//This function shows the inital start menu
bool startMenu()
{
	string choice;

	cout << "Welcome to Black Jack!" << endl << endl << endl;
	cout << "Would you like to play?" << endl;
	cout << "Please type Yes or No: ";
	cin >> choice;
	while (!(choice == "Yes" || choice == "yes" || choice == "No" || choice == "no"))
	{
		cout << "Invalid choice.";
		cout << "Would you like to play?" << endl;
		cout << "Please type Yes or No: ";
		cin >> choice;
	}
	if (choice == "Yes" || choice == "yes")
	{
		return true;
	}
	else
	{
		return false;
	}
}

//This function lets the player choose to hit, stay, double down, split, or surrender
char inGameMenu(HANDLE screen, bool check)
{
	char choice;
	
		cout << "A. Hit	B. Stay	C. Double Down D. Split	E. Surrender" << endl;
		cin >> choice;
		while (!(choice == 'A' || choice == 'a' || choice == 'B' || choice == 'b' || choice == 'C' || choice == 'c' || choice == 'D' || choice == 'd' || choice == 'E' || choice == 'e'))
		{
			cout << "Invalid choice. Please enter a single letter A-E: ";
			cin >> choice;
		}
	return choice;
}

//This function places the cursor on the screen in a specific location
void placeCursor(HANDLE screen, int row, int col){
	COORD position;
	position.Y = row;
	position.X = col;
	SetConsoleCursorPosition(screen, position);
}

//This function shows a blank card for when the hands are intitially shown
void showBlank(HANDLE screen, int row, int col)
{
	placeCursor(screen, row, col);
	cout << "------" << endl;
	placeCursor(screen, row + 1, col);
	cout << "|    |" << endl;
	placeCursor(screen, row + 2, col);
	cout << "|    |" << endl;
	placeCursor(screen, row + 3, col);
	cout << "|    |" << endl;
	placeCursor(screen, row + 4, col);
	cout << "|    |" << endl;
	placeCursor(screen, row + 5, col);
	cout << "|    |" << endl;
	placeCursor(screen, row + 6, col);
	cout << "------" << endl;
}

//This function checks for a black jack for either the dealer or the player
bool blackJackCheck(int card1, int card2)
{
	int check;
	check = card1 + card2;
	if (check == 21)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//This function checks the total amount the cards add up to. Also checks if there is an Ace and whether it should be 1 or 11
int cardAmountCheck(int card1, int card2, int cardHit1, int cardHit2, int cardHit3, int hitCount)
{
	int total;
	if (hitCount == 0)
	{
		total = card1 + card2;
		if (card1 == 11 && total == 22)
		{
			total -= 10;
		}
		if (card2 == 11 && total == 22)
		{
			total -= 10;
		}
		return total;
	}
	else if (hitCount == 1)
	{
		total = card1 + card2 + cardHit1;
		if (card1 == 11 && total > 21)
		{
			total -= 10;
		}
		if (card2 == 11 && total > 21)
		{
			total -= 10;
		}
		if (cardHit1 == 11 && total > 21)
		{
			total -= 10;
		}
		return total;
	}
	else if (hitCount == 2)
	{
		total = card1 + card2 + cardHit1 + cardHit2;
		if (card1 == 11 && total > 21)
		{
			total -= 10;
		}
		if (card2 == 11 && total > 21)
		{
			total -= 10;
		}
		if (cardHit1 == 11 && total > 21)
		{
			total -= 10;
		}
		if (cardHit2 == 11 && total > 21)
		{
			total -= 10;
		}
		return total;
	}
	else
	{
		total = card1 + card2 + cardHit1 + cardHit2 + cardHit3;
		if (card1 == 11 && total > 21)
		{
			total -= 10;
		}
		if (card2 == 11 && total > 21)
		{
			total -= 10;
		}
		if (cardHit1 == 11 && total > 21)
		{
			total -= 10;
		}
		if (cardHit2 == 11 && total > 21)
		{
			total -= 10;
		}
		if (cardHit3 == 11 && total > 21)
		{
			total -= 10;
		}
		return total;
	}
}