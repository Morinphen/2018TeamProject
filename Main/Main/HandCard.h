#pragma once
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�f�b�L
class CObjHand :public CObj
{
public:
	CObjHand() {};
	~CObjHand() {};
	void Init();
	void Action();
	void Draw();

	int hand[20];

	int basyo[20];
	int hensu;
	int hensu2;
	int hensu3;

private:

};