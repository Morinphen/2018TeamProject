#pragma once
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�f�b�L
class CObjPHero :public CObj
{
public:
	CObjPHero();
	~CObjPHero() {};
	void Init();
	void Action();
	void Draw();

	bool Punch;//�����X�^�[�̍U������
	bool Pusave;
	bool Set;//����̑�������

private:
	bool start;
	int m_x, m_y;//�J�[�h�̕`��ʒu
	int playertrun;
	int enemytrun;

	int Hp;//�J�[�h��hp
	int Atack;//�J�[�h�̍U����
	int Guard;//�J�[�h�̖h���

	bool Button;//�{�^���p�ϐ�
	int BDraw;//�{�^��draw�p�ϐ�

	float Deadt;//�Q�[���I�[�o�[��ʂɈڍs����܂ł̎���
	float inviD;//�摜�̓��ߓx

	//�{�^���p�\���ʒu
	float b_x;
	float b_y;

	int Bat3;

	bool CardHitCheck;//�}�E�X���J�[�h�ƐG��Ă��邩�Q�Ƃ���ϐ�
	int Opdraw;//�J�[�h�̐؎��ʒu�P
	int Updraw;//�J�[�h�̐؎��ʒu�Q
	int Rotdraw;//�J�[�h�̊p�x����

	//����̈ʒu��ۑ�
	bool LWeapon;
	bool RWeapon;

	bool m_f;
	bool m_l;
	bool m_l2;
	bool r_f;

	int test;

	bool L_position;

	bool S_position;
	bool S_position2;

	bool R_position;
};