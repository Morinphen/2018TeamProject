#pragma once
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�f�b�L
class CObjMau :public CObj
{
public:
	CObjMau() {};
	~CObjMau() {};
	void Init();
	void Action();
	void Draw();

private:
	float m_x;		//��l���@�̂������ړ��ϐ�
	float m_y;		//��l���@�̂������ړ��p�ϐ�
};