#pragma once
#include "GameL\SceneObjManager.h"
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

	void SetpointFlag(bool b) { m_flag_point = b; }
private:
	int m_point;
	bool m_flag_point;
	bool m_p;
};
