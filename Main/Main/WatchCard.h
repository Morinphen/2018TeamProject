#pragma once
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト　観賞用カード
class CObjWatchCard :public CObj
{
public:
	CObjWatchCard() {};
	~CObjWatchCard() {};
	void Init();
	void Action();
	void Draw();

private:

};