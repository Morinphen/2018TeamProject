#pragma once

#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：バックグラウンド(白の線枠)
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

//オブジェクト：バックグラウンド2(左のブロック背景)
class CObjBackGround2: public CObj
{
public:
	CObjBackGround2() {};
	~CObjBackGround2() {};
	void Init();
	void Action();
	void Draw();

private:

};

//オブジェクト：バックグラウンド3(右の動くレンガ背景)
class CObjBackGround3 : public CObj
{
public:
	CObjBackGround3() {};
	~CObjBackGround3() {};
	void Init();
	void Action();
	void Draw();

	int Position[30][26]; //動く背景の位置変数
	int time;
private:

};