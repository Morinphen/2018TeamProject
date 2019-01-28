#pragma once
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

class CObjJadge :public CObj
{
public:
	CObjJadge();
	~CObjJadge();
	void Init();
	void Action();
	void Draw();
private:
	int Random;//乱数
	int Stime;//表示時間

	bool GameStart;//ゲーム開始用変数
	bool First;//1P側先攻
	bool After;//1P側後攻
};
