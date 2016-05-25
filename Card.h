#ifndef CARD_H
#define CARD_H

class Card
{
private:
	int value;
	int actualValue;
	int suit;				//3 = Hearts, 4 = Diamonds, 5 = Clubs, 6 = Spades

public:
	void setValue(int);
	void setSuit(int);
	void setActualValue();
	int getValue();
	int getActualValue();
	int getSuit();
	void showCard(int, int);
};



#endif