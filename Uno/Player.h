#pragma once
#include"common.h"
#include"Card.h"
#include"Shoe.h"
class Player {
public:
	bool fin = false;

	void Game(Shoe& shoe);
	void sort(Shoe& shoe);
	void ShowHand();
	void DeawCard(Shoe& shoe);
	Player(const char* pName);
	virtual ~Player(); 
	const char* GetName()const;
private:
	char* _pName;
	Card _hand[Hand_NUM];
	bool _draw = false; 
	int _cardNum;				// èD‚Ì–‡”
};