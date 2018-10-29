#pragma once
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト　デッキ
class CObjMau :public CObj
{
public:
	CObjMau() {};
	~CObjMau() {};
	void Init();
	void Action();
	void Draw();

private:
	float m_x;		//主人公機のｘ方向移動変数
	float m_y;		//主人公機のｙ方向移動用変数
};