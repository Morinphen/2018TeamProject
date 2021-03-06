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
	bool m_key_flag;
	bool m_l;
	bool m_c; //長押し制御用
	int t_t;//topの値
	int t_b;//bottomの値
	int i,j;//音が鳴るまでのカウント・BGMが鳴るまでのカウント
	int cou;
	bool go;
	bool BGM;

};