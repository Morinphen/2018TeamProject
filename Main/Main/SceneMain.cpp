//�r�s�k�f�o�b�O�@�\���n�e�e�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
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
	Font::SetStrTex(L"0123456789");

	Draw::LoadImageW(L"image2.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"sakura.png", 1, TEX_SIZE_512);

	CObjDekc*obj = new CObjDekc();
	Objs::InsertObj(obj, OBJ_DEKC, 1);

	CObjEnemyDeck*obj_enemy = new CObjEnemyDeck();
	Objs::InsertObj(obj_enemy, OBJ_ENEMY_DECK, 1);

	CObjHand*obj_hand = new CObjHand();
	Objs::InsertObj(obj_hand, OBJ_HAND, 1);

	CObjEnemyHand*obj_enemy_hand = new CObjEnemyHand();
	Objs::InsertObj(obj_enemy_hand, OBJ_ENEMY_HAND, 1);

	CObjmouse* obj_mouse = new CObjmouse();
	Objs::InsertObj(obj_mouse, OBJ_MAUSE, 1);

//	CObjpoint* objt = new CObjpoint();
//	Objs::InsertObj(objt, OBJ_POINT, 11);

	CObjMap* obj_map = new CObjMap();
	Objs::InsertObj(obj_map, OBJ_MAP, 1);

	CObjPlayer* obj_p = new CObjPlayer();
	Objs::InsertObj(obj_p, OBJ_PLAYER, 1);
}

//�Q�[�����C�����s�����\�b�h
void CSceneMain::Scene()
{

}