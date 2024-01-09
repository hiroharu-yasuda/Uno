#include"Card.h"
#include"Player.h"
#include"common.h"
#include <iostream>
using namespace std;
const char* suitName[Color_NUM] = { "red", "blue", "Yellow", "green","wild"};
Card::Card()
{

	 _num=0;
	_suit=0;
}

Card::~Card()
{

}
void Card::ShowCard()const
{
	cout << suitName[_suit];
	if (_suit == 4) {
		if (_num == 0) {
			cout << "Wild" << endl;
		}
		else if (_num == 1) {
			cout << "Draw4" << endl;
		}
	}
	else if (_num <= 9) {
		cout << _num;
		return;
	}
	else if (_num == 10) {
		cout << "Draw2" << endl;
	}
	else if (_num == 11) {
		cout << "Reverse" << endl;
	}
	else if (_num == 12) {
		cout << "Skip" << endl;
	}
}
void Card::dispose(Shoe& shoe) {

}