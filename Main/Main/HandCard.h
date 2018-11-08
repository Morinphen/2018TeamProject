#pragma once
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト　デッキ
class CObjHand :public CObj
{
public:
	CObjHand() {};
	~CObjHand() {};
	void Init();
	void Action();
	void Draw();

	int hand[20];

	int basyo[20];
	int hensu;
	int hensu2;
	int hensu3;

private:

};