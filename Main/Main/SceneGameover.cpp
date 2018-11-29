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
	Draw::LoadImageW(L"image2.png", 0, TEX_SIZE_512);

	CObjGameover* obj = new CObjGameover();	//�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_GAMEOVER, 10);//��l���I�u�W�F�N�g�o�^

}

//�Q�[�����C�����s�����\�b�h
void CSceneGameover::Scene()
{

}
