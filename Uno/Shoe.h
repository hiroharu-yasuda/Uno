#pragma once
#include"Common.h"
#include"Card.h"

class Shoe
{
public:
	void mount();
	void dispose(int cardNam);
	Shoe();					// �R���X�g���N�^
	virtual ~Shoe();		// �f�X�g���N�^��virtual������
	Card TakeCard();		// �J�[�h���P���Ԃ�	
private:
	int DiscardNam = 0;//�̂ĎD�̖���
	Card DiscardPile[CARD_NUM]; //�̂ĎD
	Card _card[CARD_NUM];	// �R�D
	int _cardNum;			// �J�[�h�������c���Ă��邩
	void _Shuffle();		// �V���b�t��
	void InitShoe();		// �R�D�̏�����
};

