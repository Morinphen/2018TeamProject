//�g�p����w�b�_�[�t�@�C��
#include"Cardlist.h"
#include"GameHead.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

void CObjCardlist::Init()
{

}

int CObjCardlist::Action(int x,int y,int a)//x=Type,y=Nanber,a=�����i�g�o�C�U���́A�h��́j
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