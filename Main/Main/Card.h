#pragma once
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�f�b�L
class CObjCard :public CObj
{
public:
	CObjCard(float x,float y,int z);
	~CObjCard() {};
	void Init();
	void Action();
	void Draw();

	bool Punch;//�����X�^�[�̍U������
	bool Set;//����̑�������

private:
	int m_x, m_y;//�J�[�h�̕`��ʒu
	int Setcard;//�J�[�h�̏ꏊ
	int Posicard;//�J�[�h�̏ꏊ�Q
	int Number;//���Ԃ̌Œ�
	int Number2;//��D�̃J�[�h�ԍ�
	int Number3;//�J�[�h�̏��Ԕԍ�
	int Number4;//�J�[�h���ԍ�
	int playertrun;
	int enemytrun;

	int Hp;//�J�[�h��hp
	int Atack;//�J�[�h�̍U����
	int Guard;//�J�[�h�̖h���

	//�J�[�h�e�L�X�g�̕\��
	char *Name;
	char *Text;
	char name[256];
	char text[256];
	char text2[5][64];
	int Tlong;

	//�_�~�[�f�[�^
	int aaaa;
	int Nlist;

	int Type;//�J�[�h�̎�ށ@1=�L����,2=����,3=�h��

	bool CardHitCheck;//�}�E�X���J�[�h�ƐG��Ă��邩�Q�Ƃ���ϐ�
	int Opdraw;//�J�[�h�̐؎��ʒu�P
	int Updraw;//�J�[�h�̐؎��ʒu�Q
	int Rotdraw;//�J�[�h�̊p�x����

	//����̈ʒu��ۑ�
	bool LWeapon;
	bool RWeapon;

	//�����X�^�[�̈ʒu��ۑ�
	bool FSummon;
	bool FSummon2;

	bool m_r;
	bool Summon;//�J�[�h���������ꂽ���ǂ���
	bool StopSm;//�J�[�h�̏�������p
	bool m_f;
	bool m_l;

	int test;

	bool L_position;

	bool S_position;
	bool S_position2;

	bool R_position;

	//�R�X�g����U�ۑ�
	int m_kos;
};