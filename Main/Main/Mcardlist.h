#pragma once

#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

class CObjMCardlist
{
public:
	CObjMCardlist() {};
	~CObjMCardlist() {};
	void Init();
	int Action(int a,int b);
	void Draw();

private:
	//int Cardlist[50];
	//int Cardlist;
};