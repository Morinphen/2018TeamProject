//�r�s�k�f�o�b�O�@�\���n�e�e�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;
//�g�p�w�b�_�[
#include"SceneMain.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//�Q�[�����C�����������\�b�h
void CSceneMain::InitScene()
{
	Draw::LoadImageW(L"image2.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"sakura.png", 1, TEX_SIZE_512);

	CObjDekc*obj = new CObjDekc();
	Objs::InsertObj(obj, OBJ_DEKC, 1);

	CObjmouse* obj_mouse = new CObjmouse();
	Objs::InsertObj(obj_mouse, OBJ_MAUSE, 1);

	CObjMau*obja = new CObjMau();
	Objs::InsertObj(obja, OBJ_PLAYER, 11);
}

//�Q�[�����C�����s�����\�b�h
void CSceneMain::Scene()
{

}