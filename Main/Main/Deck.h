#pragma once

#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

enum type {
	monster = 1,
	weapon = 2,
	shield = 3
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
	int m_point;
	int Cost;
	bool Turn;
private:
	int x, y;
	int m_x, m_y;
	int Ctype;//�J�[�h�̎��

	int Cardcount;//�������J�[�h�̍��v
	int stop;

	int Deck[40];//

	

	bool m_f;
	bool m_f2;
	bool Start;
	bool m_flag_point;
};