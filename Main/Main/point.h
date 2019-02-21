#pragma once
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

class CObjpoint :public CObj
{
public:
	CObjpoint();
	~CObjpoint();
	void Init();
	void Action();
	void Draw();
	int Cost;	//カード使用のためのコスト
	int PreviousCost; //前のターン最後に残ったコストを一時保存する変数
	int AddCost; //コスト加算表示用
	float time;
	int e_Cost;

	void SetpointFlag(bool b) { m_flag_point = b; }
private:
	int m_point;
	int e_point;
	bool m_flag_point;
	bool m_p;
};
