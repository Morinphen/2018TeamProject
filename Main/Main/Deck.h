#pragma once

#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

enum type {
	monster = 1,
	weapon = 2,
	shield = 3,
	item = 4,
};

//�I�u�W�F�N�g�@�f�b�L
class CObjDekc :public CObj
{
public:
	CObjDekc() {};
	~CObjDekc() {};
	void Init();
	void Action();
	void Draw();
	void SetpointFlag(bool b) { m_flag_point = b; }

	int Cnanber;//��D�̃J�[�h�̍ő吔
	int Card;//�������J�[�h�̔ԍ�
	int Deck[40];//�f�b�L�̒��̃J�[�h�z��
	int Pullc[40];

	int m_point;
	int p_point; //�^�[���I�����̏����S�[���h���ꎞ�ۑ�����ϐ�
	int Cost;
	bool Turn;
	bool STurn;
	bool AddCostDisplay; //�S�[���h�ǉ����o������ϐ�
	bool Start;//������D��[�p�ϐ�
	bool StartG;//�Q�[���J�n�p�ϐ�

	bool Button2;//�{�^���o���p�ϐ�

	int i;

	bool effect;//�J�[�h�̌��ʕϐ�
	bool go;
private:
	int x, y;
	int m_x, m_y;
	bool m_l; //�}�E�X�̃N���b�N����
	bool m_c; //�}�E�X�������ςȂ��̂܂ܔ������Ȃ��悤�ɐ��䂷��ϐ�
	int Ctype;//�J�[�h�̎��

	int Deckcount; //�f�b�L�̎c�薇�����Q�Ƃ���ϐ�
	int Cardcount; //�������J�[�h�̍��v
	int stop;
	int Data;//�f�b�L�ɓo�^����J�[�h�f�[�^

	bool m_f;
	bool m_f2;
	bool m_flag_point;
	bool r_f;

	int DrawButton_y; //�h���[�{�^����y�����W
	int DrawButton_time; //�h���[�{�^���̎��Ԑ���
	//int TurnCount; //���݂̃^�[������\�����邽�߂̕ϐ�
};