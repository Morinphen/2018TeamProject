#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#include "SceneClear.h"
#include "GameHead.h"
#include "SceneGameover.h"

//�R���X�g���N�^
CSceneGameover::CSceneGameover()
{

}

//�f�X�g���N�^
CSceneGameover::~CSceneGameover()
{

}

//�Q�[�����C�����������\�b�h
void CSceneGameover::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"Arma Batlle");
	Draw::LoadImageW(L"Game Over.png", 5, TEX_SIZE_1024);

	CObjGameover* obj = new CObjGameover();	//�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_GAMEOVER, 10);//��l���I�u�W�F�N�g�o�^

	//�}�E�X�I�u�W�F�N�g�쐬
	CObjmouse* obj_mouse = new CObjmouse();
	Objs::InsertObj(obj_mouse, OBJ_MAUSE, 100);
}

//�Q�[�����C�����s�����\�b�h
void CSceneGameover::Scene()
{

}
