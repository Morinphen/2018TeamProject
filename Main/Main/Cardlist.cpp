//使用するヘッダーファイル
#include"Cardlist.h"
#include"GameHead.h"

//使用するネームスペース
using namespace GameL;

void CObjCardlist::Init()
{

}

int CObjCardlist::Action(int x,int y,int a)//x=Type,y=Nanber,a=属性（ＨＰ，攻撃力、防御力）
{
	int z = 0;

	if (x == 1)
	{
		if (a == 0) {
			z = 2;
		}
		if (a == 1)
		{
			z = 2;
		}
		if (a == 2)
		{
			z = 0;
		}
	}
	else if (x == 2)
	{
		if (a == 0) {
			z = 3;
		}
		if (a == 1)
		{
			z = 2;
		}
		if (a == 2)
		{
			z = 0;
		}
	}
	else if (x == 3)
	{
		if (a == 0) {
			z = 3;
		}
		if (a == 1)
		{
			z = 0;
		}
		if (a == 2)
		{
			z = 2;
		}
	}
	return z;
}

void CObjCardlist::Draw()
{

}