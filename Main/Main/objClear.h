#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjClear :public CObj
{
public:
	CObjClear() {};
	~CObjClear() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;
	bool m_l;
	bool gc;
	bool BGM;
	int t_t;//topの値
	int t_b;//bottomの値
	int i, j;//音が鳴るまでのカウント・BGMが鳴るまでのカウント
	int cou;


};