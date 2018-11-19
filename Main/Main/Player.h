#pragma once

#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：マップ
class CObjPlayer : public CObj
{
public:
	CObjPlayer() {};
	~CObjPlayer() {};
	void Init();
	void Action();
	void Draw();

	bool m_f;
private:
	int m_x, m_y;
	bool start;

};