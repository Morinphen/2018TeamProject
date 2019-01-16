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

		bool Touch;//自分のカードに触れた場合trueになる
		bool Wtouch;//手札の武器を選択した場合trueになる

		int Choice[3];//自分のカードに触れたときの変数

		//敵のカードに触れたときの変数
		bool EChoice;
		bool EChoice2;
		bool EChoice3;

		float m_mouse_x;//マウスのX座標
		float m_mouse_y;//マウスのY座標

	private:

};