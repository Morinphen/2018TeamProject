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
#include "SceneTitle.h"

//�R���X�g���N�^
CSceneClear::CSceneClear()
{

}

//�f�X�g���N�^
CSceneClear::~CSceneClear()
{

}

//�Q�[�����C�����������\�b�h
void CSceneClear::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"Arma Batlle");
	Draw::LoadImageW(L"image2.png", 0, TEX_SIZE_512);

	CObjClear* obj = new CObjClear();	//�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_CLEAR, 10);//��l���I�u�W�F�N�g�o�^

	//�^�C�g���I�u�W�F�N�g�쐬
	//CObjTitle* obj = new CObjTitle();	//�^�C�g���I�u�W�F�N�g�쐬
	//Objs::InsertObj(obj, OBJ_TITLE, 10);//��l���I�u�W�F�N�g�o�^

}

//�Q�[�����C�����s�����\�b�h
void CSceneClear::Scene()
{

}
