#pragma once

#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�f�b�L
class CObjEnemyDeck :public CObj
{
public:
	CObjEnemyDeck() {};
	~CObjEnemyDeck() {};
	void Init();
	void Action();
	void Draw();

	int EnemyDeck[40];
	int Pullc[40];

	int Cnanber;
	int e_Card;

	bool Summon2;

	bool EDraw;

	bool EStartG;

	int set;
	int Recount;
private:
	int x, y;
	int m_x, m_y;

	int e_Cardcount;
	int stop;
	int Rotdraw;

	int ETruntime;

	int Data;//�f�b�L�ɓo�^����J�[�h�f�[�^

	bool m_f;
	bool Start;
};