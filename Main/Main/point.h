#pragma once
#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjpoint :public CObj
{
public:
	CObjpoint();
	~CObjpoint();
	void Init();
	void Action();
	void Draw();
	int Cost;	//�J�[�h�g�p�̂��߂̃R�X�g
	int AddCost; //�R�X�g���Z�\���p
	int time;
	int e_Cost;

	void SetpointFlag(bool b) { m_flag_point = b; }
private:
	int m_point;
	int e_point;
	bool m_flag_point;
	bool m_p;
};
