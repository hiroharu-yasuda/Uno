#include <iostream>
#include"Shoe.h"
#include"Card.h"
#include"Player.h"
using namespace std;

const char* mountName[Color_NUM] = { "red", "blue", "Yellow", "green","wild" };
void Shoe::InitShoe()
{
	

	// カード初期化
	for (int i = 0; i < CARD_NUM; ++i)
	{
		_card[i].SetNum(i % 13);	//０～１２で初期化
		_card[i].SetSuit(i % Color_NUM);	//０～4で初期化
	}

	// シャッフル
	_Shuffle();
}
Shoe::Shoe()
{
	InitShoe();

	// カード枚数初期化
	_cardNum = CARD_NUM;
}

// デストラクタ
Shoe::~Shoe()
{

}

// カードを１枚取る
Card Shoe::TakeCard()
{
	// カードの残り枚数が０だったら山札を初期化
	if (_cardNum <= 0)
	{
		InitShoe();
		_cardNum = CARD_NUM;
	}

	// 山札の後ろから引いていく
	--_cardNum;
	Card card = _card[_cardNum];

	// デバッグ用
	// 引いたカードに－１を入れる
	_card[_cardNum].SetNum(-1);
	_card[_cardNum].SetSuit(-1);

	return card;
}

//シャッフル（フィッシャーイェーツ）
void Shoe::_Shuffle()
{
	for (int i = CARD_NUM; i > 0; --i) {
		int a = i - 1;
		int b = rand() % i;

		int tempNum = _card[a].GetNum();
		int tempSuit = _card[a].GetSuit();
		_card[a].SetNum(_card[b].GetNum());
		_card[a].SetSuit(_card[b].GetSuit());
		_card[b].SetNum(tempNum);
		_card[b].SetSuit(tempSuit);
	}
}
void Shoe::dispose(int cardNam) {
	int DColor = DiscardNam % Color_NUM;
	int color = cardNam % Color_NUM;
	int selectcolor=0;
	if (DColor == color||DiscardNam%13==cardNam%13) {
		cout << "カードを捨てました" << endl;
		DiscardNam = cardNam;
	}
	else if (color == 4) {
		cout << "次の色を決めてください" << endl
			<<"1:赤　2:青　3:黄　4:緑"<<flush;
		cin >> selectcolor;
		switch (selectcolor)
		{
		case 1:
			DiscardNam = 0;
			break;
		case 2:
			DiscardNam = 1;
			break;
		case 3:
			DiscardNam = 2;
			break;
		case 4:
			DiscardNam = 3;
			break;
		default:
			break;
		}
		
	}
	else {
		cout << "このカードを捨てることはできません！" << endl;
	}
}
void ShwCard(int num)
{
	int _suit = num % Color_NUM;
	int _num = num % 13;
	cout << mountName[_suit];
	if (_suit == 4) {
		if (_num == 0) {
			cout << "Wild" << endl;
		}
		else if (_num == 1) {
			cout << "Draw4" << endl;
		}
	}
	else if (_num <= 9) {
		cout << _num << endl;
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
	return;
}
void Shoe::mount() {
	Card card;
	cout << "====================" << endl;
	cout << "捨て札の一番上" << endl;
	ShwCard(DiscardNam);
	cout << "====================" << endl;

}
