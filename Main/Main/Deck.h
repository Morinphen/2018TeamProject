#pragma once

#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�f�b�L
class CObjDekc :public CObj
{
public:
	CObjDekc() {};
	~CObjDekc() {};
	void Init();
	void Action();
	void Draw();

	int cardcou;
private:
	int x, y;
	int m_x, m_y;
	bool m_f;

	bool Start;
};