#pragma once
#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjJadge :public CObj
{
public:
	CObjJadge();
	~CObjJadge();
	void Init();
	void Action();
	void Draw();
private:
	int Random;
	int Stime;

	bool GameStart;
	bool First;
	bool After;
};
