#pragma once

#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

class CObjPlist
{
public:
	CObjPlist() {};
	~CObjPlist() {};
	void Init();
	char* Action(char **name,int type, int *nanber,int *ntnanber, int *hp, int *atack, int *guard, char **text);
	void Draw();

private:
	int ability;
	int i, j;
};