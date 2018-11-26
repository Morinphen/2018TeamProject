#pragma once
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CSceneGameover :public CScene
{
public:
	CSceneGameover();
	~CSceneGameover();
	void InitScene();
	void Scene();
private:
};