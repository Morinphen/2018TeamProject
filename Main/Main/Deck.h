#pragma once

#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�f�b�L
class CObjDekc :public CObj
{
public:
	CObjDekc() {};
	~CObjDekc() {};
	void Init();
	void Action();
	void Draw();

	int cardcou;
	int Card;
private:
	int x, y;
	int m_x, m_y;

	int Cardcount;
	int stop;
	int Deck[40];
	int tehuda[40];

	bool m_f;
	bool Start;
};