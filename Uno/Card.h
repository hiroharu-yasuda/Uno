#pragma once
#include"common.h"
class Card {
public :
	Card();						// �R���X�g���N�^
	virtual ~Card();			// �f�X�g���N�^
	void CheckCard(); 	// �ǂݎ��A��������
	int GetNum() const { return _num; }const
		int GetSuit() const { return _suit; }const
		
	void SetNum(int num)
	{
		_num = num;
	}
	void SetSuit(int suit)
	{
		_suit = suit;
	}
	void ShowCard()const;
	

private:
	int _num;
	int _suit;
};