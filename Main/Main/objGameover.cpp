//�g�p����w�b�_�[
#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjGameover.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameover::Init()
{

}

//�A�N�V����
void CObjGameover::Action()
{

}

//�h���[
void CObjGameover::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"�������`���b�^", 430, 220, 32, c);
}