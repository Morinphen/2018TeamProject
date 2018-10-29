#pragma once
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト　デッキ
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
	int basyo;
	int bango;
	int genba;
	int test;
	int playertrun;
	int enemytrun;
	int taka;

	int test2;
};