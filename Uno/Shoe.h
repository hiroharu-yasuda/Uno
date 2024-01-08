#pragma once
#include"Common.h"
#include"Card.h"

class Shoe
{
public:
	Shoe();					// �R���X�g���N�^
	virtual ~Shoe();		// �f�X�g���N�^��virtual������
	Card TakeCard();		// �J�[�h���P���Ԃ�	
private:

	int DiscardPile[CARD_NUM]; //�̂ĎD
	Card _card[CARD_NUM];	// �R�D
	int _cardNum;			// �J�[�h�������c���Ă��邩
	void _Shuffle();		// �V���b�t��
	void InitShoe();		// �R�D�̏�����
};

