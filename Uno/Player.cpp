#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include"Card.h"
#include"Player.h"
#include"Shoe.h"
#include"Common.h"
using namespace std;

// �R���X�g���N�^
Player::Player(const char* pName)
{
	// ������
	for (int i = 0; i < Hand_NUM; ++i)
	{
		_hand->SetNum(-1);
		_hand->SetSuit(-1);
	}

	_cardNum = 0;

	_pName = new char[strlen(pName) + 1];
	strcpy(_pName, pName);
}


// �f�X�g���N�^
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

	// ��������񂪓n����Ă�����
	if (card.GetNum() >= 0)
	{
		// ��D�̖�����20���ȉ��Ȃ�
		if (_cardNum < Hand_NUM)
		{
			//��D�ɏ�������
			_hand[_cardNum] = card;
			// ��D�����X�V
			++_cardNum;
		}
		else
		{
			printf("��D�������ς��ł�\n");
		}
	}
	else
	{
		printf("�J�[�h�������܂���ł���\n");
	}
}
void Player::ShowHand() {
	//�W���o��
	cout << "hand: " << endl;

	// ��D�z��̍ŏ�����Ō�܂ł����ɕ\��
	for (int i = 1; i < _cardNum+1; ++i)
	{
		cout << i << ":";
		_hand[i].ShowCard();
		cout << endl;

	}

}
const char* Player::GetName()const
{
	return _pName;
}
void Player::sort() {

}
void Player::Game(Shoe& shoe) {
	int end = 0;
	do
	{
		end = 0;
	int select = 0;
	int selectCard = 0;
	cout << "====================" << endl;
	cout << GetName() << endl;
	ShowHand();
	cout << "====================" << endl;
	do
	{
		cout << "�������܂����H" << endl
			<< "1:�J�[�h���̂Ă�";
		if (_draw == false) {
			cout << "2:�J�[�h���h���[����" << flush;
		}
		else {
			cout << "2:�p�X����" << flush;
		}
		cin >> select;
	} while (select<0&&select>3);
	switch (select)
	{case 1:
			cout << "====================" << endl;
			ShowHand();

			cout << "====================" << endl;
			cout << ">" << flush;
			cin >> selectCard;
		break;
	case 2:
		if (_draw == false) {
			DeawCard(shoe);
			_draw = true;
		}
		else if(_draw==true)
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