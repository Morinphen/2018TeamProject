#pragma once
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト　デッキ
class CObjEnemyHand :public CObj
{
public:
	CObjEnemyHand() {};
	~CObjEnemyHand() {};
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