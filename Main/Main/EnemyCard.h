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
	void Cardname();

	int m_x, m_y;
	int Setcard;
	int Number;
	int Number2;
	int Number3;
	int Number4;
	int Posicard;
	int Reset;
	int playertrun;
	int enemytrun;

	bool R_Summon;
	bool L_Summon;

	int aaaa;

	int Hp;//�J�[�h��hp
	int Atack;//�J�[�h�̍U����
	int Guard;//�J�[�h�̖h���
	int Hp2;//�J�[�h�̌��X��hp
	int Atack2;//�J�[�h�̌��X�̍U����
	int Guard2;//�J�[�h�̌��X�̖h���
	int Ccost;//�J�[�h�̃R�X�g

	int Tlong;

	bool CardHitCheck;//�}�E�X���J�[�h�ƐG��Ă��邩�Q�Ƃ���ϐ�

	//�J�[�h�e�L�X�g�̕\��
	char *Name;
	char *Text;
	char text[256];
	int Tlong;

	int TextD;//�e�L�X�g�f�[�^�ۑ��p�ϐ�
	int Ccost;//�J�[�h�̃R�X�g
	int NTcard;//�J�[�h�f�[�^�ԍ�

	int Shand;

	int Opdraw;
	int Updraw;
	int Rotdraw;

	bool m_r;
	bool Summon;
	bool StopSm;
	bool m_f;
	bool Reflag;

	bool L_position;
	bool S_position;
	bool R_position;

	int Type;//�J�[�h�̎�ށ@1=�L����,2=����,3=�h��
};