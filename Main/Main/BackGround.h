#pragma once

#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：バックグラウンド
class CObjBackGround : public CObj
{
public:
	CObjBackGround() {};
	~CObjBackGround() {};
	void Init();
	void Action();
	void Draw();

private:

};