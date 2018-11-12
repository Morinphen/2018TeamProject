//使用するヘッダーファイル
#include"Mcardlist.h"
#include"GameHead.h"

//使用するネームスペース
using namespace GameL;

void CObjMCardlist::Init()
{

}

int CObjMCardlist::Action(int a,int b)
{
	if (a >= 1)
	{
		b = 2;
		return b;
	}
	return 0;
}

void CObjMCardlist::Draw()
{

}