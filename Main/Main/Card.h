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

	int SeedHp;//�J�[�h��hp�̃^�l
	int SeedAtack;//�J�[�h�̍U���͂̃^�l
	int SeedGuard;//�J�[�h�̖h��͂̃^�l

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

	bool Punch;//�����X�^�[�̍U������
	bool Set;//����̑�������

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
};