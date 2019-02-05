#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_DEKC,
	OBJ_ENEMY_DECK,
	OBJ_CARD,
	OBJ_ENEMY_CARD,
	OBJ_HAND,
	OBJ_ENEMY_HAND,
	OBJ_MAUSE,
	OBJ_PLAYER,
	OBJ_ENEMY,
	OBJ_MAP,
	OBJ_POINT,
	OBJ_BACKGROUND,
	OBJ_BACKGROUND2,
	OBJ_BACKGROUND3,
	OBJ_LIST,
	OBJ_WINDOW,
	OBJ_JADGE,
	OBJ_PHERO,


	OBJ_FIELD_PLAYER,
	OBJ_FIELD_PLAYER2,
	OBJ_FIELD_PLAYER3,

	OBJ_FIELD_ENEMY,
	OBJ_FIELD_ENEMY2,
	OBJ_FIELD_ENEMY3,

	OBJ_TITLE,
	OBJ_CLEAR,
	OBJ_GAMEOVER,
};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
	ELEMENT_CARD,
};
//------------------------------------------------

//------------------------------------------------
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--



//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include"Deck.h"
#include"EnemyDeck.h"
#include"EnemyHand.h"
#include"Card.h"
#include"EnemyCard.h"
#include"mouse.h"
#include"map.h"
#include"point.h"
#include"testmau.h"
#include"HandCard.h"
#include"Cardlist.h"
#include"BackGround.h"
#include"PHero.h"
#include"EHero.h"
#include"PList.h"
#include"Window.h"
#include"Playjadge.h"

#include"Player.h"
#include"ObjTitle.h"
#include"ObjClear.h"
#include"objGameover.h"

//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include"SceneMain.h"
#include"SceneTitle.h"
#include"SceneClear.h"
#include"SceneGameover.h"
#include"point.h"
//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START CSceneMain
//-----------------------------------------------