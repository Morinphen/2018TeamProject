#pragma once
#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjwindow :public CObj
{
public:
	CObjwindow(int _x,int _y,int _z);
	~CObjwindow();
	void Init();
	void Action();
	void Draw();
	bool Wdelete;
private:
	int x;
	int y;

	int OpenT;
};
