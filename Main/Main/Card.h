#pragma once
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�f�b�L
class CObjCard :public CObj
{
public:
	CObjCard(float x,float y);
	~CObjCard() {};
	void Init();
	void Action();
	void Draw();

private:
	int m_x, m_y;
	int Setcard;
	int Nanber;
	int Posicard;
	int playertrun;
	int enemytrun;

	int Opdraw;
	int Updraw;
	int Rotdraw;

	bool m_r;
	bool Summon;
};