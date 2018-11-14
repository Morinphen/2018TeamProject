//使用するヘッダーファイル
#include"Cardlist.h"
#include"GameHead.h"

//使用するネームスペース
using namespace GameL;

void CObjCardlist::Init()
{

}

int CObjCardlist::Action(int x,int y,int a)
{
	int z = 0;

	if (x == 1)
	{
		if (y >= 1)
		{
			z = 2;
		}
		else
		{
			z = 1;
		}
	}
	else if (x == 2)
	{
		if (y >= 8)
		{
			z = 2;
		}
		else
		{
			z = 1;
		}
	}
	else if (x == 3)
	{
		if (y >= 12)
		{
			z = 2;
		}
		else
		{
			z = 1;
		}
	}
	else {
		z = 2;
	}
	return z;
}

void CObjCardlist::Draw()
{

}