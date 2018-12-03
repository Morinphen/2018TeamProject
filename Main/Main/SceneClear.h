#pragma once
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CSceneClear :public CScene
{
public:
	CSceneClear();
	~CSceneClear();
	void InitScene();
	void Scene();
private:
};