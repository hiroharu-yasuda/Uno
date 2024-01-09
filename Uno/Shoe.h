#pragma once
#include"Common.h"
#include"Card.h"

class Shoe
{
public:
	void mount();
	void dispose(int cardNam);
	Shoe();					// コンストラクタ
	virtual ~Shoe();		// デストラクタはvirtualをつける
	Card TakeCard();		// カードを１枚返す	
private:
	int DiscardNam = 0;//捨て札の枚数
	Card DiscardPile[CARD_NUM]; //捨て札
	Card _card[CARD_NUM];	// 山札
	int _cardNum;			// カードが何枚残っているか
	void _Shuffle();		// シャッフル
	void InitShoe();		// 山札の初期化
};

