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
	int Nanber;//�J�[�h�ԍ�
	int Nanber2;//��D�̃J�[�h�ԍ�
	int Nanber3;//�J�[�h�̏��Ԕԍ�
	int playertrun;
	int enemytrun;

	int Hp;//�J�[�h��hp
	int Atack;//�J�[�h�̍U����
	int Guard;//�J�[�h�̖h���

	int Type;//�J�[�h�̎��

	int Opdraw;//�J�[�h�̐؎��ʒu�P
	int Updraw;//�J�[�h�̐؎��ʒu�Q
	int Rotdraw;//�J�[�h�̊p�x����

	bool Punch;

	bool m_r;
	bool Summon;//�J�[�h���������ꂽ���ǂ���
	bool m_f;
	bool m_l;

	int test;

	bool Kstop;

	bool L_position;
	bool L_position2;
	bool L_position3;
	bool S_position;
	bool S_position2;
	bool R_position;
	bool R_position2;
	bool R_position3;
};