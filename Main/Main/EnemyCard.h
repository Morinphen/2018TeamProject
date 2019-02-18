#pragma once
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�f�b�L
class CObjEnemyCard :public CObj
{
public:
	CObjEnemyCard(float x, float y);
	~CObjEnemyCard() {};
	void Init();
	void Action();
	void Draw();

private:
	int m_x, m_y;
	int Setcard;
	int Number;
	int Number2;
	int Number3;
	int Posicard;
	int Reset;
	int playertrun;
	int enemytrun;

	int Hp;//�J�[�h��hp
	int Atack;//�J�[�h�̍U����
	int Guard;//�J�[�h�̖h���
	int Hp2;//�J�[�h�̌��X��hp
	int Atack2;//�J�[�h�̌��X�̍U����
	int Guard2;//�J�[�h�̌��X�̖h���
	int Ccost;//�J�[�h�̃R�X�g

	int Tlong;

	bool CardHitCheck;//�}�E�X���J�[�h�ƐG��Ă��邩�Q�Ƃ���ϐ�

	int Shand;

	int Opdraw;
	int Updraw;
	int Rotdraw;

	bool m_r;
	bool Summon;
	bool m_f;
	bool Reflag;

	bool L_position;
	bool S_position;
	bool R_position;

	int Type;//�J�[�h�̎�ށ@1=�L����,2=����,3=�h��
};