#include <iostream>
#include"Shoe.h"
#include"Card.h"
#include"Player.h"
using namespace std;

const char* mountName[Color_NUM] = { "red", "blue", "Yellow", "green","wild" };
void Shoe::InitShoe()
{
	

	// �J�[�h������
	for (int i = 0; i < CARD_NUM; ++i)
	{
		_card[i].SetNum(i % 13);	//�O�`�P�Q�ŏ�����
		_card[i].SetSuit(i % Color_NUM);	//�O�`4�ŏ�����
	}

	// �V���b�t��
	_Shuffle();
}
Shoe::Shoe()
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
	int DColor = DiscardNam % Color_NUM;
	int color = cardNam % Color_NUM;
	int selectcolor=0;
	if (DColor == color||DiscardNam%13==cardNam%13) {
		cout << "�J�[�h���̂Ă܂���" << endl;
		DiscardNam = cardNam;
	}
	else if (color == 4) {
		cout << "���̐F�����߂Ă�������" << endl
			<<"1:�ԁ@2:�@3:���@4:��"<<flush;
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
		cout << "���̃J�[�h���̂Ă邱�Ƃ͂ł��܂���I" << endl;
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
	cout << "�̂ĎD�̈�ԏ�" << endl;
	ShwCard(DiscardNam);
	cout << "====================" << endl;

}
