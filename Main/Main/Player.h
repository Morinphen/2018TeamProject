#pragma once

#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�}�b�v
class CObjPlayer : public CObj
{
public:
	CObjPlayer() {};
	~CObjPlayer() {};
	void Init();
	void Action();
	void Draw();

	bool m_f;
private:
	int m_x, m_y;
	bool start;

};