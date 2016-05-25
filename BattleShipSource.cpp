//Ryan Beckett

//TO DO:
//Make core game that actually works: //done
//Make player and enemy "maps" //done
//Make ability for player to guess random "points" to attack //done
//Make ability for player to win //done
//Make computer fight back //done
//Make "medium" computer //done
//Make ability for player to place ships (preferably not point-by-point) //done
//Make ability for player to type in 2 coordinates //done
//and chars are changed from 'O' to 'A' for set up //done
//Make randomized computer map //done
//Make board more user friendly (colors) //done
//State when you sink enemy ship to player //done
//State when computer sinks players ship //done          
//Have output text display to the right of the screen //done
//Bug fix player submarine holding "garbagio" //done													
//Let player be lazy and have map generated for them by option to them placing manually //done 	
//Make "hard" computer										<------Next on to-do list
//Convert to functions //done
//Optimize:
//Make validation for user map set up "Idiot Proof"
//Make player attack turn "Idiot Proof" //done
//Realize how bad game is and delete it

#include <iostream>
#include <ctime>
#include <limits>
#include <string>
#include <Windows.h>
using namespace std;

const int COLS = 10;
const int ROWS = 10;
const int CARRIER = 5;
const int BATTLE_SHIP = 4;
const int CRUISER = 3;
const int SUBMARINE = 3;
const int PATROL = 2;
//Prototypes
void playerSetUp(HANDLE, char[][COLS], int, int playerCarrier[], int playerBattleShip[], int playerCruiser[], int playerSubmarine[], int playerPatrol[]);
void mapGenerator(char[][COLS], int, int enemyCarrier[], int enemyBattleShip[], int enemyCruiser[], int enemySubmarine[], int enemyPatrol[]);
void displayScoreBoard(HANDLE, char[][COLS], char[][COLS], int, int enemyCarrier[], int enemyBattleShip[], int enemyCruiser[], int enemySubmarine[], int enemyPatrol[], int &, int &, int &, int &, int &, int &, int &, int &, int &, int &, int playerCarrier[], int playerBattleShip[], int playerCruiser[], int playerSubmarine[], int playerPatrol[]);
void placeCursor(HANDLE, int, int);
int winCondition(int, int);
int startMenu();
int shipCheck(char[][COLS], int, int ship[], int);
int letterVal(char);
int numValidation(int);
void displayBoard(HANDLE, char[][COLS], int);
void playerTurn(HANDLE, char[][COLS], char[][COLS], int);
void enemyTurn(HANDLE, char[][COLS], int, int);
int main()
{
	//computer map
	char computer[ROWS][COLS] = {
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
	};
	//map the player will see
	char enemyDisplay[ROWS][COLS] = {
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
	};
	//player map
	char player[ROWS][COLS] = {
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
	};
	int startNumber, gameOver;
	int enemyCarrier[7], enemyBattleShip[6], enemyCruiser[5], enemySubmarine[5], enemyPatrol[4];			//holds numbers for points of ship location
	int playerCarrier[7], playerBattleShip[6], playerCruiser[5], playerPatrol[4];		//holds numbers for points of ship location
	int playerSubmarine[5];
	int enemyCarrierAlive = 1, enemyBattleShipAlive = 1, enemyCruiserAlive = 1, enemySubmarineAlive = 1, enemyPatrolAlive = 1;		//1 = ship alive 2 = ship dead
	int playerCarrierAlive = 1, playerBattleShipAlive = 1, playerCruiserAlive = 1, playerSubmarineAlive = 1, playerPatrolAlive = 1; //1 = ship alive 2 = ship dead
	int enemyAlive, playerAlive;							//holds number 1-5 for how many ships are left

	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);		//needed for color and cursor control

	startNumber = startMenu();								//gets player choice for difficulty
	if (startNumber == 1 || startNumber == 2){
		system("CLS");
		playerSetUp(screen, player, ROWS, playerCarrier, playerBattleShip, playerCruiser, playerSubmarine, playerPatrol);									//function that lets player place ships accordingly
		mapGenerator(computer, ROWS, enemyCarrier, enemyBattleShip, enemyCruiser, enemySubmarine, enemyPatrol);	//function that sets computer ships
		do{
			placeCursor(screen, 0, 0);										//places cursor for boards
			displayBoard(screen, enemyDisplay, ROWS);						//displays computer board
			displayBoard(screen, player, ROWS);								//displays player board
			displayScoreBoard(screen, player, computer, ROWS, enemyCarrier, enemyBattleShip, enemyCruiser, enemySubmarine, enemyPatrol, enemyCarrierAlive, enemyBattleShipAlive, enemyCruiserAlive, enemySubmarineAlive, enemyPatrolAlive, playerCarrierAlive, playerBattleShipAlive, playerCruiserAlive, playerSubmarineAlive, playerPatrolAlive, playerCarrier, playerBattleShip, playerCruiser, playerSubmarine, playerPatrol);				//displays score board
			playerTurn(screen, computer, enemyDisplay, ROWS);				//lets player choose a point to attack
			enemyTurn(screen, player, COLS, startNumber);					//computer chooses a point to attack
			enemyAlive = enemyCarrierAlive + enemyBattleShipAlive + enemyCruiserAlive + enemySubmarineAlive + enemyPatrolAlive;
			playerAlive = playerCarrierAlive + playerBattleShipAlive + playerCruiserAlive + playerSubmarineAlive + playerPatrolAlive;
			gameOver = winCondition(enemyAlive, playerAlive);				//checks if all ships are destroyed
		} while (gameOver == 1);
		if (gameOver == 2){
			system("CLS");
			placeCursor(screen, 0, 0);
			cout << "You Win!" << endl;
			cin.get();
		}
		else{
			system("CLS");
			placeCursor(screen, 0, 0);
			cout << "You Lost!" << endl;
			cin.get();
		}
	}
	else{
		char quitKey;
		cout << "Press any key then enter to exit: ";
		cin >> quitKey;
	}


	return 0;
}
//This function lets the player pick between playing or quitting, then from computer or human, then from which difficulty
int startMenu(){
	int start;
	char choice;
	cout << "\t\tBattle Ship Game 1.0\n\n\n";
	cout << "This game is real beta stuff right now." << endl;
	cout << "Please press the maxmize screen button for best quality." << endl << endl << endl;
	cout << "A. Start \nB. Quit\nChoose: ";
	cin >> choice;
	if (choice == 'A' || choice == 'a'){
		cout << "Would you like to face the computer or another person?" << endl;
		cout << "A. Computer\nB. Human\nC. Quit" << endl;
		cout << "Your choice: ";
		cin >> choice;
		if (choice == 'A' || choice == 'a'){
			cout << "What difficulty would you like?" << endl;
			cout << "A. Easy\nB. Medium\nC. Hard (Under Construction}" << endl;
			cout << "Your choice: ";
			cin >> choice;
			if (choice == 'A' || choice == 'a'){
				start = 1;
			}
			else if (choice == 'B' || choice == 'b'){
				start = 2;
			}
			else{
				cout << "Hard still under constuction. Loading Medium difficulty.";
				start = 2;
			}
		}
		else if (choice == 'B' || choice == 'b'){
			cout << "Still under construction. Now exiting program." << endl;
			start = 0;
		}
		else
			start = 0;
	}
	else
		start = 0;
	return start;
}
//This function displays the game board of the player or the computer
void displayBoard(HANDLE screen, char map[][COLS], int row){
	cout << "    0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "  -----------------------\n";
	for (int x = 0; x < 10; x++){
		if (x == 0)
			cout << "A ";
		if (x == 1)
			cout << "B ";
		if (x == 2)
			cout << "C ";
		if (x == 3)
			cout << "D ";
		if (x == 4)
			cout << "E ";
		if (x == 5)
			cout << "F ";
		if (x == 6)
			cout << "G ";
		if (x == 7)
			cout << "H ";
		if (x == 8)
			cout << "I ";
		if (x == 9)
			cout << "J ";
		cout << "| ";
		for (int y = 0; y < 10; y++){
			if (map[x][y] == 'O'){
				SetConsoleTextAttribute(screen, 7);
				cout << map[x][y] << " ";
			}
			else if (map[x][y] == 'A'){
				SetConsoleTextAttribute(screen, 1);
				cout << map[x][y] << " ";
				SetConsoleTextAttribute(screen, 7);
			}
			else if(map[x][y] == 'M'){
				SetConsoleTextAttribute(screen, 6);
				cout << map[x][y] << " ";
				SetConsoleTextAttribute(screen, 7);
			}
			else{
				SetConsoleTextAttribute(screen, 4);
				cout << map[x][y] << " ";
				SetConsoleTextAttribute(screen, 7);
			}
		}
		cout << "|";
		cout << endl;
	}
	cout << "  -----------------------\n";
}
//This function will allow the player to place his ships anywhere on the array.
void playerSetUp(HANDLE screen, char playerSetUp[][COLS], int rows, int playerCarrier[], int playerBattleShip[], int playerCruiser[], int playerSubmarine[], int playerPatrol[]){
	static int shipCount = 0;
	int place1, place2, place3, place4, placer2, placer4, shipSize, sizeDifference;
	char placer1, placer3;
	string shipName;
	int overLapCheck = 1;
	char choice;


	displayBoard(screen, playerSetUp, ROWS);
	cout << "Welcome to BattleShip! This is your board where you get to place your ships!" << endl;
	cout << "Do you wish to place your ships manually or have a randomly generated board?" << endl;
	cout << "Type A to make your own board or B to have one make for you: ";
	cin >> choice;
	if (choice == 'A' || choice == 'a'){
		do{
			system("CLS");
			displayBoard(screen, playerSetUp, ROWS);
			cout << "Please type the letter followed by the number (example: a6) then press enter." << endl;
			cout << "Then type in the second coordinate in the same format. Please only place ships" << endl;
			cout << "from left to right or from up to down. The game will crash otherwise :(" << endl;
			if (shipCount == 0){
				shipName = "carrier";
				shipSize = CARRIER;
			}
			else if (shipCount == 1){
				shipName = "battle_ship";
				shipSize = BATTLE_SHIP;
			}
			else if (shipCount == 2){
				shipName = "cruiser";
				shipSize = CRUISER;
			}
			else if (shipCount == 3){
				shipName = "submarine";
				shipSize = SUBMARINE;
			}
			else if (shipCount == 4){
				shipName = "patrol";
				shipSize = PATROL;
			}
			cout << "Placing " << shipName << " that is " << shipSize << " spaces long." << endl;
			cout << "Please type the letter first followed by the number\nfor one point followed by the other point\nFirst point (e.g. a5): ";
			cin.ignore();
			cin >> placer1;
			place1 = letterVal(placer1);
			cin >> placer2;
			place2 = numValidation(placer2);
			cout << "Second point (e.g. a8): ";
			cin.ignore();
			cin >> placer3;
			place3 = letterVal(placer3);
			cin >> placer4;
			place4 = numValidation(placer4);
			if (place1 == place3){
				sizeDifference = place4 - place2 + 1;
				if (sizeDifference == shipSize){
					for (int x = place2; x <= place4; x++){
						if (playerSetUp[place1][x] == 'O'){
							overLapCheck = 1;
						}
						else{
							overLapCheck = 2;
							break;
						}
					}
					if (overLapCheck == 1){
						for (int x = place2, t = 2; x <= place4; x++, t++){
							if (shipCount == 0){
								playerCarrier[0] = 1;
								playerCarrier[1] = place1;
								playerCarrier[t] = x;
							}
							else if (shipCount == 1){
								playerBattleShip[0] = 1;
								playerBattleShip[1] = place1;
								playerBattleShip[t] = x;
							}
							else if (shipCount == 2){
								playerCruiser[0] = 1;
								playerCruiser[1] = place1;
								playerCruiser[t] = x;
							}
							else if (shipCount == 3){
								playerSubmarine[0] = 1;
								playerSubmarine[1] = place1;
								playerSubmarine[t] = x;
							}
							else{
								playerPatrol[0] = 1;
								playerPatrol[1] = place1;
								playerPatrol[t] = x;
							}
							playerSetUp[place1][x] = 'A';
							system("CLS");
						}
					}
					else{
						system("CLS");
						cout << "You already have a ship there!" << endl;
						shipCount--;
					}
				}
				else{
					do{
						system("CLS");
						cout << "Invalid size." << endl;
						displayBoard(screen, playerSetUp, ROWS);
						cout << "Placing " << shipName << " that is " << shipSize << " spaces long." << endl;
						cout << "Please type the letter first followed by the number\nfor one point followed by the other point\nFirst point (no space): ";
						cin.ignore();
						cin >> placer1;
						place1 = letterVal(placer1);
						cin >> placer2;
						place2 = numValidation(placer2);
						cout << "Second point (no space): ";
						cin.ignore();
						cin >> placer3;
						place3 = letterVal(placer3);
						cin >> placer4;
						place4 = numValidation(placer4);
						sizeDifference = place4 - place2 + 1;
					} while (sizeDifference != shipSize && overLapCheck == 2);
					for (int x = place2; x <= place4; x++){
						if (playerSetUp[place1][x] == 'O'){
							overLapCheck = 1;
						}
						else{
							overLapCheck = 2;
							break;
						}
					}
					if (overLapCheck == 1){
						for (int x = place2, t = 2; x <= place4; x++, t++){
							if (shipCount == 0){
								playerCarrier[0] = 1;
								playerCarrier[1] = place1;
								playerCarrier[t] = x;
							}
							else if (shipCount == 1){
								playerBattleShip[0] = 1;
								playerBattleShip[1] = place1;
								playerBattleShip[t] = x;
							}
							else if (shipCount == 2){
								playerCruiser[0] = 1;
								playerCruiser[1] = place1;
								playerCruiser[t] = x;
							}
							else if (shipCount == 3){
								playerSubmarine[0] = 1;
								playerSubmarine[1] = place1;
								playerSubmarine[t] = x;
							}
							else{
								playerPatrol[0] = 1;
								playerPatrol[1] = place1;
								playerPatrol[t] = x;
							}
							playerSetUp[place1][x] = 'A';
							system("CLS");
						}
					}
					else{
						system("CLS");
						cout << "You already have a ship there!" << endl;
						shipCount--;
					}
				}
			}
			else if (place2 == place4){
				sizeDifference = place3 - place1 + 1;
				if (sizeDifference == shipSize){
					for (int x = place1; x <= place3; x++){
						if (playerSetUp[x][place2] == 'O'){
							overLapCheck = 1;
						}
						else{
							overLapCheck = 2;
							break;
						}
					}
					if (overLapCheck == 1){
						for (int x = place1, t = 2; x <= place3; x++, t++){
							if (shipCount == 0){
								playerCarrier[0] = 2;
								playerCarrier[1] = place2;
								playerCarrier[t] = x;
							}
							else if (shipCount == 1){
								playerBattleShip[0] = 2;
								playerBattleShip[1] = place2;
								playerBattleShip[t] = x;
							}
							else if (shipCount == 2){
								playerCruiser[0] = 2;
								playerCruiser[1] = place2;
								playerCruiser[t] = x;
							}
							else if (shipCount == 3){
								playerSubmarine[0] = 2;
								playerSubmarine[1] = place2;
								playerSubmarine[t] = x;
							}
							else{
								playerPatrol[0] = 2;
								playerPatrol[1] = place2;
								playerPatrol[t] = x;
							}
							playerSetUp[x][place2] = 'A';
							system("CLS");
						}
					}
					else{
						system("CLS");
						cout << "You already have a ship there!" << endl;
						shipCount--;
					}
				}
				else{
					do{
						system("CLS");
						displayBoard(screen, playerSetUp, ROWS);
						cout << "Invalid size." << endl;
						cout << "Placing " << shipName << " that is " << shipSize << " spaces long." << endl;
						cout << "Please type the letter first followed by the number\nfor one point followed by the other point\nFirst point (no space): ";
						cin.ignore();
						cin >> placer1;
						place1 = letterVal(placer1);
						cin >> placer2;
						place2 = numValidation(placer2);
						cout << "Second point (no space): ";
						cin.ignore();
						cin >> placer3;
						place3 = letterVal(placer3);
						cin >> placer4;
						place4 = numValidation(placer4);
						sizeDifference = place4 - place2 + 1;
					} while (sizeDifference != shipSize && overLapCheck == 2);
					for (int x = place1; x <= place3; x++){
						if (playerSetUp[place1][x] == 'O'){
							overLapCheck = 1;
						}
						else{
							overLapCheck = 2;
							break;
						}
					}
					if (overLapCheck == 1){
						for (int x = place1, t = 2; x <= place3; x++, t++){
							if (shipCount == 0){
								playerCarrier[0] = 2;
								playerCarrier[1] = place2;
								playerCarrier[t] = x;
							}
							else if (shipCount == 1){
								playerBattleShip[0] = 2;
								playerBattleShip[1] = place2;
								playerBattleShip[t] = x;
							}
							else if (shipCount == 2){
								playerCruiser[0] = 2;
								playerCruiser[1] = place2;
								playerCruiser[t] = x;
							}
							else if (shipCount == 3){
								playerSubmarine[0] = 2;
								playerSubmarine[1] = place2;
								playerSubmarine[t] = x;
							}
							else{
								playerPatrol[0] = 2;
								playerPatrol[1] = place2;
								playerPatrol[t] = x;
							}
							playerSetUp[place1][x] = 'A';
							system("CLS");
						}
					}
					else{
						system("CLS");
						cout << "You already have a ship there!" << endl;
						shipCount--;
					}
				}
			}
			else{
				system("CLS");
				cout << "Must enter ships vertical or horizontal." << endl;
				cout << "Please enter the smaller point first followed by the bigger point." << endl;
				shipCount--;
			}
			shipCount++;
		} while (shipCount <= 4);
	}
	else{
		mapGenerator(playerSetUp, ROWS, playerCarrier, playerBattleShip, playerCruiser, playerSubmarine, playerPatrol);
		system("CLS");
	}
}
//This function makes the computer make a random map for the 5 ships
void mapGenerator(char computerSetUp[][COLS], int rows, int enemyCarrier[], int enemyBattleShip[], int enemyCruiser[], int enemySubmarine[], int enemyPatrol[]){
	int computerShipDirection, computerPoint1, computerPoint2; //1 = horizontal 2 = vertical
	int overLapCheck;

	srand(time(0));
	//place carrier
	computerShipDirection = rand() % 2 + 1;
	if (computerShipDirection == 1){				//horizontal
		computerPoint1 = rand() % 10;
		computerPoint2 = rand() % 6;
		computerSetUp[computerPoint1][computerPoint2] = 'A';
		computerSetUp[computerPoint1][computerPoint2 + 1] = 'A';
		computerSetUp[computerPoint1][computerPoint2 + 2] = 'A';
		computerSetUp[computerPoint1][computerPoint2 + 3] = 'A';
		computerSetUp[computerPoint1][computerPoint2 + 4] = 'A';
		enemyCarrier[0] = computerShipDirection;
		enemyCarrier[1] = computerPoint1;
		enemyCarrier[2] = computerPoint2;
		enemyCarrier[3] = computerPoint2 + 1;
		enemyCarrier[4] = computerPoint2 + 2;
		enemyCarrier[5] = computerPoint2 + 3;
		enemyCarrier[6] = computerPoint2 + 4;
	}
	else{												//vertical
		computerPoint1 = rand() % 6;
		computerPoint2 = rand() % 10;
		computerSetUp[computerPoint1][computerPoint2] = 'A';
		computerSetUp[computerPoint1 + 1][computerPoint2] = 'A';
		computerSetUp[computerPoint1 + 2][computerPoint2] = 'A';
		computerSetUp[computerPoint1 + 3][computerPoint2] = 'A';
		computerSetUp[computerPoint1 + 4][computerPoint2] = 'A';
		enemyCarrier[0] = computerShipDirection;
		enemyCarrier[1] = computerPoint2;
		enemyCarrier[2] = computerPoint1;
		enemyCarrier[3] = computerPoint1 + 1;
		enemyCarrier[4] = computerPoint1 + 2;
		enemyCarrier[5] = computerPoint1 + 3;
		enemyCarrier[6] = computerPoint1 + 4;
	}
	//place battleship
	do{
		computerShipDirection = rand() % 2 + 1;
		if (computerShipDirection == 1){				//horizontal
			computerPoint1 = rand() % 10;
			computerPoint2 = rand() % 7;
			for (int z = computerPoint2; z < computerPoint2 + 3; z++){
				if (computerSetUp[computerPoint1][z] == 'O'){
					overLapCheck = 1;
				}
				else{
					overLapCheck = 2;
					break;
				}
			}
				if (overLapCheck == 1){
					computerSetUp[computerPoint1][computerPoint2] = 'A';
					computerSetUp[computerPoint1][computerPoint2 + 1] = 'A';
					computerSetUp[computerPoint1][computerPoint2 + 2] = 'A';
					computerSetUp[computerPoint1][computerPoint2 + 3] = 'A';
					enemyBattleShip[0] = computerShipDirection;
					enemyBattleShip[1] = computerPoint1;
					enemyBattleShip[2] = computerPoint2;
					enemyBattleShip[3] = computerPoint2 + 1;
					enemyBattleShip[4] = computerPoint2 + 2;
					enemyBattleShip[5] = computerPoint2 + 3;
				}

			
		}
		else{											//vertical
			computerPoint1 = rand() % 7;
			computerPoint2 = rand() % 10;
			for (int z = computerPoint1; z < computerPoint1 + 3; z++){
				if (computerSetUp[z][computerPoint2] == 'O'){
					overLapCheck = 1;
				}
				else{
					overLapCheck = 2;
					break;
				}
			}
				if (overLapCheck == 1){
					computerSetUp[computerPoint1][computerPoint2] = 'A';
					computerSetUp[computerPoint1 + 1][computerPoint2] = 'A';
					computerSetUp[computerPoint1 + 2][computerPoint2] = 'A';
					computerSetUp[computerPoint1 + 3][computerPoint2] = 'A';
					enemyBattleShip[0] = computerShipDirection;
					enemyBattleShip[1] = computerPoint2;
					enemyBattleShip[2] = computerPoint1;
					enemyBattleShip[3] = computerPoint1 + 1;
					enemyBattleShip[4] = computerPoint1 + 2;
					enemyBattleShip[5] = computerPoint1 + 3;
				}

			
		}

	} while (overLapCheck == 2);
	//Cruiser
	do{
		computerShipDirection = rand() % 2 + 1;
		if (computerShipDirection == 1){				//horizontal
			computerPoint1 = rand() % 10;
			computerPoint2 = rand() % 8;
			for (int z = computerPoint2; z < computerPoint2 + 2; z++){
				if (computerSetUp[computerPoint1][z] == 'O'){
					overLapCheck = 1;
				}
				else{
					overLapCheck = 2;
					break;
				}
			}
				if (overLapCheck == 1){
					computerSetUp[computerPoint1][computerPoint2] = 'A';
					computerSetUp[computerPoint1][computerPoint2 + 1] = 'A';
					computerSetUp[computerPoint1][computerPoint2 + 2] = 'A';
					enemyCruiser[0] = computerShipDirection;
					enemyCruiser[1] = computerPoint1;
					enemyCruiser[2] = computerPoint2;
					enemyCruiser[3] = computerPoint2 + 1;
					enemyCruiser[4] = computerPoint2 + 2;
				}

			
		}
		else{											//vertical
			computerPoint1 = rand() % 8;
			computerPoint2 = rand() % 10;
			for (int z = computerPoint1; z < computerPoint1 + 2; z++){
				if (computerSetUp[z][computerPoint2] == 'O'){
					overLapCheck = 1;
				}
				else{
					overLapCheck = 2;
					break;
				}
			}
	if (overLapCheck == 1){
		computerSetUp[computerPoint1][computerPoint2] = 'A';
		computerSetUp[computerPoint1 + 1][computerPoint2] = 'A';
		computerSetUp[computerPoint1 + 2][computerPoint2] = 'A';
		enemyCruiser[0] = computerShipDirection;
		enemyCruiser[1] = computerPoint2;
		enemyCruiser[2] = computerPoint1;
		enemyCruiser[3] = computerPoint1 + 1;
		enemyCruiser[4] = computerPoint1 + 2;
	}

		}
	} while (overLapCheck == 2);
	//submarine
	do{
		computerShipDirection = rand() % 2 + 1;
		if (computerShipDirection == 1){				//horizontal
			computerPoint1 = rand() % 10;
			computerPoint2 = rand() % 8;
			for (int z = computerPoint2; z < computerPoint2 + 2; z++){
				if (computerSetUp[computerPoint1][z] == 'O'){
					overLapCheck = 1;
				}
				else{
					overLapCheck = 2;
					break;
				}
			}
				if (overLapCheck == 1){
					computerSetUp[computerPoint1][computerPoint2] = 'A';
					computerSetUp[computerPoint1][computerPoint2 + 1] = 'A';
					computerSetUp[computerPoint1][computerPoint2 + 2] = 'A';
					enemySubmarine[0] = computerShipDirection;
					enemySubmarine[1] = computerPoint1;
					enemySubmarine[2] = computerPoint2;
					enemySubmarine[3] = computerPoint2 + 1;
					enemySubmarine[4] = computerPoint2 + 2;
				}

			
		}
		else{											//vertical
			computerPoint1 = rand() % 8;
			computerPoint2 = rand() % 10;
			for (int z = computerPoint1; z < computerPoint1 + 2; z++){
				if (computerSetUp[z][computerPoint2] == 'O'){
					overLapCheck = 1;
				}
				else{
					overLapCheck = 2;
					break;
				}
			}
				if (overLapCheck == 1){
					computerSetUp[computerPoint1][computerPoint2] = 'A';
					computerSetUp[computerPoint1 + 1][computerPoint2] = 'A';
					computerSetUp[computerPoint1 + 2][computerPoint2] = 'A';
					enemySubmarine[0] = computerShipDirection;
					enemySubmarine[1] = computerPoint2;
					enemySubmarine[2] = computerPoint1;
					enemySubmarine[3] = computerPoint1 + 1;
					enemySubmarine[4] = computerPoint1 + 2;
				}
			
		}
	} while (overLapCheck == 2);
	//patrol
	do{
		computerShipDirection = rand() % 2 + 1;
		if (computerShipDirection == 1){				//horizontal
			computerPoint1 = rand() % 10;
			computerPoint2 = rand() % 9;
			for (int z = computerPoint2; z < computerPoint2 + 1; z++){
				if (computerSetUp[computerPoint1][z] == 'O'){
					overLapCheck = 1;
				}
				else{
					overLapCheck = 2;
					break;
				}
			}
				if (overLapCheck == 1){
					computerSetUp[computerPoint1][computerPoint2] = 'A';
					computerSetUp[computerPoint1][computerPoint2 + 1] = 'A';
					enemyPatrol[0] = computerShipDirection;
					enemyPatrol[1] = computerPoint1;
					enemyPatrol[2] = computerPoint2;
					enemyPatrol[3] = computerPoint2 + 1;
				}

			
		}
		else{											//vertical
			computerPoint1 = rand() % 9;
			computerPoint2 = rand() % 10;
			for (int z = computerPoint1; z < computerPoint1 + 1; z++){
				if (computerSetUp[z][computerPoint2] == 'O'){
					overLapCheck = 1;
				}
				else{
					overLapCheck = 2;
					break;
				}
			}
				if (overLapCheck == 1){
					computerSetUp[computerPoint1][computerPoint2] = 'A';
					computerSetUp[computerPoint1 + 1][computerPoint2] = 'A';
					enemyPatrol[0] = computerShipDirection;
					enemyPatrol[1] = computerPoint2;
					enemyPatrol[2] = computerPoint1;
					enemyPatrol[3] = computerPoint1 + 1;
				}
			
		}
	} while (overLapCheck == 2);
}
//This function displays a scoreboard and displays ships that are alive or have been destroyed
void displayScoreBoard(HANDLE screen, char playerBoard[][COLS], char enemyBoard[][COLS], int rows, int enemyCarrier[], int enemyBattleShip[], int enemyCruiser[], int enemySubmarine[], int enemyPatrol[], int& enemyCarrierAlive, int& enemyBattleShipAlive, int& enemyCruiserAlive, int& enemySubmarineAlive, int& enemyPatrolAlive, int& playerCarrierAlive, int& playerBattleShipAlive, int& playerCruiserAlive, int& playerSubmarineAlive, int& playerPatrolAlive, int playerCarrier[], int playerBattleShip[], int playerCruiser[], int playerSubmarine[], int playerPatrol[]){
	
	int size;
	int alive;

	placeCursor(screen, 0, 38);
	cout << "-----Scoreboard-----" << endl;	//1 = horizontal 2 = vertical
											//Enemy Ships
	placeCursor(screen, 2, 30);
	cout << "Enemy Ships Left: " << endl;
	placeCursor(screen, 3, 30);
	size = 7;
	alive = shipCheck(enemyBoard, ROWS, enemyCarrier, size);
	if (alive == 1){
		cout << "Carrier " << endl;
		enemyCarrierAlive = 1;
	}
	else{
		cout << "Carrier Destroyed!" << endl;
		enemyCarrierAlive = 0;
	}
	placeCursor(screen, 4, 30);
	size = 6;
	alive = shipCheck(enemyBoard, ROWS, enemyBattleShip, size);
	if (alive == 1){
		cout << "Battle Ship " << endl;
		enemyBattleShipAlive = 1;
	}
	else{
		cout << "Battle Ship Destroyed!" << endl;
		enemyBattleShipAlive = 0;
	}
	placeCursor(screen, 5, 30);
	size = 5;
	alive = shipCheck(enemyBoard, ROWS, enemyCruiser, size);
	if (alive == 1){
		cout << "Cruiser " << endl;
		enemyCruiserAlive = 1;
	}
	else{
		cout << "Cruiser Destroyed!" << endl;
		enemyCruiserAlive = 0;
	}
	placeCursor(screen, 6, 30);
	size = 5;
	alive = shipCheck(enemyBoard, ROWS, enemySubmarine, size);
	if (alive == 1){
		cout << "Submarine " << endl;
		enemySubmarineAlive = 1;
	}
	else{
		cout << "Submarine Destroyed!" << endl;
		enemySubmarineAlive = 0;
	}
	placeCursor(screen, 7, 30);
	size = 4;
	alive = shipCheck(enemyBoard, ROWS, enemyPatrol, size);
	if (alive == 1){
		cout << "Patrol " << endl;
		enemyPatrolAlive = 1;
	}
	else{
		cout << "Patrol Destroyed!" << endl;
		enemyPatrolAlive = 0;
	}
											//Player Ships
	placeCursor(screen, 2, 53);
	cout << "Your Ships Left:" << endl;
	placeCursor(screen, 3, 53);
	size = 7;
	alive = shipCheck(playerBoard, ROWS, playerCarrier, size);
	if (alive == 1){
		cout << "Carrier" << endl;
		playerCarrierAlive = 1;
	}
	else{
		cout << "Carrier Destroyed!" << endl;
		playerCarrierAlive = 0;
	}
	placeCursor(screen, 4, 53);
	size = 6;
	alive = shipCheck(playerBoard, ROWS, playerBattleShip, size);
	if (alive == 1){
		cout << "Battle Ship" << endl;
		playerBattleShipAlive = 1;
	}
	else{
		cout << "Battle Ship Destroyed!" << endl;
		playerBattleShipAlive = 0;
	}
	placeCursor(screen, 5, 53);
	size = 5;
	alive = shipCheck(playerBoard, ROWS, playerCruiser, size);
	if (alive == 1){
		cout << "Cruiser" << endl;
		playerCruiserAlive = 1;
	}
	else{
		cout << "Cruiser Destroyed!" << endl;
		playerCruiserAlive = 0;
	}
	placeCursor(screen, 6, 53);
	size = 5;
	alive = shipCheck(playerBoard, ROWS, playerSubmarine, size);
	if (alive == 1){
		cout << "Submarine" << endl;
		playerSubmarineAlive = 1;
	}
	else{
		cout << "Submarine Destroyed!" << endl;
		playerSubmarineAlive = 0;
	}
	placeCursor(screen, 7, 53);
	size = 4;
	alive = shipCheck(playerBoard, ROWS, playerPatrol, size);
	if (alive == 1){
		cout << "Patrol" << endl;
		playerPatrolAlive = 1;
	}
	else{
		cout << "Patrol Destroyed!" << endl;
		playerPatrolAlive = 0;
	}
}
//This function places the cursor on the screen in a specific location
void placeCursor(HANDLE screen, int row, int col){
	COORD position;
	position.Y = row;
	position.X = col;
	SetConsoleCursorPosition(screen, position);
}
//This function lets the player shoot at a point
void playerTurn(HANDLE screen, char enemyMap[][COLS], char enemyDisplayMap[][COLS], int rows) {
	char v;
	string attack;
	int attack1, attack2, errorCount = 0;
	char holder;
	placeCursor(screen, 15, 30);
	cout << "Choose which point you would like to attack." << endl;
	do{
		if (errorCount > 0){
			placeCursor(screen, 17, 51);
			cout << "                       " << endl;
		}
		placeCursor(screen, 16, 30);
		cout << "Please type the letter first followed by" << endl;
		placeCursor(screen, 17, 30);
		cout << "the number(e.g. a6): ";
		cin.ignore();
		cin >> attack;
		errorCount++;
	} while (!(attack == "a0" || attack == "a1" || attack == "a2" || attack == "a3" || attack == "a4" || attack == "a5" || attack == "a6" || attack == "a7" || attack == "a8" || attack == "a9" || attack == "b0" || attack == "b1" || attack == "b2" || attack == "b3" || attack == "b4" || attack == "b5" || attack == "b6" || attack == "b7" || attack == "b8" || attack == "b9" || attack == "c0" || attack == "c1" || attack == "c2" || attack == "c3" || attack == "c4" || attack == "c5" || attack == "c6" || attack == "c7" || attack == "c8" || attack == "c9" || attack == "d0" || attack == "d1" || attack == "d2" || attack == "d3" || attack == "d4" || attack == "d5" || attack == "d6" || attack == "d7" || attack == "d8" || attack == "d9" || attack == "e0" || attack == "e1" || attack == "e2" || attack == "e3" || attack == "e4" || attack == "e5" || attack == "e6" || attack == "e7" || attack == "e8" || attack == "e9" || attack == "f0" || attack == "f1" || attack == "f2" || attack == "f3" || attack == "f4" || attack == "f5" || attack == "f6" || attack == "f7" || attack == "f8" || attack == "f9" || attack == "g0" || attack == "g1" || attack == "g2" || attack == "g3" || attack == "g4" || attack == "g5" || attack == "g6" || attack == "g7" || attack == "g8" || attack == "g9" || attack == "h0" || attack == "h1" || attack == "h2" || attack == "h3" || attack == "h4" || attack == "h5" || attack == "h6" || attack == "h7" || attack == "h8" || attack == "h9" || attack == "i0" || attack == "i1" || attack == "i2" || attack == "i3" || attack == "i4" || attack == "i5" || attack == "i6" || attack == "i7" || attack == "i8" || attack == "i9" || attack == "j0" || attack == "j1" || attack == "j2" || attack == "j3" || attack == "j4" || attack == "j5" || attack == "j6" || attack == "j7" || attack == "j8" || attack == "j9"));

	if (attack == "a0"){
		attack1 = 0;
		attack2 = 0;
	}
	if (attack == "a1"){
		attack1 = 0;
		attack2 = 1;
	}
	if (attack == "a2"){
		attack1 = 0;
		attack2 = 2;
	}
	if (attack == "a3"){
		attack1 = 0;
		attack2 = 3;
	}
	if (attack == "a4"){
		attack1 = 0;
		attack2 = 4;
	}
	if (attack == "a5"){
		attack1 = 0;
		attack2 = 5;
	}
	if (attack == "a6"){
		attack1 = 0;
		attack2 = 6;
	}
	if (attack == "a7"){
		attack1 = 0;
		attack2 = 7;
	}
	if (attack == "a8"){
		attack1 = 0;
		attack2 = 8;
	}
	if (attack == "a9"){
		attack1 = 0;
		attack2 = 9;
	}
	if (attack == "b0"){
		attack1 = 1;
		attack2 = 0;
	}
	if (attack == "b1"){
		attack1 = 1;
		attack2 = 1;
	}
	if (attack == "b2"){
		attack1 = 1;
		attack2 = 2;
	}
	if (attack == "b3"){
		attack1 = 1;
		attack2 = 3;
	}
	if (attack == "b4"){
		attack1 = 1;
		attack2 = 4;
	}
	if (attack == "b5"){
		attack1 = 1;
		attack2 = 5;
	}
	if (attack == "b6"){
		attack1 = 1;
		attack2 = 6;
	}
	if (attack == "b7"){
		attack1 = 1;
		attack2 = 7;
	}
	if (attack == "b8"){
		attack1 = 1;
		attack2 = 8;
	}
	if (attack == "b9"){
		attack1 = 1;
		attack2 = 9;
	}
	if (attack == "c0"){
		attack1 = 2;
		attack2 = 0;
	}
	if (attack == "c1"){
		attack1 = 2;
		attack2 = 1;
	}
	if (attack == "c2"){
		attack1 = 2;
		attack2 = 2;
	}
	if (attack == "c3"){
		attack1 = 2;
		attack2 = 3;
	}
	if (attack == "c4"){
		attack1 = 2;
		attack2 = 4;
	}
	if (attack == "c5"){
		attack1 = 2;
		attack2 = 5;
	}
	if (attack == "c6"){
		attack1 = 2;
		attack2 = 6;
	}
	if (attack == "c7"){
		attack1 = 2;
		attack2 = 7;
	}
	if (attack == "c8"){
		attack1 = 2;
		attack2 = 8;
	}
	if (attack == "c9"){
		attack1 = 2;
		attack2 = 9;
	}
	if (attack == "d0"){
		attack1 = 3;
		attack2 = 0;
	}
	if (attack == "d1"){
		attack1 = 3;
		attack2 = 1;
	}
	if (attack == "d2"){
		attack1 = 3;
		attack2 = 2;
	}
	if (attack == "d3"){
		attack1 = 3;
		attack2 = 3;
	}
	if (attack == "d4"){
		attack1 = 3;
		attack2 = 4;
	}
	if (attack == "d5"){
		attack1 = 3;
		attack2 = 5;
	}
	if (attack == "d6"){
		attack1 = 3;
		attack2 = 6;
	}
	if (attack == "d7"){
		attack1 = 3;
		attack2 = 7;
	}
	if (attack == "d8"){
		attack1 = 3;
		attack2 = 8;
	}
	if (attack == "d9"){
		attack1 = 3;
		attack2 = 9;
	}
	if (attack == "e0"){
		attack1 = 4;
		attack2 = 0;
	}
	if (attack == "e1"){
		attack1 = 4;
		attack2 = 1;
	}
	if (attack == "e2"){
		attack1 = 4;
		attack2 = 2;
	}
	if (attack == "e3"){
		attack1 = 4;
		attack2 = 3;
	}
	if (attack == "e4"){
		attack1 = 4;
		attack2 = 4;
	}
	if (attack == "e5"){
		attack1 = 4;
		attack2 = 5;
	}
	if (attack == "e6"){
		attack1 = 4;
		attack2 = 6;
	}
	if (attack == "e7"){
		attack1 = 4;
		attack2 = 7;
	}
	if (attack == "e8"){
		attack1 = 4;
		attack2 = 8;
	}
	if (attack == "e9"){
		attack1 = 4;
		attack2 = 9;
	}
	if(attack == "f0"){
		attack1 = 5;
		attack2 = 0;
	}
	if (attack == "f1"){
		attack1 = 5;
		attack2 = 1;
	}
	if (attack == "f2"){
		attack1 = 5;
		attack2 = 2;
	}
	if (attack == "f3"){
		attack1 = 5;
		attack2 = 3;
	}
	if (attack == "f4"){
		attack1 = 5;
		attack2 = 4;
	}
	if (attack == "f5"){
		attack1 = 5;
		attack2 = 5;
	}
	if (attack == "f6"){
		attack1 = 5;
		attack2 = 6;
	}
	if (attack == "f7"){
		attack1 = 5;
		attack2 = 7;
	}
	if (attack == "f8"){
		attack1 = 5;
		attack2 = 8;
	}
	if (attack == "f9"){
		attack1 = 5;
		attack2 = 9;
	}
	if (attack == "g0"){
		attack1 = 6;
		attack2 = 0;
	}
	if (attack == "g1"){
		attack1 = 6;
		attack2 = 1;
	}
	if (attack == "g2"){
		attack1 = 6;
		attack2 = 2;
	}
	if (attack == "g3"){
		attack1 = 6;
		attack2 = 3;
	}
	if (attack == "g4"){
		attack1 = 6;
		attack2 = 4;
	}
	if (attack == "g5"){
		attack1 = 6;
		attack2 = 5;
	}
	if (attack == "g6"){
		attack1 = 6;
		attack2 = 6;
	}
	if (attack == "g7"){
		attack1 = 6;
		attack2 = 7;
	}
	if (attack == "g8"){
		attack1 = 6;
		attack2 = 8;
	}
	if (attack == "g9"){
		attack1 = 6;
		attack2 = 9;
	}
	if(attack == "h0"){
		attack1 = 7;
		attack2 = 0;
	}
	if (attack == "h1"){
		attack1 = 7;
		attack2 = 1;
	}
	if (attack == "h2"){
		attack1 = 7;
		attack2 = 2;
	}
	if (attack == "h3"){
		attack1 = 7;
		attack2 = 3;
	}
	if (attack == "h4"){
		attack1 = 7;
		attack2 = 4;
	}
	if (attack == "h5"){
		attack1 = 7;
		attack2 = 5;
	}
	if (attack == "h6"){
		attack1 = 7;
		attack2 = 6;
	}
	if (attack == "h7"){
		attack1 = 7;
		attack2 = 7;
	}
	if (attack == "h8"){
		attack1 = 7;
		attack2 = 8;
	}
	if (attack == "h9"){
		attack1 = 7;
		attack2 = 9;
	}
	if (attack == "i0"){
		attack1 = 8;
		attack2 = 0;
	}
	if (attack == "i1"){
		attack1 = 8;
		attack2 = 1;
	}
	if (attack == "i2"){
		attack1 = 8;
		attack2 = 2;
	}
	if (attack == "i3"){
		attack1 = 8;
		attack2 = 3;
	}
	if (attack == "i4"){
		attack1 = 8;
		attack2 = 4;
	}
	if (attack == "i5"){
		attack1 = 8;
		attack2 = 5;
	}
	if (attack == "i6"){
		attack1 = 8;
		attack2 = 6;
	}
	if (attack == "i7"){
		attack1 = 8;
		attack2 = 7;
	}
	if (attack == "i8"){
		attack1 = 8;
		attack2 = 8;
	}
	if (attack == "i9"){
		attack1 = 8;
		attack2 = 9;
	}
	if(attack == "j0"){
		attack1 = 9;
		attack2 = 0;
	}
	if (attack == "j1"){
		attack1 = 9;
		attack2 = 1;
	}
	if (attack == "j2"){
		attack1 = 9;
		attack2 = 2;
	}
	if (attack == "j3"){
		attack1 = 9;
		attack2 = 3;
	}
	if (attack == "j4"){
		attack1 = 9;
		attack2 = 4;
	}
	if (attack == "j5"){
		attack1 = 9;
		attack2 = 5;
	}
	if (attack == "j6"){
		attack1 = 9;
		attack2 = 6;
	}
	if (attack == "j7"){
		attack1 = 9;
		attack2 = 7;
	}
	if (attack == "j8"){
		attack1 = 9;
		attack2 = 8;
	}
	if (attack == "j9"){
		attack1 = 9;
		attack2 = 9;
	}

	/*v = cin.get();
	attack1 = letterVal(v);
	cin >> attackCheck;
	attack2 = numValidation(attackCheck);*/
	holder = enemyMap[attack1][attack2];
	while (holder == 'M' || holder == 'X'){
		placeCursor(screen, 20, 30);
		cout << "You already attacked there!" << endl;
		placeCursor(screen, 21, 30);
		cout << "Please type the letter first: ";
		cin >> v;
		attack1 = letterVal(v);
		placeCursor(screen, 22, 30);
		cout << "Now type in the number: ";
		cin >> attack2;
		holder = enemyMap[attack1][attack2];
	}
	if (holder == 'A'){
		enemyMap[attack1][attack2] = 'X';
		enemyDisplayMap[attack1][attack2] = 'X';
		system("CLS");
		placeCursor(screen, 23, 30);
		cout << "Direct hit!" << endl;
	}
	else{
		enemyMap[attack1][attack2] = 'M';
		enemyDisplayMap[attack1][attack2] = 'M';
		system("CLS");
		placeCursor(screen, 23, 30);
		cout << "You missed!" << endl;
	}
}
//This function lets the computer shoot at a point
void enemyTurn(HANDLE screen, char playerMap[][COLS], int rows, int difficulty){
	//AI												functions that lets the computer have its turn
	srand(time(0));
	//Computer(Medium);
	static char computerLastAttack1, computerLastAttack2, computerMemory = 'O';
	int computerAttack1, computerAttack2, computerNewAttack1, computerNewAttack2;
	char computerHolder;
	if (difficulty == 2){
		if (computerMemory == 'O'){
			computerAttack1 = rand() % 10;
			computerAttack2 = rand() % 10;
			computerHolder = playerMap[computerAttack1][computerAttack2];
			while (computerHolder == 'M' || computerHolder == 'X'){
				computerAttack1 = rand() % 10;
				computerAttack2 = rand() % 10;
				computerHolder = playerMap[computerAttack1][computerAttack2];
			}
			if (computerHolder == 'A'){
				playerMap[computerAttack1][computerAttack2] = 'X';
				placeCursor(screen, 24, 30);
				cout << "Computer(Medium) got a Direct hit!" << endl;
			}
			else{
				playerMap[computerAttack1][computerAttack2] = 'M';
				placeCursor(screen, 24, 30);
				cout << "Computer(Medium) missed!" << endl;
			}
			computerLastAttack1 = computerAttack1;
			computerLastAttack2 = computerAttack2;
			computerMemory = computerHolder;
		}
		//Computer Logic
		else{
			//Top Left Corner
			if (computerLastAttack1 == 0 && computerLastAttack2 == 0){
				computerNewAttack1 = computerLastAttack1;
				computerNewAttack2 = computerLastAttack2 + 1;
				computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				if (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = computerLastAttack1 + 1;
					computerNewAttack2 = computerLastAttack2 - 1;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				while (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = rand() % 10;
					computerNewAttack2 = rand() % 10;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				if (computerHolder == 'A'){
					playerMap[computerNewAttack1][computerNewAttack2] = 'X';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) got a Direct hit!" << endl;
				}
				else{
					playerMap[computerNewAttack1][computerNewAttack2] = 'M';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) missed!" << endl;
				}
			}
			//Bottom Right Corner
			else if (computerLastAttack1 == 9 && computerLastAttack2 == 9){
				computerNewAttack1 = computerLastAttack1;
				computerNewAttack2 = computerLastAttack2 - 1;
				computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				if (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = computerLastAttack1 - 1;
					computerNewAttack2 = computerLastAttack2 + 1;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				while (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = rand() % 10;
					computerNewAttack2 = rand() % 10;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				if (computerHolder == 'A'){
					playerMap[computerNewAttack1][computerNewAttack2] = 'X';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) got a Direct hit!" << endl;
				}
				else{
					playerMap[computerNewAttack1][computerNewAttack2] = 'M';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) missed!" << endl;
				}
			}
			//Top Right Corner
			else if (computerLastAttack1 == 0 && computerLastAttack2 == 9){
				computerNewAttack1 = computerLastAttack1;
				computerNewAttack2 = computerLastAttack2 - 1;
				computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				if (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = computerLastAttack1 + 1;
					computerNewAttack2 = computerLastAttack2 + 1;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				while (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = rand() % 10;
					computerNewAttack2 = rand() % 10;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				if (computerHolder == 'A'){
					playerMap[computerNewAttack1][computerNewAttack2] = 'X';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) got a Direct hit!" << endl;
				}
				else{
					playerMap[computerNewAttack1][computerNewAttack2] = 'M';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) missed!" << endl;
				}
			}
			//Bottom Left Corner
			else if (computerLastAttack1 == 9 && computerLastAttack2 == 0){
				computerNewAttack1 = computerLastAttack1;
				computerNewAttack2 = computerLastAttack2 + 1;
				computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				if (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = computerLastAttack1 - 1;
					computerNewAttack2 = computerLastAttack2 - 1;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				while (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = rand() % 10;
					computerNewAttack2 = rand() % 10;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				if (computerHolder == 'A'){
					playerMap[computerNewAttack1][computerNewAttack2] = 'X';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) got a Direct hit!" << endl;
				}
				else{
					playerMap[computerNewAttack1][computerNewAttack2] = 'M';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) missed!" << endl;
				}
			}
			//Top Wall
			else if (computerLastAttack1 == 0){
				if (computerLastAttack2 == 9){
					computerNewAttack1 = computerLastAttack1;
					computerNewAttack2 = computerLastAttack2 - 1;
				}
				else{
					computerNewAttack1 = computerLastAttack1;
					computerNewAttack2 = computerLastAttack2 + 1;
				}
				computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				if (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = computerLastAttack1 + 1;
					computerNewAttack2 = computerLastAttack2;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				while (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = rand() % 10;
					computerNewAttack2 = rand() % 10;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				if (computerHolder == 'A'){
					playerMap[computerNewAttack1][computerNewAttack2] = 'X';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) got a Direct hit!" << endl;
				}
				else{
					playerMap[computerNewAttack1][computerNewAttack2] = 'M';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) missed!" << endl;
				}
			}
			//Left Wall
			else if (computerLastAttack2 == 0){
				if (computerLastAttack1 == 9){
					computerNewAttack1 = computerLastAttack1 - 1;
					computerNewAttack2 = computerLastAttack2;
				}
				else{
					computerNewAttack1 = computerLastAttack1 + 1;
					computerNewAttack2 = computerLastAttack2;
				}
				computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				if (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = computerLastAttack1;
					computerNewAttack2 = computerLastAttack2 + 1;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				while (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = rand() % 10;
					computerNewAttack2 = rand() % 10;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				if (computerHolder == 'A'){
					playerMap[computerNewAttack1][computerNewAttack2] = 'X';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) got a Direct hit!" << endl;
				}
				else{
					playerMap[computerNewAttack1][computerNewAttack2] = 'M';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) missed!" << endl;
				}
			}
			//Right Wall
			else if (computerLastAttack2 == 9){
				if (computerLastAttack1 == 8){
					computerNewAttack1 = computerLastAttack1 - 1;
					computerNewAttack2 = computerLastAttack2;
				}
				else{
					computerNewAttack1 = computerLastAttack1 + 1;
					computerNewAttack2 = computerLastAttack2;
				}
				computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				if (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = computerLastAttack1;
					computerNewAttack2 = computerLastAttack2 - 1;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				while (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = rand() % 10;
					computerNewAttack2 = rand() % 10;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				if (computerHolder == 'A'){
					playerMap[computerNewAttack1][computerNewAttack2] = 'X';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) got a Direct hit!" << endl;
				}
				else{
					playerMap[computerNewAttack1][computerNewAttack2] = 'M';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) missed!" << endl;
				}
			}
			//Bottom Wall
			else if (computerLastAttack1 == 9){
				if (computerLastAttack2 == 8){
					computerNewAttack1 = computerLastAttack1;
					computerNewAttack2 = computerLastAttack2 - 1;
				}
				else{
					computerNewAttack1 = computerLastAttack1;
					computerNewAttack2 = computerLastAttack2 + 1;
				}
				computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				if (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = computerLastAttack1 - 1;
					computerNewAttack2 = computerLastAttack2;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				while (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = rand() % 10;
					computerNewAttack2 = rand() % 10;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				if (computerHolder == 'A'){
					playerMap[computerNewAttack1][computerNewAttack2] = 'X';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) got a Direct hit!" << endl;
				}
				else{
					playerMap[computerNewAttack1][computerNewAttack2] = 'M';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) missed!" << endl;
				}
			}
			//anywhere else on map
			else{
				computerNewAttack1 = computerLastAttack1;
				computerNewAttack2 = computerLastAttack2 + 1;
				computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				if (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = computerLastAttack1;
					computerNewAttack2 = computerLastAttack2 - 1;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				else if (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = computerLastAttack1 - 1;
					computerNewAttack2 = computerLastAttack2;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				else if (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = computerLastAttack1 + 1;
					computerNewAttack2 = computerLastAttack2;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				while (computerHolder == 'M' || computerHolder == 'X'){
					computerNewAttack1 = rand() % 10;
					computerNewAttack2 = rand() % 10;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				if (computerHolder == 'A'){
					playerMap[computerNewAttack1][computerNewAttack2] = 'X';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) got a Direct hit!" << endl;
				}
				else{
					playerMap[computerNewAttack1][computerNewAttack2] = 'M';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) missed!" << endl;
				}

			}
		}
	}
	//Computer(Easy);
	else{
		computerAttack1 = rand() % 10;
		computerAttack2 = rand() % 10;
		computerHolder = playerMap[computerAttack1][computerAttack2];
		while (computerHolder == 'M' || computerHolder == 'X'){
			computerAttack1 = rand() % 10;
			computerAttack2 = rand() % 10;
			computerHolder = playerMap[computerAttack1][computerAttack2];
		}
		if (computerHolder == 'A'){
			playerMap[computerAttack1][computerAttack2] = 'X';
			placeCursor(screen, 24, 30);
			cout << "Computer(Easy) got a Direct hit!" << endl;
		}
		else{
			playerMap[computerAttack1][computerAttack2] = 'M';
			placeCursor(screen, 24, 30);
			cout << "Computer(Easy) missed!" << endl;
		}
	}

}
//This function checks if there are any ships left
int winCondition(int enemy, int player){

	if (enemy == 0){
		return 2;
	}
	else if (player == 0){
		return 3;
	}
	else{
		return 1;
	}
}
//This function checks if the letter entered by the user is valid
int letterVal(char c){
	int attack;
	if (!(c == 'A' || c == 'a' || c == 'B' || c == 'b' || c == 'C' || c == 'c' || c == 'D' || c == 'd' || c == 'E' || c == 'e' || c == 'F' || c == 'f' || c == 'G' || c == 'g' || c == 'H' || c == 'h' || c == 'I' || c == 'i' || c == 'J' || c == 'j')){
		do
		{
			cin.clear();
			cout << "Invalid input, please enter a letter that is from A-J: ";
			cin.get(c);
		} while (!(c == 'A' || c == 'a' || c == 'B' || c == 'b' || c == 'C' || c == 'c' || c == 'D' || c == 'd' || c == 'E' || c == 'e' || c == 'F' || c == 'f' || c == 'G' || c == 'g' || c == 'H' || c == 'h' || c == 'I' || c == 'i' || c == 'J' || c == 'j'));
	}
	if (c == 'A' || c == 'a')
		attack = 0;
	else if (c == 'B' || c == 'b')
		attack = 1;
	else if (c == 'C' || c == 'c')
		attack = 2;
	else if (c == 'D' || c == 'd')
		attack = 3;
	else if (c == 'E' || c == 'e')
		attack = 4;
	else if (c == 'F' || c == 'f')
		attack = 5;
	else if (c == 'G' || c == 'g')
		attack = 6;
	else if (c == 'H' || c == 'h')
		attack = 7;
	else if (c == 'I' || c == 'i')
		attack = 8;
	else if (c == 'J' || c == 'j')
		attack = 9;
	return attack;
}
//This function checks if the number entered by the user is valid
int numValidation(int z){
	if (cin.fail() || z < 0 || z > 9){
		do{
			cin.clear();
			cout << "Invalid input. Please enter a number 0-9: ";
			cin >> z;
		} while (cin.fail());
	}
	return z;
}
//This function checks which ships are alive or dead when called
int shipCheck(char board[][COLS], int rows, int ship[], int size){
	
	int holder;

	if (ship[0] == 1){
		for (int x = 2; x < size; x++){		
			if(board[ship[1]][ship[x]] == 'A'){
				holder = 1;
				break;
			}
			else{
				holder = 2;
			}
		}
	}
	else{
		for (int x = 2; x < size; x++){
			if (board[ship[x]][ship[1]] == 'A'){
				holder = 1;
				break;
			}
			else{
				holder = 2;
			}
		}
	}
	return holder;
}