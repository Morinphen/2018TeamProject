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

	int e_point;
	int e_Cost;
	bool Turn;
	bool StartG;//�Q�[���J�n�p�ϐ�

	bool StartED;//��s�����̕ϐ�

	int i;

	int set;
	int Recount;
private:
	int x, y;
	int m_x, m_y;
	int Ctype;//�J�[�h�̎��

	int e_Cardcount;
	int stop;
	int Data;//�f�b�L�ɓo�^����J�[�h�f�[�^
	int e_Deckcount; //�f�b�L�̎c�薇�����Q�Ƃ���ϐ�
	int Rotdraw;

	int ETruntime;

	bool m_f;
	bool Start;
};