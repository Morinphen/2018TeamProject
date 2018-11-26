#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjGameover :public CObj
{
public:
	CObjGameover() {};
	~CObjGameover() {};
	void Init();
	void Action();
	void Draw();
private:
};