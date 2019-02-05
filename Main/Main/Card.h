#pragma once
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�J�[�h
class CObjCard :public CObj
{
public:
	CObjCard(float x,float y,int z);
	~CObjCard() {};
	void Init();
	void Action();
	void Draw();

	bool Punch;//�����X�^�[�̍U��
	bool Pusave;//�����X�^�[�̍U������
	bool Set;//����̑�������

	int Bat;
	int Bat2;
	 
private:
	void Cardname();
	void Effect(float _Cnanber,bool *When,bool *Play,bool *Indu,int Position);
	void Wwindow(bool *_set,bool _delete);

	int m_x, m_y;//�J�[�h�̕`��ʒu
	int Setcard;//�J�[�h�̏ꏊ
	int Posicard;//�J�[�h�̏ꏊ�Q
	int Number;//���Ԃ̌Œ�
	int Number2;//��D�̃J�[�h�ԍ�
	int Number3;//�J�[�h�̏��Ԕԍ�
	int Number4;//�J�[�h���ԍ�

	int Hp;//�J�[�h��hp
	int Atack;//�J�[�h�̍U����
	int Guard;//�J�[�h�̖h���
	int Ccost;//�J�[�h�̃R�X�g
	bool Wstop;//����̑�������ϐ�
	int WSetting;//����𑕔������ۂɌ��߂�ϐ�

	int TextD;//�e�L�X�g�f�[�^�ۑ��p�ϐ�
	int NTcard;//�J�[�h�f�[�^�ԍ�
	int Cadata;//�f�[�^�ԍ��ۑ��p�ϐ�

	bool WhenEfe;//���������ʕϐ�
	bool PlayEfe;//�N�����ʕϐ�
	bool InduEfe;//�U�����ʕϐ�

	int playertrun;
	int enemytrun;

	int Type;//�J�[�h�̎�ށ@1=�L����,2=����,3=�h��

	//�J�[�h�e�L�X�g�̕\��
	char *Name;
	char *Text;
	char text[256];
	int Tlong;

	bool CardHitCheck;//�}�E�X���J�[�h�ƐG��Ă��邩�Q�Ƃ���ϐ�
	int Opdraw;//�J�[�h�̐؎��ʒu�P
	int Updraw;//�J�[�h�̐؎��ʒu�Q
	int Rotdraw;//�J�[�h�̊p�x����

	bool Button;//�{�^���p�ϐ�
	int BDraw;//�{�^��draw�p�ϐ�
	//�{�^���p�\���ʒu
	float b_x;
	float b_y;

	//�E�B���h�E�p�ϐ�
	bool Wset;
	bool LDcard;
	bool RDcard;
	int WLcard;
	int WRcard;
	int WLupdraw;
	int WRupdraw;
	int Wcount;

	//�����X�^�[�̈ʒu��ۑ�
	bool FSummon;
	bool FSummon2;

	//����̈ʒu��ۑ�
	bool LWeapon;
	bool RWeapon;

	bool Summon;//�J�[�h���������ꂽ���ǂ���
	bool StopSm;//�J�[�h�̏�������p

	bool m_f;
	bool m_l;
	bool m_c; //�N���b�N����������

	int test;

	//bool L_position;

	bool S_position;
	bool S_position2;

	//bool R_position;

	//�R�X�g����U�ۑ�
	int m_kos;
};