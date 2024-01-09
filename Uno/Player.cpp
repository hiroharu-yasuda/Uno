#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include <string>
#include"Card.h"
#include"Player.h"
#include"Shoe.h"
#include"Common.h"
using namespace std;

// コンストラクタ
Player::Player(const char* pName)
{
	// 初期化
	for (int i = 0; i < Hand_NUM; ++i)
	{
		_hand->SetNum(-1);
		_hand->SetSuit(-1);
	}

	_cardNum = 0;

	_pName = new char[strlen(pName) + 1];
	strcpy(_pName, pName);
}


// デストラクタ
Player::~Player()
{
	if (_pName == nullptr)
	{
		delete _pName;
		_pName = nullptr;
	}
}
void Player::DeawCard(Shoe& shoe) {
	Card card = shoe.TakeCard();

	// 正しい情報が渡されていたら
	if (card.GetNum() >= 0)
	{
		// 手札の枚数が20枚以下なら
		if (_cardNum < Hand_NUM)
		{
			//手札に書き込む
			_hand[_cardNum] = card;
			// 手札枚数更新
			++_cardNum;
		}
		else
		{
			printf("手札がいっぱいです\n");
		}
	}
	else
	{
		printf("カードが引けませんでした\n");
	}
}
void Player::ShowHand() {
	//標準出力
	cout << "====================" << endl;

	cout << "hand: " << endl;

	// 手札配列の最初から最後までを順に表示
	for (int i = 1; i < _cardNum+1; ++i)
	{
		cout << i << ":";
		_hand[i].ShowCard();
		cout << endl;

	}
	cout << "====================" << endl;


}
const char* Player::GetName()const
{
	return _pName;
}
//void Player::sort(Shoe& shoe) {
//	int box = 0;
//	for (sortNum = 0; sortNum < _cardNum; sortNum++) {
//
//		int b = 0;
//		/*if (_hand[sortNum] == NULL) {
//			
//				int tempNum = _hand[sortNum].GetNum();
//			_hand[sortNum].SetNum(_hand[b].GetNum());
//			_hand[b].SetNum(tempNum);
//		}*/
//	}
//		
//	}

void Player::Game(Shoe& shoe) {
	int end = 0;
	do
	{
		end = 0;
		cout << "====================" << endl;
		cout << GetName() << endl;
		ShowHand();
		cout << "====================" << endl;
		shoe.mount();
		do
		{
			cout << "何をしますか？" << endl
				<< "1:カードを捨てる";
			if (_draw == false) {
				cout << "2:カードをドローする" << flush;
			}
			else {
				cout << "2:パスする" << flush;
			}
			cin >> select;
		} while (select < 0 && select>3);
		switch (select)
		{
		case 1:
			do
			{
				cout << "====================" << endl;
				ShowHand();

				cout << "====================" << endl;
				cout << ">" << flush;
				cin >> selectCard;
			} while (selectCard > _cardNum);
			//shoe.dispose(_hand[selectCard]);
			//↑これがやりたいのだがやり方がわからない　なんかint型にできないので後で調べる

			break;
		case 2:
			if (_draw == false) {
				DeawCard(shoe);
				_draw = true;
			}
			else if (_draw == true)
			{
				_draw = false;
				end = 1;
			}
			break;
		default:
			break;
		}


	} while (end != 1);

}