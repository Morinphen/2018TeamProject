//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include "GameHead.h"
#include "mouse.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjmouse::Init()
{
	POINT point;
}

//�A�N�V����
void CObjmouse::Action()
{
	GetCursorPos(&point);
}

//�h���[
void CObjmouse::Draw()
{
	float c[4] = { 1,1,1,1 };
	CDrawFont::StrDraw(L"aiueo",100,100,16,c);
}