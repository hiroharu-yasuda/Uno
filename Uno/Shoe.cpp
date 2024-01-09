#include <iostream>
#include"Shoe.h"
#include"Card.h"
#include"Player.h"
using namespace std;
void Shoe::InitShoe()
{
	

	// �J�[�h������
	for (int i = 0; i < CARD_NUM; ++i)
	{
		_card[i].SetNum(i % 13);	//�O�`�P�Q�ŏ�����
		_card[i].SetSuit(i % 5);	//�O�`4�ŏ�����
	}

	// �V���b�t��
	_Shuffle();
}Shoe::Shoe()
{
	InitShoe();

	// �J�[�h����������
	_cardNum = CARD_NUM;
}

// �f�X�g���N�^
Shoe::~Shoe()
{

}

// �J�[�h���P�����
Card Shoe::TakeCard()
{
	// �J�[�h�̎c�薇�����O��������R�D��������
	if (_cardNum <= 0)
	{
		InitShoe();
		_cardNum = CARD_NUM;
	}

	// �R�D�̌�납������Ă���
	--_cardNum;
	Card card = _card[_cardNum];

	// �f�o�b�O�p
	// �������J�[�h�Ɂ|�P������
	_card[_cardNum].SetNum(-1);
	_card[_cardNum].SetSuit(-1);

	return card;
}

//�V���b�t���i�t�B�b�V���[�C�F�[�c�j
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
	int DColor = DiscardPile[DiscardNam] % 5;
	int color = cardNam % 5;
	if (DColor == color) {
		
	}
	else if (color == 4) {

	}
}