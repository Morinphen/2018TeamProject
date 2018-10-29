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
	int Setcard;
	int Nanber;
	int Posicard;
	int playertrun;
	int enemytrun;

	int Opdraw;
	int Updraw;
	int Rotdraw;
};