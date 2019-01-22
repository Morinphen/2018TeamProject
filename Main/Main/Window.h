#pragma once
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

class CObjwindow :public CObj
{
public:
	CObjwindow(int _x,int _y);
	~CObjwindow();
	void Init();
	void Action();
	void Draw();
	bool Wdelete;
private:
	int x;
	int y;
};
