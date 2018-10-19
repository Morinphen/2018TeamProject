#pragma once

#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：マウス
class CObjmouse : public CObj
{
	public:
		CObjmouse(){};
		~CObjmouse(){};
		void Init();
		void Action();
		void Draw();

	private:
		float m_mouse_x;
		float m_mouse_y;
};