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

		bool m_r;
		bool m_f;

		bool EChoice;

	private:
		float m_mouse_x;//マウスのX座標
		float m_mouse_y;//マウスのY座標

};